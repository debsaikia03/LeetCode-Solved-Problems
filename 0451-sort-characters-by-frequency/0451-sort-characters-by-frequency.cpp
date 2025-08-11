class Solution {
public:
    string frequencySort(string s) {

        // Step 1: Count the frequency of each character in the string
        unordered_map<char, int> mpp;
        for (char ch : s) {
            mpp[ch]++; // increment count for character 'ch'
        }

        // Step 2: Move the frequency map into a vector of pairs
        // Each element is (character, frequency)
        vector<pair<char, int>> vec(mpp.begin(), mpp.end());

        // Step 3: Sort the vector in descending order of frequency
        // If a.second > b.second → 'a' comes before 'b'
        sort(vec.begin(), vec.end(), [](auto& a, auto& b) {
            return a.second > b.second;
        });

        // Step 4: Rebuild the string based on sorted frequencies
        s = "";
        for (auto& [ch, count] : vec) {
            // Append 'count' copies of character 'ch' to the string
            s += string(count, ch);
        }

        // Step 5: Return the frequency-sorted string
        return s;
    }
};
