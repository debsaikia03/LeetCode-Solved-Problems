class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> prev(n), next(n);
        stack<int> s1, s2;
        int mod = 1e9 + 7;

        // Previous Smaller Element
        for (int i = 0; i < n; ++i) {
            while (!s1.empty() && arr[s1.top()] > arr[i]) {
                s1.pop();
            }
            prev[i] = s1.empty() ? i + 1 : i - s1.top();
            s1.push(i);
        }

        // Next Smaller Element
        for (int i = n - 1; i >= 0; --i) {
            while (!s2.empty() && arr[s2.top()] >= arr[i]) {
                s2.pop();
            }
            next[i] = s2.empty() ? n - i : s2.top() - i;
            s2.push(i);
        }

        // Calculate result
        long long result = 0;
        for (int i = 0; i < n; ++i) {
            long long contrib = (long long)arr[i] * prev[i] * next[i];
            result = (result + contrib) % mod;
        }

        return (int)result;
    }
};
