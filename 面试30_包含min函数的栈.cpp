#include<iostream>
#include<stack>
#include<assert.h>
using namespace std;
/*
����30 - ����min������ջ ����ջ�����ݽṹ��ʵ��һ���ܹ��õ�ջ����СԪ�ص�min����
��ջ�е���min push pop ��ʱ�临�Ӷȶ���O��1�� 
*/ 
//����������Ҫ�õ�ѹջ�������Сֵ������������Ҫ�Ƚ�ÿ��ѹջ��ֵ�Ĵ�С��������Ǵ�����һ����Сֵ�Ĵ�Ŷ�ջ��ÿpushһ�ε�ʱ��ͻ�Ƚ�һ�δ�С.

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
	const T& min() const { //�Ѷ����const�ĳ�Ա������һ����ͼ�޸����ݳ�Ա��ֵ�����������������
		assert(sta.size()>0&&sta_min.size()>0);
		return sta_min.top();
	}
	
	
		
}; 

int main () {
	
	StactWithMin<int> sta;
	sta.push(1);
	sta.push(0);
	sta.push(3);
	
	cout<<"min��ջ�Ĵ�С�ǣ�"<<sta.size()<<endl;
	
	cout<<"min��ջ�е���Ϊ: "<<sta.min()<<" ";
	sta.pop(); 
	cout<<sta.min()<<" ";
	sta.pop(); 
	cout<<sta.min()<<endl;
	

	
	return 0;
}
