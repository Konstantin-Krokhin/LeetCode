class Solution {
public:
    int heightChecker(vector<int>& heights)
    {
        vector<int> heights2 = heights;
        bool sorted = false;
        int buf = 0, instances = 0;
        while (sorted == false)
        {
            sorted = true;
            for (int i = 0; i < heights2.size()-1; i++)
            {
                
                if (heights2[i] > heights2[i+1])
                {
                    sorted = false;
                    buf = heights2[i];
                    heights2[i] = heights2[i+1];
                    heights2[i+1] = buf;
                }
            }
        }
        
        for (int i = 0; i < heights.size(); i++)
            if (heights[i] != heights2[i])
                instances++;
        return instances;
    }
};