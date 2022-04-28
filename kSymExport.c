#include <linux/init.h>
#include <linux/module.h>

MODULE_LICENSE("GPL");

int exportteri(void)
{
	printk(KERN_ALERT "Viestii ulos funktiost %s\n", __func__);
	return 0;
}
EXPORT_SYMBOL(exportteri);

__init int kModuleInit(void)
{
	printk(KERN_ALERT "kSymExport.c Tää funktio siis %s\n", __func__);
	return 0;
}

void kModuleExit(void)
{
	printk(KERN_ALERT "kSymExport.c Tää funktio on %s\n", __func__);
}

module_init(kModuleInit);
module_exit(kModuleExit);
