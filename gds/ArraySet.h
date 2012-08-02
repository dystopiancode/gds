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

/*
 * Description:
 *  Creates an ArraySet data structure
 * Parameters:
 *  set - a pointer to the set who is going to be created
 * Returns:
 *  A pointer to the initialized set OR
 *  NULL if there is not enough memory
 */
ArraySet* ArraySet_Create(int capacity);
/*
 * Description:
 *  Resizes an ArraySet data structure
 * Parameters:
 *  capacity - the new capacity of the set
 * Returns:
 *  A pointer to the set OR
 *  NULL if there is no memory left or the newCapacity is
 *  smaller than the size of the array.
 */
ArraySet* ArraySet_Resize(ArraySet* set, int newCapacity);
/*
 * Description:
 *  Destroys an ArraySet structure
 * Parameters:
 *  set - a pointer to the set who is going to be created
 * Returns:
 *  NULL
 */
ArraySet* ArraySet_Destroy(ArraySet* set);
/*
 * Description:
 *  Verifies if @object belongs in @set
 * Parameters:
 *  object - a pointer to a object
 *  set - a pointer to a set
 * Returns:
 *  True - if the object exists in the set
 *  False - if the object does not exist in the set
 */
bool ArraySet_Belongs(const Object* object, const ArraySet* set);
/*
 * Description:
 *  Adds an object to a set
 * Parameters:
 *  set - a pointer to the current set
 *  object - a pointer to an object
 * Returns:
 *  A pointer to the current set OR
 *  NULL if the object already exists in the set or
 *    if adding the object would cause a buffer overflow
 */
ArraySet* ArraySet_AddObject(ArraySet* set, const Object* object);
/*
 * Description:
 *  Removes an object from the set
 * Parameters:
 *  set - a pointer to the current set
 *  object - a pointer to an object
 * Returns:
 *  A pointer to the current set OR
 *  NULL if the object does not exist in the set or
 *    if there is no object in the set
 */
ArraySet* ArraySet_RemoveObject(ArraySet* set, const Object *object);
/*
 * Description:
 *  Removes all objects from the set
 * Parameters:
 *  set - a pointer to the current set
 * Returns:
 *  A pointer to the set
 */
ArraySet* ArraySet_RemoveAll(ArraySet* set);
/*
 * Description:
 *  Creates a hard copy of a set
 * Parameters:
 *  set - a pointer to a set
 * Returns:
 *  A pointer to a copy of the set
 */
ArraySet* ArraySet_Copy(const ArraySet* set);
/*
 * Description:
 *  Compares two sets to see if they are equal
 * Parameters:
 *  set1, set2 - pointers to the two sets
 * Returns:
 *  True - if both sets have the same objects
 *  False - if there are differences between the sets
 */
bool ArraySet_Equals(const ArraySet* set1, const ArraySet* set2);
/*
 * Description:
 *  Check is a a set is a subset of another set
 * Parameters:
 *  smallSet - the possible subset
 *  largeSet - the set who is verified
 * Returns:
 *  True - if @smallset is a subset of @largeset
 *  False - otherwise
 */
bool ArraySet_IsSubset(const ArraySet* smallSet, const ArraySet* largeSet);
/*
 * Description:
 *  Creates a new ArraySet containing the result of the reunion
 *  between 2 other sets.
 * Parameters:
 *  set1, set2 - the sets who are going to be reunited
 * Returns:
 *  A pointer to the ArraySet containing the result of the reunion OR
 *  NULL if there is no memory available to allocate for the new set
 */
ArraySet* ArraySet_Reunion(const ArraySet* set1, const ArraySet* set2);
/*
 * Description:
 *  Creates a new ArraySet containing the result of the intersection
 *  between 2 other sets.
 * Parameters:
 *  set1, set2 - the sets who are going to be intersected
 * Returns:
 *  A pointer to the ArraySet containing the result of the intersection OR
 *  NULL if there is no memory available to allocate for the new set
 */
ArraySet* ArraySet_Intersection(const ArraySet* set1, const ArraySet* set2);
/*
 * Description:
 *  Creates a new ArraySet containing the result of the difference
 *  between the first set and the last set.
 * Parameters:
 *  mainSet - the set which will evaluated according to the secondary set
 *  secondarySet - the set containing the objects which will be eliminated
 *        from the main set.
 * Returns:
 *  A pointer to the ArraySet containing the result of set1 \ set2
 *  (the difference between set1 and set2) OR
 *  NULL if there is no memory available to allocate for the new set
 */
ArraySet* ArraySet_Difference(const ArraySet* mainSet, const ArraySet* secondarySet);
#endif /* ARRAYSET_H_ */
