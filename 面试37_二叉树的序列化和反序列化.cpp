#include<iostream>
#include <fstream>
using namespace std;
/*
面试37 - 序列化二叉树
实现两个函数，分别用来序列化和反序列化二叉树。 
*/

class Tree {
public:
	int val;
	Tree* left;
	Tree* right;
	Tree(int x):val(x), left(nullptr), right(nullptr){}	

};
//先序遍历 
void preorder(Tree* root) {
	if (root!=nullptr) {
		cout<<root->val<<",";
		preorder(root->left);
		preorder(root->right);
	}
} 
void Serialize(Tree* root, ostream& stream) {
	if (root==nullptr) {
		stream<<"$,";
		return;
	}
	stream<<root->val<<",";
	Serialize(root->left, stream);
	Serialize(root->right, stream);	 
}
bool ReadStream(istream& stream, int* number)
{
    if(stream.eof())
        return false;

    char buffer[32];
    buffer[0] = '\0';

    char ch;
    stream >> ch;
    int i = 0;
    while(!stream.eof() && ch != ',') 
    {
        buffer[i++] = ch;
        stream >> ch;
    }

    bool isNumeric = false;
    if(i > 0 && buffer[0] != '$')
    {
        *number = atoi(buffer);
        isNumeric = true;
    }

    return isNumeric;
}
void Deserialize(Tree** root, istream& stream) {
	int num;
	//读取序列化的文件，若为数字则是true，否则为false。 
	if (ReadStream(stream, &num)) {
		*root = new Tree(num);
		(*root)->left = nullptr;
		(*root)->right = nullptr;
		
		Deserialize(&((*root)->left), stream);
		Deserialize(&((*root)->right), stream);
	}
}

int main () {
	Tree* root = new Tree(1);
	root->left = new Tree(2);
	root->left->left = new Tree(4);
	root->right = new Tree(13);
	root->right->left = new Tree(5);
	root->right->right = new Tree(6);
	/*==========test1=============*/
	char* fileName = "37_serialized.txt";
    ofstream fileOut;
    fileOut.open(fileName);
	
	Serialize(root, fileOut);
	fileOut.close();
	
	// print the serialized file
    ifstream fileIn1;
    char ch;
    fileIn1.open(fileName);
    while(!fileIn1.eof())
    {
        fileIn1 >> ch;
        cout << ch;
    }
    fileIn1.close();
    cout << endl;
	/*==========test2=============*/
	ifstream fileIn2;
    fileIn2.open(fileName);
    Tree* pNewRoot = nullptr;
    Deserialize(&pNewRoot, fileIn2);
    fileIn2.close();
	
	preorder(pNewRoot);
	
	return 0;
} 
