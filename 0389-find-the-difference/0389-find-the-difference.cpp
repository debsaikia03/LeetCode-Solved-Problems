class Solution {
public:
    char findTheDifference(string s, string t) {
        
        string combine = s + t;

        char res = 0;

        for(char ch : combine){

            res ^= ch;
        }

        return res;
    }
};