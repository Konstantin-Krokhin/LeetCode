class Solution:
	def reverse(self, x: int) -> int:
		temp = x.__str__()
		s = list(temp)
		i = 0
		j = len(s) - 1
		buf = 0
		
		while i < j:
			if s[i] == '-':
				i += 1
				continue
			buf = s[i]
			s[i] = s[j]
			s[j] = buf
			i += 1
			j -= 1
		
		rev_num = int(''.join(s))
		if (rev_num > 2147483647 or rev_num < -2147483648):
			return 0
		return rev_num