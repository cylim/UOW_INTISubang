struct Rainfall{
	char month[10];
	int daysWithRain;
	float avgRainfall;
};

void setRainfallData(Rainfall); //get data from user input and save to file
void displayRainfall(Rainfall); //display highest average rainfall
void displayDay(Rainfall); //display month having hisghest rainfall
void searchRecord(Rainfall); //search by record number
void searchMonth(Rainfall); //search by month