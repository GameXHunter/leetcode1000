/*
给定一个长度为 n 的整数数组 height 。有 n 条垂线，第 i 条线的两个端点是 (i, 0) 和 (i, height[i]) 。

找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。

返回容器可以储存的最大水量。

说明：你不能倾斜容器。
*/

#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
    //可用，但超出leetcode时间限制。
    int maxArea_overtime(std::vector<int>& height) {
        int maxSize = 0;

        for (int i = 0; i < height.size()-1; i++)
        {
            for (int j = i + 1; j < height.size(); j++)
            {
                int minHegiht = min(height[i],  height[j]);
                int curr = abs(j - i) * minHegiht;
                maxSize = maxSize> curr? maxSize :curr;
            }

        }

        return maxSize;
    }

    //双指针
    int maxArea(std::vector<int>& height)
    {
        int n = height.size();
        int left = 0, right = n-1;
        int maxWater = 0;
        while (left < right)
        {
            int h = min(height[left], height[right]);
            int w = right - left;
            maxWater = max(maxWater, h * w);
            // 移动较短的一边
            if (height[left] < height[right]) {
                ++left;
            }
            else {
                --right;
            }
        }

        return maxWater;

    }
};

int main()
{
    Solution sol;

    vector<int> height = { 1,8,6,2,5,4,8,3,7 };

    cout<< sol.maxArea(height) <<endl;

    return 0;
}