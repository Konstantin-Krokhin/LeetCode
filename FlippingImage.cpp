class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image)
    {
        int i = 0, j, row_len = image[i].size(), k = row_len - 1, equializer = 0;

        if (row_len % 2 == 0) equializer = 1;

        while (i < image.size())
        {
            j = 0;
            k = row_len - 1;
            while (j < row_len / 2 && k > row_len / 2 - equializer)
            {
                swap(image, i, j, k);

                invert(image, i, j);
                invert(image, i, k);

                j++;
                k--;
            }
            if (equializer == 0) invert(image, i, j);
            i++;
        }
        return image;
    }

    void invert(vector<vector<int>>& image, int i, int j)
    {
        if (image[i][j] == 1)
            image[i][j] = 0;
        else
            image[i][j] = 1;
    }

    void swap(vector<vector<int>>& image, int i, int j, int k)
    {
        int buf = image[i][j];
        image[i][j] = image[i][k];
        image[i][k] = buf;
    }
};