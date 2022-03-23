class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        vector<int> stack;
        for (const auto& token : tokens) {
            if (isdigit(token.back())) {
                stack.push_back(stoi(token));
                continue;
            }

            int second = stack.back();
            stack.pop_back();
            int first = stack.back();
            stack.pop_back();
            int ans;

            switch (token[0]) {
                case '+':
                    stack.push_back(first + second);
                    break;
                case '-':
                    stack.push_back(first - second);
                    break;
                case '*':
                    stack.push_back(first * second);
                    break;
                case '/':
                    stack.push_back(first / second);
                    break;
            }

        }
        return stack.back();
    }
};