class Solution {
public:
    int strStr(string haystack, string needle) {

        int i = 0, j = 0, m = 0;

        while(i < haystack.size()){

            if(haystack[i] == needle[m]){

                i++;
                m++;

                if(m == needle.size()) return i - m;
            } else {

                j++;
                i = j;
                m = 0;
            }           
        }
        
        return -1;
    }
};