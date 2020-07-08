#ifndef __PROXY_H
#define __PROXY_H

#include <stdio.h>


/**
 * \brief ���ܺ����ṹ�� 
 */ 
struct proxy_funcs {
	/** \brief ���ɿ��� */
	void (*chocolates_giving)(void *p_drv);
	
	/** \brief ���̲� */
	void (*milk_tea_giving)(void *p_drv);
	
	/** \brief ������ */
	void (*dolls_giving)(void *p_drv);
		
}; 

/** \brief ���� */
typedef struct proxy_serv{
	const struct proxy_funcs *funcs; /**< \brief ���ܺ���       */
	void *p_arg;			        /**< \brief ������һ������ */ 
} proxy_serv_t;


typedef proxy_serv_t *proxy_handle;  /**< oledͨ�÷����� */



/** \brief ���ɿ��� */
inline
static void chocolates_giving(proxy_handle handle)
{
	 handle->funcs->chocolates_giving(handle->p_arg);
} 


/** \brief ���̲� */
inline
static void milk_tea_giving(proxy_handle handle)
{
	 handle->funcs->milk_tea_giving(handle->p_arg);
} 


/** \brief ���̲� */
inline
static void dolls_giving(proxy_handle handle)
{
	 handle->funcs->dolls_giving(handle->p_arg);
} 

#endif
