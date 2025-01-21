class Solution {
public:
    bool isPalindrome(int x) {
    if (x < 0) return false; // Negative numbers are not palindromes

    // Convert the number to a string
    string str = to_string(x);

    // Reverse the string and compare
    int len = str.length();
    for (int i = 0; i < len / 2; i++) {
        if (str[i] != str[len - i - 1]) {
            return false; // Not a palindrome
        }
    }

    return true; // Is a palindrome
}
    
};