class Solution {
public:
    bool checkFreq(vector<int>& a, vector<int>& b) {
        for (int i = 0; i < 26; i++) {
            if (a[i] != b[i]) return false;
        }
        return true;
    }

    vector<int> findAnagrams(string s, string p) {
        
        vector<int> sCount(26, 0), pCount(26, 0);
        vector<int> result;

        int m = p.size(), n = s.size();
        if (n < m) return result;

        for (char ch : p)
            pCount[ch - 'a']++;

        for (int i = 0; i < n; i++) {
            sCount[s[i] - 'a']++;

            if (i >= m)
                sCount[s[i - m] - 'a']--;

            if (i >= m - 1 && checkFreq(sCount, pCount))
                result.push_back(i - m + 1);
        }

        return result;
    }
};
