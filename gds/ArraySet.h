/*
 * ArraySet.h
 *
 *  Created on: Jul 28, 2012
 *      Author: bogdan
 */

#ifndef ARRAYSET_H_
#define ARRAYSET_H_

#include "Object.h"
#include <stdlib.h>
#include <stdbool.h>

typedef struct
{
	/*The allocated size for the Object array elements*/
	int capacity;
	/*How many elements are actually in the array*/
	int size;
	/*The vector containing the objects*/
	Object *objects;
}ArraySet;

ArraySet* ArraySet_Create(int capacity);
ArraySet* ArraySet_Resize(ArraySet* set, int newCapacity);
ArraySet* ArraySet_Destroy(ArraySet* set);
bool ArraySet_Belongs(const Object* object, const ArraySet* set);
ArraySet* ArraySet_AddObject(ArraySet* set, const Object* object);
ArraySet* ArraySet_RemoveObject(ArraySet* set, const Object *object);
ArraySet* ArraySet_RemoveAll(ArraySet* set);
ArraySet* ArraySet_Copy(const ArraySet* set);
bool ArraySet_Equals(const ArraySet* set1, const ArraySet* set2);
bool ArraySet_IsSubset(const ArraySet* smallSet, const ArraySet* largeSet);
ArraySet* ArraySet_Reunion(const ArraySet* set1, const ArraySet* set2);
ArraySet* ArraySet_Intersection(const ArraySet* set1, const ArraySet* set2);
ArraySet* ArraySet_Difference(const ArraySet* mainSet, const ArraySet* secondarySet);
#endif /* ARRAYSET_H_ */
