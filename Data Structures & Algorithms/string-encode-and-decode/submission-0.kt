class Solution {
        fun encode(strs: List<String>): String {
            return strs.map{str -> str.map{char -> "0" + char}.joinToString(separator = "") + "11"}.joinToString(separator = "")
        }
        fun decode(str: String): List<String> {
            var tempStr = ""
            var output = mutableListOf<String>()
            for (i in 0..<str.length/2) {
                if (str[2*i] == '1') {
                    output.add(tempStr)
                    tempStr = ""
                } else {
                    tempStr += str[2*i+1]
                }
            }
            return output
        }
}
