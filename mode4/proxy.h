#ifndef __PROXY_H
#define __PROXY_H

#include <stdio.h>


/**
 * \brief 功能函数结构体 
 */ 
struct proxy_funcs {
	/** \brief 送巧克力 */
	void (*chocolates_giving)(void *p_drv);
	
	/** \brief 送奶茶 */
	void (*milk_tea_giving)(void *p_drv);
	
	/** \brief 送娃娃 */
	void (*dolls_giving)(void *p_drv);
		
}; 

/** \brief 服务 */
typedef struct proxy_serv{
	const struct proxy_funcs *funcs; /**< \brief 功能函数       */
	void *p_arg;			        /**< \brief 函数第一个参数 */ 
} proxy_serv_t;


typedef proxy_serv_t *proxy_handle;  /**< oled通用服务句柄 */



/** \brief 送巧克力 */
inline
static void chocolates_giving(proxy_handle handle)
{
	 handle->funcs->chocolates_giving(handle->p_arg);
} 


/** \brief 送奶茶 */
inline
static void milk_tea_giving(proxy_handle handle)
{
	 handle->funcs->milk_tea_giving(handle->p_arg);
} 


/** \brief 送奶茶 */
inline
static void dolls_giving(proxy_handle handle)
{
	 handle->funcs->dolls_giving(handle->p_arg);
} 

#endif
