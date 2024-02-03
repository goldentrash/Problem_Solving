#! /bin/bash

CNT=1
RET=0
while [ -f "./input$CNT.text" ]; do
  RET=$(
    "./solution" < "./input$CNT.text" \
      | diff --ignore-space-change "./output$CNT.text" -
  )

  if [ -z $RET ]; then
    echo "PASS $CNT"
    echo
  else
    echo "FAIL $CNT"
    echo $RET
    echo

    RET=1
  fi

  CNT=$(expr $CNT + 1)
done

exit $RET
