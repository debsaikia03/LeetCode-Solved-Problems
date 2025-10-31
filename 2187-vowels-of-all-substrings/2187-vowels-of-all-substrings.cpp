class Solution {
public:

    long long countVowels(string word) {

        vector<char> vowels = {'a','e','i','o','u'};

        long long count = 0;
        int n = word.size();

        for(int i = 0; i < word.size(); i++){

            char ch = word[i];
  
            if(find(vowels.begin(), vowels.end(), ch) != vowels.end()){

               count += (long long)(i + 1)*(n - i);
            }    
        }

        return count;

        //36/51 testcases passed
        /*vector<char> vowels = {'a','e','i','o','u'};

        long long maxCount = 0;
        
        for(int i = 0; i < word.size(); i++){
            for(int j = i; j < word.size(); j++){

                long long count = 0;
                string substring = word.substr(i, j-i+1);
                
                for(char ch : substring){

                    if(find(vowels.begin(), vowels.end(), ch) != vowels.end()){

                        count++;
                    }
                }

                maxCount += count;
            }
        }

        return maxCount;*/
    }
};