class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {

        unordered_map<char, int> mpp;

        for(char ch : ransomNote){

           mpp[ch]++;
        }

        for(char ch : magazine){

            if(mpp.count(ch)){

                mpp[ch]--;

                if(mpp[ch] == 0){

                    mpp.erase(ch);
                }
            }
        }

        
        return mpp.empty();
    }
};