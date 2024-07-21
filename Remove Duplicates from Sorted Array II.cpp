class Solution {
public:
    int removeDuplicates(vector<int>& nums)
    {
        int rep = 0, curNum = INT_MIN, size = nums.size();

        for (int i = 0; i < size; ++i)
        {
            cout << "i = " << i << endl;
            if (curNum == nums[i])
                rep++;
            else
            {
                if (curNum != INT_MIN) rep = 0;
                curNum = nums[i];
            }

            if (rep >= 2)
            {
                size--;
                nums = removeAndShiftLeft(i, nums);
                --i;
                rep--;
            }
                
        }
        return size;
    }

    vector<int> removeAndShiftLeft(int j, vector<int> v)
    {
        for (int i = j; i < v.size() - 1; i++)
        {
            v[i] = v[i + 1];
        }

        return v;
    }
};