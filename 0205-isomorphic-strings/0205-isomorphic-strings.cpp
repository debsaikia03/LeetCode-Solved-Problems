#include <unordered_map>
#include <string>
using namespace std;

// Template function to check if a value exists in a map
template <typename K, typename V>
bool isValuePresent(const unordered_map<K, V>& myMap, const V& valueToFind) {
    for (const auto& pair : myMap) {
        if (pair.second == valueToFind) {
            return true;
        }
    }
    return false;
}

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.length() != t.length()) return false;

        unordered_map<char, char> mpp;

        for (int i = 0; i < s.length(); i++) {
            char first = s[i];
            char second = t[i];

            // If first is already mapped
            if (mpp.find(first) != mpp.end()) {
                if (mpp[first] != second) return false;
            } else {
                // Check if second is already mapped to another character
                if (isValuePresent(mpp, second)) return false;

                // Create the mapping
                mpp[first] = second;
            }
        }

        return true;
    }
};
