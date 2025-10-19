class Solution {
public:

    void rotate(string &s, int b){

        reverse(s.begin(), s.end());
        reverse(s.begin(), s.begin() + b);
        reverse(s.begin() + b, s.end());
    }

    string findLexSmallestString(string s, int a, int b) {
        
        string smallestString = s;

        //bfs
        unordered_set<string> visited;
        queue<string> que;
        que.push(s);
        visited.insert(s);

        while(!que.empty()){

            string curr = que.front();
            que.pop();

            if(curr < smallestString){

                smallestString = curr;
            }

            //operation 1: add a to the digits
            string temp = curr;

            for(int i = 1; i < temp.length(); i+=2){

                temp[i] = ((temp[i] - '0' + a) % 10) + '0';
            }

            if(!visited.count(temp)){

                visited.insert(temp);
                que.push(temp);
            }

            //operation 2: rotate right by b
            rotate(curr, b);

            if(!visited.count(curr)){

                visited.insert(curr);
                que.push(curr);
            }
        }

        return smallestString;
    }
    //tc & sc: O(n^2)
};