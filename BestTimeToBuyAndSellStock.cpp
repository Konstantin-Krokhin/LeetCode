
class Solution {
public:
    int maxProfit(vector<int>& prices)
    {
        int buy = prices[0], max_profit = 0;

        for (int i = 1; i < prices.size(); i++)
        {
            if (prices[i] < buy)
                buy = prices[i];

            else if (prices[i] > (max_profit + buy))
                max_profit = prices[i] - buy;
        }

        return max_profit;
    }
};

// #2 Solution passes 200/212 test
// int i = 0, j = 0, diff = 0, min = INT_MAX, max = 0;
//         int size = prices.size();
//         if (i+1 < size)
//             j = i+1;
        
//         for (;i < size-1; i++)
//         {
//             for (j = i+1; j < size; j++)
//             {
//                 if (prices[j] - prices[i] > diff)
//                 {
//                     diff = prices[j] - prices[i];
//                     min = prices[i];
//                     max = prices[j];
//                 }
//             }
//         }

//         return diff;

// #1 Solution passes 178/212 tests
        // int i, j, k = -1, l, m = -1, profit = 0, min, max = 0;
        // bool isProfitMax = false, flagForMax = false;

        // while (max == 0 || isProfitMax == false)
        // {
        //     i = 0, j = 0, min = INT_MAX;
        //     if (flagForMax == true) min = prices[l];
        //     while (i < prices.size())
        //     {
        //         if (k == i)
        //         {
        //             i++;
        //             continue;
        //         }
        //         if (prices[i] < min)
        //         {
        //             min = prices[i];
        //             l = i;
        //         }
        //         i++;
        //     }
        //     j = l;
        //     while (++j < prices.size())
        //     {
        //         if (m == i)
        //         {
        //             j++;
        //             break;
        //         }
        //         if (prices[j] > max)
        //         {
        //             max = prices[j];
        //             m = j;
        //         }
        //     }
        //     if (k > -1 && max == 0)
        //         break;
        //     if (max == 0)
        //         k = l;
        //     else if (isProfitMax == false && flagForMax == false)
        //     {
        //         //k = l;
        //         flagForMax = true;
        //     }
        //     else if (flagForMax == true)
        //         isProfitMax = true;
        // }

        // printf("%d,", min);
        // printf("%d,", max);
        // if (max > 0 && max > min) profit = max-min;
        // return (profit);