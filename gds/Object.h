#ifndef OBJECT_H_
#define OBJECT_H_

#include<stdlib.h>

typedef struct
{
	/*A pointer to a hard copy function*/
	void* (*Copy)(const void*);
	/*A pointer to a destructor function*/
	void* (*Destroy)(void*);
	/*A pointer to a compare function*/
	int   (*Compare)(const void*,const void*);
	/*Reserved for further use*/
	void* (*GetType)(void);
}Interface;

typedef struct
{
	void	   *value;
	Interface  *interface;
}Object;

Object* Object_Create(void* value, void* interface);
int Object_Compare(const Object* element1, const Object* element2);
Object* Object_Copy(const Object* element);
Object* Object_Destroy(Object* element);
Interface* Interface_Create(void* (*Copy)(const void*),
			    void* (*Destroy)(void*),
			    int   (*Compare)(const void*,const void*),
			    void* (*GetType)(void));



#endif /* OBJECT_H_ */
