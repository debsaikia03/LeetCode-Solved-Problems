class Solution {
public:
    int strStr(string haystack, string needle) {

        int idx;

        int i = 0;
        while(i < haystack.size()){
            
            int pst_idx = i;
            int j = 0;
            while(j < needle.size()){

                if(haystack[i] != needle[j]){
                    
                    i = pst_idx;
                    break;
                }

                else{

                    if(j == 0) idx = i;

                    i++;
                    j++;
                }
            }

            if(j == needle.size()) return idx;

            i++;
        }

        return -1;
    }
};