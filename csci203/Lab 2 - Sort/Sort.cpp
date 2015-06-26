#include "sort.h"
//#include <windows.h>

int sortedArray[dataSIZE];

void insertionSort (int dataArray[],int size)
{
	int i, j, temp;
	for (i=1; i<size; i++) {
		temp = dataArray[i];
		j = i - 1;
		while (j >= 0 && temp < dataArray[j]) {
			dataArray[j+1] = dataArray[j];
			j--;
		}
		dataArray[j+1] = temp;
	}
}

void shellSort (int dataArray[], int size)
{
	int inc = size, x, k, j, cur, pre, tmp;
	bool done;
	while (inc > 0) {
		inc = inc / 2;
		for (j=0; j<inc; j++) {
			k = j + inc;
			while (k < size) {
				done = false;
				x = dataArray[k];
				cur = k;
				pre = cur - inc;
				while (pre >= j && !done) {
					if (x < dataArray[pre]) {
						tmp = dataArray[cur];
						dataArray[cur] = dataArray[pre];
						dataArray[pre] = tmp;
						cur = pre;
						pre = pre - inc;
					}
					else {
						done = true;
						//dataArray[cur] = x;
						k = k + inc;
					}
				}
			}
		}
	}
}


void mergeSort(int data[], int start, int end)
{
		
	if (start < end){
        int middle = (start+end)/2;

        mergeSort(data, start, middle);

        mergeSort(data, middle+1, end);

        merge(data, start, middle, end);
    }
}

void merge(int arr[], int l, int m, int h)
{
	int arr1[dataSIZE],arr2[dataSIZE];  
  	int n1,n2,i,j,k;
  	n1=m-l+1;
  	n2=h-m;
 
  	for(i=0; i<n1; i++)
    	arr1[i]=arr[l+i];
  	for(j=0; j<n2; j++)
    	arr2[j]=arr[m+j+1];

	 arr1[i]=9999999;  // To mark the end of each temporary array
	 arr2[j]=9999999;
 
  	i=0;
  	j=0;
  	for(k=l; k<=h; k++) { 
    	if(arr1[i]<=arr2[j])
      	arr[k]=arr1[i++];
    	else
      	arr[k]=arr2[j++];
  	}
}