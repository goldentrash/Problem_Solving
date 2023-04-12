#!/bin/bash

if [ -z `command -v curl` ]
then
  1>&2 echo "plz install curl and try again"
  exit 1
fi

if [ -z `command -v xmllint` ]
then
  1>&2 echo "plz install xmllint and try again"
  exit 1
fi

CF()
{
  EXAMPLES=`curl "https://codeforces.com/problemset/problem/$1/$2" | \
    xmllint --html --xpath //div[@class=\"sample-test\"] - 2>/dev/null`
  
  if [ -z "$EXAMPLES" ]
  then
    1>&2 echo "there's no data. Are you sure it's $1/$2?"
    exit 2
  fi

  if [ ! -d $2$1 ]
  then
    mkdir $2$1
  fi

  CNT=`echo $EXAMPLES | xmllint --html --xpath "count(//div[@class=\"input\"])" - 2>/dev/null`

  while [ $CNT -gt 0 ]
  do
    echo $EXAMPLES | \
      xmllint --html --xpath "//div[@class=\"input\"][$CNT]/pre" - 2>/dev/null | \
      sed "s/<\/\?pre>//g" | \
      sed "s/<br\/>/\\n/g" \
    > ./$2$1/input$CNT.txt 
    truncate -s -1 ./$2$1/input$CNT.txt

    echo $EXAMPLES | \
      xmllint --html --xpath "//div[@class=\"output\"][$CNT]/pre" - 2>/dev/null | \
      sed "s/<\/\?pre>//g" | \
      sed "s/<br\/>/\\n/g" \
      > ./$2$1/output$CNT.txt
    truncate -s -1 ./$2$1/output$CNT.txt

    CNT=`expr $CNT - 1`
  done

  cat ./$2$1/input1.txt > $2$1/input.txt
  touch ./$2$1/solution.cpp
}

# only codeforces is supported yet
case $1 in
  cf)
    CF $2 $3
    ;;
  *)
    1>&2 echo "Unknown Platform"
    exit 2
      ;;
esac

exit 0