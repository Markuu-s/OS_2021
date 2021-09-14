# !/bin/bash
gcc ex1.c -o ex1
sleep 4s
for ((i=1; i < 10; i++))
do
./ex1
sleep 1s
done