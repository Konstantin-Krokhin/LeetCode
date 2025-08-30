# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def dfs(self, node, targetSum):
        if node == None:
            return False
        if node.left == None and node.right == None:
            return targetSum == node.val

        targetSum -= node.val

        return self.dfs(node.left, targetSum) or self.dfs(node.right, targetSum)

    def hasPathSum(self, root: Optional[TreeNode], targetSum: int) -> bool:
        curr_node = root
        curr_sum = 0

        return self.dfs(root, targetSum)
        #while curr_node.left != None and curr_node.right != None:
        #    curr_sum += curr_node.val

        '''if targetSum == curr_sum:
            return True
        else
            return False
        '''