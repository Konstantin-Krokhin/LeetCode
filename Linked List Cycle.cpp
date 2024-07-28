/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head)
    {
        vector <int> prevs;
        int i = 0, n = 0;
        
        for (auto p = head; p; p = p->next)
        {
            if (std::find(std::begin(prevs), std::end(prevs), p->val) != std::end(prevs))
                n++;
            else
                n = 0;
            prevs.insert(prevs.begin(), p->val);
            if (n >= 10)
                return true;
        }
        return false;
    }
};