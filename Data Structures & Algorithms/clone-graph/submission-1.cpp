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
public:
    Node* cloneGraph(Node* node) {
        if (!node) return nullptr;
        map<Node*, Node*> store;
        return cloneGraph(node, store);
    }

    Node* cloneGraph(Node* node, map<Node*, Node*>& store) {
        if (!node) return nullptr;
        store[node] = new Node(node -> val);
        for(auto n : node -> neighbors){
            if(store.find(n) == store.end()){
                (store[node] -> neighbors).push_back(cloneGraph(n, store));
            } else {
                (store[node] -> neighbors).push_back(store[n]);
            }
        }
        return store[node];
    }
};
