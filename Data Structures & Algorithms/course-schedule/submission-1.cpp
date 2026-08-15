class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses, 0);

        // Build graph and indegree array
        for (auto &p : prerequisites) {
            adj[p[1]].push_back(p[0]);
            indegree[p[0]]++;
        }

        queue<int> q;

        // Push all nodes with indegree 0
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0)
                q.push(i);
        }

        int count = 0;

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            count++;

            for (int it : adj[node]) {
                indegree[it]--;
                if (indegree[it] == 0)
                    q.push(it);
            }
        }

        return count == numCourses;
    }
};