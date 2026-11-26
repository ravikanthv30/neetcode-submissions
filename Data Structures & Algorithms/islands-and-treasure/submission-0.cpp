class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        if(grid.empty() || grid[0].empty())
            return;
        int rows = grid.size();
        int cols = grid[0].size();
        constexpr int INF = 2147483647;

        queue <pair<int, int>> q;

        for(int i=0; i<rows; i++)
        {
            for(int j=0;j<cols;j++)
            {
                if(grid[i][j] == 0)
                    q.push({i,j});
            }
        }
        const int dirs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        while(!q.empty())
        {
            auto [r,c] = q.front();
            q.pop();

            for(auto&d: dirs)
            {
                int nr = r+d[0];
                int nc = c+d[1];

                if(nr<0 || nr>=rows || nc<0 || nc>=cols )
                  continue;
                
                if(grid[nr][nc] ==INF)
                {
                    grid[nr][nc] = grid[r][c]+1;
                    q.push({nr,nc});
                }
            }
        }
    }
};
