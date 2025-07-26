class Solution {
public:
    int beautySum(string s) {
        
        int total = 0;

        for(int i = 0; i < s.size(); i++){ //O(n)
 
            unordered_map<char, int> freq;

            for(int j = i; j < s.size(); j++){ //O(n-i) : O(n)

                freq[s[j]]++;

                int maxF = 0, minF = INT_MAX;

                for(auto& [ch, count] : freq){ //O(26) : O(1) 

                    maxF = max(maxF, count);
                    minF = min(minF, count);
                }

                total += (maxF - minF);
            }
        }
        
        return total;
    }
};

//tc : O(n^2)
//sc : O(1) since it only takes O(26)