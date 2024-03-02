class Solution {
public:
    int majorityElement(vector<int>& nums)
    {
        int i = 1;
        int n = nums.size();
        int majority = 0;
        int numOfRepetition = 1;
        int j = 0;
        //vector<int> numUnique;

        while (1)
        {
            majority = nums[j];
            while (i < n)
            {
                //if (find(nums.begin(), nums.end(), nums[i]) != nums.end())
                if (nums[i] == majority)
                    numOfRepetition++;
                i++;
            }
            if (numOfRepetition > n / 2)
                return majority;
            if (j < n-1)
            {
                j++;
                i = 0;
                numOfRepetition = 0;
            }
            else
                break;
        }
        return majority;
    }
};