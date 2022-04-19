
obj-m := kModuuli2_init.o
obj-m += kModuuli2_exit.o

obj-m := kModuuli2.o
kModuuli2-objs := kModuuli2_init.o kModuuli2_exit.o

obj-m := kSymExport.o
obj-m += kModuuli.o
