/*
给你两个 非空 的链表，表示两个非负的整数。它们每位数字都是按照 逆序 的方式存储的，并且每个节点只能存储 一位 数字。

请你将两个数相加，并以相同形式返回一个表示和的链表。

你可以假设除了数字 0 之外，这两个数都不会以 0 开头。给你两个 非空 的链表，表示两个非负的整数。它们每位数字都是按照 逆序 的方式存储的，并且每个节点只能存储 一位 数字。

请你将两个数相加，并以相同形式返回一个表示和的链表。

你可以假设除了数字 0 之外，这两个数都不会以 0 开头。
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

#include <vector>
#include <iostream>
using namespace std;
 struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
    
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode dummy(0); // 虚拟头节点，简化边界处理
        ListNode* curr = &dummy;
        int carry = 0;
        while (l1 != nullptr || l2 != nullptr || carry != 0)
        {
            int val1 = (l1 != nullptr) ? l1->val : 0;
            int val2 = (l2 != nullptr) ? l2->val : 0;

            int total = val1 + val2 + carry;

            carry = total / 10;
            int digit = total % 10;

            curr->next = new ListNode(digit);
            curr = curr->next;

            if (l1 != nullptr) l1 = l1->next;
            if (l2 != nullptr) l2 = l2->next;

        }
        return dummy.next;
    }
};

//错误，仅返回了list的最后的元素，而不是返回整个链表
ListNode* createList_error(const vector<int>& nums)
{
    ListNode* output = new ListNode(nums[0]);
    for (int i = 1; i < nums.size(); i++)
    {
        output->next = new ListNode(nums[i]);
        output = output->next;
    }
    return output;
}


ListNode* createList(const std::vector<int>& nums) {
    if (nums.empty()) return nullptr;
    ListNode* head = new ListNode(nums[0]);
    ListNode* curr = head;
    for (int i = 1; i < nums.size(); ++i) {
        curr->next = new ListNode(nums[i]);
        curr = curr->next;
    }
    return head;
}
void printList(ListNode* head)
{

    cout << "[";

    while (head != nullptr)
    {
        cout << head->val ;
        if (head->next != nullptr) std::cout << ",";

        head = head->next;
    }

    cout << "]";
}

int main()
{
    Solution listNode;
    ListNode* l1 = createList({9,9,9,9});
    ListNode* l2 = createList({ 9,9,9 });
    printList(l1);

    ListNode* result =  listNode.addTwoNumbers(l1, l2);
    printList(result);

    return 0;
}