#include<iostream>
#include<vector>
using namespace std;

/*
����29 ��˳ʱ���ӡ���� 
*/

//����1�������Ϻ����µ�������ȷ��һȦ��Ȼ���ӡһȦ���󣬽����������һȦ���������� 
vector<int> PrintMatrix1(vector<vector<int> > a) {
	
	int row = a.size();
	int col = a[0].size();
	vector<int> res;
	if (row==0 || col==0) return res;
	int left=0, top=0, right = col-1, bottom=row-1;
	
	while (left<=right&&top<=bottom) {
		for (int i=left; i<=right; i++) res.push_back(a[top][i]);
		for (int i=top+1; i<=bottom; i++) res.push_back(a[i][right]);
		for (int i=right-1; i>=left; i--) res.push_back(a[bottom][i]);
		for (int i=bottom-1; i>top; i--) res.push_back(a[i][left]);
		left++;top++;right--;bottom--;
	} 
	return res;
} 

//����2������һ��Ȧ���ı�����Ȼ��һȦһȦ�Ĵ�ӡ������1���ơ� 
void Printcircle(vector<vector<int> > a, int circle) {
	
	for (int i=circle; i<a[0].size()-circle; i++) {
		int tmp = a[circle][i];
		cout<<tmp<<" ";
	}
	for (int i=circle+1; i<a.size()-circle; i++) {
		int tmp = a[i][a[0].size()-1-circle];
		cout<<tmp<<" ";
	}
	for (int i=a[0].size()-2-circle; i>=circle;i--) {
		int tmp = a[a.size()-1-circle][i];
		cout<<tmp<<" ";
	}
	for (int i=a.size()-2-circle; i>circle; i--) {
		int tmp = a[i][circle];
		cout<<tmp<<" ";
	}
	
}
void PrintMatrix2(vector<vector<int> > a) {
	int row = a.size();
	int col = a[0].size();
	if (row==0 || col==0) return;
	
	int circle = 0;
	while (col>2*circle&&row>2*circle) {
		Printcircle(a,circle);
		++circle;
	}
} 


int main () {


//	int a[3][3] = {{1,2,3}, 
//	               {4,5,6},
//	               {7,8,9}};
	
	vector<vector<int> > matrix;
	matrix = { { 1, 2, 3 }, { 4, 5, 6 }, {7,8,9} };
	
	vector<int> res = PrintMatrix1(matrix);
	cout<<"˳ʱ���ӡ�ľ���Ϊ:\n"; 
	for (int i=0; i<res.size(); i++) {
		cout<<res[i]<<" ";
	}
	cout<<"\n====================================="<<endl; 
	PrintMatrix2(matrix);
	
	
	return 0;
}
