class Solution:
    def countOdds(self, low: int, high: int) -> int:
        odd_count = 0
        if low % 2 == 1 or high % 2 == 1:
            odd_count += 1
        odd_count += (high - low) // 2
        
        return odd_count
        
# Too slow for big sets
# for i in range(low, high + 1):
#     if i % 2 == 1:
#         odd_count += 1