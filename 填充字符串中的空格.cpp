#include<iostream>

using namespace std;

bool ReplaceBlank(char string[], int length) {
	bool res = true; 
	if (string==nullptr||length<=0) {
		res = false;
	}
	int originlength = 0;
	int blanklength = 0;
	int i=0;
	while(string[i]!='\0') {
		++originlength;
		if (string[i]==' ') {
			blanklength++;
		}
		++i;
	}
	int newlength = originlength+2*blanklength;
	if (length<newlength) {
		res = false;
	}
	cout<<"newlength:"<<newlength<<" "<<"originlength:"<<originlength<<endl;
	while (originlength>=0&&newlength>originlength) {
		if(string[originlength]==' ') {
			string[newlength--]='0';
			string[newlength--]='2';
			string[newlength--]='%';
		}
		else {
			string[newlength--] = string[originlength];
		}
		--originlength;
	}
	return res;
}

int main() {
	char string[] = " We  ily";
	int i,j = 0;
	while (string[i]!='\0') {
		cout<<string[i]<<"";
		i++;
	}
	cout<<endl;
	bool res = ReplaceBlank(string, 20);
	cout<<res<<endl;
	while (string[j]!='\0') {
		cout<<string[j]<<"";
		j++;
	}
	
	char resq[] = "res";
	cout<<"-"<<resq[3]<<";"<<endl;
	return 0;
} 
