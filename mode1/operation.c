/*
 * @Description: 
 * @Version: 0.0
 * @Autor: young
 * @Date: 2020-04-04 17:17:36
 * @LastEditors: young
 * @LastEditTime: 2020-04-04 17:54:02
 */

#include <stdlib.h>
#include "operation.h"

typedef struct add {
    oper_mode_t *dev;
} add_t;

typedef struct sub {
    oper_mode_t *dev;
} sub_t;

typedef struct mul {
    oper_mode_t *dev;
} mul_t;

typedef struct div1 {
    oper_mode_t *dev;
} div1_t;

static oper_t *add_init(oper_mode_t *p_dev)
{
    oper_t *ret = NULL;
    ret = (oper_t *)malloc(sizeof(add_t));
    ((add_t *)ret)->dev = p_dev;
    return ret;
}

static oper_t *sub_init(oper_mode_t *p_dev)
{
    oper_t *ret = NULL;
    ret = (oper_t *)malloc(sizeof(sub_t));
    ((sub_t *)ret)->dev = p_dev;
    return ret;
}

static oper_t *mul_init(oper_mode_t *p_dev)
{
    oper_t *ret = NULL;
    ret = (oper_t *)malloc(sizeof(mul_t));
    ((mul_t *)ret)->dev = p_dev;
    return ret;
}

static oper_t *div_init(oper_mode_t *p_dev)
{
    oper_t *ret = NULL;
    ret = (oper_t *)malloc(sizeof(div1_t));
    ((div1_t *)ret)->dev = p_dev;
    return ret;
}

static void release(oper_t *p_dev)
{
    free(p_dev);
}

static double add_operation(oper_t *p_handle)
{
    add_t *p_dev = (add_t *)p_handle;
    if (p_dev == NULL) {
        printf("operation error\r\n");
        return 0;
    }

    return ((p_dev->dev->data1) + (p_dev->dev->data2));
}

static double sub_operation(oper_t *p_handle)
{
    add_t *p_dev = (add_t *)p_handle;
    if (p_dev == NULL) {
        printf("operation error\r\n");
        return 0;
    }

    return ((p_dev->dev->data1) - (p_dev->dev->data2));
}

static double mul_operation(oper_t *p_handle)
{
    add_t *p_dev = (add_t *)p_handle;
    if (p_dev == NULL) {
        printf("operation error\r\n");
        return 0;
    }

    return ((p_dev->dev->data1) * (p_dev->dev->data2));
}

static double div_operation(oper_t *p_handle)
{
    add_t *p_dev = (add_t *)p_handle;
    if (p_dev == NULL) {
        printf("operation error\r\n");
        return 0;
    }

    if(p_dev->dev->data2 == 0) {
        printf("param error\r\n");
        return 0;
    }

    return ((p_dev->dev->data1) / (p_dev->dev->data2));
}

oper_t *operation_creat(char mode, oper_mode_t *p_dev)
{
    oper_t *ret = NULL;

    switch (mode) {
        case '+' : 
        {
            ret = add_init(p_dev); 
            ( (add_t *)ret)->dev->pfn_release    = release;
            ( (add_t *)ret)->dev->pfn_result_get = add_operation;
            break;
        }

        case '-' : 
        {
            ret = sub_init(p_dev); 
            ( (sub_t *)ret)->dev->pfn_release    = release;
            ( (sub_t *)ret)->dev->pfn_result_get = sub_operation; 
            break;
        }

        case '*' : 
        {
            ret = mul_init(p_dev); 
            ( (mul_t *)ret)->dev->pfn_release    = release;
            ( (mul_t *)ret)->dev->pfn_result_get = mul_operation; 
            break;
        }

        case '/' : 
        {
            ret = div_init(p_dev); 
            ((div1_t *)ret)->dev->pfn_release    = release;
            ((div1_t *)ret)->dev->pfn_result_get = div_operation; 
            break;
        }

        default  : printf("error opeation !\r\n"); break;
    }
    return ret;
}