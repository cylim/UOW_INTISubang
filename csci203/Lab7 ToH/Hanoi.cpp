#include <iostream>
#define EMPTY 99

using namespace std;


void Initial(int m, int A[], int B[], int C[])
{
	A[0] = EMPTY;
	B[0] = EMPTY;
	C[0] = EMPTY;
	for (int i = 1; i <= m; i++) {
		A[i] = m + 1 - i;
		B[i] = EMPTY;
		C[i] = EMPTY;
	}
}

void Draw(int m, int A[], int B[], int C[])
{
	int a, b;
	cout << "Rod A\t\tRod B\t\tRod C\n";
	for (a = m; a > 0; a--) {
		if (A[a] != EMPTY) {
			for (b = 1; b <= A[a]; b++) {
				cout << "=";
			}
		}
		cout << "\t\t";

		if (B[a] != EMPTY) {
			for (b = 1; b <= B[a]; b++) {
				cout << "=";
			}
		}
		cout << "\t\t";

		if (C[a] != EMPTY) {
			for (b = 1; b <= C[a]; b++) {
				cout << "=";
			}
		}
		cout << "\t\t";

		cout << endl;
	}
	cout << endl;
}

void solveEven(int m, int A[], int B[], int C[]) 
{
	int p1 = m;
	int p2 = 0;
	int p3 = 0;
	int step = 1;
	while ((p1 > 0) || (p2 > 0)) {
		if (A[p1] < B[p2]) {
			p2++;
			B[p2] = A[p1];
			A[p1] = EMPTY;
			p1--;
		}
		else {
			p1++;
			A[p1] = B[p2];
			B[p2] = EMPTY;
			p2--;
		}
		cout << "Step " << step++ << endl;
		Draw(m, A, B, C);
		if (A[p1] < C[p3]) {
			p3++;
			C[p3] = A[p1];
			A[p1] = EMPTY;
			p1--;
		}
		else {
			p1++;
			A[p1] = C[p3];
			C[p3] = EMPTY;
			p3--;
		}
		cout << "Step " << step++ << endl;
		Draw(m, A, B, C);
		if (B[p2] < C[p3]) {
			p3++;
			C[p3] = B[p2];
			B[p2] = EMPTY;
			p2--;
		}
		else {
			p2++;
			B[p2] = C[p3];
			C[p3] = EMPTY;
			p3--;
		}
		cout << "Step " << step++ << endl;
		Draw(m, A, B, C);

	}
	
	cout << "Complete !" << endl;
}

void solveOdd(int m, int A[], int B[], int C[])
{
	int p1 = m;
	int p2 = 0;
	int p3 = 0;
	int step = 1;
	if(m % 2 != 0){
		p3++;
		C[p3] = A[p1];
		A[p1] = EMPTY;
		p1--;
		cout << "Step " << step++ << endl;
		Draw(m, A, B, C);
	}
	while ((p1 > 0) || (p2 > 0)) {
		if (A[p1] < B[p2]) {
			p2++;
			B[p2] = A[p1];
			A[p1] = EMPTY;
			p1--;
		}
		else {
			p1++;
			A[p1] = B[p2];
			B[p2] = EMPTY;
			p2--;
		}
		cout << "Step " << step++ << endl;
		Draw(m, A, B, C);
		if (B[p2] < C[p3]) {
			p3++;
			C[p3] = B[p2];
			B[p2] = EMPTY;
			p2--;
		}
		else {
			p2++;
			B[p2] = C[p3];
			C[p3] = EMPTY;
			p3--;
		}
		cout << "Step " << step++ << endl;
		Draw(m, A, B, C);
		if (A[p1] < C[p3]) {
			p3++;
			C[p3] = A[p1];
			A[p1] = EMPTY;
			p1--;
		}
		else {
			p1++;
			A[p1] = C[p3];
			C[p3] = EMPTY;
			p3--;
		}
		cout << "Step " << step++ << endl;
		Draw(m, A, B, C);

	}
	
	cout << "Complete !" << endl;
}

int main()
{
	int numOfDisc;
	cout << "How many disc ? ";
	cin >> numOfDisc;
	int *rodA = new int[numOfDisc+1];
	int *rodB = new int[numOfDisc+1];
	int *rodC = new int[numOfDisc+1];
	
	//initialize rods and discs position
	Initial(numOfDisc, rodA, rodB, rodC);
	Draw(numOfDisc, rodA, rodB, rodC);
	if (numOfDisc % 2 == 0)
		solveEven(numOfDisc, rodA, rodB, rodC);
	else
		solveOdd(numOfDisc, rodA, rodB, rodC);
}