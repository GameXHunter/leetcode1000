/*给定一个字符串 s ，请你找出其中不含有重复字符的 最长 子串 的长度。*/


#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int longest = 0;
        for (int i = 0; i < s.size(); i++)
        {
            for (int j = i + 1; j < s.size(); j++)
            {
                if (s[i]==s[j])
                {
                    int num = j - i;
                    longest = (num > longest) ? num : longest;
                }
            }
        }
        return longest+1;
    }
};

int main()
{
    Solution solute;
    string s = "aaaa";
    cout << solute.lengthOfLongestSubstring(s) << endl;
}