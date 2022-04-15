#include<iostream>
#include<cstring>

using namespace std;
/*
题目：地上有m×n的方格，机器人从（0，0）开始移动，他每次可以上下左右移动一格但不能进入到行列左边之和大于k的格子。
 
*/ 
int getDigit(int k) {
	int sum = 0;
	while(k>0) {
		sum += k%10;
		k = k/10;
	}
	return sum;
}
bool check(int k, int rows, int cols, int row, int col, bool *visit) {
	if (row>=0&&row<rows&&col>=0&&col<cols&&(getDigit(row)+getDigit(col))<=k&&!visit[row*cols+col]) return true;
	
	return false;
}

int isMoving(int k, int rows, int cols, int row, int col, bool *visit) {
	int count = 0;
	if (check(k, rows, cols, row, col,visit)) {
		visit[row*cols + col] = true;
		
		count = 1+isMoving(k,rows,cols,row,col-1,visit)+isMoving(k,rows,cols,row,col+1,visit)+isMoving(k,rows,cols,row+1,col,visit)+isMoving(k,rows,cols,row-1,col,visit);
	}
	return count;
}

int movingCount(int k, int rows, int cols) {
	if (k<0 || rows<=0 ||cols<=0) {
		return 0;
	}
	bool *visit = new bool[rows*cols];
	memset(visit,0,rows*cols);
	
	int cnt = isMoving(k, rows, cols, 0, 0, visit);
	
	delete[] visit;
	return cnt;
	
} 

int main () {
	int k = 3;

	int	cnt = movingCount(k,4,0);
	cout<<"能够到达的格子数(k="<<k<<"):"<<cnt<<endl; 
	return 0;
}
