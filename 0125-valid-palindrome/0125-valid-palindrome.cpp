class Solution {
public:

    string removeWhitespace(string s) {
        string newStr = "";
        int i = 0;
        while (i < s.size()) {  
            if (isalnum(s[i])) {
                newStr += tolower(s[i]);
            }
            i++;
        }
        return newStr;
    }
    
    bool isPalindrome(string s) {
        string newS = removeWhitespace(s);
        int n = newS.size();
        int i = 0, j = n - 1;

        while (i <= j) {
            if (newS[i] != newS[j]) return false;
            i++;
            j--; 
        }
        return true;
    }
};
