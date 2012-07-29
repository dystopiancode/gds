/*
 * Object.c
 *
 *  Created on: Jul 28, 2012
 *      Author: bogdan
 */
#include"Object.h"

Object* Object_Create(void* value, void* interface)
{
	Object* object = NULL;
	object = (Object*)malloc(sizeof(Object));
	object->interface = interface;
	object->data = object->interface->Copy(value);
	return object;
}

int Object_Compare(const Object* object1, const Object* object2)
{
	return object1->interface->Compare(object1,object2);
}

Object* Object_Copy(const Object* object)
{
	return object->interface->Copy(object);
}

Object* Object_Destroy(Object* object)
{
	return object->interface->Destroy(object);
}

Interface* Interface_Create(void* (*Copy)(const void*),
			    			void* (*Destroy)(void*),
			    			int   (*Compare)(const void*,const void*))
{
	Interface *interface = malloc(sizeof(Interface));
	interface->Copy = Copy;
	interface->Destroy = Destroy;
	interface->Compare = Compare;
	return interface;
}

Interface* Interface_Destroy(Interface* interface)
{
	free(interface);
	return NULL;
}
