class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        if(nums.empty()) return 0;
        
        set<int> s(nums.begin(), nums.end());
        vector<int> v(s.begin(), s.end());

        int len = 1, maxLen = 1;

        for(int i = 1; i < v.size(); i++){

            if(v[i] == v[i-1] + 1){
                len++;
            } else{

                maxLen = max(maxLen, len);
                len = 1;
            }
        }
        
        maxLen = max(maxLen, len);

        return maxLen;
    }
};