class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k)
    {
        int n = nums.size();

        unordered_map<int, int> mpp;

        for (int x : nums)
        {
            mpp[x]++;
        }

        vector<vector<int>> freq(n + 1);

        for (auto& [key, value] : mpp)
        {
            freq[value].push_back(key);
        }

        vector<int> res;

        for (int i = n; i >= 0 && res.size() < k; i--)
        {
            for (int x : freq[i])
            {
                res.push_back(x);

                if (res.size() == k)
                    break;
            }
        }

        return res;
    }
};