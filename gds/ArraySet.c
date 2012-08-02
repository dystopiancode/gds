/*
 * ArraySet.c
 *
 *  Created on: Jul 28, 2012
 *      Author: bogdan
 */

#include "ArraySet.h"


ArraySet* ArraySet_Create(int capacity)
{
	ArraySet* set = NULL;
	set = (ArraySet*)malloc(sizeof(ArraySet));
	set->objects =  malloc(sizeof(Object)*capacity);
	set->capacity = capacity;
	set->size = 0;
	return set;
}

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

ArraySet* ArraySet_Destroy(ArraySet* set)
{
	if((set!=NULL) && (set->objects!=NULL))
	{
		free(set->objects);
		free(set);
	}
	return NULL;
}

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

ArraySet* ArraySet_RemoveAll(ArraySet* set)
{
	set->size = 0;
	return set;
}

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
