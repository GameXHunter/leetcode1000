/*
给定一个整数数组 nums 和一个整数目标值 target，请你在该数组中找出 和为目标值 target  的那 两个 整数，并返回它们的数组下标。

你可以假设每种输入只会对应一个答案，并且你不能使用两次相同的元素。

你可以按任意顺序返回答案。



示例 1：

输入：nums = [2,7,11,15], target = 9
输出：[0,1]
解释：因为 nums[0] + nums[1] == 9 ，返回 [0, 1] 。
示例 2：

输入：nums = [3,2,4], target = 6
输出：[1,2]
示例 3：

输入：nums = [3,3], target = 6
输出：[0,1]

*/

#include <vector>
#include <iostream>
using namespace std;

class Solution {


public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> output(2);
            for (int i = 0; i < nums.size() - 1; i++)
            {
                for (int j = i+1; j < nums.size(); j++)
                {
                    if (nums[i] + nums[j] ==  target)
                    {
                        return output = { nums[i],nums[j] };
                    }
                }

            }
            return output;
    }


};


int main()
{
    Solution solution;
    vector<int> nums = { 8,2,3, 7, 11, 15 };
    int target = 9;
    vector<int> result = solution.twoSum(nums, target);
    cout << "[" << result[0] << "," << result[1] << "]" << endl;
}