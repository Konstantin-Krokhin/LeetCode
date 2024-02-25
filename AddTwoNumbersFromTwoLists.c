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
    /*struct ListNode* createNode()
    {
        struct ListNode* temp;
        temp = (struct ListNode*)malloc(sizeof(struct ListNode));
        temp->next = NULL;
        return temp;
    }*/

    struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2)
    {
        struct ListNode *head1;
        struct ListNode *next1;
        struct ListNode *head2;
        struct ListNode *next2;
        struct ListNode *res;
        struct ListNode *resHead = new ListNode();
        res = resHead;
        head1 = l1;
        next1 = l1->next;
        head2 = l2;
        next2 = l2->next;
        int num;
        int increase_by_one = 0;
        int val1 = 0;
        int val2 = 0;
        int flag1 = -1;
        int flag2 = -1;
        
        while (head1 != NULL && head2 != NULL)
        {
            num = head1->val + head2->val + increase_by_one;
            if(num > 9)
            {
                res->val = num % 10;
                increase_by_one = 1;
            }
            else
            {
                res->val = num;
                increase_by_one = 0;
            }
            head1 = next1;
            if (next1 != NULL) next1 = next1->next;
            else
            {
                head2 = next2;
                if (next2 != NULL) next2 = next2->next;
                break;
            }
            head2 = next2;
            if (next2 != NULL) next2 = next2->next;
            else break;
            res->next = new ListNode();
            res = res->next;
        }
        while (head1 != NULL || head2 != NULL)
        {
            res->next = new ListNode();
            res = res->next;
            if (flag1 != 0 && head1 != NULL) val1 = head1->val;
            if (flag2 != 0 && head2 != NULL) val2 = head2->val;
            num = val1 + val2 + increase_by_one;
            if(num > 9)
            {
                res->val = num % 10;
                increase_by_one = 1;
            }
            else
            {
                res->val = num;
                increase_by_one = 0;
            }
            head1 = next1;
            if (next1 != NULL) next1 = next1->next;
            else flag1 = 0;
            head2 = next2;
            if (next2 != NULL) next2 = next2->next;
            else flag2 = 0;
            if (head1 == NULL && head2 == NULL && increase_by_one == 1)
            {
                res->next = new ListNode();
                res = res->next;
                res->val = 1;
                increase_by_one = 0;
            }
        }
        if (increase_by_one == 1)
        {
            res->next = new ListNode();
            res = res->next;
            res->val = 1;
        }

        return resHead;
    }
};