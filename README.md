# CPSC351-Assignment1-Part1
Part I Overview
Write a simple shell program called shell. When ran, the parent process will print out the
prompt which looks like:

cmd>

and will then wait for the user to enter a command such as ls, ps, or any other command. For
example:
cmd> ls
The parent process will then use fork() in order to create a child and then call wait() in order
to wait for the child to terminate. The child process will use execlp() in order to replace its
program with the program entered at the command line. After the child produces the output,
the parent will prompt the user for another command. For example:
cmd>ls
file.txt fork fork.c mystery1 mystery1.cpp mystery2 shell shell.cpp

The parent will repeat the above sequence until the user types the exit command, which will
cause the parent process to exit.
Sample/Skeleton Codes
A basic forking example (fork.cpp) had been provided in the class notes as well as in the zip
bundle of sample files/skeletons accompanying this assignment called samples.zip. The bundle
also includes a skeleton file for the shell with parts to complete marked with TODO. You are not
required to use these files, but may find them helpful.
NOTE: Please make sure to error-check all system calls in this assignment. This
is very important in practice and can also save you hours of debugging frustration. fork(),
execlp(), and wait() will return -1 on error. Hence, you need to always check their return
values and terminate your program if the return value is -1. For example:
p i d t pid = f o r k ( )
i f ( pid < 0 )
{

p e r r o r ( ’ ’ f o r k ’ ’ ) ;
e x i t ( −1);

}
The perror() function above will print out fork followed by the explanation of the error.
