class Solution:
    def findDisappearedNumbers(self, nums: List[int]) -> List[int]:
        sorted_nums = sorted(nums)
        missing_nums = {}
        j = 0

        for i, num in enumerate(sorted_nums):
            print(num, i)
            if i - num > 1:
                missing_nums[j] = num
                j += 1
        return missing_nums