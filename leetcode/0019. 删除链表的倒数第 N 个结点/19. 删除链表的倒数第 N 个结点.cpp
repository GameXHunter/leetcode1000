/**
* 给你一个链表，删除链表的倒数第 n 个结点，并且返回链表的头结点。
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode() : val(0), next(nullptr) {}
*     ListNode(int x) : val(x), next(nullptr) {}
*     ListNode(int x, ListNode *next) : val(x), next(next) {}
* };
* 
* 
*/

#include <vector>
#include <iostream>
using namespace std;

struct ListNode {
    int val;    //当前节点储存的整数值
    ListNode* next; //指向下一个节点的指针（nullptr表示链表结束）

    // 默认构造函数：val=0, next=nullptr
    ListNode() : val(0), next(nullptr) {}

    // 构造函数：给定值 x，next 默认为 nullptr
    ListNode(int x) : val(x), next(nullptr) {}

    // 构造函数：给定值 x 和下一个节点指针
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:

    //使用双指针（快慢指针）技巧。
    /**
        创建一个虚拟头节点（dummy node），指向原链表的头。这样可以统一处理删除头节点的情况。
        使用两个指针：fast 和 slow，都从 dummy 开始。
        先让 fast 指针向前走 n 步。
        然后 fast 和 slow 同时向前移动，直到 fast->next == nullptr。此时 slow 指向的是要删除节点的前一个节点。
        执行删除操作：slow->next = slow->next->next;
        返回 dummy->next 作为新的头节点。
    **/
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        //创建虚拟头节点

        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        
        ListNode* fast = dummy;
        ListNode* slow = dummy;

        //fast 先走n+1 步
        for (int i = 0; i <= n; ++i)
        {
            fast = fast->next;
        }

        // fast 和 slow 同时前进，直到 fast 为 nullptr
        while (fast != nullptr)
        {
            fast = fast->next;
            slow = slow->next;
        }
        
        // 删除倒数第 n 个节点
        ListNode* toDelete = slow->next;
        slow->next = slow->next->next;
        delete toDelete;

        ListNode* newHead = dummy->next;
        delete dummy;
        return newHead;

    }
};

//创建链表（从数组）
ListNode* createList(const vector<int>& vals)
{
    if (vals.empty()) return nullptr;

    ListNode* head = new ListNode(vals[0]);

    ListNode* curr = head;
    for (int i = 1; i < vals.size(); ++i)
    {
        curr->next = new ListNode(vals[i]);
        curr = curr->next;
    }
    return head;

}
// 辅助函数：打印链表
void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val;
        if (head->next != nullptr) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

//释放链表内存
void deleteList(ListNode* head)
{
    while (head != nullptr)
    {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }
}


int main()
{
    vector<int> vals = { 1, 2, 3, 4, 5 };
    ListNode* head = createList(vals);

    cout << "原始链表: ";
    printList(head);

    Solution sol;
    int n = 2;
    head = sol.removeNthFromEnd(head, n);

    cout << "删除倒数第 " << n << " 个节点后: ";
    printList(head);

    // 释放内存
    deleteList(head);

    return 0;
}