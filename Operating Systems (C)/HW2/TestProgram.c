#include <stdio.h>
#include <string.h>
#include <linux/kernel.h>
#include <sys/syscall.h>
#include <unistd.h>
#include <linux/fs.h>

char printmenu()
{
	printf("\n");
	printf("Press r to read from device\n");
	printf("Press w to write to the device\n");
	printf("Press s to seek into the device\n");
	printf("Press e to exit from the device\n");
	printf("Press anything else to keep reading or writing from the device\n");
	char a = 'a';
	printf("Enter command: ");
	scanf(" %c", &a);
	printf("You entered: %c\n", a);
	return a;
}
int main()
{
	int bytes;
	char data[256];
	int offset;
	int whence;
	
	int a = printmenu();
	if(a == 'r')
	{
		printf("Enter the number of bytes you want to read: ");
		scanf(" %d", &bytes);
		FILE *fp;
		fp = fopen("/dev/simple_character_device", "r+");
		char buffer[bytes];
		fread(buffer, 1, bytes, fp);
		fclose(fp);
		printf("Data read from the device: %s\n", buffer);
		main();
	}
	else if(a == 'w')
	{
		printf("Enter data you want to write to the device: ");
		scanf(" %s", data);
		FILE *fp;
		fp = fopen("/dev/simple_character_device", "w+");
		fwrite(data, 1, sizeof(data), fp);
		fclose(fp);
		main();
	}
	else if(a == 's')
	{
		printf("Enter an offset value: ");
		scanf(" %d", &offset);
		printf("Enter a value for whence (third parameter): ");
		scanf(" %d", &whence);
		FILE *fp;
		fp = fopen("/dev/simple_character_device", "w+");
		fseek(fp, offset, whence);
		fclose(fp);
		main();
	}
	else if(a == 'e')
	{
		return 0;
	}
	else
	{
		main();
	}
}
