/*
给你一个整数 x ，如果 x 是一个回文整数，返回 true ；否则，返回 false 。

回文数是指正序（从左向右）和倒序（从右向左）读都是一样的整数。

例如，121 是回文，而 123 不是。
*/

#include <iostream>
#include<string>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        string s = to_string(x);
        int length = s.size();
        int right = length-1, left = 0;
        for (int i = 0; i < s.size(); i++)
        {
            left = i;
            right = length - left-1;
            if (left < right)
            {
                if (s[left] != s[right])
                {
                    return false;
                }
            }
            else
            {
                break;
            }

        }
        return true;
    }
};

int main()
{
    Solution solution;

    cout<< solution.isPalindrome(10)<<endl;

	return 0;
}