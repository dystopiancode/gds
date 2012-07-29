/*
 * ArraySet_Example.c
 *
 *  Created on: Jul 28, 2012
 *      Author: bogdan
 */

#include<stdio.h>
#include"Examples.h"
#include"ArraySet.h"
#include"SampleObject.h"

static void PrintArraySet(ArraySet* set)
{
	int i;
	printf("Size: %d Capacity: %d Objects: ", set->size, set->capacity);
	for (i = 0; i < set->size; i++)
	{
		printf("%d ", *(int*)(set->objects[i].value));
	}
	putchar('\n');
}

void ArraySet_Example1(void)
{

	ArraySet* s1 = NULL;
	ArraySet* s2 = NULL;
	Interface *I_Integer = NULL;

	/*Creates 2 ArraySet capable of holding 10 objects*/
	I_Integer = Interface_Create(&Integer_Copy
								,&Integer_Destroy,
								 &Integer_Compare);
	s1 = ArraySet_Create(10);

	/*Adds the objects {-3,5,2,0,-14,3}*/
	ArraySet_AddObject(s1, Object_Create(Integer_Create(-3),I_Integer));
	ArraySet_AddObject(s1, Object_Create(Integer_Create(5),I_Integer));
	ArraySet_AddObject(s1, Object_Create(Integer_Create(2),I_Integer));
	ArraySet_AddObject(s1, Object_Create(Integer_Create(0),I_Integer));
	ArraySet_AddObject(s1, Object_Create(Integer_Create(-14),I_Integer));
	ArraySet_AddObject(s1, Object_Create(Integer_Create(3),I_Integer));
	puts("After adding objects to s1: ");
	PrintArraySet(s1);

	/*Tries to add duplicate values*/
	ArraySet_AddObject(s1, Object_Create(Integer_Create(-3),I_Integer));
	ArraySet_AddObject(s1, Object_Create(Integer_Create(5),I_Integer));
	puts("After adding duplicate values to s1: ");
	PrintArraySet(s1);

	/*Creates a new ArraySet as a copy of the first ArraySet*/
	s2 = ArraySet_Copy(s1);

	/*Removes some objects*/
	ArraySet_RemoveObject(s1, Object_Create(Integer_Create(-3),I_Integer));
	ArraySet_RemoveObject(s1, Object_Create(Integer_Create(0),I_Integer));
	ArraySet_RemoveObject(s1, Object_Create(Integer_Create(-14),I_Integer));
	puts("After removing some objects from s1: ");
	PrintArraySet(s1);
	puts("s2 remains the same: ");
	PrintArraySet(s2);

	/*Resizing the array*/
	ArraySet_Resize(s1, 6);
	puts("After resizing s1 ");
	PrintArraySet(s1);

	/*After removing all objects*/
	puts("After removing all objects from s2: ");
	ArraySet_RemoveAll(s2);
	PrintArraySet(s2);
}
/*Output:
 After adding objects to s1:
 Size: 6 Capacity: 10 Objects: -3 5 2 0 -14 3
 After adding duplicate values to s1:
 Size: 6 Capacity: 10 Objects: -3 5 2 0 -14 3
 After removing some objects from s1:
 Size: 3 Capacity: 10 Objects: 5 2 3
 s2 remains the same:
 Size: 6 Capacity: 10 Objects: -3 5 2 0 -14 3
 After resizing s1
 Size: 3 Capacity: 6 Objects: 5 2 3
 After removing all objects from s2:
 Size: 0 Capacity: 10 Objects:
 */


