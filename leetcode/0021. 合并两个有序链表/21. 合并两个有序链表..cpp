/**
* 
* 将两个升序链表合并为一个新的 升序 链表并返回。
新链表是通过拼接给定的两个链表的所有节点组成的。 

 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
#include<vector>
#include "../Utils/Utils.h"



class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        //创建一个虚拟头节点，方便处理边界情况。
        ListNode dummy(0);
        ListNode* tail = &dummy;

        //双指针遍历两个链表
        while (list1 != nullptr && list2 != nullptr)
        {
            if (list1->val <= list2->val)
            {
                tail->next = list1;
                list1 = list1->next;
            }
            else {
                tail->next = list2;
                list2 = list2->next;
            }
            tail = tail->next;
        }
        // 将剩余非空链表接上
        tail->next = (list1 != nullptr) ? list1 : list2;

        return dummy.next;
    }
};



int main()
{
    Solution sol;
   std::vector<int> vec1 = { 1,2,4};
   std::vector<int> vec2= { 1,3,4 };
   ListNode* list1 = Utils::createList(vec1);
   ListNode* list2 = Utils::createList(vec2);

   Utils::print_list(list1);
   Utils::print_list(list2);

   ListNode* list3 = sol.mergeTwoLists(list1, list2);
   Utils::print_list(list3);

    return 0;
}