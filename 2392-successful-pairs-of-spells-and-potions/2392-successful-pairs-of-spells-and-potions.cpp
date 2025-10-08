class Solution {
public:

    int binarySearch(vector<int>& potions, double potionStr){

        int l = 0, r = potions.size(); //may return potions.size() if all elements < potionStr

        while(l < r){

            int mid = l + (r - l) / 2;

            if(potions[mid] < potionStr){

                l = mid + 1;
            }else{

                r = mid;
            }
        }
 
        return l;
    }

    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {

        vector<int> res;

        sort(potions.begin(), potions.end());
        
        for(double spell : spells){

            double potionStr = ceil(success/spell); //minimum strength required

            //iterator to find the idx of the value equal to or just more than the potionStr using lower_bound on sorted potions array
            //auto itr = lower_bound(potions.begin(), potions.end(), potionStr);

            //int countSuccess = potions.end() - itr;

            //alternate -> use user-defined binary search to find the lower_bound
            int idx = binarySearch(potions, potionStr);

            int countSuccess =  potions.size() - idx;

            res.push_back(countSuccess);
        }

        return res;
    }
};