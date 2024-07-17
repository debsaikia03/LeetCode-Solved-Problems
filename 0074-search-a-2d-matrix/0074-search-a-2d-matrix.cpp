class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int n = matrix.size();     //no. of rows
        int m = matrix[0].size();  //no. of columns

        int row = 0;
        int column = m-1; //start from

        while(row <= n-1 && column >= 0){
            int curr = matrix[row][column];

            if(target == curr) return true;

            else if(target > curr) row++;

            else column--;
        }

        return false;
    }
};