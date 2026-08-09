class Solution {
public:
    int evalRPN(vector<string>& tokens)
    {
        stack<int>s;
        int n = tokens.size();
        for(auto str : tokens)
        {
            if(str == "+" || str == "-" || str == "*" || str == "/")
            {
                int num1 = s.top();
                s.pop();
                int num2 = s.top();
                s.pop();
                if(str == "+")
                {
                    s.push(num2+num1);
                }
                if(str == "-")
                {
                    s.push(num2-num1);
                }
                if(str == "*")
                {
                    s.push(num2*num1);
                }
                if(str == "/")
                {
                    s.push(num2/num1);
                }
            }
            else
            {
                int num = stoi(str);
                s.push(num);
            }
        } 
        return s.top();
    }
};
