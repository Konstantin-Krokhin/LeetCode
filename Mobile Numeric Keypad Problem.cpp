class Solution {
public:
    int minimumPushes(string word)
    {
        char *alphas[8] = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        int n, i = 0, clicks = 1, k = 0;

        while (word[i] != '\0')
        {
            n = 0;
            while(n < 8)
            {
                if (word[i] == alphas[n][k])
                    break;
                k++;
                if (k >= strlen(alphas[n])-1) 
                {
                    k = 0;
                    n++;
                }
            }
            for (int j = 0; n < 8 && j < strlen(alphas[n]); j++)
            {
                if (alphas[n][j] == word[i])
                    break;
                clicks++;
            }
            i++;
        }

        return clicks;
        
    }
};