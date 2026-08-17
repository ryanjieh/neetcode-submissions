class Node {
private:
public: 
    std::unordered_map<char, Node*> nextNodes;
    bool isFinal;
    Node() {
        isFinal = false;
    }
};

class WordDictionary {
private:
    Node root;
public:
    string characterset = "qwertyuiopasdfghjklzxcvbnm";
    WordDictionary() {
    }
    void addWord(string word) {
        Node* current = &root;
        for (auto &wordch: word) {
            if (current->nextNodes.count(wordch) == 0) {
                current->nextNodes[wordch] = new Node;
            }
            current = current->nextNodes[wordch];
        }
        current->isFinal = true;
    }
    
    bool searchHelper (string word, Node* temproot) {
        Node* current = temproot;
        bool answer = false;
        for (int it = 0; it < word.length(); it++) {
            if (word[it] == '.') {
                for (auto& [ch, child] : current->nextNodes) {
                    if (searchHelper(word.substr(it + 1), child)) {
                        return true;   // early exit too — don't keep searching once found
                    }
                }
                return false;
            } else {
                if (current->nextNodes.count(word[it]) == 0) {
                    return false;
                }
                current = current->nextNodes[word[it]];
            }            
        }
        return current->isFinal;
    }

    bool search(string word) {
        return searchHelper(word, &root);
    }
};