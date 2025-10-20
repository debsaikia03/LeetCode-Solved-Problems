class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        
        int sum = 0;

        for(string str : operations){

            if(str[0] == '+' || str[2] == '+'){

                sum++;
            }

            if(str[0] == '-' || str[2] == '-'){

                sum--;
            }
        }

        return sum;
    }
};