class Solution {
private:
    int dx[4]={0,0,1,-1};
    int dy[4]={-1,1,0,0};
public:
    int orangesRotting(vector<vector<int>>& grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        int fresh = 0;
        vector<vector<int>>vis(m,vector<int>(n,0));
        queue<pair<pair<int,int>,int>>q;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==2)
                {
                    q.push({{i,j},0});
                    vis[i][j]=2;
                }
            }
        }    
        int maxt = 0;
        while(!q.empty())
        {
            int x = q.front().first.first;
            int y = q.front().first.second;
            int t = q.front().second;
            maxt = max(maxt,t);
            q.pop();
            for(int i=0;i<4;i++)
            {
                int nx = x+dx[i];
                int ny = y+dy[i];
                if(nx>=0 && nx<m && ny>=0 && ny<n && grid[nx][ny]==1 && vis[nx][ny]!=2)
                {
                    q.push({{nx,ny},t+1});
                    vis[nx][ny]=2;   
                }
            }
        }
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(vis[i][j]!=2 && grid[i][j]==1)
                {
                    return -1;
                }
            }
        }
        return maxt;
    }
};