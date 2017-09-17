/*
题目：
Given an array and a value, remove all instances of that value in place and return the new length.

The order of elements can be changed. It doesn't matter what you leave beyond the new length.


思路：
基本思路是遍历数组一遍，当遇到一个满足条件的数时，将它与数组的最后的值交换。当交换时当前遍历的位置与数组有效的位置相同时需要提前结束运算；否则继续遍历。
*/
class ListNode
{
  unsigned int val;
  ListNode* next;
  ListNode(unsigned int x): val(unsigned int x), next(null)(){}
}

class Solution
{
public:
  int RemoveElement(int* A, int n, int elements)
  {
    
  }
}
