#ifndef __OLED2_H__
#define __OLED2_H__

#include "./../interface.h"


typedef struct oled2_info {
	const char *name; /* 设备名 */
}oled2_info_t; 

/** \brief oled设备 */
typedef struct oled2 {
	oled_serv_t          isa;  /**< \brief 继承oled通用设备 */ 
	const oled2_info_t  *info; /**< \brief 设备信息         */ 
}oled2_t;

/** \brief 设备句柄 */
typedef oled2_t *oled2_handle;


/** \brief 初始化 */
oled_handle oled2_init(oled2_handle        handle,
					   const oled2_info_t *info);


/** \brief 解初始化 */ 
void oled2_deinit(oled2_handle handle);


#endif

/* end of file */


