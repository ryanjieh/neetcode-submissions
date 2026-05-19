class Solution:
    def reverseBits(self, n: int) -> int:
        binN = bin(n)
        binN = binN[2:].zfill(32)
        output = ""
        for i in range(32):
            output += binN[(-1-i)]
        return int(output, 2)
        