class Solution:
    def smallerNumbersThanCurrent(self, nums: List[int]) -> List[int]:

        sorted_nums = sorted(nums)

        smaller_nums = {}

        for i, num in enumerate(sorted_nums):
            if num not in smaller_nums:
                smaller_nums[num] = i
        
        return [smaller_nums[num] for num in nums]
        