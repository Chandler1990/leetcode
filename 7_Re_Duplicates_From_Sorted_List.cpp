/*************************************************************************
	> File Name: 7_Re_Duplicates_From_Sorted_List.cpp
	> Author:
	> Mail:
	> Created Time: 2017年09月25日 星期一 18时39分25秒
 ************************************************************************/
 /*
题目：Given a sorted linked list, delete all duplicates such that each element appear only once.
For example,
Given 1->1->2, return 1->2.
Given 1->1->2->3->3, return 1->2->3.
思路：
思路1：遍历的时候，利用Hash表保存已经遍历的数值。对于每个数值，我们先查看Hash表中是否已经存在这个值，若存在，链表跳过该节点；若不存在，输出结果保留该节点。为了节省空间，我们更可以用bitmap来实现，当时bitmap需要同时支持正数与负数。
*/
#include<iostream>
using namespace std;

struct ListNode{
  int val;
  ListNode * next;
  ListNode(int n): val(n), next(NULL){}
}
/*用bitmap代替hash表*/
class bitmap{
public:
  bitmap(int n);
  ~bitmap();
  set(int n);
  judge(int n);
}

bitmap::bitmap(int n){
  len = n/32+1;
  map = new unsigned int[len];
  for(i=0;i<len;i++)
  map[i] = 0;
}
void bitmap::set(int n){

   int a = n / 32;
   int b = n % 32;
   if( 0 == ((map[a]/pow(2,b))%2)){
     map[a] = pow(2,b);
   }

}
bool bitmap::val(int n){

  int a = n / 32;
  int b = n % 32;
  if( 1 == ((map[a]/pow(2,b))%2)){
    return true;
  }
  else
   return false;
}

class Solutin{

  ListNode *process(ListNode *head){
    ListNode *lead = head;
    ListNode *ptr =lead;
    bitmap.set(ptr->val);
    while(NULL != ptr->next){
      if(true == bitmap->val(ptr->next->val))
      {
        ptr->next = ptr->next->next;
      }
      else
      {
        bitmap->set(ptr->next->val)
        ptr = ptr->next;
      }
    }
  }
}
