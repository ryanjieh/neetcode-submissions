class Node {
private:
public: 
    std::unordered_map<char, Node*> nextNodes;
    bool isFinal;
    Node() {
        isFinal = false;
    }
};

class PrefixTree {
private:
    Node root;
public:
    PrefixTree() {
    }
    void insert(string word) {
        Node* current = &root;
        for (auto &wordch: word) {
            if (current->nextNodes.count(wordch) == 0) {
                current->nextNodes[wordch] = new Node;
            }
            current = current->nextNodes[wordch];
        }
        current->isFinal = true;
    }
    
    std::optional<Node*> traverse (string word) {
        Node* current = &root;
        for (auto &wordch: word) {
            if (current->nextNodes.count(wordch) == 0) {
                return std::nullopt;
            }
            current = current->nextNodes[wordch];
        }
        return current;
    }

    bool search(string word) {
        std::optional<Node*> found = traverse(word);
        return found.has_value() && (found.value()->isFinal); 

    }
    
    bool startsWith(string prefix) {
        std::optional<Node*> found = traverse(prefix);
        return found.has_value(); 
    }
};