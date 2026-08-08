class Solution {
public:
    int dx[4] = {-1,1,0,0};
    int dy[4] = {0,0,-1,1};
    void dfs(int x, int y, vector<vector<char>>&grid, vector<vector<int>>&vis)
    {
        vis[x][y]=1;
        int m = grid.size();
        int n = grid[0].size();
        for(int i=0;i<4;i++)
        {
            int nx = x+dx[i];
            int ny = y+dy[i];
            if(nx>=0 && nx<m && ny>=0 && ny<n && grid[nx][ny]=='1' && vis[nx][ny]==0)
            {
                dfs(nx,ny,grid,vis);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>>vis(m,vector<int>(n,0));
        int cnt = 0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(vis[i][j]==0 && grid[i][j]=='1')
                {
                    dfs(i,j,grid,vis);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};
