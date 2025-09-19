class Solution {
public:

    void swap(int& a, int& b){

        a = a + b;
        b = a - b;
        a = a - b;
    }

    void reverse(vector<vector<int>>& matrix, int i){

        int n = matrix.size() - 1;

        int j = 0;

        while(j < n){

            swap(matrix[i][j], matrix[i][n]);

            j++;
            n--;
        }        
    }

    void rotate(vector<vector<int>>& matrix) {

        int n = matrix.size();

        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){

                swap(matrix[i][j], matrix[j][i]);
            }
        }
        
        /*for(int i = 0; i < n; i++){

            reverse(matrix[i].begin(), matrix[i].end());
        }*/

        for(int i = 0; i < n; i++){
            
            reverse(matrix, i);
        }
    }
};