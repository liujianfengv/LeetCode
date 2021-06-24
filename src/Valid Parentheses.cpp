class Solution {
public:
    bool isValid(string s) {
    unordered_map<char, char> left = {
                                       {'(',')'},
                                       {'[',']'},
                                       {'{','}'}
                                     };
    unordered_map<char, char> right = {
                                       {')','('},
                                       {']','['},
                                       {'}','{'}
                                      };
    stack<char> stack;
    for (auto c : s) {
        if (left.find(c) != left.end()) {
            stack.push(c);
        } else {
            if (stack.size() == 0) {
                return false;
            }
            char top = stack.top();
            if (top == right[c]) {
                stack.pop();
            } else {
                return false;
            }
        }
    }
    return stack.size() == 0;
    }
};