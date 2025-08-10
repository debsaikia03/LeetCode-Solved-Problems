class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        unordered_map<int, int> mpp;

        for(int num : nums){

            mpp[num]++;
        }

        auto cmp =[&](int a, int b){
            return mpp[a] < mpp[b];
        };

        priority_queue<int, vector<int>, decltype(cmp)> pq(cmp);

        for(auto& p : mpp){

            pq.push(p.first);
        }

        vector<int> ans;

        while(k--){

            ans.push_back(pq.top());
            pq.pop();
        }

        return ans;
    }
};