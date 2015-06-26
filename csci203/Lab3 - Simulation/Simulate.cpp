#include <iostream>
#include "Queue.h"

using namespace std;

const int MAX = 6;
cust customer[MAX] = {
	//	ID, Arrival_Time, Service_Time
	{ 1, 0.5, 2.3 },
	{ 2, 1.1, 3.5 },
	{ 3, 2.9, 3.0 },
	{ 4, 5.5, 1.0 },
	{ 5, 6.8, 4.2 },
	{ 6, 8.9, 2.0 } };

Queue cQueue;
cust srv_customer;	//current customer the program is working on 
unsigned int cur_customer = 0;	//current customer count that has been serviced
bool busy = false;
float ptime = 0.0;
float cur_srv_end = 0.0;	//keep track service end time of current customer
float next_arrival = 0.0;	//keep track next arrival time of customer
float waiting_time = 0.0;	//keep track of total waiting time of customer 
float previousTime;

// Queue customer if server is busy
void queue_up()
{
	if (cQueue.size() > 0){
		waiting_time = waiting_time +( (ptime- previousTime) * cQueue.size());
	}

	cQueue.enqueue(srv_customer);
	cout << ptime << "\t " << srv_customer.ID << " queue up\t " << busy << "\t ";
	cQueue.showQueue();
	cout << "\t " << waiting_time << "\t\t " << cur_srv_end << endl;
}

// Start to process customer if server is not busy
void process_arrival()
{
	if (busy)
		queue_up();
	else {
		busy = true;
		cur_srv_end = ptime + srv_customer.srv_time;
		cout << ptime << "\t " << srv_customer.ID << " starts\t " << busy << "\t ";
		cQueue.showQueue();
		cout << "\t " << waiting_time << "\t\t " << cur_srv_end << endl;
	}
}

// Finish servicing current customer
void process_service_complete()
{
	previousTime = ptime;
	ptime = cur_srv_end;
	busy = false;
	cur_customer++;

	if (!cQueue.isEmpty()){
		waiting_time = waiting_time +((ptime - previousTime) * cQueue.size());
	}

	cout << ptime << "\t " << cur_customer << " completes\t " << busy << "\t ";
	cQueue.showQueue();
	cout << "\t " << waiting_time << "\t\t " << cur_srv_end << endl;
}

int main()
{
	int count = 0;
	cout << "time\t event\t\t server\t queue\t waiting_time\t cus_srv_end" << endl;
	cout << "============================================================================" << endl;
	cout << ptime << "\t " << "---\t\t " << busy << "\t ";
	cQueue.showQueue();
	cout << "\t " << waiting_time << "\t\t " << cur_srv_end << endl;

	do {
		if (!busy) { //if server is free
			if (cQueue.isEmpty()) {	//if queue is empty
				srv_customer = customer[count];
				next_arrival = srv_customer.arr_time;
				previousTime = ptime;
				ptime = next_arrival;
			}
			else { //if got customer in the queue
				cQueue.dequeue(srv_customer);
			}
			process_arrival();
			count++;
		}
		else { //if server is busy
			if (count < MAX) { //if still got customers to process
				srv_customer = customer[count];
				next_arrival = srv_customer.arr_time;
				//if current customer finish first before the next arrival
				if (cur_srv_end <= next_arrival) { 
					process_service_complete();
					if (cQueue.isEmpty()) {
						srv_customer = customer[count];
						next_arrival = srv_customer.arr_time;
						previousTime = ptime;
						ptime = next_arrival;
					}
					else {
						cQueue.dequeue(srv_customer);
					}

					process_arrival();

				}
				//if current customer finish after the next arrival
				else {
					previousTime = ptime;
					ptime = next_arrival;
					process_arrival();
					count++;
				}

			}
			else {//no more new customer
				process_service_complete();
			}
		}

	} while ((count < MAX) || (busy == true) || (cQueue.isEmpty() == false));

	cout << "\nThe average waating time is " << waiting_time / MAX << endl;
	//system("PAUSE");
}