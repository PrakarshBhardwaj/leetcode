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
    Node *go(Node *node, unordered_map<Node*, Node*> &mp){
        if(!node) return NULL;
        
        Node *tmp = new Node(node->val);
        mp[node] = tmp;
        
        for(int i = 0; i < node->neighbors.size(); i++){
            Node *tp;
            
            if(mp.find(node->neighbors[i]) != mp.end()){
                tp = mp[node->neighbors[i]];
            }
            else tp = go(node->neighbors[i], mp);
            
            tmp->neighbors.push_back(tp);
        }
        
        return tmp;
    }
        
    Node* cloneGraph(Node* node) {
        unordered_map<Node*, Node*> mp;
        return go(node, mp);
    }
};