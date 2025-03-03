class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals)
    {
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> merged;

        for (const auto interval : intervals)
            if (merged.empty() || merged.back()[1] < interval[0])
                merged.push_back(interval);
            else
                merged.back()[1] = max(merged.back()[1], interval[1]);

        return merged;
        

        /*

        // OLD SOLUTION

        vector<vector<int>> res;
        int flag = 0;

        for (int i = 0; i < intervals.size(); i++)
        {
            if (i == intervals.size() - 1)
            {
                if (res[0][0] < intervals[i][0] && res[0][1] < intervals[i][1])
                {
                    res[0][1] = intervals[i][1];
                }
                if (flag == 0) res.push_back({intervals[i]});
                break;
            }

            // if (intervals[i][0] > intervals[i+1][0] && intervals[i][1] > intervals[i+1][1] && )
            //     res.push_back({intervals[i][0], intervals[i][1]});
            
            if (intervals[i][0] > intervals[i+1][0] && intervals[i][0] > intervals[i+1][1])
            {
                res.push_back({intervals[i][0], intervals[i][1]});
                flag = 1;
            }

            if (intervals[i + 1][0] <= intervals[i][0] && intervals[i + 1][1] >= intervals[i][0] && (!(intervals[i][0] == intervals[i+1][0] && intervals[i][1] == intervals[i+1][1])))
            {
                if (intervals[i + 1][1] >= intervals[i][1]) res.push_back({intervals[i + 1][0], intervals[i+1][1]});
                else res.push_back({intervals[i + 1][0], intervals[i][1]});

                i++;
            }
            else if (intervals[i][1] >= intervals[i + 1][0])
            {
                if (intervals[i][0] > intervals[i + 1][0])
                    res.push_back({intervals[i + 1][0], intervals[i + 1][1]});
                else if (intervals[i][1] <= intervals[i + 1][1])
                    res.push_back({intervals[i][0], intervals[i + 1][1]});
                else
                    res.push_back({intervals[i][0], intervals[i][1]});
                if (i + 1 == intervals.size() - 1) flag = 1;
                i++;
            }
            else
            {
                res.push_back({intervals[i]});
                if (intervals[i][0] == intervals[i+1][0] && intervals[i][1] == intervals[i+1][1])
                {
                    flag = 1;
                }
            }
        }

        // Print the updated intervals
        for (const auto& res : res) {
            cout << "[" << res[0] << ", " << res[1] << "] ";
        }

        return res;

        */
    }
};