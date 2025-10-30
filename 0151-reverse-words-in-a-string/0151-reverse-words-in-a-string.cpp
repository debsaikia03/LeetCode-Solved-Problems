class Solution {
public:
    string reverseWords(string s) {

        stringstream ss(s);
        string word;
        vector<string> words;

        //extract each word from the string
        while(ss >> word){

            words.push_back(word);
        }

        //reverse the order of the words
        reverse(words.begin(), words.end());

        //join the words 
        string ans;

        for(int i = 0; i < words.size(); i++){
 
            if(i > 0) ans += " ";

            ans += words[i];
        }

        return ans;

        /*string ans = "";

        int n = s.size();

        reverse(s.begin(), s.end());

        for(int i = 0; i < n; i++){

            string word = "";
            while(i < n && s[i] != ' '){
                word += s[i];
                i++;
            }

            reverse(word.begin(), word.end());

            if(word.length() > 0) ans += " " + word;
        }

        return ans.substr(1);*/
    }
};