/* Emma Jerrier & Matt Burton 
 Install: sudo insmod seconds.ko
 Using: cat /proc/seconds
Remove: sudo rmmod seconds.ko
 * */
#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/proc_fs.h>
#include <linux/uaccess.h>
#include <linux/jiffies.h>
#include <asm/param.h>

#define BUFFER_SIZE 128
#define PROC_NAME "seconds"

static unsigned long start_jiffies;
ssize_t proc_read(struct file *file, char __user *usr_buf,
                  size_t count, loff_t *pos);

static struct proc_ops proc_ops = {
   .proc_read = proc_read,
};

/* This function is called when the module is loaded. */
int proc_init(void)
{
         printk(KERN_INFO "Loading Module (creating /proc/seconds)\n");
        /* creates the /proc/seconds entry */
        proc_create(PROC_NAME, 0666, NULL, &proc_ops);
        start_jiffies=jiffies;
        return 0;
}

/* This function is called when the module is removed. */
void proc_exit(void)
{
   printk(KERN_INFO "Removing Module (removing /proc/seconds)\n");
   /* removes the /proc/hello entry */
   printk(KERN_INFO "Removing proc Module\n");
   remove_proc_entry(PROC_NAME, NULL); 
}

/* This function is called each time /proc/hello is read */
ssize_t proc_read(struct file *file, char __user *usr_buf,
                  size_t count, loff_t *pos) {

   int rv = 0;
   char buffer[BUFFER_SIZE];
   unsigned long current_jiffies;
   unsigned long elapsed_jiffies;
   unsigned long calc_sec;
   static int completed = 0;
   if (completed) {
      completed = 0;
      return 0;
   }
   completed = 1;
   current_jiffies=jiffies;
   elapsed_jiffies=current_jiffies-start_jiffies;
   calc_sec=elapsed_jiffies/HZ;
   rv = sprintf(buffer,"%lu\n", calc_sec);
   /* copies kernel space buffer to user space usr_buf */
   if(copy_to_user(usr_buf, buffer, rv))
      printk(KERN_INFO "Opps, copy_to_user has failed\n");
   return rv;
}

module_init(proc_init);
module_exit(proc_exit);
MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Seconds Module");
MODULE_AUTHOR("EKJ");
