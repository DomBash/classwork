#include <linux/init.h>
#include <linux/module.h>

#include <linux/fs.h>
#include <linux/slab.h>
#include <linux/uaccess.h>

#define BUFFER_SIZE 1024
#define DEVICE_NAME "simple_dev"	  
 
static char *alloc;
static int Major;		

static int simple_char_driver_init(void);
static void simple_char_driver_exit(void);
static int simple_char_driver_open(struct inode *, struct file *);
static int simple_char_driver_close(struct inode *, struct file *);
static loff_t simple_char_driver_seek(struct file *, loff_t, int);
static ssize_t simple_char_driver_read(struct file *, char *, size_t, loff_t *);
static ssize_t simple_char_driver_write(struct file *file,const char *,size_t,loff_t *);

ssize_t simple_char_driver_read (struct file *pfile, char __user *buffer, size_t length, loff_t *offset)
{
	printk(KERN_ALERT "Reading");
	
	if(*offset >= BUFFER_SIZE)
	{
		return 0;
	}
	
	if(*offset + length > BUFFER_SIZE)
	{
		length = BUFFER_SIZE - *offset;
	}
	
	if(copy_to_user(buffer, alloc + *offset,length) != 0)
	{
		return -EFAULT;
	}
	*offset += length;
	return length;
}

ssize_t simple_char_driver_write (struct file *pfile, const char __user *buffer, size_t length, loff_t *offset)
{
	int nbytes;
	int toWrite;
	int max;
	
	max = BUFFER_SIZE - *offset;

	if(max > length)
	{
		toWrite = length;
	}
	else
	{
		toWrite = max;
	}

	nbytes = toWrite - copy_from_user(alloc + *offset,buffer, toWrite);
	*offset += nbytes;
	printk(KERN_ALERT "Writing");
	return nbytes;
}

int simple_char_driver_open (struct inode *pinode, struct file *pfile)
{
	static int counter = 1;
	printk(KERN_ALERT "Device opened %d time/s.\n", counter++);
	return 0;
}

int simple_char_driver_close (struct inode *pinode, struct file *pfile)
{
	static int counter = 1;
	printk(KERN_ALERT "Device closed %d time/s.\n", counter++);
	return 0;
}

loff_t simple_char_driver_seek (struct file *pfile, loff_t offset, int whence)
{
	loff_t curPos = 0;
	printk(KERN_ALERT "Seeking.\n");
	switch(whence)
	{
	case 0:
		curPos = offset;
		break;
	case 1:
		curPos = pfile -> f_pos + offset;
		break;
	case 2:
		curPos = BUFFER_SIZE - offset;
		break;
	}
	if(curPos > BUFFER_SIZE)
	{
		curPos = BUFFER_SIZE;
	}
    if(curPos < 0 ) 
    {
		curPos = 0;
	}
	pfile -> f_pos = curPos;
	return curPos;	
}

struct file_operations simple_char_driver_file_operations = {

	.owner   = THIS_MODULE,
	.read    = simple_char_driver_read,
	.write   = simple_char_driver_write,
	.open    = simple_char_driver_open,
	.llseek  = simple_char_driver_seek,
	.release   = simple_char_driver_close,
};

static int simple_char_driver_init(void)
{
	alloc = kmalloc(BUFFER_SIZE, GFP_KERNEL);
	Major = register_chrdev(261, DEVICE_NAME, &simple_char_driver_file_operations);
	printk(KERN_ALERT "inside %s function\n",__FUNCTION__);
	return 0;
}

static void simple_char_driver_exit(void)
{
	kfree(alloc);
	unregister_chrdev(Major, DEVICE_NAME);
	printk(KERN_ALERT "inside %s function\n",__FUNCTION__);
}

module_init(simple_char_driver_init);
module_exit(simple_char_driver_exit);
MODULE_LICENSE("GPL");

