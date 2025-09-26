class Solution {
public:

    bool comparator(string first, string second){

        string str1 = first+second;
        string str2 = second+first;

        int i = 0;
        while(str1[i] && str2[i]){

            if(str1[i] > str2[i]){

                return true;
            }else if(str1[i] < str2[i])
                return false;

            i++;
        }

        return false;
    }
    
    string largestNumber(vector<int>& nums) {

        vector<string> str;

        for (int num : nums) {
            str.push_back(to_string(num));
        }

        sort(str.begin(), str.end(), [](string &a, string &b){

            return a + b > b + a;
        });

        if(str[0] == "0") return "0";
        
        string res = "";

        for(string num : str){

            res += num;
        }

        return res;
    }
};