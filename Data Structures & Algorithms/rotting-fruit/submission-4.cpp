class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
    //input: grid with 0, 1, 2 => each loop is a minute where 1 will become 2 
    //output -> how many loops where all 1s become 2s
    // all adjusent ones of 2 is to be tracked and move 1s to 2s -> BFS 
    // add all 2s to queue first 
    //while q is non empty --> minutes++ 
    // udpate all 2s nighs to 2s and add them to queue 
    // repeat till q is empty 
    //return minutes 

    if(grid.empty() || grid[0].empty())
        return -1;

    int rows = grid.size();
    int cols = grid[0].size();
    queue <pair<int,int>> q;
    int fresh = 0;
    for(int r=0; r<rows; r++)
    {
        for(int c=0; c<cols; c++)
        {
            if(grid[r][c] == 2)
                q.push({r,c});
            else if(grid[r][c] == 1)
                fresh++;
        }
    }
    //2,2
      
    int min=0;
    vector<vector<int>> dir {{-1,0},{1,0},{0,-1},{0,1}};
    while(fresh>0 && !q.empty())
    {
        int len = q.size();
        min++;
        //pop the first one
        for(int i=0; i<len; i++)
        {
            auto [r,c] = q.front();
            q.pop();
            //find all neigh and update
            for(auto d:dir)
            {
                int nr=r+d[0];
                int nc=c+d[1];

                if(nr<0 || nr>=rows || nc<0 || nc>=cols || grid[nr][nc]==0)
                    continue;
                
                if(grid[nr][nc]==1)
                {
                    grid[nr][nc] = 2;
                    q.push({nr,nc});
                    fresh--;
                }
            }
        }
    }

    return fresh==0?min:-1;

    }
};
