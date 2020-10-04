/*
 * Stats.cpp
 *
 *  Created on: Sep 10, 2019
 *      Author: keith
 */

#include <vector>

#include "../includes/stats.h"

Stats::Stats(std::vector<PCB> &finished_vector) { // @suppress("Member declaration not found")

	Stats::av_wait_time = UNINITIALIZED;
	Stats::av_turnaround_time = UNINITIALIZED;
	Stats::av_response_time = UNINITIALIZED;
	Stats::vec = &finished_vector;

	//vec.calcStats();
}


//loops thru vec, prints 1 line for each process using the following format
//Process 1 Required CPU time:2  arrived:0 started:0 finished:2
//if there are 10 processes in vector, should print 10 lines
void Stats::showAllProcessInfo() {
	for(int i = 0; i < int(vec->size()); i++) {
		std::cout<<"Process:" << vec->at(i).process_number <<
				"Required CPU Time:" << vec->at(i).required_cpu_time <<
				"arrival time:" << vec->at(i).arrival_time <<
				"start time:" << vec->at(i).start_time <<
				"finish time:" << vec->at(i).finish_time << std::endl;
	}
}

//after a process is placed in the ready_q, how long does
//it take before its placed on the processor?
//response_time per process = start_time - arrival_time
//this funtion returns the average over all processes
float Stats::get_av_response_time() {
	float response;
	int count;
	for(int i  = 0; i < int(vec->size()); i++) {
		response += (vec->at(i).start_time - vec->at(i).arrival_time);
		count++;
	}

	float avg = response/(count + 1);
	return avg;
}

//after a process is placed in the ready_q, how long does
//it take to complete?
//turnaround time per process = finish_time - arrival_time
//this funtion returns the average over all processes
float Stats::get_av_turnaround_time() {
	float turnaround;
		int count;
		for(int i  = 0; i < int(vec->size()); i++) {
			turnaround += (vec->at(i).finish_time - vec->at(i).arrival_time);
			count++;
		}

		float avg = turnaround/(count + 1);
		return avg;
}

//after a process is placed in the ready_q, how much time does it
//spend waiting for processor time?
//wait time per process = finish_time - arrival_time-required_CPU_time
//this funtion returns the average over all processes
float Stats::get_av_wait_time() {
	float wait;
		int count;
		for(int i  = 0; i < int(vec->size()); i++) {
			wait += (vec->at(i).finish_time - vec->at(i).arrival_time -
					vec->at(i).required_cpu_time);
			count++;
		}

		float avg = wait/(count + 1);
		return avg;
}
