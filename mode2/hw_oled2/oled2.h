#ifndef __OLED2_H__
#define __OLED2_H__

#include "./../interface.h"


typedef struct oled2_info {
	const char *name; /* �豸�� */
}oled2_info_t; 

/** \brief oled�豸 */
typedef struct oled2 {
	oled_serv_t          isa;  /**< \brief �̳�oledͨ���豸 */ 
	const oled2_info_t  *info; /**< \brief �豸��Ϣ         */ 
}oled2_t;

/** \brief �豸��� */
typedef oled2_t *oled2_handle;


/** \brief ��ʼ�� */
oled_handle oled2_init(oled2_handle        handle,
					   const oled2_info_t *info);


/** \brief ���ʼ�� */ 
void oled2_deinit(oled2_handle handle);


#endif

/* end of file */


