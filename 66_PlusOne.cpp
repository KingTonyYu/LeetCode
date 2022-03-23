class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int length = static_cast<int>(digits.size());
        bool plus_one = true;
        for (int i = length - 1; i > -1; i--) {
            if (!plus_one)
                break;
            int digit = digits[i] + 1;
            if (digit < 10) {
                plus_one = false;
            }
            else {
                digit -= 10;
            }
            digits[i] = digit;

        }
        if (plus_one) {
            digits.insert(digits.begin(), 1);
        }

        return digits;
    }
};