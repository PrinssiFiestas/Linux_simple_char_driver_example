#include <linux/init.h>
#include <linux/module.h>

MODULE_LICENSE("GPL");

__init int alusta(void)
{
	printk(KERN_ALERT "kModuuli 2 alustus");
	return 0;
}

module_init(alusta);
