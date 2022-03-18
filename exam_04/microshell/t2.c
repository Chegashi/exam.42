
#include<stdio.h>
  
// chdir function is declared
// inside this header
#include<unistd.h> 
int main()
{   
    close(0);
    close(1);
    close(2);
    close(3);
    return 0;
}