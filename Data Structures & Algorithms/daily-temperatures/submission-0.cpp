class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures)
    {
        int n = temperatures.size();
        vector<int>result(n,0);
        stack<int> st;
        st.push(0);
        for(int i=1;i<n;i++)
        {
            int temp = temperatures[i];
            while(!st.empty() && temp>temperatures[st.top()])
            {
                int gap = i-st.top();
                result[st.top()]=gap;
                st.pop();
            }
            st.push(i);
        }
        return result;
    }
};
