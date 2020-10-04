/*
 * SchedulerSTRR.cpp
 *
 *  Created on: Sep 7, 2019
 *      Author: keith
 *
 *      implements round robin scheduling algorithm
 *      pre-emptive
 */

//TODO fill in content


#include "../includes/scheduler_RR.h"

//Scheduler_RR::Scheduler_RR(std::queue<PCB> &queue,int time_slice =UNINITIALIZED):Scheduler(queue,true,time_slice){};

//override base class behaviour if necessary, otherwise call it
bool Scheduler_RR::time_to_switch_processes(int tick_count, PCB &p) {
	return Scheduler::time_to_switch_processes(tick_count, p);
}

//RR - preemptive - no sorting of ready_q needed.
void Scheduler_RR::sort() {

}
