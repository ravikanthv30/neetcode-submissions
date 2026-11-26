class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        //input grid of mXn
        //output - same grid inplace edit INF to have distance to nearest 0; -1 is hard wall cant go
        //flood fill with conditions and each cell distance to 0 = 1+ min disatance from any neigh
        //if(grid[r][c] == -1) return INT_MAX;
        //if(grid[r][c] == 0) return 0;
        //if grid[r][c] == INF  grid[r][c] = 1+ min(dfs(4 neighors of grid[r][c]));
        //return grid[r][c];
        //WRONG THINKING:  DFS cannot be as it needs to fill distance in each path which may NOT be short one.
        //BFS is the correct one as every next nodes breadth wise will have 1 as shortest path, next one will be 1+grid[r][c]
        // see the numbers also 0, INF(1+prev) and -1 ; it is all previously calcuated distances .
        // q<int, int> where the grid locations =>  if grid[r][c]==0 -> add all of them to the queue
        // q.pop() each and move towards all 4 directions till end of rows and cols if  grid[r][c]==INF -> replace with  1+grid[r][c]; skip if it is -1, min (exisiting, new one)

        if(grid.empty() || grid[0].empty())
            return;
        
        int rows = grid.size();
        int cols = grid[0].size();
        queue <pair<int,int>> q;
        constexpr int INF{2147483647};
        for(int r=0; r<rows; r++ )
        {
            for(int c=0; c<cols; c++)
            {
                if(grid[r][c] == 0)
                    q.push({r,c});
            }
        }

        vector<vector<int>> dir {{-1,0},{1,0},{0,-1},{0,1}};
        while(!q.empty())
        {
            auto [r,c] = q.front();
            q.pop();
            //all 4 directions 
            for(auto d:dir)
            {
                int nr=r+d[0];
                int nc=c+d[1];
                if(nr<0 || nr>=rows || nc<0 || nc>=cols || grid[nr][nc] == -1)
                     continue;
                if(grid[nr][nc] == INF)
                {
                    grid[nr][nc] = 1+grid[r][c];
                    q.push({nr,nc});
                }
            }
        }
    }
};



/*
      if(grid.empty() || grid[0].empty())
            return;
        int rows = grid.size();
        int cols = grid[0].size();
        for(int i=0; i<rows; i++)
        {
            for(int j=0;j<cols;j++)
            {
                if(grid[i][j] == 2147483647 )
                {
                    dfs(grid, i, j, rows,cols);
                }
            }
        }

        return;
    }
private:
    int  dfs(vector<vector<int>>& grid, int r, int c, int rows, int cols)
    {
        if(r<0 || r>=rows || c<0 || c>=cols || grid[r][c] == -1)
            return INT_MAX;
        
        if(grid[r][c] == 0)
            return 0;
        if(grid[r][c] == 2147483647)
        {
            grid[r][c] = 1+ min(  dfs(grid, r+1, c, rows,cols), 
                                  dfs(grid, r-1, c, rows,cols), 
                                  dfs(grid, r, c+1, rows,cols), 
                                  dfs(grid, r, c-1, rows,cols));
        }

        return grid[r][c];
*/