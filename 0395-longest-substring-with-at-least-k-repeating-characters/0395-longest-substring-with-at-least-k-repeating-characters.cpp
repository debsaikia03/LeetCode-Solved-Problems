class Solution {
public:
    int longestSubstring(string s, int k) {

        //sliding window - O(26 * n)
        int n = s.size();  // total length of the string
        int maxLen = 0;    // stores the maximum length of valid substring found

        // Try all possible numbers of distinct characters in the window
        // targetUnique = how many distinct letters we allow in the sliding window
        for(int targetUnique = 1; targetUnique <= 26; targetUnique++) {

            vector<int> freq(26, 0); // frequency of each lowercase letter in current window
            int left = 0;             // left boundary of the sliding window
            int right = 0;            // right boundary of the sliding window
            int uniqueCount = 0;      // current number of distinct characters in the window
            int countAtLeastK = 0;    // number of distinct chars in window that appear at least k times

            // Slide the window over the string
            while(right < n) {

                // --- Expand the window to include s[right] ---
                if(freq[s[right] - 'a'] == 0) uniqueCount++;   // new character enters window
                freq[s[right] - 'a']++;                        // increment frequency of this char
                if(freq[s[right] - 'a'] == k) countAtLeastK++; // char just reached k occurrences
                right++;                                       // move right pointer forward

                // --- Shrink window if we have more unique chars than targetUnique ---
                while(uniqueCount > targetUnique) {
                    if(freq[s[left] - 'a'] == k) countAtLeastK--; // removing a char that had ≥k occurrences
                    freq[s[left] - 'a']--;                         // decrease its frequency
                    if(freq[s[left] - 'a'] == 0) uniqueCount--;   // char completely removed from window
                    left++;                                       // move left pointer forward
                }

                // --- Check if the current window is valid ---
                // Valid if all unique characters appear at least k times
                if(uniqueCount == countAtLeastK) {
                    maxLen = max(maxLen, right - left); // update maximum length
                }
            }
        }

        return maxLen; // return the length of the longest valid substring

        //Brutefore - o(n^3)
        /*int n = s.size();

        int longStr= 0;

        for(int i = 0; i < n; i++){
            for(int j = i; j < n; j++){

                string subStr = s.substr(i, j - i + 1);

                unordered_map<char, int> mpp;

                for(char ch : subStr){

                    mpp[ch]++;
                }

                bool valid = true;
                for(auto& p : mpp){

                    if(p.second < k){

                        valid = false;
                        break;
                    }
                }

                if(valid && longStr < subStr.size()){

                    longStr = subStr.size();
                }
            }
        }

        return longStr;*/  
    }
};