class Solution {
public:
    bool isNumber(string s) {
        string s1;
        string s2;
        bool isE = false;
        int index_e = -1;

        if (s.find('e') != string::npos) {
            size_t pos = s.find('e');
            isE = true;
            index_e = static_cast<int>(pos);            
        }

        if (s.find('E') != string::npos) {
            size_t pos = s.find('E');
            isE = true;
            index_e = static_cast<int>(pos);
        }

        if (!isE)
            return isDecimal(s) || isInteger(s);
        s1 = s.substr(0, index_e);
        s2 = s.substr(index_e + 1);
        // cout << s1 << endl << s2;
        return (isDecimal(s1) || isInteger(s1)) && isInteger(s2);
    }

    bool isDecimal(string s) {
        if (s.empty())
            return false;
        int length = static_cast<int>(s.size());
        if (s[0] == '+' || s[0] == '-')
            return isPureDecimal(s.substr(1));
        return isPureDecimal(s);
    }

    bool isInteger(string s) {
        if (s.empty())
            return false;
        int length = static_cast<int>(s.size());
        if (s[0] == '+' || s[0] == '-')
            return isPureInteger(s.substr(1));
        return isPureInteger(s);
    }

    bool isPureDecimal(string s) {
        if (s.empty())
            return false;
        int length = static_cast<int>(s.size());
        bool isDot = false;

        for (int i = 0; i < length; i++) {
            if (isNum(s[i]))
                continue;
            if (s[i] == '.' && !isDot) {
                isDot = true;
                continue;
            }
            return false;
        }
        if (length == 1 && isDot)
            return false;
        return isDot;
    }

    bool isPureInteger(string s) {
        if (s.empty())
            return false;
        int length = static_cast<int>(s.size());

        for (int i = 0; i < length; i++) {
            if (!isNum(s[i]))
                return false;
        }
        return true;
    }

    bool isNum(char c) {
        return c >= '0' && c <= '9';
    }
};