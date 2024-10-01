// CODE

class solution {
public:
    long long multiplyTwoLists(Node *first, Node *second) {
        long long num1 = 0, num2 = 0;
        const long long MOD = 1e9 + 7;
        
        // Traverse first list and generate the number
        while (first != NULL) {
            num1 = (num1 * 10 + first->data) % MOD;
            first = first->next;
        }
        
        // Traverse second list and generate the number
        while (second != NULL) {
            num2 = (num2 * 10 + second->data) % MOD;
            second = second->next;
        }
        
        // Multiply the two numbers and return the result modulo MOD
        return (num1 * num2) % MOD;
    }
};