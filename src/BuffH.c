/*
 * BuffH.c
 *
 *  Created on: May 12, 2018
 *      Author: oks
 */


#include "BuffH.h"


u_int8_t * BuffH_ReturnBufferfromStruct(Object map[], u_int8_t number_of_objects){
	static u_int8_t buffer[MAX_BUFFER];
	u_int8_t counter_0 = 0;
	u_int8_t counter_1 = 0;
	u_int8_t counter_2 = 0;
	u_int8_t counter_3 = 0;
	while(counter_0 < number_of_objects){
		counter_2 = counter_1 + 1;
		counter_3 = counter_2 + 1;
		buffer[counter_1] = map[counter_0]->object_id;
		buffer[counter_2] = map[counter_0]->object_type;
		buffer[counter_3] = map[counter_0]->object_orientation;
		counter_1 = counter_3 + 1;
		counter_0++;
	}
	return buffer;
}

Object * BuffH_AssignStructfromBuffer(u_int8_t PDU[], u_int8_t number_of_objects_rec){
	static Object auto_structure;
	static Object * data_to_assign = &auto_structure;
	u_int8_t counter_rec_0 = 0;
	u_int8_t counter_rec_1 = 0;
	u_int8_t counter_rec_2 = 0;
	u_int8_t counter_rec_3 = 0;
	while(counter_rec_0 < number_of_objects_rec){
		counter_rec_2 = counter_rec_1 + 1;
		counter_rec_3 = counter_rec_2 + 1;
		data_to_assign[counter_rec_0]->object_id = PDU[counter_rec_1];
		data_to_assign[counter_rec_0]->object_type = PDU[counter_rec_2];
		data_to_assign[counter_rec_0]->object_orientation = PDU[counter_rec_3];
		counter_rec_1 = counter_rec_3 + 1;
		counter_rec_0++;
	}
	return data_to_assign;
}
