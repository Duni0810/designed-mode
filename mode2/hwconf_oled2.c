#include "hwconf_function.h"
#include "./hw_oled2/oled2.h"


static const  oled2_info_t __g_oled_info = {
	"oled2\0",  /**< \brief �豸�� */
};

static  oled2_t __g_oled_dev;

/** \brief ʵ����ʼ�� */
oled_handle oled2_inst_init()
{
	return oled2_init(&__g_oled_dev, &__g_oled_info);
}


/** \brief ʵ����ʼ�� */
void oled2_inst_deinit(oled_handle handle)
{
	oled2_deinit(handle->p_arg);
}

/* end of file */

