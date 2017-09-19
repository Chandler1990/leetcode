/*
题目：
Given two binary strings, return their sum (also a binary string).

For example,
    a = "11"
    b = "1"
    Return "100".


    思路：
    本质上是反序遍历两个字符串，然后依次相加，相加过程与http://blog.csdn.net/lanxu_yy/article/details/11688591类似。
    */

#include "string"
#include "iostream"
using namespace std;

class Solution
{
public:
	string AddBinary();
	
	void GetBinaries(); 
private:
	struct ListNode{
	int index;
	ListNode* next;
	ListNode(int val): index(val),next(NULL){}
	};
	
	string first_binary;
	string second_binary;
};

void Solution ::  GetBinaries(){
	cout << "please enter the first binary string: " << endl;
	cin >> first_binary;
	cin.clear();
	cin.ignore();
 	cout << "please enter the second binary string: " << endl;
	cin >> second_binary;
}

string Solution :: AddBinary(){
	return first_binary;
}



int main()
{
	Solution process;
	process.GetBinaries();	
	process.AddBinary();
	return 0;
}
