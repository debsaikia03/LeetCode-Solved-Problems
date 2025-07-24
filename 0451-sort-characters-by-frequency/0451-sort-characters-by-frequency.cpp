class Solution {
public:
    string frequencySort(string s) {

        unordered_map<char, int> mpp;

        for(char ch: s){
            mpp[ch]++;
        }

        vector<pair<char,int>> vec(mpp.begin(), mpp.end());

        sort(vec.begin(), vec.end(), [](auto& a, auto& b){
            return a.second > b.second;
        });

        s = "";

        for(auto& [ch, count]: vec){
            s += string(count, ch);
        }

        return s;
    }
};