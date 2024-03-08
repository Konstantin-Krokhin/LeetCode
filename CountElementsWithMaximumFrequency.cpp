class Solution {
public:
    int maxFrequencyElements(vector<int>& nums)
    {
        int nums100[101];
        int nums100count[101];
        int nums100countMax = 0;
        int freqOfOccur = 0;

        for (int i = 0; i <= 100; i++)
            nums100[i] = i;
        for (int i = 0; i <= 100; i++)
            nums100count[i] = 0;

        for (int i = 0, k = 0; i <= 100; i++)
        {
            for (int j = 0; j < nums.size(); j++)
            {
                if (nums[j] == i)
                {
                    nums100[i] = ++nums100[i];
                }
            }
            if (nums100[i] > i)
            {
                nums100count[k] = nums100[i] - i;
                if (nums100count[k] > nums100countMax)
                    nums100countMax = nums100count[k];
                k++;
            }
        }
        for (int i = 0; nums100count[i] != 0; i++)
        {
            if (nums100count[i] == nums100countMax)
                freqOfOccur += nums100countMax;
        }

        return freqOfOccur;
    }
};