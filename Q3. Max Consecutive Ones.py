class Solution:
    def findMaxConsecutiveOnes(self, nums: List[int]) -> int:
        max_consecutive = 0
        curr_iteration = 0
        for i in range(0, len(nums)):
            if nums[i] == 1:
                curr_iteration += 1
            else:
                if curr_iteration > max_consecutive:
                    max_consecutive = curr_iteration
                curr_iteration = 0
        if curr_iteration > max_consecutive:
                    max_consecutive = curr_iteration
        
        return max_consecutive
        