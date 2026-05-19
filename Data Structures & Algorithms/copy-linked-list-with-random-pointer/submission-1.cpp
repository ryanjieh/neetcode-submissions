/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
#include <unordered_map>

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr) {
            return nullptr;
        }
        unordered_map<Node*, Node*> umap;
        Node* copy = copyHelper(head, umap);
        randomHelper(head, umap);
        return copy;
    }
    Node* copyHelper(Node* head, unordered_map<Node*, Node*>& mappointer) {
        Node* copy = new Node(head->val);
        mappointer[head] = copy; 
        if (head->next != nullptr) {
            copy->next = copyHelper(head->next, mappointer);
        }
        return copy;
    }
    void randomHelper(Node* head, unordered_map<Node*, Node*> umap) {
        if (head->random != nullptr) {
            umap[head]->random = umap[head -> random];
        }
        if (head->next != nullptr) {
            randomHelper(head->next, umap);
        }
    }
};
