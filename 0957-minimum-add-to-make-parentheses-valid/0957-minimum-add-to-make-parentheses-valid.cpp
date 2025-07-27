class Solution {
public:
    int minAddToMakeValid(string s) {

        /*stack<int> stk;
        

        for(char ch : s){

            if(ch == '('){

                stk.push(ch);
            } else {

                if(!stk.empty() && stk.top() == '('){

                    stk.pop();
                } else {

                    stk.push(ch);
                }
            }
        }

        return stk.size();*/

        int open = 0, close = 0;

        for(char ch : s){

            if(ch == '(') open++;

            else {

                if(open <= 0) close++;

                else open--;
            }
        }

        return open+close;
    }
};