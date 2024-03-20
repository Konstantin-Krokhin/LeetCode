class Solution {
public:
    int strStr(string haystack, string needle)
    {
        int i = 0, j = 0, index = -1;

        if (needle.size() > haystack.size())
            return index;
        while (j < needle.size() && i < haystack.size())
        {
            if (haystack[i] == needle[j])
            {
                if (j == 0)
                    index = i;
                if (j >= needle.size()-1)
                    return index;
                j++;
            }
            else if (index > -1)
            {
                j = 0;
                i = index;
                index = -1;
            }
            i++;
        }

        return -1;
    }
};