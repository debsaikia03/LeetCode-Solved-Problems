class Solution {
public:

    string findRoot(string &word, unordered_set<string> &st){
        
        for(int i = 1; i <= word.length(); i++){

            string root = word.substr(0, i);

            if(st.count(root)){

                return root;
            }
        }

        return word;
    }

    string replaceWords(vector<string>& dictionary, string sentence) {
        
        unordered_set<string> st(dictionary.begin(), dictionary.end());

        stringstream ss(sentence);//get each word/token after seperated by whitespaces
        string word;//store each word/token

        string res;

        while(ss >> word){

            res += findRoot(word, st) + " ";
        }

        res.pop_back();

        return res;
    }
};