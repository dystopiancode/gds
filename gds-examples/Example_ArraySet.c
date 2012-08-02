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
		printf("%d ", *(int*)(set->objects[i].data));
	}
	putchar('\n');
}

void ArraySet_Example2(void)
{
	ArraySet* s1 = NULL;
	ArraySet* s2 = NULL;
	ArraySet* r = NULL;
	Interface *I_Integer = NULL;
	bool result;

	/*Creating the Interface*/
	I_Integer = Interface_Create(&Integer_Copy,
								 &Integer_Destroy,
								 &Integer_Compare);

	/*Creating the first ArraySet and adding objects*/
	s1 = ArraySet_Create(10);
	ArraySet_AddObject(s1, Object_Create(Integer_Create(-3),I_Integer));
	ArraySet_AddObject(s1, Object_Create(Integer_Create(5),I_Integer));
	ArraySet_AddObject(s1, Object_Create(Integer_Create(2),I_Integer));
	ArraySet_AddObject(s1, Object_Create(Integer_Create(0),I_Integer));
	ArraySet_AddObject(s1, Object_Create(Integer_Create(-14),I_Integer));
	ArraySet_AddObject(s1, Object_Create(Integer_Create(3),I_Integer));

	/*Creates the second ArraySet and adding objects*/
	s2 = ArraySet_Create(10);
	ArraySet_AddObject(s2, Object_Create(Integer_Create(0),I_Integer));
	ArraySet_AddObject(s2, Object_Create(Integer_Create(1),I_Integer));
	ArraySet_AddObject(s2, Object_Create(Integer_Create(2),I_Integer));
	ArraySet_AddObject(s2, Object_Create(Integer_Create(0),I_Integer));
	ArraySet_AddObject(s2, Object_Create(Integer_Create(-14),I_Integer));
	ArraySet_AddObject(s2, Object_Create(Integer_Create(3),I_Integer));

	/*Prints the sets*/
	puts("Set S1");
	PrintArraySet(s1);
	puts("Set S2");
	PrintArraySet(s2);

	/*Checks if the set are equal*/
	result = ArraySet_Equals(s1, s2);
	if (result == true)
	{
		puts("S1 and S2 are equal");
	}
	else
	{
		puts("S1 and S2 are  not equal");
	}

	/*Checks if S1 is a subset of S2*/
	result = ArraySet_IsSubset(s1, s2);
	if (result == true)
	{
		puts("S1 is a subset of S2");
	}
	else
	{
		puts("S1 is not a subset of S2");
	}

	/*Computes the reunion of the two sets*/
	r = ArraySet_Reunion(s1, s2);
	puts("Reunion(S1,S2)");
	PrintArraySet(r);
	r = ArraySet_Destroy(r);

	/*Computes the intersection of the two sets*/
	puts("Intersection(S1,S2)");
	r = ArraySet_Intersection(s1, s2);
	PrintArraySet(r);
	r = ArraySet_Destroy(r);

	/*Computes the difference between S1 and S2*/
	r = ArraySet_Difference(s1, s2);
	puts("Difference(S1,S2)");
	PrintArraySet(r);
	r = ArraySet_Destroy(r);

	/*Computes the difference between S2 and S1*/
	r = ArraySet_Difference(s2, s1);
	puts("Difference(S2,S1");
	PrintArraySet(r);
	r = ArraySet_Destroy(r);
}
/*Output:
	Set S1
	Size: 6 Capacity: 10 Elements: -3 5 2 0 -14 3
	Set S2
	Size: 5 Capacity: 10 Elements: 0 1 2 -14 3
	S1 and S2 are  not equal
	S1 is not a subset of S2
	Reunion(S1,S2)
	Size: 7 Capacity: 11 Elements: -3 5 2 0 -14 3 1
	Intersection(S1,S2)
	Size: 4 Capacity: 10 Elements: 2 0 -14 3
	Difference(S1,S2)
	Size: 2 Capacity: 10 Elements: -3 5
	Difference(S2,S1
	Size: 1 Capacity: 10 Elements: 1
*/

void ArraySet_Example1(void)
{
	/*We declare 2 ArraySet data structures*/
	ArraySet* s1 = NULL;
	ArraySet* s2 = NULL;
	/*The interface for the objects*/
	Interface* I_Integer = NULL;
	/*Creating the interface*/
	I_Integer = Interface_Create(&Integer_Copy
								,&Integer_Destroy,
								 &Integer_Compare);
	/*Creating the first set*/
	s1 = ArraySet_Create(10);

	/*We shall add 6 objects who will symbolize the set {-3,5,2,0,-14,3}*/
	ArraySet_AddObject(s1, Object_Create(Integer_Create(-3),I_Integer));
	ArraySet_AddObject(s1, Object_Create(Integer_Create(5),I_Integer));
	ArraySet_AddObject(s1, Object_Create(Integer_Create(2),I_Integer));
	ArraySet_AddObject(s1, Object_Create(Integer_Create(0),I_Integer));
	ArraySet_AddObject(s1, Object_Create(Integer_Create(-14),I_Integer));
	ArraySet_AddObject(s1, Object_Create(Integer_Create(3),I_Integer));

	puts("After adding objects to s1: ");
	PrintArraySet(s1);

	/*Trying to add duplicate values*/
	ArraySet_AddObject(s1, Object_Create(Integer_Create(-3),I_Integer));
	ArraySet_AddObject(s1, Object_Create(Integer_Create(5),I_Integer));
	puts("After adding duplicate values to s1: ");
	PrintArraySet(s1);

	/*Creates a new ArraySet as a copy of the first ArraySet*/
	s2 = ArraySet_Copy(s1);

	/*Removing some objects from the first set*/
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

	/*After removing all objects from the second set*/
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


