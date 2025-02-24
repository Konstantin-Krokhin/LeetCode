class Solution {
public:
    int findCenter(vector<vector<int>>& edges)
    {
        int i = 0, j = 0, n = 0;

        while (i < edges.size() - 1)
        {
            n = edges[i][j];
            j = 0;
            if (n == edges[i+1][j] || n == edges[i+1][j+1])
                break;
            if (j > 0) i++;
            j++;
        }
        return n;
    }
};