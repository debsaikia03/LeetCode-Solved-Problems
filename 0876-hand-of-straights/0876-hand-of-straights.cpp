class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        
        int n = hand.size();

        // If total cards can't be divided evenly into groups of size `groupSize`, it's impossible
        if (n % groupSize != 0) return false;

        // Use an ordered map to store card frequency
        // Keys are card values (sorted automatically), values are counts
        map<int, int> mpp;

        // Count the frequency of each card
        for (int card : hand) {
            mpp[card]++;
        }

        // Keep forming groups until all cards are used
        while (!mpp.empty()) {

            // Get the smallest card value currently available
            int start = mpp.begin()->first;

            // Try to build a group starting from `start`
            for (int i = 0; i < groupSize; i++) {

                int curr = start + i; // The current card we need in this group

                // If we can't find the required card, grouping fails
                if (mpp.find(curr) == mpp.end()) return false;

                // Use one occurrence of this card
                mpp[curr]--;
                
                // If count becomes 0, remove the card from the map
                if (mpp[curr] == 0) {
                    mpp.erase(curr);
                }
            }
        }

        // If we used all cards successfully, return true
        return true;
    }
};
