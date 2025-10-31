class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        //t.c. = O(n)
        if(nums.empty()) return 0;

        unordered_set<int> st(nums.begin(), nums.end());

        int maxLen = 0;

        for(int num : st){
            
            if(st.find(num - 1) == st.end()){//only start if num is the start of a sequence

                int currNum = num;
                int len = 1;

                while(st.find(currNum + 1) != st.end()){

                    currNum++;
                    len++;
                }

                maxLen = max(maxLen, len);
            }
        }

        return maxLen;

        //t.c: o(nlogn)
        /*if(nums.size() == 0) return 0;
        
        sort(nums.begin(), nums.end());

        int mxLen = 1;
        
        int len = 1;

        for(int i = 1; i < nums.size(); i++){

            if(nums[i] == nums[i-1]) continue;

            if(nums[i] - nums[i-1] == 1) len++; 

            else{      
               mxLen = max(mxLen, len);
               len = 1;
            }
        }

        return max(mxLen, len);*/
    }
};