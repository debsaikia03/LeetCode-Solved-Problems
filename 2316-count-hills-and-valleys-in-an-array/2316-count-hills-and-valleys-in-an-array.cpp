class Solution {
public:
    int countHillValley(vector<int>& nums) {

        //Compress the array by removing consecutive duplicates.
        vector<int> comp;
        comp.push_back(nums[0]);

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] != nums[i - 1]) {
                comp.push_back(nums[i]);
            }
        }

        int c = 0;
        // Skip consecutive duplicates
        for (int i = 1; i < comp.size() - 1; i++) {
            if (comp[i] == comp[i + 1]) {
                continue;  // Skip duplicates
            }

            if (comp[i] > comp[i - 1] && comp[i] > comp[i + 1] || comp[i] < comp[i - 1] && comp[i] < comp[i + 1]) {
                c++;  // Count hills or valleys
            }
        }
        
        return c;
    }
};
