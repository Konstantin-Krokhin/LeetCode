# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def inorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        results = []

        def dfs(node):
            if not node:
                return results
            dfs(node.left)
            results.append(node.val)
            dfs(node.right)
            return results

        return dfs(root)