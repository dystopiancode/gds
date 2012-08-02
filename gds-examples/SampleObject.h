/*
 * SampleObject.h
 *
 *  Created on: Jul 29, 2012
 *      Author: bogdan
 */

#ifndef SAMPLEOBJECT_H_
#define SAMPLEOBJECT_H_

#include<stdlib.h>

typedef struct
{
	int value;
}Integer;

Integer* Integer_Create(int value);
Integer* Integer_Copy(const Integer* integer);
Integer* Integer_Destroy(Integer* integer);
int Integer_Compare(const Integer* i1,const Integer *i2);

#endif /* SAMPLEOBJECT_H_ */
