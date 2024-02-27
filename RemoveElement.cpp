class Solution {
public:
    int removeElement(vector<int>& nums, int val)
    {
        vector<int> res(100);
        int j = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] != val)
            {
                res[j] = nums[i];
                j++;
            }   
        }

        nums = res;
        return j;
    //Second solution (more complicated)
    //     int stop;
    //     int k = 0;
    //     for (int i = 0; i < nums.size(); i++)
    //     {
    //         if (nums[i] == val)
    //         {
    //             if (i + 1 == nums.size())
    //             {
    //                 nums[i] = NULL;
    //                 break;
    //             }
    //             stop = i;
    //             for (; i < nums.size()-2; i++)
    //             {
    //                 nums[i] = nums[i+1];
    //             }
    //             if (stop - 1 > 0)
    //                 i = stop - 1;
    //             else
    //                 i = 0;
    //         }
    //         else
    //             k++;
    //     }
    //     printf("%d", k);
    //     return k;
    }
};