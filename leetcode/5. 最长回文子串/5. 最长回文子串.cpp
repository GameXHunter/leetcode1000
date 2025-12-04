/*
给你一个字符串 s，找到 s 中最长的 回文 子串。
示例 1：

输入：s = "babad"
输出："bab"
解释："aba" 同样是符合题意的答案。
示例 2：

输入：s = "cbbd"
输出："bb"

输入ac
输出a
*/

#include <string>
#include <unordered_set>
#include<iostream>
using namespace std;

class Solution {
public:
    //正确版本1：中心扩展法
    string longestPalindrome(string s) {
        if (s.empty()) return "";


    }

     
   /*
   正确版本2：动态规划 Dynamic Programming
   核心思想
    定义 dp[i][j] 表示 子串 s[i...j] 是否是回文。

    如果 dp[i][j] == true，说明从下标 i 到 j 的子串是回文。
    我们的目标是找到所有 dp[i][j] == true 中 长度最长的子串。

    从长度为1~长度为n一一排查
   
   */
    string longestPalindrome_DP(string s) {
        int n = s.size();
        if (n <= 1) return s;

        //创建一个大小为 n x n 的二维布尔向量（即矩阵），并将其所有元素初始化为 false
        vector<vector<bool>> dp(n, vector<bool>(n, false));//创建一个二维布尔数组（即矩阵）


        int start = 0, maxLen = 1;//// 记录最长回文的起始位置和长度


        // 所有长度为1的子串都是回文
        for (int i = 0; i < n; i++) {
            dp[i][i] = true;
        }


        // 枚举子串长度 L 
        for (int L = 2; L <= n; ++L)
        {
            // 枚举起始位置 i
            for (int i = 0; i <= n - L; i++)
            {
                int j = i + L - 1;//结束位置 //回文的长度
                
                if (s[i] == s[j])
                {
                    if (L == 2)
                    {
                        dp[i][j] = true;
                    }
                    else 
                    {
                        dp[i][j] = dp[i + 1][j - 1];
                    }
                }
                else
                {
                    dp[i][j] = false;
                }

                // 如果是回文，且更长，就更新答案
                if (dp[i][j] && L > maxLen) {
                    maxLen = L;
                    start = i;
                }
            }
        }

        return s.substr(start, maxLen);

    }


    //只检查了字符串中第一个可能的回文结构。若输入输入："aabbaa"则只输出aa
    string longestPalindrome_wrong(string s) {
        unordered_set<char>  substring;
        int left = 0;
        int right = 0;
        string palind;
        string result;
        string middleChar = "";
        if (s.size() == 1) return s;

        for (int i = 0; i < s.size(); i++)
        {
            if (substring.count(s[i]))
            {
                if (s[i] == s[i - 1])
                {
                    left = i-1;
                    right = i;
                    while (s[left] == s[right])
                    {
                        palind.push_back(s[right]);
                        ++right;
                        --left;
                        if (left<0 || right>s.size() - 1)  break;
                    }
                    break;

                }
                else
                {
                    middleChar = s[i - 1];
                    left = i - 2;
                    right = i;
                    while (s[left] == s[right])
                    {
                        palind.push_back(s[right]);
                        ++right;
                        --left;
                        if(left<0  || right>s.size()-1 )  break;
                    }
                    break;

                }
            }
            else
            {
                substring.insert(s[i]);
            }
        }

        for (int i = palind.size()-1; i >=0; --i)
        {
            result.push_back(palind[i]);
        }

        result = result+ middleChar + palind;

        return result;
    }
};





int main() {

    Solution solution;
    cout << solution.longestPalindrome_DP("") << endl;
    cout << solution.longestPalindrome_DP("eabccba") << endl;
    cout << solution.longestPalindrome_DP("eabcfcba") << endl;
    cout << solution.longestPalindrome_DP("babad") << endl;
    cout << solution.longestPalindrome_DP("cbbd") << endl;
    cout << solution.longestPalindrome_DP("a") << endl;
    cout << solution.longestPalindrome_DP("aba") << endl;
    cout << solution.longestPalindrome_DP("aa") << endl;
    cout << solution.longestPalindrome_DP("ac") << endl;
    cout << solution.longestPalindrome_DP("aabbaa") << endl;
    return 0;
}