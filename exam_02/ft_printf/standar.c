#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>

int	main(void)
{

	printf("Simple test\n");
	printf("--printformat---");
	printf("\n");
	printf("%d\n", 0);
	printf("%d\n", 42);
	printf("%d\n", 1);
	printf("%d\n", 5454);
	printf("%d\n", (int)2147483647);
	printf("%d\n", (int)2147483648);
	printf("%d\n", (int)-2147483648);
	printf("%d\n", (int)-2147483649);
	printf("\n");
	printf("%x\n", 0);
	printf("%x\n", 42);
	printf("%x\n", 1);
	printf("%x\n", 5454);
	printf("%x\n", (int)2147483647);
	printf("%x\n", (int)2147483648);
	printf("%x\n", (int)-2147483648);
	printf("%x\n", (int)-2147483649);
	printf("%s\n", "");
	printf("%s\n", "toto");
	printf("%s\n", "wiurwuyrhwrywuier");
	printf("-%s-%s-\n", "toto", "wiurwuyrhwrywuier");
	printf("\n--Mixed---\n");
	printf("%d%x%d%x%d%x%d%x\n", 0, 0, 42, 42, 2147483647, 2147483647, (int)-2147483648, (int)-2147483648);
	printf("-%d-%x-%d-%x-%d-%x-%d-%x-\n", 0, 0, 42, 42, 2147483647, 2147483647, (int)-2147483648, (int)-2147483648);
	printf("\n");
	printf("%s%s%s\n", "", "toto", "wiurwuyrhwrywuier");
	printf("-%s-%s-%s-\n", "", "toto", "wiurwuyrhwrywuier");
}
