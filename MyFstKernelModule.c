#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>

static int __init hello_init(void)
{
    printk();
    return 0;
}

static void __exit hello_exit(void)
{
    printk(KERN_INFO "Hello Driver Exit!\n");
}

module_init();
module_exit();

MODULE_LICENSE();
MODULE_AUTHOR();
MODULE_DECRIPTION();