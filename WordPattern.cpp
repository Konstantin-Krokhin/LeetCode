class Solution {
public:
    bool wordPattern(string pattern, string s)
    {
        std::map<char, string> encounteredAlpha = {};
        int i = 0, j = 0, i_s = 0, flag = 0, wrd_cnt = 0;
        string s_word, prev_word;

        while(pattern[i] != '\0')
        {
            // If not found a pattern in our map of already met patterns then add new pattern where key is a pattern letter (i.e. 'a') and a value is a word (i.e. 'dog')
            if (encounteredAlpha.find(pattern[i]) == encounteredAlpha.end())
            {
                while (s[i_s] != ' ' && s[i_s] != '\0')
                {
                    s_word += s[i_s];
                    i_s++;
                }
                if (s[i_s] == ' ')
                    i_s++;
                encounteredAlpha.insert(pair<char, string>(pattern[i], s_word));
                s_word = "";
            }
            else
            {
                while (s[i_s] != ' ' && s[i_s] != '\0')
                    i_s++;
                if (s[i_s] == ' ')
                    i_s++;
            }
            i++;
        }

        string duplicate;
        auto t = encounteredAlpha.cbegin();
        int u = 0;
        while (t != encounteredAlpha.cend())
        {
            duplicate = t->second;
            for(auto it = encounteredAlpha.cbegin(); it != encounteredAlpha.cend(); ++it)
                if (duplicate == it->second)
                    u++;
            
            if (u > 1)
                return false;
            u = 0;
            ++t;
        }

        i = 0, i_s = 0;
        while(pattern[i] != '\0')
        {
            while (s[i_s] != ' ' && s[i_s] != '\0')
            {
                s_word += s[i_s];
                i_s++;
            }
            if (s[i_s] == ' ')
            {
                wrd_cnt++;
                i_s++;
            }
            auto it = encounteredAlpha.begin();
            std::advance(it, distance(encounteredAlpha.begin(),encounteredAlpha.find(pattern[i])));
            if (s_word != it->second)
                return false;
            s_word = "";
            i++;
        }

        if (wrd_cnt + 1 != i)
            return false;
        
        return true;
    }
};