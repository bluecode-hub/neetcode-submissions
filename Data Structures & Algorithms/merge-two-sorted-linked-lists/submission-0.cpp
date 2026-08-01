class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

        ListNode* head1 = list1;
        ListNode* head2 = list2;

        ListNode* dummyNode = new ListNode(0);
        ListNode* head = dummyNode;

        while(head1 != nullptr && head2 != nullptr){

            if(head1->val < head2->val){
                ListNode* temp = new ListNode(head1->val);
                head->next = temp;
                head = temp;
                head1 = head1->next;
            }
            else{
                ListNode* temp = new ListNode(head2->val);
                head->next = temp;
                head = temp;
                head2 = head2->next;
            }
        }

        while(head1 != nullptr){
            ListNode* temp = new ListNode(head1->val);
            head->next = temp;
            head = temp;
            head1 = head1->next;
        }

        while(head2 != nullptr){
            ListNode* temp = new ListNode(head2->val);
            head->next = temp;
            head = temp;
            head2 = head2->next;
        }

        return dummyNode->next;
    }
};