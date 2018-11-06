/*
 * BuffH.h
 *
 *  Created on: May 12, 2018
 *      Author: oks
 */

#ifndef BUFFH_H_
#define BUFFH_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>

#define MAX_OBJECTS  10
#define MAX_DATA 	 3
#define TEST_DATA	 8
#define OBJECT_TYPES 3
#define MAX_BUFFER   OBJECT_TYPES*MAX_OBJECTS
#define MAX_TEST	 OBJECT_TYPES*TEST_DATA

typedef struct ObjecTag{
	u_int8_t object_id;
	u_int8_t object_type;
	u_int8_t object_orientation;
}Object[MAX_OBJECTS];

extern u_int8_t * BuffH_ReturnBufferfromStruct(Object map[], u_int8_t number_of_objects);
extern Object * BuffH_AssignStructfromBuffer(u_int8_t PDU[], u_int8_t number_of_objects_rec);

#endif /* BUFFH_H_ */
