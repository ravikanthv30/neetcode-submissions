class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        //input is grid map and output is the max area of island - int
        //lets visist each island and when visiting count the area
        // do the max of all the island areas
        //edge cases ? 0 or 1 
        // time & space complexity = O(v+e)

        if(grid.empty() || grid[0].empty())
            return 0;

        int maxArea = 0;
        int rows = grid.size();
        int cols = grid[0].size();

        for(int i=0; i<rows; i++)
        {
            for(int j=0; j<cols; j++)
            {
                if(grid[i][j] == 1)
                {
                    int area=0;
                    dfs(grid, i, j, rows, cols, area);
                    maxArea = max(area, maxArea);
                }
            }
        }
        return maxArea;
    }
private:
    void dfs(vector<vector<int>>& grid, int r, int c, int rows, int cols, int& area)
    {
        if(r<0 || r>=rows || c<0 || c>=cols || grid[r][c] != 1)
            return;

        area++;
        grid[r][c] = 0;

        dfs(grid, r + 1, c, rows, cols, area);
        dfs(grid, r - 1, c, rows, cols, area);
        dfs(grid, r, c + 1, rows, cols, area);
        dfs(grid, r, c - 1, rows, cols, area);
    }

};
