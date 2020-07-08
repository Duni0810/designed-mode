#include "young_man.h"
#include <string.h>

// ���ɿ���
static void __chocolates_giving(void *p_drv)
{
	young_man_handle dev = (young_man_handle)p_drv;
	
	if(NULL == dev) {
		printf("xiaoming ������, ������ �ɿ����ˣ�\n");
		return ;
	}
	
	char str[80] = {0};
	sprintf(str, "%s �и��Ǹ� %s ���ɿ���\n", dev->info->name, dev->girl_name);
	
	printf("%s", str); 
}


// ���̲�
static void __milk_tea_giving(void *p_drv)
{
	young_man_handle dev = (young_man_handle)p_drv;
	
	if(NULL == dev) {
		printf("xiaoming ������, ������ �̲��ˣ�\n");
		return ;
	}
	
	char str[80] = {0};
	sprintf(str, "%s �и��Ǹ� %s ���̲�\n", dev->info->name, dev->girl_name);
	
	printf("%s", str); 
}

// ������
static void __dolls_giving(void *p_drv)
{
	young_man_handle dev = (young_man_handle)p_drv;
	
	if(NULL == dev) {
		printf("xiaoming ������, ������ �����ˣ�\n");
		return ;
	}
	
	char str[80] = {0};
	sprintf(str, "%s �и��Ǹ� %s ������\n", dev->info->name, dev->girl_name);
	
	printf("%s", str); 
}


static const struct proxy_funcs __g_proxy_funcs = {
	__chocolates_giving,
	__milk_tea_giving,
	__dolls_giving,
};



/** \brief ��ʼ�� */
proxy_handle young_man_init(young_man_handle        handle,
					        const young_man_info_t *info,
							char                   *name,
							int                     name_len)
{
	if (handle == NULL) {
		printf("init ERROR\n");
		return NULL;
	}
	
	// handle ��Ϣ��� 
	handle->info      = info;
	handle->isa.funcs = &__g_proxy_funcs;
	handle->isa.p_arg = handle;
	
	memcpy(handle->girl_name, name, name_len);
	
	// run dev functions 
	
	printf("init ok\n");
	
	
	return &(handle->isa);
}
					   
					   
/** \brief ���ʼ�� */ 
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



