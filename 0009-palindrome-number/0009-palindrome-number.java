class Solution {
    public boolean isPalindrome(int x) {

        if (x < 0) return false; // Negative numbers are not palindromes

        // Convert the number to a string
        String str = Integer.toString(x);

        // Reverse the string and compare
        int len = str.length();
        for (int i = 0; i < len / 2; i++) {
            if (str.charAt(i) != str.charAt(len - i - 1)) {
                return false; // Not a palindrome
            }
        }

        return true; // Is a palindrome
    }
}