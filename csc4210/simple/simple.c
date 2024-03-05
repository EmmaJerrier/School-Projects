/* 
 Emma Jerrier
 CSC4210
 */
    #include <linux/module.h>
    #include <linux/kernel.h>
    #include <linux/init.h> 
    #include <linux/jiffies.h>
    #include <asm/param.h>

    MODULE_LICENSE("GPL");
    MODULE_DESCRIPTION("Simple Module");
    MODULE_AUTHOR("RSS");
    /* This function is called when the module is loaded. */
    int simple_init(void)
    {
       printk(KERN_INFO "Loading Module\n");
       printk(KERN_INFO "Current value of jiffies: %lu\n", jiffies);
       printk(KERN_INFO "Value of HZ: %d\n", HZ);
return 0; }
    /* This function is called when the module is removed. */
    void simple_exit(void)
    {
       printk(KERN_INFO "Removing Module\n");
       printk(KERN_INFO "Current value of jiffies: %lu\n", jiffies);
    }
    /* Macros for registering module entry and exit points. */
    module_init(simple_init);
    module_exit(simple_exit);
