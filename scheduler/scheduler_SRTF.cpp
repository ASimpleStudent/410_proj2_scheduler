/*
 * SchedulerSRTF.cpp
 *
 *  Created on: Sep 10, 2019
 *      Author: keith
 *
 *      implements shortest remaining time first scheduling algorithm
 *     pre-emptive
 */

//TODO fill in content
#include <vector>
#include <algorithm>
#include "../includes/scheduler_SRTF.h"

//override base class behaviour if necessary, otherwise call it
bool Scheduler_SRTF::time_to_switch_processes(int tick_count, PCB &p) {
	return Scheduler::time_to_switch_processes(tick_count, p);
}

bool compareRemainingCpuTime(const PCB& a, const PCB& b) {
	return a.remaining_cpu_time > b.remaining_cpu_time;
}
//SRTF-preemptive - sort ready_q by remaining_cpu_time whenever add(PCB p) or time_to_switch_processes is called
void Scheduler_SRTF::sort(){
	std::vector<PCB> temp;

	while (ready_q->empty() == false) {
		temp.push_back(ready_q->front());
		ready_q->pop();
	}

	std::sort(temp.begin(), temp.end(), compareRemainingCpuTime);

	for (int i = temp.size()-1; i >= 0; i--) {
		ready_q->push(temp[i]);
		temp.pop_back();
	}

}


