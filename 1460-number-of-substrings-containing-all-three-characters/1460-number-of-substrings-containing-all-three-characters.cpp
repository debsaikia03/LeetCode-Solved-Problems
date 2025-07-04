#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    int numberOfSubstrings(string s) {
        unordered_map<char, int> lastSeen;
        int count = 0;

    for (char ch = 'a'; ch <= 'c'; ++ch) {
        lastSeen[ch] = -1; 
    }

    for (int i = 0; i < s.size(); ++i) {
        // Update the last seen index of the current character
        lastSeen[s[i]] = i;

        // Check if all three characters have been seen
        if (lastSeen['a'] != -1 && lastSeen['b'] != -1 && lastSeen['c'] != -1) {
            count += 1 + min({lastSeen['a'], lastSeen['b'], lastSeen['c']});
        }
    }

    return count;
}
};
