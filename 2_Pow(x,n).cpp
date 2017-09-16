/*
题目：
Implement pow(x, n).
思路：
最简单的办法是根据n进行循环并计算乘积，但是这样的时间开销比较大。最好能够再减少循环次数，例如n4可以表示成（n2）2。将n表示成二进制的格式便能够轻松知道如何减少循环次数。
*/
#include "iostream"

class Solution
{
public:
  double pow_new(double x, int n)
  {
    if(0 == n)
    return false;
    if (n < 0)
    {
      x = 1 / x;
      n = -1 * n;
    }
      double result =1 ;
    while(n > 0)
    {
      if(n%2 == 1)
        result *= x;

        n /= 2;
        x *= x;
    }
        return result;
  }
};

int main()
{
    double result = 0;
    double x=100;
    int n=2;
    Solution tar;
    std::cout <<"###########"<< tar.pow_new(x,n);
    return true;
}
