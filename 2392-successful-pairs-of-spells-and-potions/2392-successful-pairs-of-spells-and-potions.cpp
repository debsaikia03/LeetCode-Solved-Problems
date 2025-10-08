class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {

        vector<int> res;

        sort(potions.begin(), potions.end());
        
        for(double spell : spells){

            double potionStr = ceil(success/spell); //minimum strength required

            //iterator to find the idx of the value equal to or just more than the potionStr using lower_bound on sorted potions array
            auto itr = lower_bound(potions.begin(), potions.end(), potionStr);

            //alternate -> use user-defined binary search

            int countSuccess = potions.end() - itr;

            res.push_back(countSuccess);
        }

        return res;
    }
};