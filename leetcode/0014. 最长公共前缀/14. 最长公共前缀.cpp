/*
编写一个函数来查找字符串数组中的最长公共前缀。

如果不存在公共前缀，返回空字符串 ""。



示例 1：

输入：strs = ["flower","flow","flight"]
输出："fl"
示例 2：

输入：strs = ["dog","racecar","car"]
输出：""
解释：输入不存在公共前缀。

*/

#include<string>
#include<vector>
#include<iostream>

class Solution {
public:
    std::string longestCommonPrefix(std::vector<std::string>& strs) 
    {
        if (strs.empty()) {
            return "";
        }

        std::string prefix = strs[0];

       // // 不断缩短 prefix，直到 strs[i] 以 prefix 开头
        for (int i = 1; i < strs.size(); ++i)
        {
            while (strs[i].find(prefix) != 0)
            {
                std::cout << "字符串strs[i]\" " << strs[i] << " \" find prefix  \"" << prefix << "\"的值为：" << strs[i].find(prefix) << std::endl;
                prefix.pop_back();  // 去掉最后一个字符
                if (prefix.empty()) {
                    return "";
                }
            }
            std::cout << "2字符串strs[i]\" " << strs[i] << " \" find prefix  \"" << prefix << "\"的值为：" << strs[i].find(prefix) << std::endl;

        }



        return prefix;


    }
};
#include <bitset> 
int main()
{
    Solution sol;
    std::vector<std::string> strs = { "flower","flow","flight" };

    std::cout <<"返回值为" << sol.longestCommonPrefix(strs) << std::endl;

    std::vector<std::string> strs2 = { "dog","racecar","car" };
    std::cout << "返回值为" <<sol.longestCommonPrefix(strs2) << std::endl;

    float a = 0.3f;

    std::cout << "a bits: " << std::bitset<32>(std::bit_cast<uint32_t>(a)) << "\n";
    
    return 0;
}