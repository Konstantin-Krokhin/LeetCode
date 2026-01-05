class Solution:
    def findDisappearedNumbers(self, nums: List[int]) -> List[int]:
        unique_nums = set(nums)
        res = []

        for i in range(1, len(nums) + 1):
            if i not in unique_nums:
                res.append(i)
        return res