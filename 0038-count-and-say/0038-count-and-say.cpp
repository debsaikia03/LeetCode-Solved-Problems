class Solution {
public:
    string countAndSay(int n) {
        
        string ans = "1";

        while(--n){

            string temp = "";
            int i = 0;

            while(i < ans.size()){
 
                char curr = ans[i];
                int count = 0;

                while(i < ans.size() && ans[i] == curr){

                    count++;
                    i++;
                }

                temp += to_string(count) + curr;
            }
            
            ans = temp;
        }

        return ans;
    }
};