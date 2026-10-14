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
        if (head == nullptr) return nullptr;

        unordered_map<Node*, Node*> mp;

        Node* temp = head;

        while (temp) {
            mp[temp] = new Node(temp->val);
            temp = temp->next;
        }

        temp = head;

        while (temp) {
            mp[temp]->next = temp->next ? mp[temp->next] : nullptr;
            mp[temp]->random = temp->random ? mp[temp->random] : nullptr;
            temp = temp->next;
        }

        return mp[head];
    }
};
