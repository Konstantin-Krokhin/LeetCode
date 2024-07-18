class Solution {
public:
    int missingNumber(vector<int>& nums)
    {
        int numsSize = nums.size(), j, flag = 0;
        for (int i = 0; i <= numsSize; i++)
        {
            j = 0;
            while (j < numsSize)
            {
                if (nums[j] == i)
                    flag = 1;
                j++;
            }
            if (flag == 0)
                return i;
            flag = 0;
        }
        return i;
    }
};