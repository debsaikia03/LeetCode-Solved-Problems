class Solution {
public:
    string longestPalindrome(string s) {
        // Transform the string
        string t = "#";
        for (char c : s) t += c, t += '#';
        int n = t.size();

        vector<int> p(n, 0);
        int c = 0, r = 0, maxLen = 0, center = 0;

        for (int i = 0; i < n; i++) {
            int mirror = 2 * c - i;
            if (i < r) p[i] = min(r - i, p[mirror]);

            // Expand around center i
            int a = i + (1 + p[i]);
            int b = i - (1 + p[i]);
            while (a < n && b >= 0 && t[a] == t[b]) {
                p[i]++;
                a++;
                b--;
            }

            // Update center and right boundary
            if (i + p[i] > r) {
                c = i;
                r = i + p[i];
            }

            // Track longest palindrome
            if (p[i] > maxLen) {
                maxLen = p[i];
                center = i;
            }
        }

        int start = (center - maxLen) / 2;
        return s.substr(start, maxLen);
    }
};
