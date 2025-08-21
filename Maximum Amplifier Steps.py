from collections import defaultdict
import sys
sys.setrecursionlimit(10**7)

def max_amplifier_steps(input1, input2, input3):
	
	max_steps = -1
	dp = [defaultdict(lambda: -1) for _ in range(input1)]

	def dfs(i, curr_product, steps, visited):
		nonlocal max_steps

		if curr_product == input3:
			max_steps = max(max_steps, steps)
			return

		if curr_product > input3 or input3 % curr_product != 0:
			return

		if dp[i][curr_product] >= steps:
			return
		dp[i][curr_product] = steps

		for idx in (-1, 1):
			ni = i + idx
			if 0 <= ni < input1 and ni not in visited:
				dfs(ni, curr_product * input2[ni], steps + 1, visited | {ni})

	for i in range(input1):
		dfs(i, 1, 0, visited = set())

	return max_steps

def main():
    # Test cases
    tests = [
        (5, [2, 3, 1, 2, 2], 12, 4),   # 1*2*3*2=12, max 3 steps
        (4, [2, 2, 2, 2], 8, 3),       # 1*2*2*2=8, 3 steps
        (3, [3, 5, 7], 105, 3),        # 1*3*5*7=105, 3 steps
        (3, [2, 3, 5], 7, -1),         # Impossible to reach 7
        (6, [1, 2, 3, 4, 5, 6], 24, 4) # 1*2*3*4=24, 3 steps
    ]

    for idx, (n, arr, target, expected) in enumerate(tests, 1):
        result = max_amplifier_steps(n, arr, target)
        print(f"Test {idx}: Expected {expected}, Got {result} - {'PASS' if result == expected else 'FAIL'}")

if __name__ == "__main__":
    main()