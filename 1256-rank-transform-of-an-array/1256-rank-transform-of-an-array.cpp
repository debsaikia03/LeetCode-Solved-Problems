class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {

       vector<int> srtArr = arr;
       sort(srtArr.begin(), srtArr.end());

        unordered_map<int, int> rank;
        int rankValue = 1;

        for(int i : srtArr){

            if(rank.find(i) == rank.end())
                rank[i] = rankValue++;    
        }
        
        for(int& i : arr){

            i = rank[i];
        }

        return arr;   
    }
};