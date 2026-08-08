// class MinStack {
// public:
//     MinStack() {}
//     stack<long long>st;
//     long long mini;
//     void push(long long val)
//     {
//         if(st.empty())
//         {
//             mini = val;
//             st.push(val);
//         }
//         else if(val>mini)
//         {
//             st.push(val);
//         }
//         else
//         {
//             st.push(2*val-mini);
//             mini = val;
//         }
//     }
    
//     void pop()
//     {
//         if(st.empty()) return;
//         long long num = st.top();
//         st.pop();
//         if(num<mini)
//         {
//             mini = 2*mini - num;
//         }    
//     }
    
//     long long top()
//     {
//         // if(st.empty()) return;
//         long long num = st.top();
//         if(num<mini) return mini;
//         return num;
//     }
    
//     long long getMin()
//     {
//         return mini;    
//     }
// };
class MinStack {
public:
    stack<pair<int, int>> st;

    MinStack() {
    }

    void push(int val) {
        if (st.empty()) {
            st.push({val, val});
        }
        else {
            int mini = min(val, st.top().second);
            st.push({val, mini});
        }
    }

    void pop() {
        if (!st.empty()) {
            st.pop();
        }
    }

    int top() {
        return st.top().first;
    }

    int getMin() {
        return st.top().second;
    }
};

