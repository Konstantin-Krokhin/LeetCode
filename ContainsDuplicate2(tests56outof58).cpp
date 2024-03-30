
// Solution 56 out of 58 test
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k)
    {
        int i = 0, j = 0, l = 0, size = nums.size();
        while(j < size)
        {
            while(i < size)
            {
                printf("i = %i j = %i\n", i, j);
                if (abs(i - j) > k)
                {
                    break;
                }

                if (i != j && nums[i] == nums[j])
                {
                    return true;
                }
                i++;
            }
            if (size > k && i > k) i -= 2;
            j++;
        }
        return false;
    }
};