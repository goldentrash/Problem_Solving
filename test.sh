#!/bin/sh

if [ ! -d $1 ]
then
  1>&2 echo "there's no problem. Are you sure it's $1?"
  exit 2
fi

CNT=1
while [ -f "./$1/input$CNT.txt" ]
do
  RET=`"./$1/solution" < "./$1/input$CNT.txt" | \
    diff -b "./$1/output$CNT.txt" -`

  [ -z "$RET" ] && echo "clear case $CNT!" || echo "fail case $CNT\r\n$RET"
  echo

  CNT=`expr $CNT + 1`
done

exit 0