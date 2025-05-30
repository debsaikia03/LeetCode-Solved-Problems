class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {

        intervals.push_back(newInterval);

        sort(intervals.begin(), intervals.end());

        vector<vector<int>> merge;

        merge.push_back(intervals[0]);

        for(int i = 1; i < intervals.size(); i++){

            vector<int>& last = merge.back();

            if(intervals[i][0] <= last[1]) last[1] = max(last[1], intervals[i][1]);

            else merge.push_back(intervals[i]);
        }

        return merge;        
    }
};