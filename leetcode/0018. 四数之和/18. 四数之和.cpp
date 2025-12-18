 /*
 给你一个由 n 个整数组成的数组 nums ，和一个目标值 target 
 。请你找出并返回满足下述全部条件且不重复的四元组 [nums[a], nums[b], nums[c], nums[d]] 
 （若两个四元组元素一一对应，则认为两个四元组重复）：

0 <= a, b, c, d < n
a、b、c 和 d 互不相同
nums[a] + nums[b] + nums[c] + nums[d] == target
你可以按 任意顺序 返回答案 
 
 
 */
#include<vector>
#include<algorithm>
#include<iostream>
#include "../Utils/Utils.h"

using namespace std;
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> res;
        if (n < 4) return res;

        sort(nums.begin(), nums.end());

        for (int i = 0; i < n - 3; ++i)
        {
            //跳过重复的第一个
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            //剪枝：最小可能和 > target(注意用 long long 防溢出)
            if ((long long)nums[i] + nums[i + 1] + nums[i + 2] + nums[i + 3] > target) break;

            for (int j = i + 1; j < n - 2; ++j)
            {
                //跳过重复的第二个数
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;


                // 剪枝：当前最小四数和 > target
                if ((long long)nums[i] + nums[j] + nums[j + 1] + nums[j + 2] > target) break;
                // 剪枝：当前最大四数和 < target
                if ((long long)nums[i] + nums[j] + nums[n - 2] + nums[n - 1] < target) continue;

                int left = j + 1, right = n - 1;

                while (left < right) {
                    // 使用 long long 防止加法溢出
                    long long sum = (long long)nums[i] + nums[j] + nums[left] + nums[right];
                    if (sum == target) {
                        res.push_back({ nums[i], nums[j], nums[left], nums[right] });
                        // 跳过重复的 left 和 right
                        while (left < right && nums[left] == nums[left + 1]) ++left;
                        while (left < right && nums[right] == nums[right - 1]) --right;
                        ++left;
                        --right;
                    }
                    else if (sum < target) {
                        ++left;
                    }
                    else {
                        --right;
                    }
                }
            }

        }
        
        return res;

    }
};

int main() {
    Solution sol;
    vector<int> nums = { 1, 0, -1, 0, -2, 2 };
    int target = 0;
    auto result = sol.fourSum(nums, target);

    Utils::print_vector_vector(result);

    return 0;
}