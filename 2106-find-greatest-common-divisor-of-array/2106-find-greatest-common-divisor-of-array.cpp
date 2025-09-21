class Solution {
public:

    //euclidean algo: gcd(a,b) = gcd(a-b,b), where a > b
    //(a % b, b) instead of (a - b, b)

    int gcd(int a, int b) {

        // Base case: if b is 0, then a is the GCD
        if (b == 0) {
            return a;
        }

        // Recursive step: call gcd with b and the remainder of a divided by b
        return gcd(b, a % b);
    }

// Function to find gcd of array of numbers
    int findGCD(vector<int> &arr) {

        int mn = *min_element(arr.begin(), arr.end());
        int mx = *max_element(arr.begin(), arr.end());

        return gcd(mn, mx);
    }
};

