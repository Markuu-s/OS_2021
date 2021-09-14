gcc ex2.c -o ex2
./ex2 &
pid_2=$!
for ((i=1; i < 5; i++))
do
pstree $pid_2
sleep 2
done
