// link:: https://leetcode.com/problems/copy-list-with-random-pointer/
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

class Solution {
public:
    Node* copyRandomList(Node* head) {
        
        if(!head) return NULL;
        
        Node *curr = head;
        map<Node*, Node*> mp;
        
        while(curr)
        {
            mp[curr] = new Node(curr->val);
            curr = curr->next;
        }
        
        for(auto x: mp)
        {
            Node *temp = x.second;
            temp->next = mp[x.first->next];
            temp->random = mp[x.first->random];
        }
        
        return mp[head];
    }
};
