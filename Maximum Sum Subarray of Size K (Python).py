class Solution:
    def subarraySum(self, nums: List[int], k: int) -> int:
        arrSum = 0
        subArrAmount = 0
        hash_map_sums = {0 : 1}

        for i in range(len(nums)):
            arrSum += nums[i]
            if arrSum - k in hash_map_sums:
                subArrAmount += hash_map_sums[arrSum - k]
            hash_map_sums[arrSum] = hash_map_sums.get(arrSum, 0) + 1
        return subArrAmount


'''
pref_sum = {}
runningSum = 0
subarr_num = 0

for i, item in enumerate(nums):
    runningSum += item
    pref_sum[i] = runningSum
    if k == runningSum:
        subarr_num += 1

i = 0
for i in range(len(pref_sum)):
    j = i + 1
    while j < len(pref_sum):
        if pref_sum[j] - pref_sum[i] == k:
            subarr_num += 1
        j += 1
return subarr_nu'
'''