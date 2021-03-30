#include<iostream>
using namespace std;
//void swap(int *a, int *b, int length);
bool FindMaxInteger(int *matrix, int rows, int columns, int num);
int main() {
	int i=5;
	cout<<i--<<endl;
	
	
 	char arrary[] = "hahaha";
//	arrary[0] = "H";
	cout<<arrary[0]<<endl;
	int a[] = {1,2,3,4};
	int b[] = {4,5,6,7};
	int matrix[] = {1,2,8,9,2,4,9,12,4,7,10,13,6,8,11,15};
	swap(a, b);
//	cout<<len(a)<<endl; 
//	for (int i=0; i<sizeof(a)/sizeof(int); i++) {
//		cout<<a[i]<<"\t"; 
//		cout<<b[i]<<"\t" ;
//	}
	bool res = FindMaxInteger(matrix, 4, 4, 6);
	cout<<res<<endl;
	return 0; 
} 

bool FindMaxInteger(int *matrix, int rows, int columns, int num) {
	if (matrix==nullptr || rows<=0 || columns<=0) {
		return false;	
	}
	bool res = false;
	int row = 0;
	int column = columns-1;
	while(row<rows&&column>=0) {
		if (matrix[row*columns+column]==num) {
			res = true;
			break;
		}
		else if (matrix[row*columns+column]>num) {
			column--;
		}
		else
			row++;
	}
//	cout<<column<<row<<endl;
	return res;
}

void swap(int a[], int b[], int length) {
	for (int i=0; i<length; i++) {
		int tmp = a[i];
		a[i] = b[i];
		b[i] = tmp;
	}
	
} 
