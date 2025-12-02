/*给定一个字符串 s ，请你找出其中不含有重复字符的 最长 子串 的长度。*/


#include <string>
#include <iostream>
#include <unordered_set>
using namespace std;

class Solution {
public:
    //使用unordered_set
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> seen;
        int right = 0, left = 0;
        int maxLength = 0;
        int n = s.size();
        while (right < n)
        {
            if (seen.find(s[right]) == seen.end())
            {
                seen.insert(s[right]);
                maxLength = max(maxLength,right-left+1);
                ++right;
            }
            else
            {
                // 出现重复，收缩左边界
                seen.erase(s[left]);
                ++left;
            }
        }
        return maxLength;
       
    }

    //已知字符集范围由英文字母、数字、符号和空格组成，优化方案：
    int lengthOfLongestSubstring2(string s)
    {
        bool used[128] = { false };
        return 0;
    }
    //暴力法：



};

int main()
{
    Solution solute;
    string s = "aaaa";
    string a = "";
    string b = "abcabcbb";
    string c = "pwwkew";
    cout << solute.lengthOfLongestSubstring(s) << endl;
    cout << solute.lengthOfLongestSubstring(a) << endl;
    cout << solute.lengthOfLongestSubstring(b) << endl;
    cout << solute.lengthOfLongestSubstring(c) << endl;

    return 0;
}