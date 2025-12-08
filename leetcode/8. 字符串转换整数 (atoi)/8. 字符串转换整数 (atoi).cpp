/*
请你来实现一个 myAtoi(string s) 函数，使其能将字符串转换成一个 32 位有符号整数。

函数 myAtoi(string s) 的算法如下：

空格：读入字符串并丢弃无用的前导空格（" "）
符号：检查下一个字符（假设还未到字符末尾）为 '-' 还是 '+'。如果两者都不存在，则假定结果为正。
转换：通过跳过前置零来读取该整数，直到遇到非数字字符或到达字符串的结尾。如果没有读取数字，则结果为0。
舍入：如果整数数超过 32 位有符号整数范围 [−231,  231 − 1] ，需要截断这个整数，使其保持在这个范围内。具体来说，小于 −231 的整数应该被舍入为 −231 ，大于 231 − 1 的整数应该被舍入为 231 − 1 。
返回整数作为最终结果。
*/

#include<iostream>
#include<string>
#include<vector>

class Solution {
public:
    int myAtoi(std::string s) {
        //1. 丢弃前导空格
        int i = 0;
        while (i < s.size() && s[i] == ' ')
        {
            i++;
        }
        //全为空格
        if (i >= s.size()) return 0;

        //2.检查符号 +-。后续乘以sign 1，-1来表示正负
        int sign = 1;
        if (s[i] == '-')
        {
            sign = -1;
            i++;
        }
        else if(s[i] == '+')
        {
            sign = 1;
            i++;
        }

        //3.转换数字并处理溢出。
        long long result = 0;//用64位的
        while (i < s.size() && std::isdigit(s[i]))
        {
            int digit = s[i] - '0';
            result = result * 10 + digit;//把string转为int

            //4.检查溢出
            if (sign == 1 && result > INT_MAX)
            {
                return INT_MAX;
            }
            if (sign == -1 && result > (long long)INT_MAX + 1)
            {
                return INT_MIN;
            }
            
            i++;


        }
        result *= sign;

        // 最终范围检查（虽然上面已经处理了，但为了安全）
        if (result > INT_MAX) return INT_MAX;
        if (result < INT_MIN) return INT_MIN;

        return (int)result;
    }
};
#include <bitset>

union FloatBits {
    float f;
    uint32_t i;
    //不要自己定义以 _t 结尾的类型：
   /* POSIX 保留了所有以 _t 结尾的名称
        自定义可能导致冲突（如 my_type_t 不安全）
        应该用 using MyType = ...; 或 typedef ... MyType;*/
};


//关于float的测试代码
void testcode() {
  /*  FloatBits fb;
    fb.f = -0.2f;
    std::cout << std::bitset<32>(fb.i) << std::endl;
    fb.f = 0.1f;
    std::cout << std::bitset<32>(fb.i) << std::endl;*/


    float sum = 0.0f;
    for (int i = 0; i < 1000000; ++i) {
        sum += 0.1f;  // 每次都加一个不精确的 0.1
    }
    // 期望 sum == 100000.0，但实际可能偏差很大！变成了100958
    std::cout << sum<< std::endl;//


    double sumd = 0.0;
    for (int i = 0; i < 1000000; ++i) {
        sumd += 0.1;
    }
    std::cout << sumd << std::endl;  // 输出：100000（或非常接近，如 99999.999999998）
}

int main()
{
    Solution sol;

    std::vector<std::string> testCases = {
       "42",
       "   -42",
       "4193 with words",
       "words and 987",
       "-91283472332",
       "91283472332",
       "+1",
       "   +0 123",
       "",
       "   ",
       "-+12",
       "00000-42a1234"
    };

    for (const std::string& test : testCases) {
        std::cout << "myAtoi(\"" << test << "\") = " << sol.myAtoi(test) << std::endl;
    }

   // testcode();

    return 0;
}