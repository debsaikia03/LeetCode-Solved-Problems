class Solution {
public:
    bool checkIfPangram(string sentence) {
        
        int count = 0;

        unordered_set<char> st;

        for(char ch : sentence){

            if(isalpha(ch) && st.find(ch) == st.end()){

                count++;
                st.insert(ch);
            }
        }

        return count == 26 ? true : false;
    }
};