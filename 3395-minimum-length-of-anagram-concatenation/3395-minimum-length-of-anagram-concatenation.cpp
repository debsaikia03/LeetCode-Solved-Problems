class Solution {
public:

    bool matchFreq(const string& s, int len){

        int n = s.size();

        vector<int> strFreq(26, 0);

        for(int i = 0; i < len; i++){

           strFreq[s[i] - 'a']++;
        }

        for(int i = len; i < n; i += len){

            vector<int> rangeFreq(26, 0);

            for(int j = i; j < i + len; j++){

                rangeFreq[s[j] - 'a']++;
            }

            for(int j = 0; j < 26; j++){

                if(strFreq[j] != rangeFreq[j]){

                    return false;
                }
            }
        }

        return true;
    }

    int minAnagramLength(const string& s) {

        int n = s.size();

        vector<int> divisors;

        for(int i = 1; i <= n; i++){

            if(n % i == 0){

                divisors.push_back(i);
            }
        }


        for(int len : divisors){

            if(matchFreq(s, len)){

                return len;
            }
        }

        return -1;
    }
};
