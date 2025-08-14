class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        if len(nums) == 0:
            return nums

        non_zero_len = len(nums)

        i = 0
        while i < non_zero_len:
            if nums[i] == 0:
                zero = nums.pop(i)
                nums.append(zero)
                non_zero_len -= 1
                i -= 1
            i += 1

        return nums
        