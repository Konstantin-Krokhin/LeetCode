class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n)
    {
        int i = 0;
        int j = 0;
        int num1_len = m;
        for (;j < n; j++)
        {
            nums1[num1_len] = nums2[j];
            num1_len++;
        }

        int flag = 0;
        int a = 0;
        while (flag < m+n-1)
        {
            for(i = 0; i < m+n-1; i++)
            {
                if (nums1[i] > nums1[i+1])
                {
                    a = nums1[i];
                    nums1[i] = nums1[i+1];
                    nums1[i+1] = a;
                    flag = 0;
                }
                else
                    flag++;
            }
        }
    }
};
