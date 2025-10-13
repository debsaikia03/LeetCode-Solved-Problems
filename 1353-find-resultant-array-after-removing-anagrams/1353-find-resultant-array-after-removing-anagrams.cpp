class Solution {
public:

    bool checkAnagram(string &s1, string &s2){

        if(s1.size() != s2.size()) return false;

        vector<int> strFreq(26, 0);

        for(int i = 0; i < s1.size(); i++){

            strFreq[s1[i] - 'a']++;
        }

        for(int j = 0; j < s2.size(); j++){

            strFreq[s2[j] - 'a']--;
        }

        for(int count : strFreq){

            if(count != 0) return false;
        }

        return true;
    }
    vector<string> removeAnagrams(vector<string>& words) {
        
        vector<string> res;

        res.push_back(words[0]);

        for(int i = 0; i < words.size(); i++){

            if(!checkAnagram(words[i], res.back())){

                res.push_back(words[i]);
            }
        }

        return res;
    }
};