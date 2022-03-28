class Solution {
public:
    int calculate(string s) {
        int tmp = 0;
        return helper(s, tmp);
    }

    int helper(string& s, int& loc) {
        char operation = '+';
        int length = static_cast<int>(s.size());
        int num = 0;
        vector<int> list;
        for (; loc < length; loc++) {
            if (s[loc] == ' ')
                continue;

            else if (isdigit(s[loc]))
                num = getNumber(s, loc);

            else if (s[loc] == '(')
                num = helper(s, ++loc);

            switch (operation) {
                case '+':
                    list.push_back(num);
                    break;
                case '-':
                    list.push_back(-num);
                    break;
                case '*':
                    list.back() *= num;
                    break;
                case '/':
                    list.back() /= num;
                    break;
            }
            if (loc >= length || s[loc] == ')')
                break;
            operation = s[loc];
        }
        int ans = 0;
        for (auto num : list) {
            ans += num;
        }
        loc++;
        return ans;
    }

    int getNumber(string& s, int& loc) {
        int ans = 0;
        int length = static_cast<int>(s.size());
        while (loc < length) {
            if (isdigit(s[loc])) {
                ans = ans * 10 + s[loc] - '0';
                loc++;
            }
            else
                break;
        }
        return ans;
    }
};