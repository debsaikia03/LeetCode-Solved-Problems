class Solution {
public:

    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        unordered_map<string, vector<string>> mpp;

        for(auto& s: strs){

           string t = s;

           sort(t.begin(), t.end()); //sort letters in the string
           mpp[t].push_back(s); //group by sorted strin
        }

        vector<vector<string>> res;
        for(auto& p: mpp){

            res.push_back(p.second);
        }

        return res;


    //time limit exceeded for last case 126/127 
    /*bool checkFreq(string first, string second){

        vector<int> str1(26);
        vector<int> str2(26);

        for(char ch : first){

            str1[ch - 'a']++;
        }

        for(char ch : second){

            str2[ch - 'a']++;
        }

        for(int i = 0; i < 26; i++){

            if(str1[i] != str2[i]){

                return false;
            }
        }

        return true;
    }

    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        vector<vector<string>> res;

        for(int i = 0; i < strs.size(); i++){

            if(strs[i] == "0" && strs[i] != "") continue;

            vector<string> group;

            group.push_back(strs[i]);

            for(int j = i+1; j < strs.size(); j++){

                if( strs[j] == "" || strs[i].size() != strs[j].size() || !checkFreq(strs[i], strs[j])){

                   continue;
                }

                group.push_back(strs[j]);
                
                strs[j] = "0";
            } 

            strs[i] = "0";
            res.push_back(group);
        }

        return res;*/
    }
};