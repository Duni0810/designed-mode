#ifndef __YOUNG_MAN_H
#define __YOUNG_MAN_H

#include <stdio.h>
#include "proxy.h"


typedef struct young_man_info {
	const char *name;   						// ����С���ӵ����� 
}young_man_info_t; 

/** \brief oled�豸 */
typedef struct young_man {
	proxy_serv_t              isa;   		  // ��ȡ�����ܴ����������          
	const young_man_info_t   *info; 
	char                      girl_name[10];  // ��¼��������� 
}young_man_t;

/** \brief �豸��� */
typedef young_man_t *young_man_handle;


/** \brief ��ʼ�� */
proxy_handle young_man_init(young_man_handle        handle,
					        const young_man_info_t *info,
							char                   *name,
							int                     name_len);
					   
					   
/** \brief ���ʼ�� */ 
void young_man_deinit(young_man_handle handle);					   
					   


#endif
