#include <stdbool.h>
#include <string.h>

bool isValid(char* s) {
    char stack[10000];
    int top = -1;
    
    for (int i = 0; s[i] != '\0'; i++) {
        
        // If opening bracket, push to stack
        if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
            stack[++top] = s[i];
        }
        else {
            // If stack is empty → no matching opening
            if (top == -1)
                return false;
            
            char topElement = stack[top--];
            
            // Check matching pairs
            if ((s[i] == ')' && topElement != '(') ||
                (s[i] == '}' && topElement != '{') ||
                (s[i] == ']' && topElement != '[')) {
                return false;
            }
        }
    }
    
    // If stack empty → valid
    return top == -1;
}