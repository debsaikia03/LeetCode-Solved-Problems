class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {

        // Comparator for the min-heap (priority queue)
        auto compare = [&](const vector<int>& a, const vector<int>& b) {
            return a[0] + a[1] > b[0] + b[1];  // Min-heap based on sum of pairs
        };

        // Priority queue storing {nums1[i], nums2[j], j}
        priority_queue<vector<int>, vector<vector<int>>, decltype(compare)> pq(compare);

        vector<vector<int>> res;

        // Push the first element in nums2 for up to k elements from nums1
        for (int i = 0; i < nums1.size() && i < k; i++) {
            pq.push({nums1[i], nums2[0], 0});
        }

        // Extract the k smallest pairs
        while (k-- > 0 && !pq.empty()) {
            vector<int> curr = pq.top();
            pq.pop();

            res.push_back({curr[0], curr[1]});  // Add the current pair

            int idx = curr[2];  // Index in nums2

            // Push the next pair in the same row (nums1[i], nums2[j+1]) if possible
            if (idx + 1 < nums2.size()) {
                pq.push({curr[0], nums2[idx + 1], idx + 1});
            }
        }

        return res;
    }
};
//tc: O(klogk)
//sc: O(k)