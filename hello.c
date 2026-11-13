/*
 * hello.c — Hello World Linux kernel module
 *
 * The classic first kernel module: prints "Hello, World!" to the
 * kernel log when loaded, and "Goodbye, World!" when unloaded.
 *
 * Build:  make
 * Load:   sudo insmod hello.ko
 * Check:  dmesg | tail
 * Unload: sudo rmmod hello
 *
 * License: GPL
 */

#include <linux/init.h>    /* __init, __exit, module_init, module_exit */
#include <linux/module.h>  /* MODULE_* macros, module boilerplate */
#include <linux/kernel.h>  /* pr_info() */

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Faisal Ridho");
MODULE_DESCRIPTION("A simple Hello World Linux kernel module");
MODULE_VERSION("1.0");

/* Called when the module is loaded (insmod / modprobe). */
static int __init hello_init(void)
{
	pr_info("Hello, World! from the Linux kernel\n");
	return 0; /* 0 = loaded successfully */
}

/* Called when the module is unloaded (rmmod). */
static void __exit hello_exit(void)
{
	pr_info("Goodbye, World!\n");
}

module_init(hello_init);
module_exit(hello_exit);
