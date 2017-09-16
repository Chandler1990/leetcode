/*
题目的要求是给定一个数组，找出数组中和为一定值的两个数。也就是给定一定值target，从数组中要找出a+b=target。等式转换一下，我们可以知道，a=target-b。所以我们要做的事情可以翻译为，找到一个数a，满足a与target-a都在数组之中。

第一个思路，遍历数组中的某一个数，对于每个数再一次遍历数组中的所有数，找到满足条件的两个数。这个算法的时间复杂度为O(n2)，空间复杂度为O(1)。
第二个思路，在前一个算法的基础上降低时间复杂度。我们可以将数组排序，然后定义两个指针，一个指针从左向右，另一个从右向左，遍历直到找到满足条件的两个数。由于排序的最佳时间复杂度为O(nlogn)，两个指针的遍历时间复杂度为O(n)。所以总的时间复杂度为O(nlogn)
第三个思路，我希望通过O(n)的时间复杂度完成要求。第一遍O(n)的算法将每个数据a对应的target-a建立查询的数据结构，例如Hash表；第二遍遍历时，查询每个数是否在Hash表中，每次查询时间复杂度为O(1)，总的时间复杂度是O(n)。但是Hash表将需要一定的存储空间，为了节省空间，我们可以采用bitmap的方法来最大化的压缩空间复杂度。
*/
#include <cmath>


class bitmap
{
	public:
		bitmap(int n);
		~bitmap();
		bool set(int k);
		bool val(int k);

	private:
		int len;
		unsigned int* map;
};


bitmap::bitmap(int n)
{
    len = n/32+1;
	map = new unsigned int[len];


	for(int i = 0; i < len; i++)
	{
		map[i] = 0;
	}
}


bitmap::~bitmap()
{
		delete map;
		len = 0;
}


bool bitmap::set(int k)
{
	int a = k/32;
	int b = k%32;


	if(a >= len)
	{
		return false;
	}
	else
	{
		int tmp = map[a]/pow(2,b);
		if(tmp%2 == 0)
		{
			map[a] += pow(2,b);
		}
		return true;
	}
}


bool bitmap::val(int k)
{
	int a = k/32;
	int b = k%32;


	if(a >= len)
	{
		false;
	}
	else
	{
		int tmp = map[a]/pow(2,b);
		if(tmp%2 == 1)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
}




class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        bitmap* bm = new bitmap(target);
        for(int i = 0;i < numbers.size(); i++)
        {
            bm->set(target - numbers[i]);
        }


        for(int i = 0;i < numbers.size(); i++)
        {
            if(bm->val(numbers[i]))
            {
                for(int j = i + 1;j < numbers.size(); j++)
                {
                    if(numbers[i] == target - numbers[j])
                    {
                        vector<int> v;
                        v.push_back(i+1);
                        v.push_back(j+1);
                        return v;
                    }
                }
            }
        }
    }
};