#!/bin/bash
cat /proc/cpuinfo | grep flag | head -1
cd /home/grid/testbed/tb147/lab/vec_samples/src 
ml icc
arr=( "-xSSE2" "-xSSE3" "-xAVX"  )
for a in "${arr[@]}"; do
  for b in {1..3}; do
    var1=$(date +%M)
    var2=$(date +%S)
    echo icpc -std=c++17 -O$b $a lab.cpp -o file-$var1-$var2
    icpc -std=c++17 -O$b $a lab.cpp -o file-$var1-$var2
    echo "$a $b:"
    time ./file-$var1-$var2
  done 
done