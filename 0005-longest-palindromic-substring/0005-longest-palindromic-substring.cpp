class Solution {
public:

    bool solve(string &s, int i, int j){

        while(i < j){

            if(s[i] != s[j]) return false;

            i++;
            j--;
        }

        return true;
    }

    string longestPalindrome(string s) {
     
        int n = s.size();

        int maxLength = INT_MIN;
        int startPt = -1;

        for(int i = 0; i < n; i++){
            for(int j = i; j < n; j++){

                if(j - i + 1 > maxLength && solve(s, i, j)){
                    
                    maxLength = j - i + 1;
                    startPt = i;
                }
            }
        }

        return s.substr(startPt, maxLength);
    }
};