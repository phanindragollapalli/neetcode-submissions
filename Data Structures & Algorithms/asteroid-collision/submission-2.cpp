class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids)
    {
        stack<int> s;
        int n = asteroids.size();

        vector<int> survival(n, 0);

        for (int i = 0; i < n; i++)
        {
            int x = asteroids[i];

            if (x > 0)
            {
                s.push(i);
            }
            else
            {
                while (!s.empty() && asteroids[s.top()] < abs(x))
                {
                    s.pop();
                }

                if (s.empty())
                {
                    survival[i] = 1;
                }
                else if (asteroids[s.top()] == abs(x))
                {
                    s.pop();
                }
            }
        }

        while (!s.empty())
        {
            survival[s.top()] = 1;
            s.pop();
        }

        vector<int> ans;

        for (int i = 0; i < n; i++)
        {
            if (survival[i])
            {
                ans.push_back(asteroids[i]);
            }
        }

        return ans;
    }
};