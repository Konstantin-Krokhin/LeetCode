class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix)
    {
        int mat_rows = matrix.size(), mat_columns = matrix[0].size(), i = 0, j, k = 0, m;
        vector<vector<int>> res_mat(mat_columns, vector<int>(mat_rows));

        while (i < mat_columns && k < mat_columns)
        {
            j = 0;
            m = 0;
            while (j < mat_rows && m < mat_rows)
            {
                res_mat[i][j] = matrix[m][k];
                j++;
                m++;
            }
            k++;
            i++;
        }

        return res_mat;
    }
};