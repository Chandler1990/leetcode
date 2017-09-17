/*
题目：
Given an array and a value, remove all instances of that value in place and return the new length.

The order of elements can be changed. It doesn't matter what you leave beyond the new length.


思路：
基本思路是遍历数组一遍，当遇到一个满足条件的数时，将它与数组的最后的值交换。当交换时当前遍历的位置与数组有效的位置相同时需要提前结束运算；否则继续遍历。
*/
#include "iostream"
using namespace std;
class ListNode
{
public:
  unsigned int val;
  ListNode* behind;
  ListNode* next;
  ListNode(int x):val(x), behind(NULL) ,next(NULL){}
};

class Solution
{
public:
  int RemoveElement(ListNode* A, int elements)
  {
    ListNode* ptr = NULL;
	ptr = A;
	while(NULL != ptr)
	{
		if(elements == ptr->val)
		{
			ptr->behind->next = ptr->next;
		}
		ptr = ptr->next;
	} 
	return true;
  }

};

int main()
{
	int num = 0;
	int element = 0;
	Solution result;
	ListNode* ptr_org=NULL;
	ListNode* ptr=NULL;
	ListNode* ptr_vis=NULL;
	cout << "please enter numbers!" <<endl;
	ptr_org = new ListNode(0);
	ptr = ptr_org;
	
	while(cin >> num)
	{

		ptr->next = new ListNode(num);
		ptr->next->behind = ptr;
		ptr = ptr->next;
	}	
	cin.clear();
	cin.ignore();
	cout << "please enter the element!" <<endl;
	cin >> element;
	
	if(true == result.RemoveElement(ptr_org, element))
		cout<<"success！！！！！！"<<endl;
	else
		cout<<"fail！！！！！！"<<endl;
	ptr_vis = ptr_org;
	while(NULL != ptr_vis)
	{
		cout <<  "val: " <<ptr_vis->val << endl;
		cout <<  "now: " <<ptr_vis << endl;
		cout <<  "behind: " <<ptr_vis->behind << endl;
		cout <<  "next: " <<ptr_vis->next << endl;
		ptr_vis = ptr_vis->next;
		
	}
	return true;
	
}

