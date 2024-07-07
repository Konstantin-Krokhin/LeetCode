class Solution {
public:
    vector<int> plusOne(vector<int>& digits)
    {
        int dig_size = digits.size();
        for (int i = 0; i < dig_size; i++)
        {
            if (i == 0) dig_size -=1;
            if (dig_size - i < 0) break;
            if (digits[dig_size - i] < 9)
            {
                digits[dig_size - i]++;
                break;
            }
            else if (dig_size-i == 0)
            {
                digits[dig_size - i] = 1;
                digits.insert(digits.end(), 0);
            }
            else
            {
                digits[dig_size - i] = 0;
                if (dig_size - i - 1 >= 0 && digits[dig_size - i - 1] > 8)
                {
                    for (int j = dig_size - i - 1; j >= 0; j--)
                    {
                        if (digits[j] == 9 && j > 0)
                            digits[j] = 0;
                        else if (digits[j] == 9 && j == 0)
                        {
                            digits[j] = 1;
                            digits.insert(digits.end(), 0);
                            return digits;
                        }
                        else if (j == 0 || digits[j] < 9)
                        {
                            digits[j]++;
                            return digits;
                        }
                    }
                }
                else if (dig_size - i - 1 >= 0)
                {
                    digits[dig_size - i - 1]++;
                    break;
                }
            }
        }
        return digits;
    }
};