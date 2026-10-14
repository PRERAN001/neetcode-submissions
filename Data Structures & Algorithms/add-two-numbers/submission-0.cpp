/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy=new ListNode(0);
        ListNode* tail=dummy;
        int carry=0;
        while(l1!=nullptr || l2!=nullptr || carry!=0){
            int d1=(l1!=nullptr)?l1->val:0;
            int d2=(l2!=nullptr)?l2->val:0;
            int sum=d1+d2+carry;
            int dig=sum%10;
            carry=sum/10;
            ListNode* a=new ListNode(dig);
            tail->next=a;
            tail=a;

            l1=(l1!=nullptr)?l1->next:nullptr;
            l2=(l2!=nullptr)?l2->next:nullptr;
        }
        ListNode* res=dummy->next;
        delete dummy;
        return res;
    }
};
