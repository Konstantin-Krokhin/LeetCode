class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums)
    {
        int num_size = nums.size(), i = 0, j, product, prefix = 1, suffix = 1;
        vector<int> answer(num_size, 1);
        unordered_map<int, int> prefixSumMap;

        for (int i = 0; i < num_size; i++)
        {
            answer[i] = prefix;
            prefix *= nums[i];
        }

        for (int i = num_size - 1; i >= 0; i--)
        {
            answer[i] *= suffix;
            suffix *= nums[i];
        }

        return answer;
    }
};


// class Solution {
// public:
//     vector<int> productExceptSelf(vector<int>& nums)
//     {
//         int num_size = nums.size(), i = 0, j, product;
//         vector<int> answer(num_size, 1);

//         while (i < num_size)
//         {
//             j = 0;
//             product = 1;
//             while (j < num_size)
//             {
//                 if (j == i)
//                 {
//                     j++;
//                     continue;
//                 }

//                 product *= nums[j];
//                 j++;
//             }
//             answer[i] = product;
//             i++;
//         }

//         return answer;
//     }
// };