/*
给你一个字符串 s 和一个字符规律 p，请你来实现一个支持 '.' 和 '*' 的正则表达式匹配。

'.' 匹配任意单个字符
'*' 匹配零个或多个前面的那一个元素
所谓匹配，是要涵盖 整个 字符串 s 的，而不是部分字符串。
*/

#include<string>
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool isMatch(std::string s, std::string p) {
        
        int m = s.size();
        int n = p.size();
        
        //使用dp，设dp[i][j] 表示 s 的前 i 个字符 和 p 的前 j 个字符是否匹配。
        std::vector<std::vector<bool>> dp(m + 1, std::vector<bool>(n + 1, false));

        // 空字符串匹配空模式
        dp[0][0] = true;

        // 初始化第一行：s 为空，p 是否能匹配空串？
        // 只有形如 a*b*c*... 才能匹配空串
        for (int j = 2; j <= n; ++j) {
            if (p[j - 1] == '*') {
                dp[0][j] = dp[0][j - 2];
            }
        }

        // 填充 DP 表




        return dp[m][n];
    }

    // 递归 + 记忆化思路
    bool isMatch_memorize(std::string s, std::string p)
    {


    }




    //纯dfs实现（无记忆化）
    
    bool isMatch_dfs(std::string s,std::string p)
    {
        return dfs(s, p, 0, 0);
    }

private:
    // //纯dfs实现（无记忆化）
    /*
    思路：
        我们从字符串 s 和模式 p 的开头出发：
        每一步决定：当前能不能匹配？
        如果遇到 *，就面临分支选择：
        不使用前面的字符（匹配 0 次）→ 跳过 X*
        使用一次（匹配 1 次），然后继续保留 X*（因为 * 可以匹配多次）
        这就形成了一个搜索树，DFS 就是遍历这棵树，只要有一条路径能同时走到 s 和 p 的末尾，就返回 true。
    */
    bool dfs(const string& s, const string& p, int i, int j)
    {
        //模式p已经结束
        if (j == p.size())
        {
            return i == s.size();//字符串s也必须结束
        }
        //判断当前字符是否匹配（注意i不能越界）
        bool firstMatch = (i < s.size()) && (p[j] == '.' || p[j] == s[i]);

        //如果下一个字符是*
        if (j + 1 < p.size() && p[j + 1] == '*')
        {
            // 两种选择：
           // 1. '*' 匹配 0 次：跳过 p[j] 和 '*'
           // 2. '*' 匹配 >=1 次：当前匹配成功，且继续用 p[j..] 匹配 s[i+1..]
            return dfs(s, p, i, j + 2) || firstMatch && dfs(s, p, i + 1, j);
        }
        else {
            // 没有 '*'，必须当前匹配，且继续
            return firstMatch && dfs(s, p, i + 1, j + 1);
        }

    }

};

int main()
{
    Solution sol;

    cout << sol.isMatch("aab", "c*a*b") << endl;         // 1 (true)
    cout << sol.isMatch("mississippi", "mis*is*p*.") << endl; // 0 (false)
    cout << sol.isMatch("ab", ".*") << endl;             // 1 (true)
    cout << sol.isMatch("", "a*") << endl;               // 1 (true)
    cout << sol.isMatch("aaa", "a*a") << endl;           // 1 (true)
    cout << sol.isMatch("aaa", "ab*a*c*a") << endl;      // 1 (true)

    return 0;
}