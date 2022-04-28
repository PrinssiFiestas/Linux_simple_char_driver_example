#include <linux/init.h>
#include <linux/module.h>
#include <linux/moduleparam.h>
#include <linux/fs.h>

MODULE_LICENSE("GPL");

//----------------------------------------

const int MAJOR_NUM = 69;

int avaa(struct inode *ptrInode, struct file *ptrTied)
{
	printk(KERN_ALERT "Avattiin ajuri %i instanssi\n", MAJOR_NUM);
	return 0;
}

ssize_t lue(struct file *ptrTied, char __user *puskuri, size_t koko, loff_t *offset)
{
	printk(KERN_ALERT "Luetaan ajuri %i instanssii\n", MAJOR_NUM);
	return 0;
}

ssize_t kirjoita(struct file *ptrTied, const char __user *puskuri, size_t koko, loff_t *offset)
{
	printk(KERN_ALERT "Kirjotetaa ajuri %i instanssii\n", MAJOR_NUM);
	return koko;
}

int sulje(struct inode *ptrInode, struct file *ptrTied)
{
	printk(KERN_ALERT "Suljetaan ajuri %i instanssi\n", MAJOR_NUM);
	return 0;
}

const struct file_operations tiedOperaatiot = {
	.owner	= THIS_MODULE,
	.open	= avaa,
	.read	= lue,
	.write	= kirjoita,
	.release= sulje,
};

int shidii = 3;
module_param(shidii, int, 0);

//Prototyyppi kSymExport-moduulist
int exportteri(void);

__init int kModuleInit(void)
{
	int i;
	printk(KERN_ALERT "Kernäälin sisäl jee. Tää funktio siis %s\n", __func__);
	exportteri();
	for(i=0; i<shidii; i++) printk(KERN_ALERT "shidii");

	// Registering a character device driver to kernel
	register_chrdev(MAJOR_NUM,"Meitsin ajuri",&tiedOperaatiot);

	return 0;
}

__exit void kModuleExit(void)
{
	unregister_chrdev(MAJOR_NUM,"Meitsin ajuri");
	printk(KERN_ALERT "Lähettiin menee. Tää funktio on %s\n", __func__);
}

module_init(kModuleInit);
module_exit(kModuleExit);
