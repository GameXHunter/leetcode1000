/*
给你一个 32 位的有符号整数 x ，返回将 x 中的数字部分反转后的结果。

如果反转后整数超过 32 位的有符号整数的范围 [−231,  231 − 1] ，就返回 0。

假设环境不允许存储 64 位整数（有符号或无符号）。
*/
#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
    //没法检查反转后整数是否超过 32 位的有符号整数的范围 
    int reverse_wrong(int x) {

        string str;
        string s = to_string(abs(x));

        for (int i = s.size()-1; i >= 0; --i)
        {
            str.push_back(s[i]);
        }

        int result = stoi(str);// 自动按十进制解析，忽略前导零
        if (x<0)
        {
            result = -result;
        }
        return result;
    }

    int reverse(int x) {
        int rev = 0;
        while (x != 0) {
            int pop = x % 10;//取模得到最后一位数字
            x /= 10; //去掉最后一位

            // 检查正溢出：rev > INT_MAX / 10 或 rev == INT_MAX / 10 且 pop > 7
            if (rev > INT_MAX / 10 || (rev == INT_MAX / 10 && pop > 7)) return 0;
            // 检查负溢出：rev < INT_MIN / 10 或 rev == INT_MIN / 10 且 pop < -8
            if (rev < INT_MIN / 10 || (rev == INT_MIN / 10 && pop < -8)) return 0;

            rev = rev * 10 + pop;
        }
        return rev;

    }
};


int main() {
    Solution solution;
    cout << solution.reverse(110)<<endl;
    return 0;
}