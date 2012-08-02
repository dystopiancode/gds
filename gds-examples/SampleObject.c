/*
 * SampleObject.c
 *
 *  Created on: Jul 29, 2012
 *      Author: bogdan
 */
#include"SampleObject.h"


Integer* Integer_Create(int value)
{
	Integer *i = NULL;
	i = malloc(sizeof(Integer));
	i->value = value;
	return i;
}

Integer* Integer_Copy(const Integer* integer)
{
	Integer *i = NULL;
	i = malloc(sizeof(Integer));
	i->value = integer->value;
	return i;
}

Integer* Integer_Destroy(Integer* integer)
{
	free(integer);
	return NULL;
}

int Integer_Compare(const Integer* i1, const Integer* i2)
{
	return (*(int*)(i1->value) - *(int*)(i2->value));
}
