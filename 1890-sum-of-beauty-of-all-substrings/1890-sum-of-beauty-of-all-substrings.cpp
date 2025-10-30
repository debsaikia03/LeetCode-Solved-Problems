class Solution {
public:
    int beautySum(string s) {
        
        int total = 0;

        for(int i = 0; i < s.size(); i++){ //O(n)
 
            unordered_map<char, int> freq;

            for(int j = i; j < s.size(); j++){ //O(n-i) : O(n)

                freq[s[j]]++;

                int maxFreq = 0, minFreq = INT_MAX;

                for(auto& [ch, count] : freq){ //O(26) : O(1) 

                    maxFreq = max(maxFreq, count);
                    minFreq = min(minFreq, count);
                }

                total += (maxFreq - minFreq);
            }
        }
        
        return total;
    }
};

//tc : O(n^2)
//sc : O(1) since it only takes O(26)