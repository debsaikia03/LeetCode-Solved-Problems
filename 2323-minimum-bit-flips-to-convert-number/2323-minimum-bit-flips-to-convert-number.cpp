class Solution {
public:
    int minBitFlips(int start, int goal) {
        int ans = start ^ goal;
        int count = 0;
        for (int j = 0; j < 32; ++j) {
            if (ans & (1 << j)) {
                count++;
            }
        }
        return count;
    }
};
