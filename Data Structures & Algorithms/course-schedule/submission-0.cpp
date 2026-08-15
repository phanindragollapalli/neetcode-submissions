class Solution {
public:
    bool dfs(int node, vector<vector<int>>& adj, vector<int>& vis) {
        vis[node] = 1; // visiting

        for (int it : adj[node]) {
            if (vis[it] == 1) return false;          // cycle
            if (vis[it] == 0 && !dfs(it, adj, vis))
                return false;
        }

        vis[node] = 2; // finished
        return true;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);

        for (auto &p : prerequisites)
            adj[p[1]].push_back(p[0]);

        vector<int> vis(numCourses, 0);

        for (int i = 0; i < numCourses; i++) {
            if (vis[i] == 0 && !dfs(i, adj, vis))
                return false;
        }

        return true;
    }
};