class Solution {
public:
    int romanToInt(string s) {

        unordered_map<char, int> roman ={

            {'I',1},
            {'V',5},
            {'X',10},
            {'L',50},
            {'D',500},
            {'C',100},
            {'M',1000}
        };

        int sum = 0;

        int n = s.size();

        for(int i = 0; i < n; i++){

           if(i < n - 1 && roman[s[i]] < roman[s[i+1]]){

               sum -= roman[s[i]];
           }
           
           else{

              sum += roman[s[i]];
           }
        }


        return sum;
        

    }
};