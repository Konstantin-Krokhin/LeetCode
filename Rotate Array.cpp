class Solution {
public:
    void rotate(vector<int>& nums, int k)
    {
        int buf, size = nums.size() - 1, j = 0;
        vector<int> nums2;

        k = k % nums.size();

        int start = nums.size() - k;
        for (int i = start; i < nums.size(); i++)
        {
            nums2.push_back(nums[i]);
            nums.erase(nums.begin() + i);
            i--;
            cout << nums[i] << endl;
            cout << nums2[j] << endl;
            j++;
        }
        nums.insert(nums.begin(), nums2.begin(), nums2.end());

        // Works but not for a set of 100 000 and more
        // for (int i = 0; i < k; i++)
        // {
        //     for (int j = size; j >= 0; j--)
        //     {
        //         if (j == size)
        //         {
        //             buf = nums[size];
        //             continue;
        //         }   
        //         else nums[j + 1] = nums[j];
        //         if (j == 0) nums[0] = buf;
        //     }
        // }
    }
};