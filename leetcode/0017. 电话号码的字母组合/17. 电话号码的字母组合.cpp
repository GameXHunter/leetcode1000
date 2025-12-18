/*
给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。答案可以按 任意顺序 返回。

给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。
示例 1：

输入：digits = "23"
输出：["ad","ae","af","bd","be","bf","cd","ce","cf"]
*/


#include<vector>
#include<string>
#include<iostream>
#include<unordered_map>
#include "../Utils/Utils.h"

using namespace std;

class Solution {
public:
    //回溯算法：
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) {
            return {};
        }
        unordered_map<char, string> phoneMap = {
            {'2',"abc"},
            {'3',"def"},
            {'4',"ghi"},
            {'5',"jkl"},
            {'6',"mno"},
            {'7',"pqrs"},
            {'8',"tuv"},
            {'9',"wxyz"}
        };

        vector<string> result;
        string path; // 当前正在构建的组合

        backtrack(0, digits, phoneMap, path, result);
        return result;
    }
    //广度优先搜索（Breadth-First Search，简称 BFS)
    vector<string> letterCombinations_bfs(string digits) {
        if (digits.empty()) return {};
        unordered_map<char, string> phoneMap = {
         {'2',"abc"},
         {'3',"def"},
         {'4',"ghi"},
         {'5',"jkl"},
         {'6',"mno"},
         {'7',"pqrs"},
         {'8',"tuv"},
         {'9',"wxyz"}
        };

        vector<string>result;
        result.push_back("");//初始化一个空字符串作为起点。

        for (char digit : digits)
        {
            vector<string> newResult;
            string letters = phoneMap[digit];

            // 遍历当前所有组合
            for (const string& combo : result) {
                // 为每个组合添加当前数字对应的所有字母
                for (char letter : letters) {
                    newResult.push_back(combo + letter);
                }
            }

            result = move(newResult); // 更新结果（move 提升效率）
        }

        return result;
    
    }


private:
    /*
    回溯算法：
    1. 回溯是一种暴力搜索 + 剪枝优化的算法思想，常用于解决组合、排列、子集、棋盘等问题。
    它的核心是：
        尝试每一种可能的选择 → 如果不行就退回上一步 → 换另一个选择继续尝试
    2.在写回溯代码时，通常要明确以下三点：

    (1) 路径（path）
        ·已经做出的选择。
        ·在本题中：path 是当前拼出的字母组合（如 "ad"）。
    (2) 选择列表（choices）
        当前可以做的选择。
        在本题中：当前数字（如 '2'）对应的字母（如 'a','b','c'）。
    （3）结束条件（base case）
        什么时候停止递归？
        在本题中：当 index == digits.length()，说明所有数字都处理完了，得到一个完整组合。
    */
    void backtrack(int index,
        const string& digits,
        const unordered_map<char, string>& phoneMap,
        string& path,
        vector<string>& result)
    {
        //终止条件：已经处理完所有数字
        if (index == digits.size())
        {
            result.push_back(path);
            return;
        }
        char digit = digits[index];
        string letters = phoneMap.at(digit);

        for (char letter:letters)
        {
            path.push_back(letter);
            backtrack(index + 1, digits, phoneMap, path, result);
            path.pop_back();
        }
    }
};

int main()
{
    Solution sol;

    string input1 = "23";
    vector<string> output1 = sol.letterCombinations(input1);
    
    Utils::vector_print(output1);

    string input2 = "3";
    vector<string> output2 = sol.letterCombinations(input2);
    Utils::vector_print(output2);
    return 0;
}