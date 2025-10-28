#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        int leftSum = 0;
        int validCount = 0;

        for (int currentNum : nums) {
            if (currentNum != 0) {
                // Add to left sum as we move along
                leftSum += currentNum;
            } else {
                // When we encounter a zero, calculate the right sum
                int rightSum = totalSum - leftSum;

                // Case 1: perfectly balanced → both directions valid
                if (leftSum == rightSum)
                    validCount += 2;

                // Case 2: off by one → only one direction valid
                else if (abs(leftSum - rightSum) == 1)
                    validCount++;
            }
        }

        return validCount;
    }
};
