CA-Lab5

# hello.c

```
#include <linux/init.h>
#include <linux/module.h>
#include <linux/moduleparam.h>
#include <linux/printk.h>


MODULE_AUTHOR("Trotsenko Daniil");
MODULE_DESCRIPTION("Hello world printing Linux module");
MODULE_LICENSE("Dual BSD/GPL");

static int repeat = 1;
module_param(repeat, uint, S_IRUGO);
MODULE_PARM_DESC(times, "num of repeats");

static int __init hello_init(void)
{
	uint i = 0;
	if(repeat == 0){
		printk(KERN_WARNING "Repeat parameter equals 0 \n");
	}
	else if(repeat >=5 && repeat <= 10){
		printk(KERN_WARNING "Repeat parameter is between 5 and 10 \n");
	}
	else if (repeat > 10){
		printk(KERN_ERR "Repeat parameter is bigger than 10 \n");
		return -EINVAL;
	}
	else if(repeat < 0){
		printk(KERN_ERR "Repeat parameter is negative \n");
		return -EINVAL;
	}
    for(i = 0; i < repeat; i++) {
        printk(KERN_EMERG "Hello, world!\n");
    }

	pr_info("Num of repeats: %d\n", repeat);
	
	return 0;
}

static void __exit hello_exit(void)
{
	/* Do nothing here right now */
}

module_init(hello_init);
module_exit(hello_exit);
```

# Makefile

```
ifneq ($(KERNELRELEASE),)
# kbuild part of makefile
obj-m := hello.o
else
# normal makefile
KDIR ?= /lib/modules/`uname -r`/build

default:
	$(MAKE) -C $(KDIR) M=$$PWD
clean:
	$(MAKE) -C $(KDIR) M=$$PWD clean
endif
```
