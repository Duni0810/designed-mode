/*
 * @Description:  设计模式: 简单工厂模式
 * @Version: 0.0
 * @Autor: young
 * @Date: 2020-04-04 16:26:48
 * @LastEditors: young
 * @LastEditTime: 2020-04-04 17:52:51
 */

#include "operation.h"

int main(int argc, char *argv[])
{
    printf("hello world \r\n");
    
    oper_mode_t var;

    oper_t *p_dev = operation_creat('+', &var);

    var.data1 = 1;
    var.data2 = 2;

    printf("add:%f\r\n", var.pfn_result_get(p_dev));
    var.pfn_release(p_dev);

    return 0;
} 
