class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        if(nums.empty()) return 0;
        
        unordered_set<int> s(nums.begin(), nums.end());

        int maxLen = 0;

        for(int i : s){

            if(s.find(i-1) == s.end()){//only start if it's the start of a sequence

                int currNum = i;
                int len = 1;

                while(s.find(currNum+1) != s.end()){
                    
                    currNum++;
                    len++;
                }

                maxLen = max(maxLen, len);
            }
        }


        return maxLen;
    }
};