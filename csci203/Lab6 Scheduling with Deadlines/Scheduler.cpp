#include <iostream>
#include "Scheduler.h"

using namespace std;

Scheduler::Scheduler()
{
	for (int i = 0; i < SIZE; i++)
		slot[i].deadline = -1;	//sentinel value to indicate slot is empty
}

bool Compare(Jobs &A, Jobs &B)
{
	if (A.deadline < B.deadline)
		return true;
	else if (A.deadline == B.deadline) {
		if (A.profit > B.profit)
			return true;
		else
			return false;
	}
	else
		return false;

}

//insertion sort to sort jobs based on profit in descending order
void Scheduler::SortByProfit(Jobs job[], int size)
{
	int i, j;
	Jobs temp;
	for (i = 1; i<size; i++) {
		temp = job[i];
		j = i - 1;
		while (j >= 0 && temp.profit > job[j].profit) {
			job[j + 1] = job[j];
			j--;
		}
		job[j + 1] = temp;
	}
}

void merge(Jobs A[], int L, int C, int R)
{
	int apos = L, bpos = C + 1, cpos = 0;
	int size = R - L + 1;
	Jobs *tmpArr = new Jobs[size];
	while ((apos <= C) && (bpos <= R)) {
		if (Compare(A[apos], A[bpos])) {
			tmpArr[cpos] = A[apos];
			apos++;
			cpos++;
		}
		else {
			tmpArr[cpos] = A[bpos];
			bpos++;
			cpos++;
		}
	}
	while (apos <= C) {
		tmpArr[cpos] = A[apos];
		cpos++;
		apos++;
	}
	while (bpos <= R) {
		tmpArr[cpos] = A[bpos];
		cpos++;
		bpos++;
	}

	for (cpos = 0, apos = L; apos <= R; apos++) {
		A[apos] = tmpArr[cpos];
		cpos++;
	}
}

void split(Jobs Arr[], int left, int right)
{
	int center;
	if (left < right) {
		center = (left + right) / 2;
		split(Arr, left, center);
		split(Arr, center + 1, right);
		merge(Arr, left, center, right);
	}
}

void mergeSort(Jobs dataArray[], int size)
{
	split(dataArray, 0, size - 1);
}

//merge sort to sort jobs based on deadline and profit
void Scheduler::SortByDeadline(Jobs job[], int size)
{
	mergeSort(job, size);
}

void Scheduler::Input()
{
	cout << "Number of jobs to schedule : ";
	cin >> numOfJobs;
	char ID = 'A';
	for (int i = 0; i<numOfJobs; i++) {
		J[i].id = ID;
		cout << "Job " << ID << endl;
		cout << "Profit = "; cin >> J[i].profit;
		cout << "Deadline = "; cin >> J[i].deadline;
		cout << endl;
		ID++;
	}
}

void Scheduler::Schedule()
{
	int m, i, count;
	//Sort the jobs according to profit
	SortByProfit(J, numOfJobs);
	cout << "\nSorted Jobs List :\n";
	for (int i = 0; i<numOfJobs; i++) {
		cout << i + 1 << ") Job " << J[i].id << "\tProfit : " << J[i].profit
			<< "\tDeadline : " << J[i].deadline << endl;
	}

	int dl;

	i = 0;
	count = 0;
	while (i < numOfJobs) {
		//while still have job to schedule
		dl = J[i].deadline;
		do {
			//if slot is still available
			if (slot[dl].deadline == -1) {
				slot[dl] = J[i];
				count++;
				break;
			}
			else //try to use the slot in front
				dl--;
		} while (dl > 0);
		i++;
	}
	numOfScheduledJobs = count;
	cout << "\nNumber of scheduled job = " << numOfScheduledJobs << endl;

	count = 0;
	//Transfer jobs to execution list
	for (m = 0; m < SIZE; m++) {
		if (slot[m].deadline != -1) {
			exeList[count] = slot[m];
			count++;
		}
	}

	SortByDeadline(exeList, numOfScheduledJobs);

}

void Scheduler::Display()
{
	cout << "\nScheduled Jobs List :\n";
	for (int i = 0; i<numOfScheduledJobs; i++) {
		cout << i + 1 << ") Job " << exeList[i].id << "\tProfit : " << exeList[i].profit
			<< "\tDeadline : " << exeList[i].deadline << endl;
	}
}