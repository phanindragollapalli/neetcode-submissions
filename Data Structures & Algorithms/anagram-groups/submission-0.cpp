class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs)
    {
        int n = strs.size();
        vector<vector<string>>ans;
        map<vector<int>,vector<string>>mpp;
        for(auto& str : strs)
        {
            vector<int>count(26,0);
            for(auto ch:str)
            {
                count[ch-'a']++;
            }
            mpp[count].push_back(str);
        }    
        for(auto& [key,value]:mpp)
        {
            ans.push_back(value);
        }
        return ans;
    }
};
