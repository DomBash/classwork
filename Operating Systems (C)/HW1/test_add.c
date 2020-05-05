#include <stdio.h>
#include <linux/kernel.h>
#include <sys/syscall.h>
#include <unistd.h>

int main()
{
	int result;
	syscall(334, 1, 2, &result); 
	printf("Test result: %d\n", result);
	return 0;
}
