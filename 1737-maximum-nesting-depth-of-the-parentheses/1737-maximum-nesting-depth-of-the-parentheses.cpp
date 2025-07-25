class Solution {
public:
    int maxDepth(string s) {

        int maxN = 0;

        int top = 0;
        
        stack<int> stk;
        
        for(char c : s){

            if(c == 40){

                stk.push(c);
                top++;
                maxN = max(maxN, top);
            } else if(c == 41){

                stk.pop();
                top--;
            }
        }

        return maxN;
    }
};