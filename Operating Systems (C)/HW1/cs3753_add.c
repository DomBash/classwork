#include <linux/kernel.h>
#include <linux/linkage.h>
#include <linux/uaccess.h>
asmlinkage long sys_cs3753_add(int number1, int number2, int *result)
{
	int mem = 0;
	int *num1 = &mem;
	printk("Number 1: %d\n", number1);
	printk("Number 2: %d\n", number2);
	*result = number1 + number2;
	printk("Result: %d\n", *result);
	copy_to_user(num1,&result,sizeof(*result));
	return *result;
}
