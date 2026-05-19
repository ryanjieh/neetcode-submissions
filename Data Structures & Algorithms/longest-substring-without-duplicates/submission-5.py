class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        answer = 0
        tempset = {}
        startgood = 0
        endgood = 0
        for endpoint in range(len(s)):
            startgood = tempset.get(s[endpoint]) or startgood
            tempset = {k: v for k, v in tempset.items() if v >= startgood}
            tempset[s[endpoint]] = endpoint
            endgood = endpoint
            print(str(startgood) + " " + str(endgood))
            print(tempset)
            answer = max(answer, len(tempset))
        return answer
