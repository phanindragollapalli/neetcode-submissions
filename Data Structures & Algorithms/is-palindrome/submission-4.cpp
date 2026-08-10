class Solution {
private:
    void clean(string& s)
    {
        int n = s.size();
        string cleans;
        for(int i=0;i<n;i++)
        {
            if((s[i]<='z' && s[i]>='a') || (s[i]<='Z' && s[i]>='A') || (s[i]>='0' && s[i]<='9'))
            {
                cleans.push_back(s[i]);
            }
        }
        for(int i=0;i<cleans.size();i++)
        {
            if(cleans[i]>='A' && cleans[i]<='Z')
            {
                cleans[i]+=('a'-'A');
            }
        }
        s=cleans;
    }
public:
    bool isPalindrome(string s)
    {
        clean(s);
        int n = s.size();
        for(int i=0;i<n/2;i++)
        {
            if(s[i]!=s[n-i-1]) return false;
        }
        return true;
    }
};
