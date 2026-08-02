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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
       int count=0;
       ListNode* it=head;
       while(it!=nullptr){
        count++;
        it=it->next;
       }
       int fromFront=count-n+1;
       if(fromFront==1){
        ListNode*temp=head;
        head=head->next;
        delete temp;
        return head;
       }
       ListNode* curr=head;
       ListNode* prev=nullptr;
       int pos=1;
       while(pos<fromFront){
        prev=curr;
        curr=curr->next;
        pos++;
       }
        prev->next=curr->next;
        delete curr;
        return head;
    }
};
