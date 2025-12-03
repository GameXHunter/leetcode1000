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

    //返回某一最长无重复字符子串，并通过引用输出长度
    string findLongestSubstring(const string& s, int& maxLength)
    {
        unordered_set<char> seen;
        int left = 0, right = 0;
        maxLength = 0;
        int firstIndex = 0;//要返回的字串起始位置
        string result;
        while (right < s.size())
        {
            if (seen.count(s[right])==0)
            {
                seen.insert(s[right]);
                int currLength = right - left + 1;
                if(currLength> maxLength)
                {
                    maxLength = currLength;
                    firstIndex = left;
                }
                ++right;
                
            }
            else
            {

                seen.erase(s[left]);
                ++left;
            }
        }
        for (int i = firstIndex; i < firstIndex+maxLength; i++)
        {
            result.push_back(s[i]);
        }

        return result;

    }

    //返回所有最长无重复字符子串，并通过引用输出长度
    vector<string> findAllLongestSubstring(const string& s, int& maxLength)
    {
        unordered_set<char> seen;
        int left = 0, right = 0;
        maxLength = 0;
        int firstIndex = 0;//要返回的字串起始位置
        vector<string> result;
        while (right < s.size())
        {
            if (seen.count(s[right]) == 0)
            {
                seen.insert(s[right]);
                int currLength = right - left + 1;
                if (currLength > maxLength)
                {
                    maxLength = currLength;
                    firstIndex = left;

                    result.clear();
                    result.push_back(s.substr(left, currLength));
                }
                else  if (currLength ==  maxLength)
                {
                    firstIndex = left;
                    result.push_back(s.substr(left, currLength));
                }
                ++right;

            }
            else
            {

                seen.erase(s[left]);
                ++left;
            }
        }
        

        return result;

    }

    //返回所有无重复字符子串，

};

int main()
{
    Solution solute;
    string s = "aaaa";
    string a = "";
    string b = "abcabcbb";
    string c = "pwwkew";
    string d = "abcbed";
    string e = "abcabc";
   /* cout << solute.lengthOfLongestSubstring(s) << endl;
    cout << solute.lengthOfLongestSubstring(a) << endl;
    cout << solute.lengthOfLongestSubstring(b) << endl;
    cout << solute.lengthOfLongestSubstring(c) << endl;*/
    cout << "changdu "<< solute.lengthOfLongestSubstring(d) << endl;

    int maxLength;
    cout << solute.findLongestSubstring(d, maxLength) << endl;
    cout << "长度为："<< maxLength << endl;

    vector<string> allLongestString = solute.findAllLongestSubstring(e, maxLength);
    for (string str : allLongestString)
    {
        cout << str << ",";
    }
    return 0;
}