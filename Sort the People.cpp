class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights)
    {
        int buf;
        string s_buf;
        bool found = true;

        while (found == true)
        {
            found = false;
            for (int i = 0; i < names.size()-1; i++)
            {
                if (heights[i] < heights[i+1])
                {
                    found = true;
                    buf = heights[i];
                    heights[i] = heights[i+1];
                    heights[i+1] = buf;

                    s_buf = names[i];
                    names[i] = names[i+1];
                    names[i+1] = s_buf;
                }
            }
        }
        for (int i = 0; i < names.size(); i++)
        {
            cout << names[i] << endl;
        }

        return names;
    }
};