/*
给你一个整数数组 nums ，
判断是否存在三元组 [nums[i], nums[j], nums[k]] 
满足 i != j、i != k 且 j != k ，同时还满足 nums[i] + nums[j] + nums[k] == 0 。

请你返回所有和为 0 且不重复的三元组。

注意：答案中不可以包含重复的三元组。

*/

#include<iostream>
#include <vector>

#include <algorithm>
using namespace std;
class Solution {
public:
    //错误，包含了重复的三元
    vector<vector<int>> threeSum_repetition(vector<int>& nums) {
        
        vector<vector<int>> results;
        for (int i = 0; i < nums.size()-2; ++i)
        {
            for (int j = i+1 ; j < nums.size() - 1; j++)
            {
                for (int k = j + 1; k < nums.size(); k++)
                {
                    if (nums[i] + nums[j] + nums[k] == 0)
                    {
                        results.push_back({ nums[i],nums[j],nums[k] });
                    }
                    
                }
            }

        }
        return results;

    }

    //使用排序 + 双指针的方法来高效解决
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        int n = nums.size();

        // 排序
        sort(nums.begin(), nums.end());

        for (int i = 0; i < n - 2; ++i)
        {
            //跳过重复的第一个元素，避免三元数组
            if (i > 0 && nums[i] == nums[i - 1])
            {
                continue;
            }
            
            int target = -nums[i];//nums[left] + nums[right] == target 
            int left = i + 1;
            int right = n - 1;
            
            while (left < right)
            {
                int sum = nums[left] + nums[right];
                if (sum == target)
                {
                    result.push_back({ nums[i], nums[left], nums[right] });

                    //跳过重复的left和right
                    while (left < right && nums[left] == nums[left + 1]) {
                        ++left;
                    }
                    while (left < right && nums[right] == nums[right - 1]) {
                        --right;
                    }

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
       

        return result;
    }
};

void printResult(const vector<vector<int>>& result) {
    cout << "{";
    for (size_t i = 0; i < result.size(); ++i) {
        if (i > 0) {
            cout << ", ";
        }
        cout << "{";
        for (size_t j = 0; j < result[i].size(); ++j) {
            if (j > 0) {
                cout << ", ";
            }
            cout << result[i][j];
        }
        cout << "}";
    }
    cout << "}" << endl;
}

int main()
{
    Solution sol;
    vector<int> nums = { -1,0,1,2,-1,-4 };
    vector<vector<int>> results=sol.threeSum(nums);
    printResult(results);
    return 0;
}
