/*题目：
You are given two linked lists representing two non-negative numbers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.
Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
思路：
思路非常简单，利用两个指针分别遍历两个链表，并且用一个变量表示是否有进位。某个链表遍历结束之后再将另一个链表连接在结果链表之后即可，若最后有进位需要添加一位。
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 实现方法如下：
 ListNode *ide = NULL；
 ide = new ListNode(3);
 ide->next = new ListNode(4);
 ide->next->next = new ListNode(5);
 */
#include "iostream"
using namespace std;
 struct ListNode
 {
   int val;
   ListNode *next;
   ListNode(int x) : val(x), next(NULL){} //和下面的初始化方式一样，但是两者不能同时使用
   #if 0
   ListNode(int x)
   {
    val = x;
    next = NULL;
   }
   #endif
 };

class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        int carry = 0;
        ListNode* tail = new ListNode(0);
        ListNode* ptr = tail;

        while(l1 != NULL || l2 != NULL){
            int val1 = 0;
            if(l1 != NULL){
                val1 = l1->val;
                l1 = l1->next;
            }

            int val2 = 0;
            if(l2 != NULL){
                val2 = l2->val;
                l2 = l2->next;
            }

            int tmp = val1 + val2 + carry;
            ptr->next = new ListNode(tmp % 10);
            carry = tmp / 10;
			
            ptr = ptr->next;
        }

        if(carry == 1){
            ptr->next = new ListNode(1);
        }
        return tail->next;
    }
};

void Get_Value(ListNode* ptr)
{
	int num = 0;
	cout<< "please enter numbers!\n" <<endl;
	while(cin >> num) 
	{
		ptr->next = new ListNode(num);
		ptr = ptr->next;
	} 
}

int main()
{
  ListNode* l1 = NULL;
  ListNode* l2 = NULL;
  ListNode* ptr = NULL; 
  ListNode* result = NULL;
  ListNode* visit = NULL;
  Solution obj;
  
  l1 = new ListNode(0);
  ptr = l1;
  Get_Value(ptr);
  cin.clear(); //这个问题困扰我很久，参考https://segmentfault.com/q/1010000006119215解决的。在第一次执行完获取值操作后，第二次获取值直接跳过了。
  cin.ignore();
  l2 = new ListNode(0);
  ptr = l2;
  Get_Value(ptr);
  
  result = obj.addTwoNumbers(l1,l2);
  visit = result;
  while(NULL != visit)
  {
	  cout << visit->val <<endl;
	  visit = visit->next;
  }
  return true;
}
