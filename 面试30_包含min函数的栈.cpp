#include<iostream>
#include<stack>
#include<assert.h>
using namespace std;
/*
面试30 - 包含min函数的栈 定义栈的数据结构，实现一个能够得到栈的最小元素的min函数
在栈中调用min push pop 的时间复杂度都是O（1） 
*/ 
//分析我们需要得到压栈进入的最小值，所以我们需要比较每次压栈数值的大小，因此我们创建了一个最小值的存放堆栈，每push一次的时候就会比较一次大小.

template <class T>
class StactWithMin 
{
public:
	stack<T> sta, sta_min;
	
	void push(const T& value) {
		sta.push(value);
		if (sta_min.size()==0||value<sta_min.top()) {
			sta_min.push(value);
		}
		else sta_min.push(sta_min.top());
	} 
	void pop() {
		assert(sta.size()>0&&sta_min.size()>0);
		sta.pop();
		sta_min.pop();
	}
	int size() const {
		return sta_min.size();
	}
	const T& min() const { //已定义成const的成员函数，一旦企图修改数据成员的值，则编译器按错误处理
		assert(sta.size()>0&&sta_min.size()>0);
		return sta_min.top();
	}
	
	
		
}; 

int main () {
	
	StactWithMin<int> sta;
	sta.push(1);
	sta.push(0);
	sta.push(3);
	
	cout<<"min堆栈的大小是："<<sta.size()<<endl;
	
	cout<<"min堆栈中的数为: "<<sta.min()<<" ";
	sta.pop(); 
	cout<<sta.min()<<" ";
	sta.pop(); 
	cout<<sta.min()<<endl;
	

	
	return 0;
}
