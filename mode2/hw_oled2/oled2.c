#include "oled2.h"

typedef unsigned char uint8_t;

#define  OLED_DECL(handle, p_drv)  \
				oled2_handle handle = (oled2_handle) p_drv


/** broef 字符大小设置 */
static void __oled2_font_size_cfg (void *p_drv, int request)
{
	OLED_DECL(handle, p_drv);  // 类型定义 
	
	uint8_t data[][6] = {"6x8\0", "6x22\0", "22x24\0"};
	
	printf("dev is :%s\n", handle->info->name);  //设备信息打印，测试handle 
	
	printf("Set the oled font to %s \n",data[request]);
}

/** \brief 显示字符 */
static void __oled2_str_show(void *p_drv, const char *p_str)
{
	OLED_DECL(handle, p_drv);  // 类型定义 
	printf("dev is :%s\n", handle->info->name); //设备信息打印，测试handle 
	
	printf("display data:%s\n",p_str);
} 


/** \brief 显示图片 */
static void __oled2_graph_show(void *p_drv, const char  *p_buf, size_t size)
{
	OLED_DECL(handle, p_drv);  // 类型定义 
	printf("dev is :%s\n", handle->info->name); //设备信息打印，测试handle 
	int i = 0;
	for (i = 0; i < size; i++) {
		printf("%c", *p_buf++);
	}
	printf("\n");
}


static const struct oled_funcs __g_oled2_funcs = {
	__oled2_font_size_cfg,
	__oled2_str_show,
	__oled2_graph_show,
};


/** \brief 初始化 */
oled_handle oled2_init(oled2_handle        handle,
					   const oled2_info_t *info)
{
	// handle 信息填充 
	handle->info      = info;
	handle->isa.funcs = &__g_oled2_funcs;
	handle->isa.p_arg = handle;
	
	// run dev functions 
	
	printf("init oled2 ok\n");
	return (&handle->isa);
}


/** \brief 解初始化 */ 
void oled2_deinit(oled2_handle handle)
{
	printf("deinit %s \n", handle->info->name);
}







