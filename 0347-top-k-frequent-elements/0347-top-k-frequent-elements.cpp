class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        unordered_map<int, int> mpp;

        for(int num : nums){

            mpp[num]++;
        }

        auto cmp =[&](pair<int, int> a, pair<int, int> b){
            return a.second > b.second; //min-heap by freq
        };

        priority_queue<pair<int,int>, vector<pair<int, int>>, decltype(cmp)> pq(cmp);

        for(auto& p : mpp){

            pq.push({p.first, p.second});

            if(pq.size() > k) pq.pop();
        }

        vector<int> ans;

        while(!pq.empty()){

            ans.push_back(pq.top().first);
            pq.pop();
        }

        return ans;
    }
};