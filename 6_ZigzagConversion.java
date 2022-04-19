class Solution {
    public String convert(String s, int numRows) {
        int length = s.length();
        if (numRows == 1)
            return s;
        char[] chars = new char[length];
        int counter = 0;

        for (int i = 0; i < numRows; i++) {
            int cur = i;
            while (cur < length) {
                if (i != numRows - 1) {
                    chars[counter] = s.charAt(cur);
                    counter++;
                    cur += 2 * (numRows - i - 1);
                }

                if (cur >= length)
                    break;

                if (i != 0) {
                    chars[counter] = s.charAt(cur);
                    counter++;
                    cur += 2 * i;
                }
            }
        }
        return new String(chars);
    }
}