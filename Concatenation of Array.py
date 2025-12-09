class Solution:
    def getConcatenation(self, nums: List[int]) -> List[int]:
        ans: List[int] = []
        n = 0
        for _ in range(0, 2):
            for i in range(0, len(nums)):
                ans.append(nums[i])
            n = len(nums)
        
        return ans
        # OR
        # return nums + nums