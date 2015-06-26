#define SIZE 20
struct Jobs {
	char id;
	int profit;
	int deadline;
};

class Scheduler {
private:
	int numOfJobs;
	Jobs slot[SIZE];
	int numOfScheduledJobs;
	Jobs J[SIZE];
	Jobs exeList[SIZE];
	void SortByProfit(Jobs job[], int size);
	void SortByDeadline(Jobs job[], int size);

public:
	Scheduler();
	void Input ();
	void Schedule ();
	void Display ();
};
