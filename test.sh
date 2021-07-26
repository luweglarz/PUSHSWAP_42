#!/bin/bash

SOMME=0
AVERAGE=0
MIN=2147483647
MAX=-2147483648
if [[ $1 =~ ^[+-]?[0-9]+$ ]] && [[ $# == 2 ]]
then
      for i in {1..5}
      do
	sleep 0.5s
      ARG=`ruby -e "puts (1..$1).to_a.shuffle.join(' ')"`
      echo "les ARGS $ARG"
         OUTPUT=$(./push_swap $ARG | wc -l)
      CHECKER=$(./push_swap $ARG | ./checker_$2 $ARG)
      if [ $MIN -gt $OUTPUT ]
      then
         MIN=$OUTPUT
      fi
      if [ $MAX -lt $OUTPUT ]
      then
         MAX=$OUTPUT
      fi
      ((SOMME+=OUTPUT))
      done
   ((AVERAGE=SOMME/5))
   echo "Average $AVERAGE"
   echo "min $MIN"
   echo "max $MAX"
else
   echo "First parameter must be the amount of numbers you want to try"
   echo "Second parameter must be the OS you are
    using this script on"
fi
