class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        //core condition: if all the neighbours are 0 surrounding 1 -> island
        // possibly dfs with each 1 go ahead and check neighbors till you find such neigh -> return true, if not false
        //mark all visited nodes as 1 meanwhile
        // do this for each node and return if it is already visited.
        //for loop-> in all the nodes -> call dfs() wiht visited[]
        // dfs() : break condition: if(r < 0 || r >= rows || c <0 || c>=col || grid[u] != 1 || visited[u]==true))  return false;
        // recursion:                its unvisited land -> mark visited as true 
        //          check all neighbors - if all water - bool isLand = (if all are false -> dfs(all neigh,) || )
        // return !isLand;
        //WHAT went WRONG: inplace visited, checkLand is problem count only once per island ; atleast 1 is there one island will be there 

        if(grid.empty() || grid[0].empty()) 
            return 0;
        int rows = static_cast<int> (grid.size());
        int cols = static_cast<int> (grid[0].size());

        int islands = 0;
        // Scan every cell as a potential starting point of a connected component
        for(int i = 0; i<rows; i++)
        {
            for(int j=0; j<cols; j++)
            {
                // Found an unvisited land cell ('1'): this starts a new island
                if(grid[i][j] == '1')
                {
                    dfs(grid, i,j, rows, cols);
                    islands++;
                }
            }
        }
        return islands;
    }

private:
    void dfs(vector<vector<char>>& grid, int r, int c, int rows, int cols)
    {
        // Base case: stop if out of bounds, water ('0'), or already sunk/visited
        if(r < 0 || r >= rows || c <0 || c>=cols || grid[r][c] != '1')
        {
            return;
        }
        // Mark current land cell as visited in-place (sinking it to '0')
        // Unlike backtracking, we do NOT restore '1' because each island is counted once
        grid[r][c] = '0';

        //call neighbors 
        dfs(grid, r+1, c, rows, cols);
        dfs(grid,  r-1 , c, rows, cols);
        dfs(grid,  r, c+1, rows, cols);
        dfs(grid, r, c-1, rows, cols);
    }
};
