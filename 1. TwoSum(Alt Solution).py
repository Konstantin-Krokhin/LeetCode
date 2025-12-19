class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        for i in range(len(nums)):
            complementary = target - nums[i]
            try:
                j = nums.index(complementary, i + 1)
                return [i, j]
            except ValueError:
                continue