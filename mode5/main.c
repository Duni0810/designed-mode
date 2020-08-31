#include <stdio.h>
#include <malloc.h>

typedef struct Clonable{
	struct Clonable * (*copy)(struct Clonable *);
} Clonable_t;


// 定义Clonable接口
//typedef Clonable* ( *Clone)(struct Clonable *);


 
// Person类扩展Clonable接口
struct Person{
	Clonable_t base;
	unsigned int age;
};
 
Clonable* ClonePerson(Clonable * p_dev)
{
	return (Clonable*)malloc(sizeof(Person));
}
 
// 创建Clonable对象的Factory
Clonable* ClonableFactory(void* p_dev)
{
	Clonable *clonable = (Clonable *)p_dev;
	
	if(NULL == clonable) {
		return NULL;	
	}
	
	return (clonable->copy(clonable));
}
 


int main()
{
	Person p;
	p.base.copy = ClonePerson;
	p.age = 10;
	printf("age: %d\r\n", p.age);
	
	Person* anotherPerson = NULL;
	anotherPerson = (Person*)ClonableFactory(&p);
	
	
	return 0;
}
