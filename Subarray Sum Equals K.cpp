class Solution {
public:

    int helper(vector<int>& nums, int k, int index, int currSum, unordered_map<int, int> &prefixSumMap)
    {
        if (index >= nums.size()) return 0;

        currSum += nums[index];

        // Count subarrays that sum up to k
        int count = (currSum == k) ? 1 : 0;

        // If (currSum - k) exists in map, add its count
        if (prefixSumMap.find(currSum - k) != prefixSumMap.end()) {
            count += prefixSumMap[currSum - k];
        }

        // Store the current prefix sum
        prefixSumMap[currSum]++;

        // Recur for the next index
        count += helper(nums, k, index + 1, currSum, prefixSumMap);

        // Backtrack: Remove current prefix sum before returning
        prefixSumMap[currSum]--;

        return count;
    }

    int subarraySum(vector<int>& nums, int k)
    {
        unordered_map<int, int> prefixSumMap;
        return helper(nums, k, 0, 0, prefixSumMap);
    }

    // int findRange(vector<int>& nums, int k, int sum, const int &index)
    // {
    //     if (index >= nums.size())
    //     {
    //         return 0;
    //     }

    //     sum += nums[index];
    //     int count = (sum == k)? 1 : 0;

    //     return count + findRange(nums, k, sum, index + 1);
    // }

    // int subarraySum(vector<int>& nums, int k)
    // {
    //     int total = 0, i = 0, index = 0;

    //     while (index < nums.size())
    //     {
    //         total += findRange(nums, k, 0, index);
    //         index++;
    //     }
        
    //     return total;
    // }
};