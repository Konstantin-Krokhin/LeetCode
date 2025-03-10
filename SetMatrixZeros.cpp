class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix)
    {
        unordered_set<int> rows;
        unordered_set<int> columns;

        for (int i = 0; i < matrix.size(); i++)
        {
            for (int j = 0; j < matrix[0].size(); j++)
            {
                if (matrix[i][j] == 0)
                {
                    rows.insert(i);
                    columns.insert(j);
                }
            }
        }

        for (int row : rows)
        {
            for (int j = 0; j < matrix[0].size(); j++)
            {
                matrix[row][j] = 0;
            }
        }

        for (int column : columns)
        {
            for (int j = 0; j < matrix.size(); j++)
            {
                matrix[j][column] = 0;
            }
        }
    }
};