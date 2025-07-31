class Solution {
public:

    bool rabinKarp(string a, string b){

        int base = 256;
        int mod = 1e9 + 7; //to prevent integer overflow

        int m = b.size(); //pattern size
        int n = a.size(); //text size

        if(m > n) return false;

        long long patternHash = 0; //store hash value of the pattern string

        long long textHash = 0; //store hash value of the rolling hash substrigs
        long long h = 1; //a helper function that removes the leftmost character from the hash when sliding the window

        for(int i = 0;  i < m - 1; ++i){

            h = (h * base) % mod; // h = base^(m-1) % mod //h is used to remove the leftmost character from the hash value
        }

        for(int i = 0; i < m; ++i){

            patternHash = (base * patternHash + b[i]) % mod; //calculates the hash value for the pattern
            textHash = (base * textHash + a[i]) % mod; //calculates the hash value for the text substring
        }

        for(int i = 0; i <= n - m; ++i){

            if(patternHash == textHash && a.substr(i, m) == b){ //check if the hash values match and if the actual strings match and substring is equal to the pattern

                return true;
            }

            if(i < n - m){

                textHash = (base * (textHash - a[i] * h) + a[i+m]) % mod; //update the hash value for the text substring by removing the leftmost character and adding the new rightmost character
                if(textHash < 0) textHash += mod; //to ensure the hash value is non-negative
            }
        }

        return false; //if no match is found
    }


    int repeatedStringMatch(string a, string b) {
        
        int minRepeats = ceil((double)b.length()/a.length());

        string repeatedA = "";

        for (int i = 0; i < minRepeats; i++) {
            
            repeatedA += a;
        }

        for(int i = 0; i <= 2; i++){

            if(rabinKarp(repeatedA, b)){

                return minRepeats + i;
            }

            repeatedA += a;
        }

        return -1;
    }
};