/*
给定两个大小分别为 m 和 n 的正序（从小到大）数组 nums1 和 nums2。请你找出并返回这两个正序数组的 中位数 。
算法的时间复杂度应该为 O(log (m+n)) 。


解题思路：
使用 二分查找（Binary Search）。核心思想是：将两个数组分别切一刀，使得左半部分和右半部分满足中位数的划分条件。

我们要在两个有序数组nums1（长度 m）和nums2（长度 n）中找到一个划分点，使得：
左半部分总共有 (m + n + 1) / 2 个元素（+1 是为了统一奇偶处理）
左半部分的所有元素 ≤ 右半部分的所有元素

具体步骤：
nums1，nums2先分别平均划分成左右两边，
把nums1和nums2的左边放一起（左12），num1,num2的右边放一起（右12）
如果（左12）的最大值小于（右12）的最小值，则成功。
如果（左12）的最大值大于（右12）的最小值，
    
*/
#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
    //正版
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        //确保nums1短于nums2
        if (nums1.size() > nums2.size())
        {
            swap(nums1,nums2);
        }
        int m = nums1.size();
        int n = nums2.size();
        int totalLeft = (n + m + 1) / 2; //AB合并后左半部分的元素

        int left = 0, right = m;

        while (left <= right)
        {
            int i = left + (right - left) / 2;           // nums1 的划分点
            int j = totalLeft - i;                       // nums2 的划分点

            int A_left_max = (i == 0) ? INT_MIN : nums1[i - 1];
            int A_right_min = (i == m) ? INT_MAX : nums1[i];
            int B_left_max = (j == 0) ? INT_MIN : nums2[j - 1];
            int B_right_min = (j == n) ? INT_MAX : nums2[j];

            // 正确划分，使左边所有元素都小于右边。
            if (A_left_max <= B_right_min &&  A_right_min >= B_left_max) {
                if ((m + n) % 2 == 1) {
                    return max(A_left_max, B_left_max); 
                }
                else {
                    return (max(A_left_max, B_left_max) + min(A_right_min, B_right_min)) / 2.0;
                }
            }
            else if(A_left_max > B_right_min)
            {
                right = i - 1;
            }
            else
            {
                left = i + 1;
            }
        }

        return 0.0;
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

    //归并排序法：归并过程：将两个已排序数组合并为一个有序数组。
    double findMedianSortedArraysByMergeSort(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        int total = m + n;
        int half = total / 2;

        int i = 0, j = 0;
        int prev = 0, curr = 0; // prev: 前一个数，curr: 当前数

        // 只需要遍历到第 half + 1 个元素（0-based 到 half）
        for (int k = 0; k <= half; ++k)
        {
            prev = curr;

            if (i < m && (j >= n || nums1[i] <= nums2[j]))
            {
                curr = nums1[i];
                ++i;
            }
            else {
                curr = nums2[j];
                ++j;
            }

        }


        if (total % 2 == 1) {
            // 奇数：中位数是第 half 个（0-based）
            return curr;
        }
        else {
            // 偶数：中位数是 (prev + curr) / 2.0
            return (prev + curr) / 2.0;
        }
    
    }
};



int main()
{
    Solution solution;
    vector<int> num1 = { 1,3};
    vector<int> num2 = { 2,4,5,6,7,8,9,10,11,12};

    cout << "\n中位数是：" << solution.findMedianSortedArrays(num1, num2);
    cout << "\n中位数是：" << solution.findMedianSortedArraysByMergeSort(num1, num2);
	return 0;
}