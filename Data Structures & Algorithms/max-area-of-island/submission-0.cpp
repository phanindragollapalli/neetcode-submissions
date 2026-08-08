class Solution {
public:
    int dx[4] = {-1,1,0,0};
    int dy[4] = {0,0,-1,1};
    int dfs(int x, int y, vector<vector<int>>&grid, vector<vector<int>>&vis, int& cnt)
    {
        vis[x][y]=1;
        cnt++;
        int m = grid.size();
        int n = grid[0].size();
        for(int i=0;i<4;i++)
        {
            int nx = x+dx[i];
            int ny = y+dy[i];
            if(nx>=0 && nx<m && ny>=0 && ny<n && vis[nx][ny]==0 && grid[nx][ny]==1)
            {
              int temp = dfs(nx,ny,grid,vis,cnt);
            }
        }
        return cnt;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>>vis(m,vector<int>(n,0));
        int maxarea = 0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(vis[i][j]==0 && grid[i][j]==1)
                {
                    int area = 0;
                    area = dfs(i,j,grid,vis,area);
                    maxarea = max(maxarea,area);
                }
            }
        }
        return maxarea;
    }
};
