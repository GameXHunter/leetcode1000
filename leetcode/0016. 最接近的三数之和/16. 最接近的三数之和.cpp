/*
给你一个长度为 n 的整数数组 nums 和 一个目标值 target。请你从 nums 中选出三个整数，使它们的和与 target 最接近。

返回这三个数的和。

假定每组输入只存在恰好一个解。
*/
#include<vector>
#include<algorithm>
#include <iostream>

class Solution {
public:
    int threeSumClosest(std::vector<int>& nums, int target) {
        std::sort(nums.begin(), nums.end());
        int n = nums.size();

        int closestSum = nums[0] + nums[1] + nums[2];

        for (int i = 0; i < n - 2; ++i)
        {
            int left = i + 1;
            int right = n - 1;

            while (left < right)
            {
                int currentSum  = nums[i] + nums[left] + nums[right];
                // 如果正好等于 target，直接返回
                if (currentSum == target) {
                    return currentSum;
                }

                // 更新最接近的和
                if (std::abs(currentSum - target) < std::abs(closestSum - target)) {
                    closestSum = currentSum;
                }

                // 移动双指针
                if (currentSum < target) {
                    ++left;
                }
                else {
                    --right;
                }
            }
        }


        return closestSum;
    }
};

int main()
{
    Solution sol;

    std::vector<int> nums = { -1, 2, 1, -4 };
    int target = 1;
    std::cout << sol.threeSumClosest(nums, target) << std::endl; // 输出: 2

    return 0;
}