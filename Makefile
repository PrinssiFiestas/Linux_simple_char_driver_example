
obj-m := kModuuli2_init.o
obj-m += kModuuli2_exit.o

obj-m := kModuuli2.o
kModuuli2-objs := kModuuli2_init.o kModuuli2_exit.o

obj-m := kSymExport.o
obj-m += kModuuli.o

all:
	make -C /lib/modules/$(shell uname -r)/buid M=$(PWD) modules
clean:
	make -C /lib/modules/$(shell uname -r)/buid M=$(PWD) clean
