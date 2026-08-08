class Solution {
public:
    bool isAnagram(string s, string t) {
        int n=s.size();
        int m=t.size();
        if(n!=m) return false;
        vector<int>arr(26);
        vector<int>brr(26);
        for(int i=0;i<26;i++){
            arr[i]==0;
            brr[i]==0;
        }
        for(int i=0;i<n;i++){
            arr[s[i]-'a']++;
            brr[t[i]-'a']++;
        }
        for(int i=0;i<26;i++)
        {
            if(arr[i]!=brr[i]) return false;
        }
        return true;
    }
};
