#ifndef __YOUNG_MAN_H
#define __YOUNG_MAN_H

#include <stdio.h>
#include "proxy.h"


typedef struct young_man_info {
	const char *name;   						// 保存小伙子的名字 
}young_man_info_t; 

/** \brief oled设备 */
typedef struct young_man {
	proxy_serv_t              isa;   		  // 获取代理能代处理的事物          
	const young_man_info_t   *info; 
	char                      girl_name[10];  // 记录姑娘的名字 
}young_man_t;

/** \brief 设备句柄 */
typedef young_man_t *young_man_handle;


/** \brief 初始化 */
proxy_handle young_man_init(young_man_handle        handle,
					        const young_man_info_t *info,
							char                   *name,
							int                     name_len);
					   
					   
/** \brief 解初始化 */ 
void young_man_deinit(young_man_handle handle);					   
					   


#endif
