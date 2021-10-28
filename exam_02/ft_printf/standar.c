#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>

int	main(void)
{
	int n;
	// n=printf("Simple test\n");printf("{%d}\n", n);
	// n=printf("\n");printf("{%d}\n", n);
	// n=printf("%d\n", 0);printf("{%d}\n", n);
	// n=printf("%d\n", 42);printf("{%d}\n", n);
	// n=printf("%d\n", 1);printf("{%d}\n", n);
	// n=printf("%d\n", 5454);printf("{%d}\n", n);
	// n=printf("%d\n", (int)2147483647);printf("{%d}\n", n);
	// n=printf("%d\n", (int)2147483648);printf("{%d}\n", n);
	// n=printf("%d\n", (int)-2147483648);printf("{%d}\n", n);
	// n=printf("%d\n", (int)-2147483649);printf("{%d}\n", n);
	// n=printf("\n");printf("{%d}\n", n);
	// n=printf("%x\n", 0);printf("{%d}\n", n);
	// n=printf("%x\n", 42);printf("{%d}\n", n);
	// n=printf("%x\n", 1);printf("{%d}\n", n);
	// n=printf("%x\n", 5454);printf("{%d}\n", n);
	// n=printf("%x\n", -0);printf("{%d}\n", n);
	n=printf("%x\n", -42);printf("{%d}\n", n);
	// n=printf("%x\n", -1);printf("{%d}\n", n);
	// n=printf("%x\n", -5454);printf("{%d}\n", n);
	// n=printf("%x\n", (int)2147483647);printf("{%d}\n", n);
	// n=printf("%x\n", (int)2147483648);printf("{%d}\n", n);
	// n=printf("%x\n", (int)-2147483648);printf("{%d}\n", n);
	// n=printf("%x\n", (int)-2147483649);printf("{%d}\n", n);
	// n=printf("%s\n", "");printf("{%d}\n", n);
	// n=printf("%s\n", "toto");printf("{%d}\n", n);
	// n=printf("%s\n", "wiurwuyrhwrywuier");printf("{%d}\n", n);
	// n=printf("-%s-%s-\n", "toto", "wiurwuyrhwrywuier");printf("{%d}\n", n);
	// n=printf("\n--Mixed---\n");printf("{%d}\n", n);
	// n=printf("%d%x%d%x%d%x%d%x\n", 0, 0, 42, 42, 2147483647, 2147483647, (int)-2147483648, (int)-2147483648);printf("{%d}\n", n);
	// n=printf("-%d-%x-%d-%x-%d-%x-%d-%x-\n", 0, 0, 42, 42, 2147483647, 2147483647, (int)-2147483648, (int)-2147483648);printf("{%d}\n", n);
	// n=printf("\n");printf("{%d}\n", n);
	// n=printf("%s%s%s\n", "", "toto", "wiurwuyrhwrywuier");printf("{%d}\n", n);
	// n=printf("-%s-%s-%s-\n", "", "toto", "wiurwuyrhwrywuier");printf("{%d}\n", n);
}
