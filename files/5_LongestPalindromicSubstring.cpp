class Solution {
public:
    string longestPalindrome(string s) {
//         // 2d dp
//         string max_string = s.substr(0, 1);
//         int max_length = 1;
//         int length = static_cast<int>(s.size());
//         vector<vector<bool>> table(length, vector<bool>(length, false));
        
//         for (int i = 0; i < length; i++)
//         {
//             table[i][i] = true;
//         }
        
//         for (int i = 1; i < length; i++)
//         {
//             table[i][i - 1] = true;
//         }
        
//         for (int l = length - 2; l > -1; l--)
//         {
//             for (int r = l + 1; r < length; r++)
//             {
//                 if (!table[l + 1][r - 1] || s[l] != s[r])
//                     continue;
//                 table[l][r] = true;
//                 if (r - l + 1 > max_length)
//                 {
//                     max_length = r - l + 1;
                    
//                     max_string = s.substr(l, max_length);
//                 }
//             }
//         }
//         return max_string;

        // 1d dp
        pair<int, int> res_idx{0, 1};
        int max_length = 1;
        int length = static_cast<int>(s.size());
        vector<bool> table(length, false);
        
        for (int i = 0; i < length; i++)
        {
            table[i] = true;
        }
        
        for (int l = length - 2; l > -1; l--)
        {
            bool last_diag = true;
            bool new_val = false;
            for (int r = l + 1; r < length; r++)
            {
                if (last_diag && s[l] == s[r])
                {
                    new_val = true;
                    if (r - l + 1 > max_length)
                    {
                        max_length = r - l + 1;
                        res_idx.first = l;
                        res_idx.second = max_length;
                    }
                }
                else
                {
                    new_val = false;
                }
                last_diag = table[r];
                table[r] = new_val;
            }
        }
        return s.substr(res_idx.first, res_idx.second);
    }
};