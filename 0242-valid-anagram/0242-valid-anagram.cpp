#include <unordered_map>
#include <string>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;
        
        unordered_map<char, int> count;
        
        // Count characters in s and t
        for (int i = 0; i < s.size(); i++) {
            count[s[i]]++;  // Increment count for character in s
            count[t[i]]--;  // Decrement count for character in t
        }
        
        // Check if all counts are zero
        for (const auto& kv : count) {
            if (kv.second != 0) return false;
        }
        
        return true;
    }
};
