#include<iostream>

using namespace std;
//int countRange(const int *numbers, int length, int start, int end);
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

int duplicate(const int*numbers, int length) {
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

bool duplicate(int numbers[], int length, int* duplication)
{
    if(numbers == nullptr || length <= 0)
        return false;

    for(int i = 0; i < length; ++i)
    {
        if(numbers[i] < 0 || numbers[i] > length - 1)
            return false;
    }

    for(int i = 0; i < length; ++i)
    {
        while(numbers[i] != i)
        {
            if(numbers[i] == numbers[numbers[i]])
            {
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
bool contains(int array[], int length, int number)
{
    for(int i = 0; i < length; ++i)
    {
        if(array[i] == number)
            return true;
    }

    return false;
}
void test(char* testName, int numbers[], int lengthNumbers, int expected[], int expectedExpected, bool validArgument)
{
    printf("%s begins: ", testName);

    int duplication;
    bool validInput = duplicate(numbers, lengthNumbers, &duplication);

    if(validArgument == validInput)
    {
        if(validArgument)
        {
            if(contains(expected, expectedExpected, duplication))
                printf("Passed.\n");
            else
                printf("FAILED.\n");
        }
        else
            printf("Passed.\n");
    }
    else
        printf("FAILED.\n");
}
    
void test1() {
    int numbers[] = { 2, 1, 3, 1, 4 };
    int duplications[] = { 1 };
    test("Test1", numbers, sizeof(numbers) / sizeof(int), duplications, sizeof(duplications) / sizeof(int), true);
}
int duplicate2(int numbers[], int length) {
	if (numbers==nullptr || length<=0) {
		return -1;
	}
	for (int i=0; i<length; i++) {
		while(numbers[i]!=i) {
			if (numbers[i]==numbers[numbers[i]]) {
				return numbers[i];
			}
			int tmp = numbers[i];
			numbers[i] = numbers[tmp];
			numbers[tmp] = tmp;
			
		}
	} 
	return -1;
}
bool duplicate3(int numbers[], int length, int* duplication)
{
    if(numbers == nullptr || length <= 0)
        return false;

    for(int i = 0; i < length; ++i)
    {
        if(numbers[i] < 0 || numbers[i] > length - 1)
            return false;
    }

    for(int i = 0; i < length; ++i)
    {
        while(numbers[i] != i)
        {
            if(numbers[i] == numbers[numbers[i]])
            {
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

int mian() {
//	int a[] = {1,2,5,6,4,7,5,3};
//	cout<<sizeof(a)<<endl;
//	int res;
//	res = duplicate2(a, 8);
//	cout<<res<<endl;
	test1();	
	return 0;
}
