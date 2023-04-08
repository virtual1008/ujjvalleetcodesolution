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
        if(node==NULL) return node;
        Node *root=new Node(node->val);
        unordered_map<Node*,Node*> map;
        map[node]=root;
        queue<Node*> q;
        q.push(node);
        while(!q.empty()){
            Node *temp=q.front();
            q.pop();
            for(auto it:temp->neighbors){
                if(!map[it]){
                    Node *n= new Node(it->val);
                    map[it]=n;
                    q.push(it);
                }
                (map[temp]->neighbors).push_back(map[it]);
            }
        }
        return root;
    }
    
};