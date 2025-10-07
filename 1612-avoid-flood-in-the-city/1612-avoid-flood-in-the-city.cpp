class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        
        int n = rains.size();

        //stores the result: -1 means raining day, 1 or lake number means dry day
        vector<int> ans(n, 0);

        //maps lake number → the last day it was filled
        unordered_map<int, int> mpp;

        //stores the indices of days when we can dry a lake (rains[i] == 0)
        set<int> index;

        for(int i = 0; i < n; i++) {

            //if it's a dry day, record the index for possible future drying
            if(rains[i] == 0) {
                index.insert(i);
                continue;
            }

            //if the current lake has already been filled earlier
            if(mpp.find(rains[i]) != mpp.end()) {

                //if no dry days available to prevent flood → not possible
                if(index.empty()) {
                    return {};
                } else {

                    //find the earliest dry day *after* the last time this lake was filled
                    auto it = index.lower_bound(mpp[rains[i]]);

                    //if there's no such dry day, flood can't be avoided
                    if(it == index.end()) {
                        return {};
                    }

                    //use that dry day to dry this lake before it rains again
                    ans[*it] = rains[i];

                    //remove this dry day since it’s now used
                    index.erase(it);
                }
            }

            //mark today as a raining day
            ans[i] = -1;

            //update last filled day for this lake
            mpp[rains[i]] = i;
        }

        //remaining dry days (that were never used) can dry any arbitrary lake (use 1)
        for(int i = 0; i < n; i++) {
            if(ans[i] == 0) {
                ans[i] = 1;
            }
        }

        return ans;
    }
};
