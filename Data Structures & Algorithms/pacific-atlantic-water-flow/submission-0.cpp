class Solution {
public:

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        //input - grid of heights 
        //output -> list of pairs where cell can reach both ends
        // codition: each cell reaching to limits Pac[{0,0}] Alt[{rows, cols}] -> if both - return true 
        // state -> 4 neigh -> lower or equal check their neigh and get to end ; else only pacific 
        //         if neigh reaches to both then i dont need to caluclate again ? yes 
        //DFS -> i can calculate and then use that again when my neigh is already visited 
        // T&S - O(m*n) - data structure -> vector 
        // break condition -> if(r<0 || c<0) return 1 ;  if(r>=rows || c>=cols) return 2; if(h[r][c] >0) return 0;
        //if(h[r][c] >= neigh)
          // map[r][c] = (dfs(all neigh))
        //return 0;
        vector<vector<int>> ret;
        if(heights.empty() || heights[0].empty())
            return ret;
        
        int rows = heights.size();
        int cols = heights[0].size();

        vector<vector<bool>> pac (rows, vector<bool>(cols, false));
        vector<vector<bool>> alt (rows, vector<bool>(cols, false));

        //move colum by column from 1st and last rown
        // Top and bottom rows
        for(int c=0; c<cols; c++)    
        {
            dfs(heights, 0, c, rows, cols, pac);
            dfs(heights, rows-1, c, rows, cols, alt);
        }

        //move row by row from 1st col and last col
        //left and right cols
        for(int r=0; r<rows; r++)
        {
          dfs(heights, r, 0, rows, cols, pac);
          dfs(heights, r, cols-1, rows, cols, alt);
        }

        //return the common set
      vector<vector<int>> result;
        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                if (pac[r][c] && alt[r][c]) {
                    result.push_back({r, c});
                }
            }
        }

        return result;
    }
private: 
    vector<vector<int>> dir {{-1,0},{1,0},{0,-1},{0,1}};
void dfs(const vector<vector<int>>& heights,
             int r,
             int c,
             int rows,
             int cols, 
              vector<vector<bool>>& visited) {
        visited[r][c] = true;

        static constexpr int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        for (const auto& d : dirs) {
            int nr = r + d[0];
            int nc = c + d[1];

            if (nr < 0 || nr >= rows || nc < 0 || nc >= cols) {
                continue;
            }
            if (visited[nr][nc]) {
                continue;
            }
            // Reverse flow: water moves from lower/equal to higher/equal height
            if (heights[nr][nc] >= heights[r][c]) {
                dfs(heights, nr, nc, rows, cols, visited);
            }
        }
    }
};
