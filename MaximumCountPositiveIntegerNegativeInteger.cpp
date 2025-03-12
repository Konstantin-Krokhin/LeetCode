class Solution {
public:
    int maximumCount(vector<int>& nums)
    {
        int neg = 0, pos = 0, i = 0;
        
        while (i < nums.size())
        {
            if (nums[i] < 0)
                neg++;
            else if (nums[i] > 0)
                pos++;
            i++;
        }
        if (neg > pos)
            return neg;
        else
            return pos;
    }
};