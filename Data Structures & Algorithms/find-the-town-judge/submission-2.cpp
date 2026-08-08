class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust)
    {  
        vector<vector<int>>adj(n+1);
        for(int i=0;i<trust.size();i++)
        {
            adj[trust[i][0]].push_back(trust[i][1]);
        }
        vector<int>indegree(n+1,0);
        for(int i=0;i<trust.size();i++)
        {
            indegree[trust[i][1]]++;
        }
        vector<int>outdegree(n+1,0);
        for(int i=0;i<trust.size();i++)
        {
            outdegree[trust[i][0]]++;
        }
        for(int i=1;i<=n;i++)
        {
            if(indegree[i]==n-1 && outdegree[i]==0)
            {
                return i;
            }
        }
        return -1;
        // queue<int>q;
        // vector<int>topo;
        // int cnt = 0;
        // for(int i=1;i<=n;i++)
        // {
        //     if(indegree[i]==0)
        //     {
        //         q.push(i);
        //         cnt++;
        //     }
        // }
        // while(!q.empty())
        // {
        //     int node = q.front();
        //     q.pop();
        //     topo.push_back(node);
        //     for(auto nbr:adj[node])
        //     {
        //         indegree[nbr]--;
        //         if(indegree[nbr]==0)
        //         {
        //             q.push(nbr);
        //             cnt++;
        //         }
        //     }
        // }
        // if(n==cnt) return topo[n-1];
        // return -1;
    }
};