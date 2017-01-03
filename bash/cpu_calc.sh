#!/bin/bash
nPid=$1;
nTimes=60; # customize it
delay=1; # customize it
strCalc=`top -d $delay -b -n $nTimes -p $nPid \
  |grep $nPid \
  |sed -r -e "s;\s\s*; ;g" -e "s;^ *;;" \
  |cut -d' ' -f9 \
  |tr '\n' '+' \
  |sed -r -e "s;(.*)[+]$;\1;" -e "s/.*/scale=2;(&)\/$nTimes/"`;
echo "# Output of strCalc = $strCalc"
nPercCpu=`echo "$strCalc" | bc -l`
echo "Average CPU for the PID[$nPid] is [$nPercCpu]"