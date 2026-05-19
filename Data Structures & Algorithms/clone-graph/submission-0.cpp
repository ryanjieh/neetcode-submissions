/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
    // Map to hold original node to its copy
    unordered_map<Node*, Node*> copies;
public:
    Node* cloneGraph(Node* node) {
        if (node == nullptr) {
        return nullptr;
        }   
        vector<Node*> nb = node->neighbors;
        if (nb.empty()) {
            Node* clone = new Node(node->val);
            return clone;
        } 
        if (copies.find(node) == copies.end()) {
            Node* clone = new Node();
            clone->val = node->val;
            copies[node] = clone;
            // Recursively clone neighbors
            for (Node* neighbor : node->neighbors) {
                clone->neighbors.push_back(cloneGraph(neighbor));
            }
        }
        return copies[node];
    }
};
