class Solution:
    def findDuplicate(self, nums: List[int]) -> int:
        seen = set()
        duplicates = set()

        for i in range(len(nums)):
            if nums[i] in seen:
                duplicates.add(nums[i])
            else:
                seen.add(nums[i])
        return list(duplicates)[0]
        