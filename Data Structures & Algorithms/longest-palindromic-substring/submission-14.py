class Solution:
    def longestPalindrome(self, s: str) -> str:
        if (len(s) == 0):
            return ""
        if (len(s) == 1):
            return s
        # checking for odd length palindromes
        max_len = 1
        max_centre = 0
        # odd length palindromes
        for i in range(len(s)):
            temp_max_len = -1
            # i is the centre that we search around
            for j in range(min(i, len(s) - i - 1) + 1):
                if s[i - j] == s[i + j]:
                    temp_max_len += 2
                else: 
                    break
            if temp_max_len > max_len:
                max_len = temp_max_len
                max_centre = i
            print("MAX_LEN" + str(max_len))
            print("MAX_CENTRE" + str(max_centre))
        # even length palindromes
        for i in range(len(s) - 1):
            if (s[i] == s[i + 1]):
                temp_max_len = 0
            else:
                continue
            # i is the centre that we search around
            for j in range(min(i, len(s) - (i+1) - 1) + 1):
                if s[i - j] == s[(i+1) + j]:
                    # print("AT LEAST 2")
                    temp_max_len += 2
                else:
                    break
            # print("TEMP_MAX_LEN" + str(temp_max_len))
            if temp_max_len > max_len:
                max_len = temp_max_len
                max_centre = i
            print("MAX_LEN" + str(max_len))
            print("MAX_CENTRE" + str(max_centre))
        #returning the final string
        # print("FINAL_MAX_LEN" + str(max_len))
        # print("FINAL_MAX_CENTRE" + str(max_centre))
        if (max_len%2 == 0):
            return s[max_centre - max_len//2 + 1: max_centre + max_len//2 + 1]
        else:
            return s[max_centre - (max_len-1)//2: max_centre + (max_len+1)//2]
        