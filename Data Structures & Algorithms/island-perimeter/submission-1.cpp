class Solution {
public:
    int dx[4] = {1,0,-1,0};
    int dy[4] = {0,1,0,-1};
    int islandPerimeter(vector<vector<int>>& grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        int perimeter = 0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1)
                {
                    int cnt = 0;
                    for(int k=0;k<4;k++)
                    {
                        int nx = i+dx[k];
                        int ny = j+dy[k];
                        if(nx>=0 && nx<n && ny>=0 && ny<m && grid[nx][ny]==1) cnt++;
                    }
                    perimeter+=(4-cnt);
                }
            }
        }
        return perimeter;
    }
};