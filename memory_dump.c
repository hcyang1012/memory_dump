#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>


#define 	CR3_MASK   (~((U64_t)0xFFF))


typedef unsigned long long U64_t;
typedef U64_t PHY_t;

PHY_t getCR3CValue(void)
{
	PHY_t CR3Value = (U64_t)0x1234567890ABCDEF;
	__asm__ ("mov %%cr3, %0\r\n"
			:"=r"(CR3Value)
			:
			:
			);

	return CR3Value;
}

int __init init_hello(void)
{

	printk( KERN_ALERT "Hello world\n" );
	printk("CR3 : %llx\n",getCR3CValue());
	*(int*)0 = 0x00;
  return 0;
}

void __exit exit_hello(void)
{
  printk( KERN_ALERT "Good-bye~n" );
}

module_init( init_hello );
module_exit( exit_hello );

MODULE_LICENSE( "GPL" );
