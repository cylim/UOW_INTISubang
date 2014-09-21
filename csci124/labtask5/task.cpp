//Author	:Lim Chee Yeong
//Student ID: J14016414(INTI) or 4933643(UOW)
//Class		:CSCI124
//Lab Task	:5
//Date		:September 12th, 2014
//This program

#include <iostream>
using namespace std;

int findMode(int[], int); //find the mode in array of integers
double findMedian(int[], int); //find the median in array of integers 
void reverseArray(int[], int); //reverse the whole array

int main(){
	int total;
	int mode; 
	double median;
	cout << "total integer: ";
	cin >> total; //read in how many integers needed in the array
	int array[total];
	for(int i=0;i<total; i++){
		cout << "Enter number: ";
		cin >> *(array+i); //read the integers one by one
		while(*(array+i)< 0){
			cout << "Error! the number must be positive,\nNumber: ";
			cin >> *(array+i);
		}
	}
	mode = findMode(array, total); //return the mode value from the function
	median = findMedian(array, total); //return the median value from the function
	reverseArray(array, total); //reversed the array

	//To show the output of mode, median and reversed array
	cout<< endl << endl;
	if (mode == -1){
		cout << "Mode\t:NONE" << endl;
	} else if(mode == -2){
		
	} else {
		cout << "Mode\t:" << mode << endl;
	}
	cout << "Median\t:" << median << endl;
	cout << "ReverseArray: ";
	for(int i=0; i< total; i++){
		cout << *(array+i) << ' ';
	}
	cout << endl << endl;
}

int findMode(int array[], int total){
	int temp[total]; //create an array to store the count of each intergers appeared time
	int count, max=0, num, mode=-1;
	for (int x=0;x<total;x++){
		count=0;
		num= *(array+x);
		//if there is any value in array same as the num, increase counter by 1
		for(int y=0; y<total; y++){
			if(num==*(array+y)){
				count++;
			}
		}
		*(temp+x) = count;
		//to get the higheest count
		if(count > max){
			max = count;
		}
	}
	if(max == 1){
		return -1;
	}
	//if the highest count appeared is same as temp[x], then there is a mode, set mode to the array location.
	//if highest count value more than temp[x] mean there is two value have same count
	for(int x=0; x<total; x++){
		if(*(temp+x) == max){
			mode = *(array+x);
			break;
		}
	}
	return mode;
}

double findMedian(int array[], int total){
	double median = 0;
	//declare a new array to store all integers
	int* temp = new int[total];
	for(int i=0;i<total;i++){
		*(temp + i) = *(array + i);
	}
	//sorting the integers to ascending order
	for(int x=0; x<total; x++){
        for(int y=0; y<total-1; y++){
            if(*(temp + y) > *(temp + y + 1)){
                int swap = *(temp + y + 1);
                *(temp + y + 1) = *(temp + y);
                *(temp + y) = swap;
            }
        }
    }
    //if the array is even number, middle is the most center two variable add up and divide by 2
    //if it is not even, then take the middle
    if(total % 2 == 0){
        median = (*(temp + total/2) + *(temp + total/2-1))/(double)2;
    }
    else{
        median = *(temp + (((total+1)/2)-1));
    }
    delete[] temp;
	return median;
}

void reverseArray(int array[], int total){
	int* temp = array; // create a pointer point to array
	int swap;
	//move the first one to last, second to second last.
	for (int i = 0; i < total/2; ++i){
  		swap = *(temp + total-i-1);
      	*(temp + total-i-1) = *(temp + i);
      	*(temp+i) = swap;
	}
}