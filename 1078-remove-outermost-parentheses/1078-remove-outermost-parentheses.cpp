class Solution {
public:
    string removeOuterParentheses(string s) {
        

        //counter based approach

        string ans = "";

        int counter = 0;

        for(int i  = 0; i < s.size(); i++){

            if(s[i] == '('){

                if(counter != 0){

                    counter++;
                    ans += s[i];
                } else{

                    counter++;
                }
            } 
            else{

                counter--;
                if(counter != 0){
                    ans += s[i];
                }
            }           
        }

        return ans;

        //stack based approach (tc- o(n) sc- o(n))
        /*stack<int>stk;

        string ans = "";

        for(int i = 0; i < s.size(); i++){

            if(s[i] == '('){
                if(!stk.empty()) ans += '(';
                stk.push('(');
            } else {
                stk.pop();
                if(!stk.empty()) ans+= ')';
            }
        }

        return ans;*/
    }
};