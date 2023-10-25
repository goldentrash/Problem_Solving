#! /bin/bash

CODE_FORCES() {
  CONTEST=$1
  PROBLEM=$2

  # Fetch examples
  SOURCE="https://codeforces.com/problemset/problem/$CONTEST/$PROBLEM"
  EXAMPLES=$(
    curl $SOURCE \
      | xmllint --html --xpath //div[@class=\"sample-test\"] - 2> /dev/null
  )

  # Error if no data
  if [ -z "$EXAMPLES" ]; then
    echo 1>&2 "there's no data. Are you sure it's $CONTEST/$PROBLEM?"
    exit 2
  fi

  # Check how many examples are provided
  CNT=$(
    echo "$EXAMPLES" \
      | xmllint --html --xpath "count(//div[@class=\"input\"])" - 2> /dev/null
  )

  # Write examples (input & output)
  while [ $CNT -gt 0 ]; do
    echo "$EXAMPLES" \
      | xmllint --html --xpath "//div[@class=\"input\"][$CNT]/pre" - 2> /dev/null \
      | sed --regexp-extended "s/<\/?pre>|<div[^>]*>//g" \
      | sed --regexp-extended "s/<br\/>|<\/div>/\\n/g" \
        > "./input$CNT.text"

    echo "$EXAMPLES" \
      | xmllint --html --xpath "//div[@class=\"output\"][$CNT]/pre" - 2> /dev/null \
      | sed "s/<\/\?pre>//g" \
      | sed "s/<br\/>/\\n/g" \
        > "./output$CNT.text"

    CNT=$(expr $CNT - 1)
  done

  cat ./input1.text > ./input.text
  echo "// $SOURCE" > ./solution.cpp
}

##################################### PROCESS #####################################

# Check Dependencies
echo "Check Dependencies"
if [ -z $(command -v curl) ]; then
  echo 1>&2 "plz install curl and try again"
  exit 1
fi
if [ -z $(command -v xmllint) ]; then
  echo 1>&2 "plz install xmllint and try again"
  exit 1
fi
echo

# Clear examples (input & output)
echo "Clear Examples (Input & Output)"
CNT=1
while [ -f "./input$CNT.text" ]; do
  rm ./input$CNT.text ./output$CNT.text

  CNT=$(expr $CNT + 1)
done
echo

# only codeforces is supported yet
echo "Fetch Examples"
PLATFORM=$1
case $PLATFORM in
  cf)
    CODE_FORCES $2 $3
    ;;
  *)
    echo 1>&2 "Unknown Platform"
    exit 2
    ;;
esac
echo

exit 0
