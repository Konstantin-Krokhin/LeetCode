class Solution {
public:
    int countSeniors(vector<string>& details)
    {
        int age, numOfMore60Y = 0;
        for (int i = 0; i < details.size(); i++)
        {
            age = 0;
            for (int j = 11; j < details[i].size() - 2; j++)
            {
                if (j == 11) age += details[i][j] - '0';
                else if (j == 12) age = age * 10 + details[i][j] - '0';
            }
            if (age > 60)
                numOfMore60Y++;
        }

        return numOfMore60Y;
    }
};