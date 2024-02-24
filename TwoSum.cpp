class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target)
    {
        vector<int> res{};
        int j = 0;
        while (res.empty())
        {
            for (int i = 0; i < nums.size() - 1; i++)
            {
                if (j != i && nums[j] + nums[i] == target)
                    return (res = {j, i});
            }
            j++;
        }
        return res;
    }
};