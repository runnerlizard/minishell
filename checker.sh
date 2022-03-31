#!/bin/sh


echo /bin/ls
/bin/ls

echo
echo
echo "echo $ ?"
echo $?

echo
echo
echo /bin/ls builtins 
/bin/ls builtins


echo
echo
echo /bin/cat main.c
/bin/cat main.c


echo
echo
echo /bin/wc builtins 
/bin/wc builtins


echo
echo
echo /bin/wc builtins/echo.c
/bin/wc builtins/echo.c


echo
echo
echo "echo It is the best minishell i have ever seen!!!"
echo It is the best minishell i have ever seen!!!

echo
echo
echo "echo -n what a brilliant job!!! and echo where is the NL??"
echo -n what a brilliant job!!!
echo where is the NL???

echo
echo
echo "ls Makefile and echo $ ?"
ls Makefile
echo $?

echo
echo
echo "ls notexist and echo $ ?"
ls notexist
echo $?

echo
echo
echo "notexistcmd and echo $ ?"
notexistcmd
echo $?

echo
echo
echo "$ ? + $ ?"
$? + $?

echo
echo
echo 'echo "cat lol.c | cat > lol.c"'
echo "cat lol.c | cat > lol.c"

echo
echo
echo "echo ''"
echo ''

echo
echo
echo "echo $ TERM_PROGRAM"
echo $TERM_PROGRAM

echo
echo
echo "ls $ PWD"
ls $PWD

echo
echo
echo "echo 'cat lol.c | cat > lol.c'"
echo 'cat lol.c | cat > lol.c'

echo
echo
echo "echo '$ USER'"
echo '$USER'

echo
echo
echo env
env

echo
echo
echo export
export

echo
echo
echo env
env

echo
echo
echo unset TERM_PROGRAM
unset TERM_PROGRAM

echo
echo
echo env
env

echo
echo
echo cd builtins
cd builtins

echo
echo
echo ls
ls

echo
echo
echo cd ..
cd ..

echo
echo
echo ls
ls

echo
echo
echo cd notexist
cd notexist

echo
echo
echo ls
ls

echo
echo
echo cd .
cd .

echo
echo
echo ls
ls

echo
echo
echo pwd
pwd

echo
echo
echo ../../../../bin/ls
../../../../bin/ls


echo
echo
echo ls >file
ls >file

echo
echo
echo "<file wc"
<file wc

echo
echo
echo "echo df,df,j >file2"
echo df,df,j >file2

echo
echo
echo "cat <file2"
cat <file2

echo
echo
echo "echo df,df,j >file3 >file4 >file5"
echo df,df,j >file3 >file4 >file5

echo
echo
echo "cat <file3"
cat <file3

echo
echo
echo "cat <file4"
cat <file4

echo
echo
echo "cat <file5"
cat <file5

echo
echo
echo "echo something >>file5"
echo something >>file5


echo
echo
echo "cat <file5"
cat <file5

echo
echo
echo "ls notexisted 2>file5"
ls notexisted 2>file5

echo
echo
echo "cat <file5"
cat <file5

rm file1 file2 file3 file4

echo
echo
echo "cat <file5 | grep ls | wc"
cat <file5 | grep ls | wc


echo
echo
echo "ls notexist | grep ls | wc"
ls notexist | grep ls | wc

echo
echo
echo "ls >file | < file5 grep ls | < file < file5 wc"
ls >file | < file5 grep ls | < file < file5 wc

echo
echo
echo notexistcmd
notexistcmd

echo
echo
echo 'ls -l $PWD | echo -n $PATH | cat | wc -l'
ls -l $PWD | echo -n $PATH | cat | wc -l

echo
echo
echo 'echo $USER'
echo $USER

echo
echo
echo 'ls dhgdjhgj || echo  || works! && echo and && works too!'
ls dhgdjhgj || echo ' || works!' && echo 'and && works too!'

echo
echo
echo 'ls dhgdjhgj && echo  && this should not be there || echo only mistake and this message - OK!'
ls dhgdjhgj && echo  '&& this should not be here!' || echo 'only mistake and this message - OK!'
