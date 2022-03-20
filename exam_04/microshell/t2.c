
#include<stdio.h>
  
// chdir function is declared
// inside this header
#include<unistd.h> 
int main(int ac, char **av)
{   
    (void)ac;
    execve(av[0], av, NULL);   // execve will execute the command for as and exit the child upon error it will not exit this child
    // write(1, "1\n", 2);
    // close(0);
    // write(1, "2\n", 2);
    // close(1);
    // write(1, "3\n", 2);
    // close(2);
    // close(3);
    return 0;
}