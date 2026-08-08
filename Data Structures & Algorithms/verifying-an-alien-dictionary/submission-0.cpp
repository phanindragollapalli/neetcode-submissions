class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order)
    {
        map<char,int>mpp;
        for(int i=0;i<order.size();i++)
        {
            mpp[order[i]]=i;
        }
        int n = words.size();
        vector<int>a(n,0);
        for(int i=0;i<n-1;i++)
        {
            string word1 = words[i];
            string word2 = words[i+1];
            for(int j=0;j<word1.size();j++)
            {
                if(j==word2.size())
                {
                    return false;
                }
                if(word2[j]!=word1[j])
                {
                    if(mpp[word2[j]]<mpp[word1[j]])
                    {
                        return false;
                    }
                    break;
                }
            }
        }
        return true;
    }
};