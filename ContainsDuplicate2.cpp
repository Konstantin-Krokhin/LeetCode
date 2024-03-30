#include <map>

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k)
    {
        map<int, int> hashmap;

        for (int i = 0; i < nums.size(); i++)
        {
            if (hashmap.count(nums[i]))
                if (i - hashmap[nums[i]] <= k)
                    return true;
            hashmap[nums[i]] = i;
        }
        return false;
    }
};