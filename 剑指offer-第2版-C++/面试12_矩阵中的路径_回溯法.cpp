#include<iostream>
#include<vector>
#include<cstring> 
using namespace std;

/*
回溯法：可以看作暴力解法的一个升级版，它从解决问题每一步的所有可能选项里系统地选择出一个可行方案。
回溯法非常适合由多个步骤组成的问题，且每个步骤有多个选项。 
*/ 
bool haspathcore(char *matrix, int rows, int cols, int row, int col, int &pathlength, char *str, bool *visit) {
	if (str[pathlength]=='\0') {
		return true;
	}
	bool hasPath = true;
	if (row>=0&&row<rows&&col>=0&&col<cols&&matrix[row*cols+col]==str[pathlength]&&!visit[row*cols+col]) {
		++pathlength;
		visit[row*cols+col] = true;
	
		hasPath = haspathcore(matrix,rows,cols,row,col-1,pathlength,str,visit) 	
				  || haspathcore(matrix,rows,cols,row,col+1,pathlength,str,visit)
				  || haspathcore(matrix,rows,cols,row+1,col,pathlength,str,visit)	
				  || haspathcore(matrix,rows,cols,row-1,col,pathlength,str,visit);
		cout<<"haspath:"<<hasPath<<" "<<row<<","<<col<<endl;
		if (!hasPath) {
			--pathlength;
			visit[row*cols+col] = false;
		}
	}
	return false;
}

bool hasPath(char *matrix, int rows, int cols, char *str) {
	if (matrix==nullptr || rows<1 ||cols<1 ||str==nullptr) {
		return false;
	}
	bool *visit = new bool[rows*cols];
	memset(visit, 0, rows*cols*sizeof(bool));
	int pathlength = 0;
	for (int row=0; row<rows; row++) {
		for (int col=0; col<cols; col++) {
			if (haspathcore(matrix,rows,cols,row,col,pathlength,str,visit)) {
				return true;
			}
			
		}
	}
	delete[] visit;
	return false;
} 





int main() {
	vector<vector<char>> dp(3,vector<char>(3));
	char x,y,z,m;
	cout<<sizeof('a')<<" "<<sizeof("a")<<" "<<sizeof(x)<<endl; //注意这两种声明方式大小不同，字符串后边默认会加上'\0' 
//	for (int i=0; i<3; i++) {		
//		cin>>x>>y>>z>>m;
//		dp[i]={x,y,z,m};
//		
//	}
	char a[3][4] = {{'a','b','t','g'},{'c','f','c','s'},{'j','d','e','h'}};
	char matrix[12] ={'a','b','t','g','c','f','c','s','j','d','e','h'}; 
	char str[4] = {'a','b','t','g'};
	cout<<matrix[2]<<endl;
	
	cout<<"矩阵中是否存在对应路径:"<<hasPath(matrix, 3, 4, str)<<endl;

	
		
	return 0;
} 
