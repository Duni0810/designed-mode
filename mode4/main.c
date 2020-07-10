#include <stdio.h>
#include "proxy.h"
#include "conf_young_man.h"
#include "string.h"


int main(int argc, char *argv[])
{
	char *girl = "xiaohua\0";
	
	// 小明看上那个姑娘告诉中介 
	proxy_handle handle = young_man_inst_init(girl, strlen(girl));
	
	// 中介实现送东西的操作 
	chocolates_giving(handle);
	milk_tea_giving(handle);
	dolls_giving(handle);
	
	// 送完东西之后，小明失败了 ，放弃了送东西操作 
	young_man_deinit(handle);
	
	chocolates_giving(handle);
	milk_tea_giving(handle);
	dolls_giving(handle);
	
	
	return 0;
}
