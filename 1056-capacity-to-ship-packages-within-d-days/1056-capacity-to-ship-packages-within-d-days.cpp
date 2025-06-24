class Solution {
public:

    int helper(vector<int>& w, int cap){

        int days = 1, load = 0;

        for(int i = 0; i < w.size(); i++){

            if(load + w[i] > cap){
                days++;
                load = w[i];
            } else{
                load += w[i];
            }
        }
 
        return days;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        
        int n = weights.size();

        int low = *max_element(weights.begin(), weights.end()); //max pkg wgt

        int high = accumulate(weights.begin(), weights.end(), 0); //sum of wgts of pkgs

        int ans = high;

        //binary search // least cpty ans -> range [max pkg wgt, sum of wgts of pkgs]
        while(low <= high){
            
            int mid = low + (high - low)/2;

            int daysReqd = helper(weights, mid);

            if(daysReqd <= days){
               ans = mid;
               high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }
};