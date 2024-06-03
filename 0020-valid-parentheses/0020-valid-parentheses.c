void push(char arr[], char ch, int *top) {
    (*top)++;
    arr[*top] = ch;
}

// Function to pop a character from the stack
void pop(int *top) {
    (*top)--;
}

// Function to check if the input string has valid brackets
bool isValid(char* s) {
    int n = strlen(s);  // Get the length of the string

    // Check if the first character is a closing bracket or if the length is odd
    if(s[0] == ')' || s[0] == '}' || s[0] == ']' || n % 2 != 0) {
        return false;
    }

    char arr[n];  // Array to use as a stack
    int top = -1;  // Initialize top of stack

    // Loop through each character in the string
    for(int i = 0; i < n; i++) {
        push(arr, s[i], &top);  // Push current character onto the stack

        // Check if the top two characters on the stack form a matching pair
        if(top-1 != -1){
        if((arr[top] == ')' && arr[top-1] == '(') ||
           (arr[top] == '}' && arr[top-1] == '{') ||
           (arr[top] == ']' && arr[top-1] == '[')) {
            pop(&top);  // Pop the matching pair from the stack
            pop(&top);
        }
        }
    }

    // If stack is not empty, return false
    if(top != -1) {
        return false;
    }

    // Return true if stack is empty, indicating all brackets matched
    return true;
}