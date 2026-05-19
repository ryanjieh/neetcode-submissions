class Solution {
        fun foreignDictionary(words: Array<String>): String {
            val noOfWords = words.size
            val adjacencyList = Array(26) {mutableSetOf<Char>()}
            //determining letters set
            val letterSet = mutableSetOf<Char>()
            for (word in words) {
                for (character in word) {
                    if (!(character in letterSet)) {
                        letterSet.add(character)
                    }
                }
            }
            //determining edges
            for (pos1 in 1 until noOfWords) {
                val pos2 = pos1 - 1
                    var checked = 0
                    while (checked < min(words[pos1].length, words[pos2].length)) {
                        if (words[pos1][checked] == words[pos2][checked]) {
                            checked++
                        } else {
                            break
                        }
                    }
                    if (checked < min(words[pos1].length, words[pos2].length)) {
                        adjacencyList[words[pos2][checked] - 'a'].add(words[pos1][checked])
                    } else {
                        if (words[pos2].length > words[pos1].length) {
                            println(pos1)
                            return ""
                        }
                    }
            }
            //topo sort
            val entered = Array(26) {false}
            val exited = Array(26) {false}
            var index = letterSet.size - 1
            val output = Array(letterSet.size) {'?'}
            fun topoSort(targetLetter: Char): Boolean {
                println("entering ${targetLetter}")
                entered[targetLetter - 'a'] = true
                for (neighbour in adjacencyList[targetLetter - 'a']) {
                    if (entered[neighbour - 'a'] == true) {
                        if (exited[neighbour - 'a'] == false) {

                            println("bad neighbour ${neighbour} with ${targetLetter}")
                            return false
                        }
                    } else {
                        val noCycle = topoSort(neighbour)
                        if (!noCycle) {
                            return false
                        }
                    }
                }
                exited[targetLetter - 'a'] = true
                println("exiting ${targetLetter}")
                output[index] = targetLetter
                println(index)
                index--
                return true
            }
            for (letter in letterSet) {
                println("${letter} ${entered[letter - 'a']}")
                if (!entered[letter - 'a']) {
                    val noCycle2 = topoSort(letter)
                    if (!noCycle2) {
                        return ""
                    }
                }
            }
            var answer = ""
            for (topoPos in 0 until letterSet.size) {
                answer += output[topoPos]
            }
            return answer
        }
}
