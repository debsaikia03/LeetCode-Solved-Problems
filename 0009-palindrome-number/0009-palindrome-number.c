bool isPalindrome(int x) {
    
    int rev = 0;

    int dup = x;

    while(dup > 0){

        int digit = dup % 10;

        // Check for overflow before multiplying by 10 or adding the digit
        if (rev > (INT_MAX - digit) / 10) {
            return false; // Overflow would occur
        }

        rev = rev * 10 + digit;
        dup = dup / 10;
    }

    return rev == x;
    
}