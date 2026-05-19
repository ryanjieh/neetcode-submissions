class Solution {
        fun ladderLength(beginWord: String, endWord: String, wordList: MutableList<String>): Int {
            var listOfLetters = "qwertyuiopasdfghjklzxcvbnm"
            var distances = wordList.associateWith{0}.toMutableMap()
            var bfsQueue: Queue<String> = LinkedList()
            fun checkIfNeighbour(refWord: String, testWord: String, refDistance: Int) {
                for (targetIndex in 0..<refWord.length) {
                    for (subChar in listOfLetters) {
                        var targetWord = (0 until refWord.length).map{if (it == targetIndex) subChar else refWord[it]}.joinToString("","","")
                        if (targetWord == testWord && distances[testWord] == 0) {
                            distances[testWord] = refDistance + 1
                            println(testWord)
                            println(distances[testWord])
                            bfsQueue.add(targetWord)
                        }
                    }
                }
            }
            if (endWord == beginWord) {
                return 1
            }
            if (!(endWord in wordList)) {
                return 0
            }
            for (word in wordList) {
                checkIfNeighbour(beginWord, word, 1)
            }
            while (bfsQueue.isNotEmpty()) {
                for (word in wordList) {
                    checkIfNeighbour(bfsQueue.peek(), word, distances[bfsQueue.peek()]!!)
                }
                bfsQueue.remove()
            }
            return distances[endWord]!!
        }
}
