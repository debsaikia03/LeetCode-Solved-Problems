class Solution {
public:

    vector<vector<int>> res;

    void pacificEdge(vector<vector<int>>& heights, int r, int c, vector<vector<int>>& grid){
       
        int row = heights.size();
        int col = heights[0].size();
        
        if(grid[r][c] == 1) return; 

        //if not visited
        //mark 1 for cell in pacific
        grid[r][c] = 1; //mark as visited and explore the 4 directions

        //direction vectors
        int dr[4] = {-1, 1, 0, 0};
        int dc[4] = {0, 0, -1, 1};

        //new coordinates
        for(int i = 0; i < 4; i++){

           int newR = r + dr[i];
           int newC = c + dc[i];

           if(newR >= 0 && newC >= 0 && newR < row && newC < col && heights[newR][newC] >= heights[r][c]){

                pacificEdge(heights, newR, newC, grid);
           }
        }
        
    }

    void atlanticEdge(vector<vector<int>>& heights, int r, int c, vector<vector<int>>& grid){
       
        int row = heights.size();
        int col = heights[0].size();
        
        if(grid[r][c] == 1){

            res.push_back({r, c});//if already visited by pacific push to result 
        }

        if(grid[r][c] == 2) return;//if already visited by atlantic

        grid[r][c] = 2; //mark 2 for cell in atlantic 

        //direction vectors
        int dr[4] = {-1, 1, 0, 0};
        int dc[4] = {0, 0, -1, 1};

        //new coordinates
        for(int i = 0; i < 4; i++){

           int newR = r + dr[i];
           int newC = c + dc[i];

           if(newR >= 0 && newC >= 0 && newR < row && newC < col && heights[newR][newC] >= heights[r][c]){

                atlanticEdge(heights, newR, newC, grid);
           }
        }
        
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        
        int row = heights.size();
        int col = heights[0].size();

        if(row == 0) return res;

        vector<vector<int>>grid(row, vector<int>(col, 0)); //storing whether cell has visited pacific or atlantic or both 

        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){

                if(i == 0 || j == 0){

                    pacificEdge(heights, i, j, grid);
                }
            }
        }

        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){

                if(i == row - 1 || j == col - 1){

                    atlanticEdge(heights, i, j, grid);
                }
            }
        }

        return res;
    }
};
