/*
 ============================================================================
 Name        : BuffTest.c
 Author      : OmarKSamy
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include "BuffH.h"

void SimulateTransmitter(void);
void SimulateReceiver(void);

int main(void) {
	u_int8_t sim_in = 0;
	printf("For simulation of receiving/transmitting press 1/2: ");
	scanf("%hhu", &sim_in);
	if(1 == sim_in){
		SimulateReceiver();
	}
	else if(2 == sim_in){
		SimulateTransmitter();
	}
	return 0;
}

void SimulateTransmitter(void){
	Object sim_sender_struct[TEST_DATA];
	u_int8_t for_counter_struct;
	u_int8_t * pdu_ptr;
	u_int8_t for_counter_sender;
	u_int8_t num_object;
	for(for_counter_struct = 0; for_counter_struct < TEST_DATA; for_counter_struct++){
		sim_sender_struct[for_counter_struct]->object_id = for_counter_struct;
		sim_sender_struct[for_counter_struct]->object_type = for_counter_struct;
		sim_sender_struct[for_counter_struct]->object_orientation = for_counter_struct;
	}
	num_object = TEST_DATA;
	pdu_ptr = BuffH_ReturnBufferfromStruct(sim_sender_struct, num_object);
	for(for_counter_sender = 0; for_counter_sender < 3*num_object; ++for_counter_sender){
		printf("%d, ", pdu_ptr[(for_counter_sender-1)]);
	}
	printf("%d.", pdu_ptr[(for_counter_sender-1)]);
}

void SimulateReceiver(void){
	static Object sim_receiver_struct_1;
	static Object * sim_receiver_struct = &sim_receiver_struct_1;
	u_int8_t for_counter_struct_0;
	u_int8_t pdu[MAX_BUFFER];
	u_int8_t for_counter_rec_1;
	u_int8_t loop_max = 3*TEST_DATA;
	for(for_counter_rec_1 = 0; for_counter_rec_1 < loop_max; for_counter_rec_1++){
		pdu[for_counter_rec_1] = for_counter_rec_1;
	}
	sim_receiver_struct = BuffH_AssignStructfromBuffer(pdu, TEST_DATA);
	for(for_counter_struct_0 = 0; for_counter_struct_0 < TEST_DATA; for_counter_struct_0++){
		printf("%d, %d, %d.\n", sim_receiver_struct[for_counter_struct_0]->object_id,
							   	sim_receiver_struct[for_counter_struct_0]->object_type,
							    sim_receiver_struct[for_counter_struct_0]->object_orientation);
	}
}
