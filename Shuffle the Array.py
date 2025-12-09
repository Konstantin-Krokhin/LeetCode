class Solution:
    def shuffle(self, nums: List[int], n: int) -> List[int]:
        res: List[int] = []
        i = 0
        j = n
        while j < (2 * n):
            res.append(nums[i])
            res.append(nums[j])
            i += 1
            j += 1

        return res
        