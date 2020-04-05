#ifndef __OPERATION_H
#define __OPERATION_H
/*
 * @Description: 
 * @Version: 0.0
 * @Autor: young
 * @Date: 2020-04-04 17:17:44
 * @LastEditors: young
 * @LastEditTime: 2020-04-04 17:54:32
 */
#include <stdio.h>

typedef  void  oper_t;

typedef struct oper_mode
{
    double        data1;
    double        data2;
    void        (*pfn_release)(oper_t *p_arg);
    double      (*pfn_result_get)(oper_t *p_arg);
}oper_mode_t;

oper_t * operation_creat(char mode, oper_mode_t *p_dev);

#endif