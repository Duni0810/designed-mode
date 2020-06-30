#include <stdio.h>
#include <malloc.h>
#include <string.h>

typedef struct object
{
    struct object *prev;

    char   name[10];
    void (*show)(struct object *p_dev);
} object_t;

/**
 * 修饰函数 
 */
void decorate(object_t *p_dev)
{
    if (p_dev == NULL) {
        return;
    }

    if(NULL != p_dev->prev) {
        p_dev->prev->show(p_dev->prev);
    }
    printf("%s\n", p_dev->name);
}

/**
 * 构建修饰 
 */ 
object_t *mkdev(object_t *prev, char *p_name, int len)
{
    object_t *p_dev = (object_t *)malloc(sizeof(object_t));

    if (p_dev != NULL) {
        memcpy(p_dev->name, p_name, len);
        p_dev->prev = prev;
        p_dev->show = decorate;
    }
    return p_dev;
}



int main()
{
    // 依次穿衣服
    object_t *dat  = mkdev(NULL, "T-shint" , sizeof("T-shint"));
    object_t *dat1 = mkdev(dat,  "jacket", sizeof("jacket"));
    object_t *dat2 = mkdev(dat1, "dress", sizeof("dress"));
    object_t *dat3 = mkdev(dat2, "coat", sizeof("coat"));

    decorate(dat3);

    free(dat3);
    free(dat2);
    free(dat1);
    free(dat);
    return 0;
}
