#include "young_man.h"
#include <string.h>

// 送巧克力
static void __chocolates_giving(void *p_drv)
{
	young_man_handle dev = (young_man_handle)p_drv;
	
	if(NULL == dev) {
		printf("xiaoming 放弃了, 不再送 巧克力了！\n");
		return ;
	}
	
	char str[80] = {0};
	sprintf(str, "%s 托哥们给 %s 送巧克力\n", dev->info->name, dev->girl_name);
	
	printf("%s", str); 
}


// 送奶茶
static void __milk_tea_giving(void *p_drv)
{
	young_man_handle dev = (young_man_handle)p_drv;
	
	if(NULL == dev) {
		printf("xiaoming 放弃了, 不再送 奶茶了！\n");
		return ;
	}
	
	char str[80] = {0};
	sprintf(str, "%s 托哥们给 %s 送奶茶\n", dev->info->name, dev->girl_name);
	
	printf("%s", str); 
}

// 送娃娃
static void __dolls_giving(void *p_drv)
{
	young_man_handle dev = (young_man_handle)p_drv;
	
	if(NULL == dev) {
		printf("xiaoming 放弃了, 不再送 娃娃了！\n");
		return ;
	}
	
	char str[80] = {0};
	sprintf(str, "%s 托哥们给 %s 送娃娃\n", dev->info->name, dev->girl_name);
	
	printf("%s", str); 
}


static const struct proxy_funcs __g_proxy_funcs = {
	__chocolates_giving,
	__milk_tea_giving,
	__dolls_giving,
};



/** \brief 初始化 */
proxy_handle young_man_init(young_man_handle        handle,
					        const young_man_info_t *info,
							char                   *name,
							int                     name_len)
{
	if (handle == NULL) {
		printf("init ERROR\n");
		return NULL;
	}
	
	// handle 信息填充 
	handle->info      = info;
	handle->isa.funcs = &__g_proxy_funcs;
	handle->isa.p_arg = handle;
	
	memcpy(handle->girl_name, name, name_len);
	
	// run dev functions 
	
	printf("init ok\n");
	
	
	return &(handle->isa);
}
					   
					   
/** \brief 解初始化 */ 
void young_man_deinit(young_man_handle handle)
{
	if (handle == NULL) {
		printf("deinit ERROR\n");
		return ;
	}
	
	handle->info = NULL;
	memset(handle->girl_name, 0, 10);
	
	//handle->isa.funcs = NULL;
	handle->isa.p_arg = NULL;
	
	printf("deinit ok\n");
	
	
}



