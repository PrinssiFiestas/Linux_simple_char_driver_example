#include <linux/init.h>
#include <linux/module.h>

MODULE_LICENSE("GPL");

int exportteri(void)
{
	printk(KERN_ALERT "Paskaa ulos funktiost %s\n", __func__);
	return 0;
}
EXPORT_SYMBOL(exportteri);

__init int kModuleInit(void)
{
	printk(KERN_ALERT "kSymExport.c T‰‰ funktio siis %s\n", __func__);
	return 0;
}

void kModuleExit(void)
{
	printk(KERN_ALERT "kSymExport.c T‰‰ funktio on %s\n", __func__);
}

module_init(kModuleInit);
module_exit(kModuleExit);
