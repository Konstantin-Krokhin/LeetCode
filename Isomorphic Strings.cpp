class Solution {
public:
    bool isIsomorphic(string s, string t)
    {
        map <char, char>l;
        map <char, char>l2;

        if (s.size() != t.size())
            false;
        for (int i = 0; i < s.size(); i++)
        {
            if (l.find(s[i]) == l.end() && l2.find(t[i]) == l2.end())
            {
                l.insert({s[i], t[i]});
                l2.insert({t[i], s[i]});
            }
            else
            {
                auto it = l.find(s[i]);
                auto it2 = l2.find(t[i]);
                if(it != l.end() && t[i] != it->second)
                    return false;
                if(it2 != l2.end() && s[i] != it2->second)
                    return false;
            }
        }
        return true;
    }
};