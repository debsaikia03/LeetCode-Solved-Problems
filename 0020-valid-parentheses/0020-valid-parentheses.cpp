class Solution {
public:
    bool isValid(string s) {

        stack<char> stk;
        
        for (int i = 0; i < s.size(); i++) {

            char ch = s[i];

            if (ch == '(' || ch == '[' || ch == '{') {
                stk.push(ch);
            } else {
                if (stk.empty()) return false;

                char c = stk.top();
                stk.pop();

                if ((ch == ')' && c != '(') ||
                    (ch == '}' && c != '{') ||
                    (ch == ']' && c != '[')) {
                    return false;
                }
            }            
        }

        return stk.empty();
    }
};
