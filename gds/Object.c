/*
 * Object.c
 *
 *  Created on: Jul 28, 2012
 *      Author: bogdan
 */
#include"Object.h"

/*
 * Description:
 *  Creates an Object structure
 * Parameters:
 *  value - The value used for initializing an object
 * Returns:
 *  A pointer to the object OR
 *  NULL if there is not enough memory
 */
Object* Object_Create(void* value, void* interface)
{
	Object* object = NULL;
	object = (Object*)malloc(sizeof(Object));
	object->interface = interface;
	object->value = object->interface->Copy(value);
	return object;
}
/*
 * Description:
 *  Compares two objects
 * Parameters:
 *  object1, object2 - the objects who are going to be compared
 * Returns:
 *  The difference between the values of the objects
 *  0  - the objects are equal
 *  >0 - object1 is greater than object2
 *  <0 - object2 is greater than object1
 */
int Object_Compare(const Object* object1, const Object* object2)
{
	return object1->interface->Compare(object1,object2);
}
/*
 * Description:
 *  Creates a hard copy of an object structure
 * Parameters:
 *  value - A pointer to object who is going to be copied
 * Returns:
 *  A pointer to the copy OR
 *  NULL if there is not enough memory
 */
Object* Object_Copy(const Object* object)
{
	return object->interface->Copy(object);
}
/*
 * Description:
 *  Destroys an object structure
 * Parameters:
 *  object - The object who is going to be destroyed
 * Returns:
 *	NULL
 */
Object* Object_Destroy(Object* object)
{
	return object->interface->Destroy(object);
}
/*
 * Description:
 *  Creates an Interface structure
 * Parameters:
 *  Copy - a pointer to the object copy function
 *  Destroy - a pointer to the object destructor
 *  Compare - a pointer to the object compare function
 *  GetType - reserved for further use
 * Returns:
 *	NULL
 */
Interface* Interface_Create(void* (*Copy)(const void*),
							void* (*Destroy)(void*),
							int   (*Compare)(const void*,const void*),
							void* (*GetType)(void))
{
	Interface *interface = malloc(sizeof(Interface));
	interface->Copy = Copy;
	interface->Destroy = Destroy;
	interface->Compare = Compare;
	interface->GetType = GetType;
	return interface;
}
