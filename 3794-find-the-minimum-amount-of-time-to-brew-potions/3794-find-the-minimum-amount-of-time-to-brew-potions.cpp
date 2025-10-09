class Solution {
public:
    long long minTime(vector<int>& skill, vector<int>& mana) {
        
        int n = skill.size();  // Number of wizards
        int m = mana.size();   // Number of potions

        // finishTime[i] stores the earliest time wizard i finishes all assigned work so far
        vector<long long> finishTime(n, 0);

        // Loop over each potion
        for(int i = 0; i < m; i++){
            
            long long int now = finishTime[0];  // Tracks running time as we assign wizards
            int currPotion = mana[i];           // Strength of the current potion

            // Forward pass: calculate earliest finishing times for each wizard sequentially
            for(int j = 1; j < n; j++){
                // Wizard j can start only after:
                // - he finishes previous work (finishTime[j])
                // - previous wizard finishes current potion (now + skill[j-1]*currPotion)
                now = max(finishTime[j], now + skill[j-1] * 1LL * currPotion);
            }

            // Update the last wizard's finish time after adding his work
            finishTime[n-1] = now + skill[n-1] * currPotion;

            // Backward pass: adjust earlier wizards to remove unnecessary idle time
            for(int j = n - 2; j >= 0; j--){
                // Wizard j's finish time = next wizard's finish time minus the work that next wizard did
                finishTime[j] = finishTime[j+1] - skill[j+1] * currPotion;
            }
        }

        // Return the total minimum time (when last wizard finishes the last potion)
        return finishTime[n-1];
    }
};
