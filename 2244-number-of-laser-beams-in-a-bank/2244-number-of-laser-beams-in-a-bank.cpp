class Solution {
public:
    // Returns the total number of laser beams.
    // bank: vector of strings where '1' = security device and '0' = empty.
    // Idea: only consecutive non-empty rows (in terms of device count) can form beams.
    // For each non-empty row, multiply its device count by the previous non-empty row's device count.
    // Time: O(R * C) where R = number of rows, C = columns per row.
    // Space: O(1) extra.
    int numberOfBeams(vector<string>& bank) {
        long long prevCount = 0;     // device count of previous non-empty row
        long long totalBeams = 0;    // accumulator (use long long to avoid overflow)
        
        for (const string &row : bank) {
            // count '1's in current row
            long long cnt = 0;
            for (char ch : row) {
                if (ch == '1') ++cnt;
            }
            
            if (cnt > 0) {
                // if there was a previous non-empty row, all devices in that row
                // connect to all devices in this row (since rows in between are empty)
                totalBeams += prevCount * cnt;
                // update previous non-empty row count
                prevCount = cnt;
            }
            // if cnt == 0, skip — it doesn't change prevCount
        }
        
        return static_cast<int>(totalBeams);
    }
};