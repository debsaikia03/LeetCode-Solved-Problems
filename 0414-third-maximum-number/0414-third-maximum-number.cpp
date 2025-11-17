class Solution {
public:
    int thirdMax(vector<int>& nums) {
        
        set<int> s;

        for(int num : nums){

            s.insert(num);
        }

        int res = 0;

        if(s.size() >= 3){

            int i = s.size() - 3;
            auto it = next(s.begin(), i);
            res = *it;
        }else{

            auto it = s.end();
            it--;
            res = *it;
        }

        return res;
    }
};