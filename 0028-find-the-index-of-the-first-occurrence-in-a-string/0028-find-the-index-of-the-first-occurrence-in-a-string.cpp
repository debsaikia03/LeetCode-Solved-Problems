class Solution {
public:
    int strStr(string haystack, string needle) {

        int n = 0;
        
        for(int i = 0; i < haystack.size(); i++){

            if(haystack[i] == needle[n]){

                n++;

                if(n == needle.length()){

                    return i - n + 1;
                }
            } else {

                i = i - n;
                n = 0;
            }
        }

        return -1;
    }
};