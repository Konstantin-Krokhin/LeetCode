class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c)
    {
        int i = 0, j = 0, k = 0, m = 0;
        std::vector<std::vector<int>> res(r, std::vector<int>(c));

        if (r * c != mat.size() * mat[0].size())
            return mat;

        while (k < mat.size())
        {
            while (m < mat[0].size())
            {
                if (i < r && j < c)
                    res[i][j] = mat[k][m];
                else if (i > r - 1)
                    return res;
                if (j > c - 1)
                {
                    i++;
                    j = 0;
                }
                else
                {
                    j++;
                    m++;
                }
            }
            k++;
            m = 0;
        }
        return res;
    }
};