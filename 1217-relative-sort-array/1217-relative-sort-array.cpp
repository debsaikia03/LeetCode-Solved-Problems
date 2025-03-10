class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        
        map<int, int> freq;

        for(int  i : arr1){

            freq[i]++;
        }

        
        int idx = 0;

        for(int i : arr2){

            while(freq[i] > 0){

                arr1[idx] = i;
                idx++;
                freq[i]--; 
            }

            freq.erase(i);
        }

        for(auto& [num, count]: freq){

            while(count > 0){

                arr1[idx] = num;
                idx++;
                count--;            
            }
        }

        return arr1;
    }
};