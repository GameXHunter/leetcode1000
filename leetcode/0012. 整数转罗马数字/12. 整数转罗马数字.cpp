/*
七个不同的符号代表罗马数字，其值如下：

符号	值
I	1
V	5
X	10
L	50
C	100
D	500
M	1000
罗马数字是通过添加从最高到最低的小数位值的转换而形成的。将小数位值转换为罗马数字有以下规则：

如果该值不是以 4 或 9 开头，请选择可以从输入中减去的最大值的符号，将该符号附加到结果，减去其值，然后将其余部分转换为罗马数字。
如果该值以 4 或 9 开头，使用 减法形式，表示从以下符号中减去一个符号，例如 4 是 5 (V) 减 1 (I): IV ，9 是 10 (X) 减 1 (I)：IX。仅使用以下减法形式：4 (IV)，9 (IX)，40 (XL)，90 (XC)，400 (CD) 和 900 (CM)。
只有 10 的次方（I, X, C, M）最多可以连续附加 3 次以代表 10 的倍数。你不能多次附加 5 (V)，50 (L) 或 500 (D)。如果需要将符号附加4次，请使用 减法形式。
给定一个整数，将其转换为罗马数字。

*/

#include<string>
#include<iostream>
#include<vector>

class Solution {
public:
    //常规解法
    std::string intToRoman(int num) {
        // 按照从大到小的顺序列出所有合法的数值和对应符号（含减法形式）
       std:: vector<int> values = { 1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1 };
       std::vector<std::string> symbols = { "M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I" };

       std::string result;
        for (int i = 0; i < values.size(); ++i)
        {
            while (num >= values[i])
            {
                result += symbols[i];
                num -= values[i];
            }
        }
        return result;
    }


    
};

//使用constexpr 
constexpr std::string intToToman_constexpr(int num)
{
    // 使用 C 风格数组或 std::array 保证 constexpr 兼容性
    constexpr std::pair<int, const char*> table[] = {
        {1000,"M"},{900,"CM"},{500,"D"},{400,"CD"},
        {100,"C"},{90,"XC"},{50,"L"},{40,"XL"},
        {10,"X"},{9,"IX"},{5,"V"},{4,"IV"},{1,"I"}
    };

     std::string roman;


  for (const auto& [value, symbol] : table)
    {
        while (num >= value) {
            roman += symbol;
            num -= value;
        }
    }

    return roman;

}


static_assert(intToToman_constexpr(1994) == "MCMXCIV");



int main()
{
    Solution sol;
    std::vector<int> nums = { 3749,58,1994 };
    for (int num : nums) {
        std::cout << sol.intToRoman(num) << std::endl;

    }





    return 0;
}