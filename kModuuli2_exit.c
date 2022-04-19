#include <linux/init.h>
#include <linux/module.h>

MODULE_LICENSE("GPL");

void lopeta(void)
{
	printk(KERN_ALERT "kModuuli2 lopetus");
}

module_exit(lopeta);
