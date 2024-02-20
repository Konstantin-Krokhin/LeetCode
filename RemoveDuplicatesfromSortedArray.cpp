class Solution {
public:
    int removeDuplicates(vector<int>& nums) 
    {
        int numLen = nums.size();
        int s[numLen];
        int j = 0;
        int i = 0;
        s[j] = nums[i];
        for (; i < numLen; i++)
        {
            if (nums[i] != s[j])
            {
                s[++j] = nums[i];
            }
        }
        j++;
        for (int k = 0; k < j; k++)
        {
            nums[k] = s[k];
        }
        return j;
    }
};