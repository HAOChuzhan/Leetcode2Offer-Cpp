#include<iostream>

using namespace std;

// 计算在start到end区间中有多少个数
int countRange(const int *numbers, int length, int start, int end) {
	if (numbers==nullptr) {
		return -1;
	}
	int count=0;
	for (int i=0; i<length; i++) {
		if (numbers[i]>=start && numbers[i]<=end) {
			count++;
		}
	}
	return count;
}
// 用时间换空间，仅使用O(1)的空间复杂度，时间复杂度为O(nlogn)
int duplicate1(const int*numbers, int length) {
	if (numbers==nullptr || length==0) {
		return -1;
	}
	int start = 1;
	int end = length-1;
	while (start<=end) {
		int middle = ((end-start)>>1)+start;
		int cnt = countRange(numbers, length, start, middle);
		if (end==start) {
			if (cnt>1) return start;
			else break;
		}
		if (cnt>(middle-start+1))
			end = middle;
		else
			start = middle+1;
	}
	return -1;
}
// 仅仅使用自身的数组空间 
bool duplicate2(int numbers[], int length, int* duplication) {
	if(numbers == nullptr || length <= 0)
		return false;

	for(int i = 0; i < length; ++i) {
		if(numbers[i] < 0 || numbers[i] > length - 1)
			return false;
	}

	for(int i = 0; i < length; ++i) {
		while(numbers[i] != i) {
			if(numbers[i] == numbers[numbers[i]]) {
				*duplication = numbers[i];
				return true;
			}

			// 交换numbers[i]和numbers[numbers[i]]
			int temp = numbers[i];
			numbers[i] = numbers[temp];
			numbers[temp] = temp;
		}
	}

	return false;
}
// 使用等长度大小空间的额外数组 
bool duplicate3(int array[], int length, int* duplication) {
	int a[length]; 
	for(int i = 0; i < length; ++i) {
		cout<<array[i]<<endl;
		if(array[i] == i) {
			*duplication = i;
			return true;
		}
		else {
			a[i] = i;
		}
			
	}

	return false;
}

int main() {
	int a[] = {1,2,5,6,4,7,5,3};
//	cout<<sizeof(a)<<endl;
//	int res;
//	res = duplicate2(a, 8);
//	cout<<res<<endl;
	int *duplication = 0; 
	cout<<duplicate2(a, 8, duplication)<<endl;
	return 0;
}
