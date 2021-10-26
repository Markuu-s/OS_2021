touch _ex3.txt
chmod ugo-x _ex3.txt 
ls -l | grep _ex3.txt > ex3.txt
chmod uo+rwx _ex3.txt 
ls -l | grep _ex3.txt >> ex3.txt
chmod -R g=u _ex3.txt 
ls -l | grep _ex3.txt >> ex3.txt

echo What does 660 mean for ex3.txt? >> ex3.txt
echo 660 = _ 110 110 000 = -rw-rw---- it mean: >> ex3.txt
echo     user can read and write >> ex3.txt
echo     group can read and write >> ex3.txt
echo     other has no permission >> ex3.txt

echo What does 775 mean for ex3.txt? >> ex3.txt
echo 775 = _ 111 111 101 = -rwxrwxr-x it mean: >> ex3.txt
echo     user can read, write and execute >> ex3.txt
echo     group can read, write and execute >> ex3.txt
echo     other can read and execute >> ex3.txt

echo What does 777 mean for ex3.txt? >> ex3.txt
echo 775 = _ 111 111 101 = -rwxrwxrwx it mean than all have all permission >> ex3.txt
