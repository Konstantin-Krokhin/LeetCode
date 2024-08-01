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
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2)
    {
        ListNode *head = list1, *prev, *buf1;
        bool ifEnd = false;
        ListNode* b = list1;

        if (list1 == nullptr)
        {
            if (list2 == nullptr)
                return list1;
            else
                return list2;
        }
        else if (list2 == nullptr)
            return list1;
        while (b->next != nullptr)
            b = b->next;
        
        cout << b->val << endl;
        b->next = list2;
        while (ifEnd == false)
        {
            ifEnd = true;
            ListNode *p = head;
            ListNode *prev = nullptr;
            while(p && p->next)
            {
                if (p->val > (p->next)->val)
                {
                    ifEnd = false;
                    buf1 = p->next;
                    p->next = buf1->next;
                    buf1->next = p;
                    
                    if (prev)
                    {
                        prev->next = buf1;
                    }
                    else
                    {
                        head = buf1;
                    }
                    prev = buf1;
                }
                else
                {
                    prev = p;
                    p = p->next;
                }
            }
        }

        return head;
    }
};