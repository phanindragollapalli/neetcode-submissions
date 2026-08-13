class Solution {
public:

    string encode(vector<string>& strs)
    {
        string ans;
        for(auto str : strs)
        {
            ans.push_back(static_cast<unsigned char>(str.size()));
            for(auto ch : str)
            {
                ans.push_back(ch);
            }
        }
        return ans;
    }

    vector<string> decode(string s)
    {
        vector<string>res;
        int n = s.size();
        int curr=0;
        while(curr<n)
        {
            int len = static_cast<unsigned char>(s[curr]);
            curr++;
            string temp;
            while(len--)
            {
                temp.push_back(s[curr]);
                curr++;
            }
            res.push_back(temp);
        }
        return res;
    }
};
