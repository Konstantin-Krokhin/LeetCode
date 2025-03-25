class Solution {
public:
    int lengthOfLongestSubstring(string s)
    {
        int left = 0, right = 0, setLength = 0;
        unordered_set<char> subSet;

        while (right < s.size())
        {
            if (subSet.find(s[right]) == subSet.end())
            {
                subSet.insert(s[right]);
                setLength = max(setLength, right - left + 1);
                right++;
            }
            else
            {
                subSet.erase(s[left]);
                left++;
            }
        }
        return setLength;
        
    }
};