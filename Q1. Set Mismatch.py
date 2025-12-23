class Solution:
    def findErrorNums(self, nums: List[int]) -> List[int]:
        nums.sort()
        dupl = -1
        miss = -1

        expected = 1

        for i in range(len(nums)):
            if i != 0 and nums[i] == nums[i-1]:
                dupl = nums[i]
            else:
                if nums[i] != expected:
                    miss = expected
                    expected = nums[i]
                expected += 1
        
        if miss == -1:
            miss = expected
        return [dupl, miss]
