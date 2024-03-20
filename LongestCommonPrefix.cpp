class Solution {
public:
    string longestCommonPrefix(vector<string>& strs)
    {
        int i = 0, j = 0, num_of_equal = 0, len = 0;
        char common_pref[1000] = "";

        while (j < strs[0].size())
        {
            num_of_equal = 0;
            i = 0;
            while(i < strs.size()-1)
            {
                if (j < strs[i].size() && j < strs[i+1].size())
                    if (strs[i][j] == strs[i+1][j])
                        num_of_equal++;
                i++;
            }
            if (num_of_equal == strs.size()-1)
                common_pref[len++] = strs[i][j];
            else
                break;
            j++;
        }

        return common_pref;
    }
};