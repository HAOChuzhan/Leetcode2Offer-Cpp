#include<iostream>

using namespace std;

int FindMin(int *a, int length) {
	if (a == nullptr || length <=0) {
		return -9999;
	}
	int index1 = 0;
	int indexend = length-1;
	int indexmid = index1; //��ʼ��Ϊindex1��Ŀ���ǣ������ڰ�ǰ��0�����ᵽ���ȥ��ʱ��whileѭ����������ȥ���������Ľ�����ǵ�һ��������indexmid = index1 
	while(a[index1]>=a[indexend]) {
		if ((indexend-index1)==1) { //���ҽ����������ǣ�����ָ��ֲ�����������ķֽ紦����ߵ�ָ�뼴�����ǲ��ҵĽ�� 
			indexmid = indexend;
			break;
		}
		indexmid = (index1+indexend)/2;
		if (a[indexmid]>=a[index1]) {
			index1 = indexmid;
		}
		else if (a[indexmid]<=a[indexend]) {
			indexend = indexmid;
		}
		
	}
	return a[indexmid];
} 
/* 
�����Ľⷨ��������{0,1,1,1,1}�ķ�ת ���ܷ�ת��indexmid �޷��ж�λ����һ������������
���磺
{1,0,1,1,1}��{1,1,1,0,1} 
���ʱ��ֱ���������Χ��������С���� 
*/ 
int MinNum(int *a, int left, int right) {
	int res = a[left];
	for (int i=left+1; i<=right; i++) {
		if (res>a[i]) {
			res = a[i];
		}	
	}
	return res;
}
int FindMin2(int *a, int length) {
	if (a==nullptr || length <=0) {
		return -9999;
	} 
	int index1 = 0;
	int indexend = length-1;
	int indexmid = index1;
	while (a[index1]>=a[indexend]) {
		if ((indexend-index1)==1) {
			indexmid = indexend;
			break;
		}
		indexmid = (index1+indexend)/2;
		if (a[index1]==a[indexend] && a[indexmid]==a[indexend]) { //�����������Ҫ˳�������С������ 
			return MinNum(a, index1, indexend);
		}
		if(a[indexmid]>=a[index1]) {
			index1 = indexmid;
		}
		else if (a[indexmid]<=a[indexend]) {
			indexend = indexmid;
		}
	}
	return a[indexmid];
} 

int main() {
	int a[] = {1,1,1,0,1};
//	cout<<sizeof(a)<<endl; 
	int res = FindMin2(a, sizeof(a)/sizeof(int));
	cout<<"Result:"<<res<<endl; 
//	cout<<sizeof(bool)<<endl; //1 
	return 0;
} 
