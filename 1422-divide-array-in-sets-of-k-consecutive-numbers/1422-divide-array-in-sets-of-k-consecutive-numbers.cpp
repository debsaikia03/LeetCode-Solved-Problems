class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        
        if(nums.size() % k != 0) return false;

        map<int, int> mpp;

        for(int num : nums){

           mpp[num]++;
        }

        while(!mpp.empty()){

            int start = mpp.begin()->first;

            for(int i = 0; i < k; i++){

                int curr = start + i;

                if(mpp.find(curr) == mpp.end()) return false;

                mpp[curr]--;

                if(mpp[curr] == 0) mpp.erase(curr);
            }
        }

        return true;
    }
};