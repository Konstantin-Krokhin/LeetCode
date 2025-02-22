class Solution {
public:
    int pivotIndex(vector<int>& nums)
    {
        int i = 0, ls, rs, li, ri, end_l, end_r;

        while (i < nums.size())
        {
            ls = 0, rs = 0;
            li = 0, ri = 0;
            end_l = 0, end_r = 0;
            if (i != 0) li = i - 1;
            if (i != nums.size() - 1) ri = i + 1;
            else ri = nums.size() - 1;

            while (li >= -1 && ri <= nums.size())
            {
                if (li != -1 && i != 0)
                {
                    ls += nums[li];
                    li--;
                }
                else
                    end_l = 1;
                if (ri != nums.size() && i != nums.size() - 1)
                {
                    rs += nums[ri];
                    ri++;
                }
                else
                    end_r = 1;
                if (end_l == 1 && end_r == 1)
                    break;
            }
            if (ls == rs)
                return i;
            i++;
        }
        return -1;
    }
};