class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        // Step 1: Count frequency of each number
        unordered_map<int, int> mpp;
        for (int num : nums) {
            mpp[num]++; // Increment frequency for num
        }

        // Step 2: Create a min-heap (priority_queue) based on frequency
        // Comparator returns true if a's frequency > b's frequency, 
        // meaning smallest frequency will be at the top
        auto cmp = [&](pair<int, int> a, pair<int, int> b) {
            return a.second > b.second; // min-heap by frequency
        };

        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(cmp);

        // Step 3: Push each number and its frequency into the heap
        for (auto& p : mpp) {
            pq.push({p.first, p.second}); // push {number, frequency}

            // Maintain heap size <= k
            // If more than k elements, remove the smallest frequency
            if (pq.size() > k) pq.pop();
        }

        // Step 4: Extract the elements from the heap into result vector
        vector<int> ans;
        while (!pq.empty()) {
            ans.push_back(pq.top().first); // take the number
            pq.pop();
        }

        // Note: The result will be in ascending order of frequency
        // If order doesn't matter, return directly
        return ans;
    }
};
