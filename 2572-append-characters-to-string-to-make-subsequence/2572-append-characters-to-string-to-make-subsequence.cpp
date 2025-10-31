class Solution {
public:
    int appendCharacters(string s, string t) {
        
        int strLen1 = s.size();
        int strLen2 = t.size();

        int i = 0, j = 0;
        while(i < strLen1 && j < strLen2){

            if(s[i] == t[j]){

                i++;
                j++;
            }else{

                i++;
            }
        }

        return strLen2 - j;
    }
};