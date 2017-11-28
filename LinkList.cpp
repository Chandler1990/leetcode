#include "iostream"
#include "cstdlib"
using namespace std;

struct ListNode{
	int val;
	ListNode* Next;
	ListNode():val(0), Next(NULL){}
};
//创建列表
bool Creat_List(ListNode* head)
{	
	cout << "Create List Start!" <<endl;
	ListNode* ptr = head;
	for(int i =0; i < 10; i++){
		ListNode* next = new ListNode;
		ptr->val = random()%10;
		cout << "Current:"<< ptr <<">>>>"; 
		ptr->Next = next;
		cout << "Next:" << ptr->Next << endl; 
		ptr = ptr->Next;
	}
	cout << "Create List End!" <<endl;
}
//单向列表反转
ListNode* Reverse_List(ListNode* head){
	cout << "Reverse List Start!" <<endl;
	ListNode* ptr = head;
	ListNode* temp =NULL;
	ListNode* pre = NULL;
	while(ptr->Next != NULL){
		temp = ptr->Next;
		ptr->Next = pre;
		pre = ptr;
		cout << "Current:"<< ptr <<">>>>";
		cout << "Next:" << ptr->Next << endl;
		ptr = temp;	
	}
	cout << "Reverse List End!" <<endl;
	//列表尾变成了列表头，最后一项的Next没有用，所以返回最后一项的值
	return pre;
}

bool Traverse_List(ListNode* head){
	cout << "Traverse List Start!" <<endl;
	ListNode* ptr = head;
	int NUM = 0;
	while(ptr != NULL){
		cout << "Current:"<< ptr <<">>>>";
		//用于记录链表长度
		NUM ++;
		//循环跳出条件
		if(ptr->Next == NULL) break; 
		else ptr = ptr->Next;
		cout << "Next:" << ptr->Next << endl;
	}
	cout << "Traverse List End!" <<endl;
	return 0;
}
int main(){
	ListNode *head = new ListNode;
	bool flag_c = Creat_List(head);
	head = Reverse_List(head);
	bool flag_t = Traverse_List(head);
	return 0;}

