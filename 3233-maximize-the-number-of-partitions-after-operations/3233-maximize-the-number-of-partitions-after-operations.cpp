class Solution {
public:
    int maxPartitionsAfterOperations(const string &s, int k) {
        int n = s.size();
        // Memoization: key -> value
        // We encode state (i, canChange, mask) into a single key, or use a map of maps, etc.
        unordered_map<long long, int> memo;
        // We define dp(i, canChange, mask) = max number of partitions from index i (not counting a partition already in progress).
        int extra = dfs(s, 0, 1, 0, k, memo);
        // +1 for the first partition
        return extra + 1;
    }

private:
    int dfs(const string &s,
            int i,
            int canChange,
            int mask,
            int k,
            unordered_map<long long, int> &memo) {
        int n = s.size();
        if (i == n) {
            return 0;
        }
        // Encode state (i, canChange, mask) into one long long key
        // We need enough bits for i, canChange, mask.
        // Suppose i uses up to 14 bits if n ≤ 10^4, mask is 26 bits, canChange 1 bit → total < 64 bits
        long long key = ((long long)i << 27) | ((long long)canChange << 26) | (long long)mask;
        if (memo.count(key)) {
            return memo[key];
        }
        int res = INT_MIN;

        // Helper lambda: try to “use” a new bit (newBit) at position i, with nextCanChange
        auto consider = [&](int newBit, int nextCanChange) {
            int newMask = mask | newBit;
            // If distinct bits in newMask exceed k, we must start a new partition here
            if (__builtin_popcount(newMask) > k) {
                // Start a new partition at i: count +1, reset mask to newBit
                return 1 + dfs(s, i + 1, nextCanChange, newBit, k, memo);
            } else {
                // Continue in the same partition
                return dfs(s, i + 1, nextCanChange, newMask, k, memo);
            }
        };

        // Option 1: do not change s[i]
        int curBit = 1 << (s[i] - 'a');
        res = max(res, consider(curBit, canChange));

        // Option 2: if we can still change, try changing to any character 'a'..'z'
        if (canChange) {
            for (int c = 0; c < 26; c++) {
                int bit = 1 << c;
                if (bit == curBit) continue;  // same as original, redundant
                res = max(res, consider(bit, 0));
            }
        }

        memo[key] = res;
        return res;
    }
};
