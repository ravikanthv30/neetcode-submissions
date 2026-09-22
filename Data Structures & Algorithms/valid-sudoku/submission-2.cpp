class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
    
    //input - matrix and output is bool 
    //m ay be unfilled --> so for this scope can I consider it given numbers checking is good enought or logical checking also needed ?
    //  [i,j] --> check for same number in 
    // 1  row -> [i,0] to [i,N]
    // 2 column -> [0,j] to [N,j]
    // 3 submatrix ->  [i-1,j-1] to [i+1,j+1] 
    //BF --> visit each one non zero and check for duplicates in all 3 cases 
    // can I use previously checked results back ?
    //divide by sets ->  submatrix - N ; rows N; col - N
    //make these set of operations -> check for duplicates O(n*n); space: O(n)
    //i can use hashmap to check if there is duplicate 

    int n = board.size();

    unordered_map <char, int> hm;
    //rows
    for(int i=0;i<n;i++)
    {
        for(int j=0; j<n; j++)
        {
            char c = board[i][j];
            if(c == '.')
                continue;
            if(hm[c]) 
                return false;
            else
                hm[c]++;
        }
        hm.clear();
    }
    hm.clear();
    //col
    for(int i=0;i<n;i++)
    {
        for(int j=0; j<n; j++)
        {
            char c = board[j][i];
            if(c == '.')
                continue;
            if(hm[c]) 
                return false;
            else
                hm[c]++;
        }
        hm.clear();
    }
    hm.clear();
    //sub matrix
    int sq = sqrt(n);
    for(int k=0; k<n; k++)
    {
        //(0,0) (0,3) (0,6) - (3,0) (3,3) (3,6) - (6,0) (6,3) (6,6)
        //use this for 9 sub matrix
        for(int i=0; i<sq; i++)
        {
            for(int j=0; j<sq; j++)
            {
                int row= (k/sq)*sq+i;
                int col= (k%sq)*sq+j;
                char c = board[row][col];
                cout<<"row"<< (k/sq)*sq<<"col"<< (k%sq)*sq<<"c"<<c <<endl;
                if(c == '.')
                    continue;
                if(hm[c])
                    return false;
                else
                    hm[c]++;
            }
        }
        hm.clear();
    }

    return true;
    }
};
