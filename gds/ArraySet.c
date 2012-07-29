/*
 * ArraySet.c
 *
 *  Created on: Jul 28, 2012
 *      Author: bogdan
 */

#include "ArraySet.h"

/*
 * Description:
 *  Creates an ArraySet data structure
 * Parameters:
 *  set - a pointer to the set who is going to be created
 * Returns:
 *  A pointer to the initialized set OR
 *  NULL if there is not enough memory
 */
ArraySet* ArraySet_Create(int capacity)
{
	ArraySet* set = NULL;
	set = (ArraySet*)malloc(sizeof(ArraySet));
	set->objects =  malloc(sizeof(Object)*capacity);
	set->capacity = capacity;
	set->size = 0;
	return set;
}
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
ArraySet* ArraySet_Resize(ArraySet* set, int newCapacity)
{
	Object* objects = NULL;
	ArraySet* result = NULL;
	int i;
	if(set->size<=newCapacity)
	{
		objects = (Object*)malloc(sizeof(Object)*newCapacity);
		if(objects!=NULL)
		{
			for(i = 0; i<set->size; i++)
			{
				objects[i] = set->objects[i];
			}
			free(set->objects);
			set->objects = objects;
			set->capacity = newCapacity;
			result = set;
		}
	}
	return result;
}
/*
 * Description:
 *  Destroys an ArraySet structure
 * Parameters:
 *  set - a pointer to the set who is going to be created
 * Returns:
 *  NULL
 */
ArraySet* ArraySet_Destroy(ArraySet* set)
{
	if((set!=NULL) && (set->objects!=NULL))
	{
		free(set->objects);
		free(set);
	}
	return NULL;
}
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
bool ArraySet_Belongs(const Object* object, const ArraySet* set)
{
	int i;
	bool belongs = false;
	for(i = 0; i<set->size; i++)
	{
		if(Object_Compare(&set->objects[i],object)==0)
		{
			belongs = true;
			break;
		}
	}
	return belongs;
}
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
ArraySet* ArraySet_AddObject(ArraySet* set, const Object* object)
{
	ArraySet* result = NULL;
	if( (set->size < set->capacity)
			&& ArraySet_Belongs(object,set) == false)
	{
		set->objects[set->size] = *(object);
		set->size++;
		result = set;
	}
	return result;
}
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
ArraySet* ArraySet_RemoveObject(ArraySet* set, const Object *object)
{
	int i, j;
	bool found = false;
	ArraySet* result = NULL;
	if(set->size > 0 )
	{
		for(i = 0; (i< set->size) && (found==false); i++)
		{
			if(Object_Compare(&set->objects[i],object)==0)
			{
				for(j = i; j<(set->size - 1); j++)
				{
					set->objects[j] = set->objects[j+1];
				}
				set->size--;
				found = true;
				result = set;
			}
		}
	}
	return result;
}
/*
 * Description:
 *  Removes all objects from the set
 * Parameters:
 *  set - a pointer to the current set
 * Returns:
 *  A pointer to the set
 */
ArraySet* ArraySet_RemoveAll(ArraySet* set)
{
	set->size = 0;
	return set;
}
/*
 * Description:
 *  Creates a hard copy of a set
 * Parameters:
 *  set - a pointer to a set
 * Returns:
 *  A pointer to a copy of the set
 */
ArraySet* ArraySet_Copy(const ArraySet* set)
{
	ArraySet *newSet = NULL;
	int i;
	newSet = ArraySet_Create(set->capacity);
	newSet->capacity = set->capacity;
	newSet->size = set->size;
	for(i=0; i<set->size; i++)
	{
		newSet->objects[i] = set->objects[i];
	}
	return newSet;
}
/*
 * Description:
 *  Compares two sets to see if they are equal
 * Parameters:
 *  set1, set2 - pointers to the two sets
 * Returns:
 *  True - if both sets have the same objects
 *  False - if there are differences between the sets
 */
bool ArraySet_Equals(const ArraySet* set1, const ArraySet* set2)
{
	bool result = true;
	int i;
	if(set1->size == set2->size)
	{
		for(i=0; i<set1->size; i++)
		{
			if(Object_Compare(&set1->objects[i],&set2->objects[i])!=0)
			{
				result = false;
				break;
			}
		}
	}
	else
	{
		result = false;
	}
	return result;
}
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
bool ArraySet_IsSubset(const ArraySet* smallSet, const ArraySet* largeSet)
{
	int i, j;
	int found = 0;
	bool result = false;
	for(i = 0; i<smallSet->size; i++)
	{
		for(j = 0; j<largeSet->size; j++)
		{
			if(Object_Compare(&smallSet->objects[i], &largeSet->objects[j])==true)
			{
				found++;
				break;
			}
		}
	}
	if(found==smallSet->size)
	{
		result = true;
	}
	return result;
}
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
ArraySet* ArraySet_Reunion(const ArraySet* set1, const ArraySet* set2)
{
	ArraySet* result = ArraySet_Create(set1->size+set2->size);
	int i;
	if(result!=NULL)
	{
		for(i=0; i<set1->size; i++)
		{
			ArraySet_AddObject(result,&set1->objects[i]);
		}
		for(i=0; i<set2->size; i++)
		{
			ArraySet_AddObject(result,&set2->objects[i]);
		}
	}
	return result;
}
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
ArraySet* ArraySet_Intersection(const ArraySet* set1, const ArraySet* set2)
{
	ArraySet* result = NULL;
	int i,j;
	bool wasFound = false;
	result = ArraySet_Copy(set1);
	if(result!=NULL)
	{
		for(i=0; i<set1->size; i++)
		{
			wasFound = false;
			for(j=0; j<set2->size; j++)
			{
				if(Object_Compare(&set1->objects[i],&set2->objects[j])==0)
				{
					wasFound = true;
					break;
				}
			}
			if(wasFound==false)
			{
				ArraySet_RemoveObject(result,&set1->objects[i]);
			}
		}
	}
	return result;
}
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
ArraySet* ArraySet_Difference(const ArraySet* mainSet, const ArraySet* secondarySet)
{
	ArraySet* result = NULL;
	int i,j;
	bool wasFound = false;
	result = ArraySet_Copy(mainSet);
	if(result!=NULL)
	{
		for(i=0; i<mainSet->size; i++)
		{
			wasFound = false;
			for(j=0; j<secondarySet->size; j++)
			{
				if(Object_Compare(&mainSet->objects[i],
						&secondarySet->objects[j])==0)
				{
					wasFound = true;
					break;
				}
			}
			if(wasFound==true)
			{
				ArraySet_RemoveObject(result,&mainSet->objects[i]);
			}
		}
	}
	return result;
}
