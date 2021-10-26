mkdir -p ../week01
echo Mark Esaian > ../week01/file.txt
# user should be in dir week10
link ../week01/file.txt _ex2.txt

find ../ -inum $(ls -li ../week01/file.txt | awk '{print $1}') > ex2.txt
find ../ -inum $(ls -li ../week01/file.txt | awk '{print $1}') -exec rm {} \; >> ex2.txt