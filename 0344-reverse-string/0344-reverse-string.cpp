class Solution {
public:
    void swap(int i, int j, vector<char>& s){

        char temp = s[i];
        s[i] = s[j];
        s[j] = temp;
    }

    void reverseString(vector<char>& s) {
        
        int n = s.size();

        int i = 0, j = n - 1;

        while(i <= j){

            swap(i, j, s);
            i++;
            j--;
        }
    }
};