class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        
        priority_queue<int, vector<int>, less<int>> pq;

        for(int i : nums){

            pq.push(i);
        } 

        int i = k - 1;
        
        while(i--){
            pq.pop();
        }

        return pq.top();
    }
};