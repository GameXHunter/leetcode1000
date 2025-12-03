/*
给定两个大小分别为 m 和 n 的正序（从小到大）数组 nums1 和 nums2。请你找出并返回这两个正序数组的 中位数 。

算法的时间复杂度应该为 O(log (m+n)) 。

*/
#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
    //正版
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {




    }

    //暴力版
    double findMedianSortedArrays__brute_force(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        vector<int> combine;
        int indexM = 0;
        int indexN = 0;
        double median;
        while (indexM<m && indexN<n)
        {
            
            if (nums1[indexM]< nums2[indexN])
            {
                combine.push_back(nums1[indexM]);
                indexM++;
            }
            else {
                combine.push_back(nums2[indexN]);
                
                indexN++;
            }
        }
        // 处理剩余部分
        while (indexM < m) combine.push_back(nums1[indexM++]);
        while (indexN < n) combine.push_back(nums2[indexN++]);
        
        for (int i : combine)
        {
            cout << i << ",";
        }

        int combSize = combine.size();
        //取模=0说明是偶数
        if (combine.size()%2 == 0)
        {
            median = (combine[combSize / 2 - 1] + combine[combSize / 2]) / 2.0;
        }
        else
        {
            median = combine[combSize / 2];
        }

        return median;

    }
};



int main()
{
    Solution solution;
    vector<int> num1 = { 1,3 };
    vector<int> num2 = { 2 ,4,5,10};

    cout << "\n中位数是：" << solution.findMedianSortedArrays__brute_force(num1, num2);
	return 0;
}