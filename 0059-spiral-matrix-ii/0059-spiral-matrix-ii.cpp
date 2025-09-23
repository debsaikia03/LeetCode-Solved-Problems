class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {

        vector<vector<int>> matrix(n , vector<int>(n, 0));

        int left = 0;
        int right = matrix[0].size() - 1;
        int top = 0;
        int bottom = matrix.size() - 1;

        int num = 1;
        while(left <= right && top <= bottom){

            //left to right
            for(int i = left; i <= right; i++){

                matrix[top][i] = num;
                num++;
            }
            top++;

            //top to bottom
            for(int i = top; i <= bottom; i++){

                matrix[i][right] = num;
                num++;
            }
            right--;

            //right to left
            if(top <= bottom){

                for(int i = right; i >= left; i--){

                    matrix[bottom][i] = num;
                    num++;
                }
                bottom--;
            }

            //bottom to top
            if(left <= right){

               for(int i = bottom; i >= top; i--){

                    matrix[i][left] = num;
                    num++;
                }
                left++;
            }
        }

        return matrix;
    }
};