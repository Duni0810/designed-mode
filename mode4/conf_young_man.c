#include "conf_young_man.h"
#include "young_man.h"

static const  young_man_info_t __g_young_man_info = {
	"xiaoming\0",  
};

static  young_man_t __g_young_man_dev;

/** \brief 实例初始化 */
proxy_handle young_man_inst_init(char *name,
								 int   len)
{
	return young_man_init(&__g_young_man_dev, 
						  &__g_young_man_info,
						  name,
						  len);
}


/** \brief 实例初始化 */
void young_man_inst_deinit(proxy_handle handle)
{
	young_man_deinit(handle->p_arg);
}

/* end of file */
