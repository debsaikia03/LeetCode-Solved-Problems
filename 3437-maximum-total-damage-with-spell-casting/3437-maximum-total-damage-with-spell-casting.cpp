class Solution {
public:

    typedef long long ll;
    vector<ll> t;

    //bottom up approach
    ll maximumTotalDamage(vector<int>& power) {
        unordered_map<ll, ll> mpp;

        for (int p : power) mpp[p]++;

        vector<ll> nums;
        for (auto &itr : mpp) nums.push_back(itr.first);

        sort(nums.begin(), nums.end());
        int n = nums.size();

        vector<ll> t(n, 0);

        ll result = INT_MIN;

        for(int i = n-1; i >= 0; i--){

            ll skip = (i+1 < n) ? t[i+1] : 0;

            int j = lower_bound(nums.begin()+i+1, nums.end(), nums[i] + 3) - nums.begin();

            ll take = nums[i] * mpp[nums[i]] + ((j < n) ? t[j] : 0);

            t[i] = max(skip, take);

            result = max(result, t[i]);
        }

        return result;
    }

    //recursion approach //tc - o(nlogn)
    /*typedef long long ll;
    vector<ll> t;

    ll solve(vector<ll>& nums, int i, int n, unordered_map<ll, ll>& mpp) {
        if (i >= n) return 0;

        if (t[i] != -1) return t[i];

        // skip current number
        ll skip = solve(nums, i + 1, n, mpp);

        // take current number and jump to the next valid index
        int j = lower_bound(nums.begin() + i + 1, nums.end(), nums[i] + 3) - nums.begin();
        ll take = nums[i] * mpp[nums[i]] + solve(nums, j, n, mpp);

        return t[i] = max(skip, take);
    }

    ll maximumTotalDamage(vector<int>& power) {
        unordered_map<ll, ll> mpp;

        for (int p : power) mpp[p]++;

        vector<ll> nums;
        for (auto &itr : mpp) nums.push_back(itr.first);

        sort(nums.begin(), nums.end());
        int n = nums.size();

        t.assign(n + 1, -1);

        return solve(nums, 0, n, mpp);
    }*/
};
