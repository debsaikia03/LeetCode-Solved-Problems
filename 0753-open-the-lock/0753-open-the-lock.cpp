class Solution {
public:

    void fillNeightbours(queue<string>& q, string& curr, unordered_set<string>& s){

        for(int i = 0; i < 4; i++){

            char ch = curr[i];

            char dec = ch == '0' ? '9' : ch - 1;
            char inc = ch == '9' ? '0' : ch + 1;

            //decrement an integer
            curr[i] = dec;
            if(s.find(curr) == s.end()){

                s.insert(curr);
                q.push(curr);
            }

            //increment an integer
            curr[i] = inc;
            if(s.find(curr) == s.end()){

                s.insert(curr);
                q.push(curr);
            }

            curr[i] = ch;
        }
    }

    int openLock(vector<string>& deadends, string target) {
        
        unordered_set<string> s(deadends.begin(), deadends.end());

        string start = "0000";

        if(s.find(start) != s.end()){

            return -1;
        }

        queue<string> q;
        q.push(start);

        int level = 0;
        
        while(!q.empty()){

            int n = q.size();

            while(n--){

                string curr = q.front();
                q.pop();

                if(curr == target){

                    return level;
                }

                fillNeightbours(q, curr, s);
            }

            level++;
        }

        return -1;
    }
};