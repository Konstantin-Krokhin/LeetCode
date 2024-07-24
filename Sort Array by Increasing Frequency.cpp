class Solution {
public:
    vector<int> frequencySort(vector<int>& nums)
    {
        map <int, int>numFreq;
        int max_key = 0, max_rep = INT_MIN;
        vector <int>builtVector;
        bool ifSorted = false;

        // Create the empty valued map with possible values
        for (int i = -1000; i < 1000; i++)
            numFreq.insert({i, 0});

        // Count how many times value (key) is met
        for (int i = 0; i < nums.size(); i++)
        {
            auto it = numFreq.find(nums[i]);
            if (it != numFreq.end()) it->second++;
        }

        while(max_rep != 0)
        {
            max_rep = INT_MIN;
            auto it = numFreq.begin();
            for (; it != numFreq.end(); ++it)
            {
                if (it->second > max_rep)
                {
                    max_key = it->first;
                    max_rep = it->second;
                }
            }

            for (int i = 0; i < max_rep; i++)
                builtVector.insert(builtVector.begin(), max_key);

            it = numFreq.find(max_key);
            it->second = 0;
        }

        //cout << it->first << " : " << it->second << endl;


        // while (ifSorted == false)
        // {
        //     auto it2 = numFreq.begin();
        //     it2++;
        //     ifSorted = true;
        //     int i = 0;
        //     for (auto it = numFreq.begin(); it != numFreq.end() && it2 != numFreq.end(); ++it, ++it2)
        //     {
        //         cout << i++ << endl;
        //         if (it->second < it2->second)
        //         {
        //             cout << "it = " << it->second << " : it2 = " << it2->second << endl;
        //             swap(it, it2);
        //             --it;
        //             ++it2;
        //             ifSorted = false;
        //             cout << "it = " << it->second << " : it2 = " << it2->second << endl;
        //         }
        //     }
        //     for (auto it = numFreq.begin(); it != numFreq.end(); ++it)
        //     cout << it->first << " : " << it->second << endl;
        // }

        // Print map
        // for (auto it = numFreq.begin(); it != numFreq.end(); ++it)
        //     cout << it->first << " : " << it->second << endl;


        // for (int i = 0; i < 10; i++)
        // {
        //     builtVector.insert(builtVector.begin() + k, numFreq.get(i));
        //     k++;
        // }
        
        return builtVector;
    }
};