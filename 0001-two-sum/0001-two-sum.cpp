class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mp; //hash map with value and index
        
        for(int i=0; i<nums.size(); i++){
            int temp = target - nums[i];  //temp value for storing the second element 
          
            if(mp.find(temp) != mp.end()){ //finding the second element
               return{mp[temp],i};   //if element found, return the two index
            }

            mp.insert({nums[i],i}); //if element not found, insert the currrent value and index 
        }

        return{}; //if element not found in the vector, return empty set
    }
};