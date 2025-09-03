# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def get_len(self, l: ListNode) -> int:
        size = 0
        while l:
            size += 1
            l = l.next
            
        return size
        
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        res_list = ListNode()
        cur = res_list
        one_over = 0
        
        if self.get_len(l1) > self.get_len(l2):
            big_list = l1
            small_list = l2
        else:
            big_list = l2
            small_list = l1
            
        while big_list:
            if small_list:
                small_l_val = small_list.val
            if small_l_val + big_list.val + one_over < 10:
                cur.next = ListNode(small_l_val + big_list.val + one_over)
                cur = cur.next
                one_over = 0
            else:
                cur.next = ListNode((small_l_val + big_list.val + one_over) % 10)
                cur = cur.next
                one_over = 1
                
            big_list = big_list.next
            if small_list:
                small_list = small_list.next
            if not small_list:
                small_l_val = 0
        if one_over:
            cur.next = ListNode(one_over)
            cur = cur.next
            
        return res_list.next
        