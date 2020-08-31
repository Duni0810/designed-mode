#include <stdio.h>
#include <malloc.h>

typedef struct Clonable{
	struct Clonable * (*copy)(struct Clonable *);
} Clonable_t;


// ����Clonable�ӿ�
//typedef Clonable* ( *Clone)(struct Clonable *);


 
// Person����չClonable�ӿ�
struct Person{
	Clonable_t base;
	unsigned int age;
};
 
Clonable* ClonePerson(Clonable * p_dev)
{
	return (Clonable*)malloc(sizeof(Person));
}
 
// ����Clonable�����Factory
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
