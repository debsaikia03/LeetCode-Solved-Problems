class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        
        stack<int> stk;

        for(int &asteroid : asteroids){

            while(!stk.empty() && asteroid < 0 && stk.top() > 0){

                int sum = asteroid + stk.top();
                
                if(sum < 0){
                    stk.pop();
                }else if(sum > 0){
                    asteroid = 0;
                    break;
                }else{
                    stk.pop();
                    asteroid = 0;
                }
            }

            if(asteroid != 0){

                stk.push(asteroid);
            }
        }

        int s = stk.size();
        vector<int> res(s);

        int i = s - 1;
        while(!stk.empty()){

            res[i] = stk.top();
            stk.pop();
            i--;
        }

        return res;
    }
};