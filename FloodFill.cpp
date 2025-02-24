class Solution {
public:
    void dfs(vector<vector<int>>& image, int i, int j, int pattern, int color)
    {
        if (i < 0 || i > image.size() - 1 || j < 0 || j > image[i].size() - 1 || image[i][j] != pattern)
        return;

        image[i][j] = color;

        dfs(image, i + 1, j, pattern, color);
        dfs(image, i - 1, j, pattern, color);
        dfs(image, i, j + 1, pattern, color);
        dfs(image, i, j - 1, pattern, color);
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color)
    {
        int pattern = image[sr][sc];

        if (pattern == color) return image;

        dfs(image, sr, sc, pattern, color);

        return image;
    }
};


// OLD brute force solution
// class Solution {
// public:
//     vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color)
//     {
//         int i = sr, j = sc, pattern = image[i][j], k = 0;
//         bool mv_lf, mv_rt, sides = false;

//         if (image[i][j] == color) return image;

//         while (i < image.size())
//         {
//             j = sc;
//             k = j;
//             mv_lf = true;
//             mv_rt = true;
//             if (image[i][j] == pattern) image[i][j] = color;
//             if (j > 0) j--;
//             if (k < image[i].size() - 1) k++;
//             while (j >= 0 || k <= image[i].size() - 1)
//             {
//                 if (j >= 0 && image[i][j] == pattern && mv_lf == true)
//                 {
//                     if (sides == false || image[sr][j] == color || image[i][sc] == color)
//                         image[i][j] = color;
//                     else
//                         mv_lf = false;
//                 } 
//                 else
//                     mv_lf = false;

//                 if (k <= image[i].size() - 1 && image[i][k] == pattern && mv_rt == true)
//                     if (sides == false || image[sr][k] == color || image[i][sc] == color)
//                         image[i][k] = color;
//                     else
//                         mv_rt = false;
//                 else if (mv_rt == false && image[sr][k] == color)
//                 {
//                     printf(" HERE ");
//                     image[i][k] = color;
//                 }
//                 else
//                     mv_rt = false;
//                 printf("!! %d %d %d", j, k, i);
//                 j--;
//                 k++;
//             }
//             sides = true;
//             if (i > 0 && i <= sr) i--;
//             else if (i > sr) i++;
//             else if (i == 0) i = sr + 1;
//         }

//         return image;
//     }
// };