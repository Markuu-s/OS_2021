while true
do
a=$(tail -n1 data.txt)
a=$((a+=1))
echo $a >> data.txt
done