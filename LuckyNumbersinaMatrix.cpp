class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix)
    {
        int minRow, j_minRow;
        vector <int>luckyNum;
        vector <int> minRowMap;
        minRowMap.push_back(0);
        
        for (int i = 0; i < matrix.size(); i++)
        {
            minRow = INT_MAX;
            for (int j = 0; j < matrix[i].size(); j++)
            {
                if (matrix[i][j] < minRow)
                {
                    minRow = matrix[i][j];
                    j_minRow = j;
                }
            }
            if (minRowMap.at(0) < minRow) minRowMap.at(0) = minRow;
            minRow = INT_MAX;
        }

        for (int i = 0; i < matrix.size(); i++)
        {
            if (matrix[i][j_minRow] > minRowMap.at(0))
                return luckyNum;
        }

        return minRowMap;
    }
};