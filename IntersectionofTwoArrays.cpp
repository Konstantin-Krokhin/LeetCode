class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2)
    {
        // res is the first intersection with repeating digits, res2 is without
        vector<int> res {};
        vector<int> res2 {};
        vector<int> n2;
        vector<int> n1;
        int numSize1 = (int)((int)nums1.size());
        int numSize2 = (int)((int)nums2.size());
        int i = 0, j = 0, k = 0, flag = 0;;

        // Check which of the vectors is the smallest, to use as a needle for haystack
        if (numSize1 > numSize2)
        {
            i = numSize2;
            j = numSize1;
            n2 = nums2;
            n1 = nums1;
        }
        else
        {
            i = numSize1;
            j = numSize2;
            n2 = nums1;
            n1 = nums2;
        }
        i--;
        j--;

        // Search through every sequence of digits from needle vector inside the haystack vector
        while (i >= 0)
        {
            for (int l = j; l >= 0; l--)
            {
                if (l < 0 || i < 0)
                    break;
                if (n2[i] == n1[l])
                {
                    res.insert(res.begin(), n2[i]);
                    k++;
                    i--;
                    flag = 1;
                }
            }
            if (flag == 0)
                i--;
            else
                flag = 0;
        }
        flag = 0;
        
        // Clean the final vector from repetition
        for (int i = 0; i < res.size(); i++)
        {
            for (int j = i + 1; j < res.size(); j++)
            {
                if (res[i] == res[j])
                {
                    flag = 1;
                    break;
                }
            }
            if (flag == 1)
            {
                flag = 0;
                continue;
            }
            res2.insert(res2.begin(), res[i]);
        }
        return res2;
    }
        
};