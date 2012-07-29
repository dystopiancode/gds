#ifndef OBJECT_H_
#define OBJECT_H_

#include<stdlib.h>

/*Contains pointers to the object's functions*/
typedef struct
{
	/*A pointer to a hard copy function*/
	void* (*Copy)(const void*);
	/*A pointer to a destructor-like function*/
	void* (*Destroy)(void*);
	/*A pointer to a compare function*/
	int   (*Compare)(const void*,const void*);
}Interface;

/*Contains the attributes and the behaviors of the object*/
typedef struct
{
	/*Contains the object's data*/
	void	   *data;
	/*Contains pointers to the object's function*/
	Interface  *interface;
}Object;

/*
 * Description:
 *  Creates an Object structure
 * Parameters:
 *  value - The value used for initializing an object
 * Returns:
 *  A pointer to the object OR
 *  NULL if there is not enough memory
 */
Object* Object_Create(void* value, void* interface);
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
int     Object_Compare(const Object* element1, const Object* element2);
/*
 * Description:
 *  Creates a hard copy of an object structure
 * Parameters:
 *  value - A pointer to object who is going to be copied
 * Returns:
 *  A pointer to the copy OR
 *  NULL if there is not enough memory
 */
Object* Object_Copy(const Object* element);
/*
 * Description:
 *  Destroys an object structure
 * Parameters:
 *  object - The object who is going to be destroyed
 * Returns:
 *	NULL
 */
Object* Object_Destroy(Object* element);

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
			    			int   (*Compare)(const void*,const void*));
/*
 * Description:
 * 	Destroys an Interface structure
 * Parameters:
 *  interface - a pointer to an interface
 * Returns:
 *  NULL
 */
Interface* Interface_Destroy(Interface* interface);


#endif /* OBJECT_H_ */
