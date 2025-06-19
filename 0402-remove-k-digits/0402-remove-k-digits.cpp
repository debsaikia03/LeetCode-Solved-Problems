class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> stk;

        for (char digit : num) {
            while (!stk.empty() && k > 0 && stk.top() > digit) {
                stk.pop();
                k--;
            }
            stk.push(digit);
        }

        // If k > 0, remove remaining digits from the end
        while (k > 0 && !stk.empty()) {
            stk.pop();
            k--;
        }

        // Build the result string
        string res;
        while (!stk.empty()) {
            res += stk.top();
            stk.pop();
        }

        while (res.size()!= 0 && res.back() == '0') {
            res.pop_back();
        }

        reverse(res.begin(), res.end());

        return res.empty() ? "0" : res;
    }
};
