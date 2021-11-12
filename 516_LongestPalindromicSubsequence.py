class Solution:
    def longestPalindromeSubseq(self, s: str) -> int:
        ## 2d dp
        length = len(s)
        
        table = [[0] * length for _ in range(length)]
        for i in range(length):
            table[i][i] = 1
            
        for i in range(length - 2, -1, -1):
            for j in range(i + 1, length):
                # print (f'{i}, {j}')
                if s[i] == s[j]:
                    table[i][j] = max(table[i + 1][j], table[i][j - 1], table[i + 1][j - 1] + 2)
                else:
                    table[i][j] = max(table[i + 1][j], table[i][j - 1])
        return table[0][length - 1]
        
        ## 1d dp
        table = [1] * length
        for i in range(length - 2, -1, -1):
            diag_val = 0
            for j in range(i + 1, length):
                # print (f'{i}, {j}')
                if s[i] == s[j]:
                    new_val = max(table[j], table[j - 1], diag_val + 2)
                else:
                    new_val = max(table[j], table[j - 1])
                diag_val = table[j]
                table[j] = new_val
                
        return table[length - 1]
        