class Solution{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2){
        if(l1 == NULL && l2 == NULL) return NULL;
        if(l1 != NULL && l2 == NULL) return l1;
        if(l1 == NULL && l2 != NULL) return l2;

        ListNode *longer, *shorter;
        if(ListSize(l1) >= ListSize(l2)){
            longer = l1;
            shorter = l2;
        }else{
            longer = l2;
            shorter = l1;
        }

        ListNode *head = longer;
        ListNode *last;
        int carry=0;
        while(longer != NULL){
            int val1 = longer->val;
            int val2;
            if(shorter == NULL){
                val2 = 0;
                shorter = NULL;
            }else{
                val2 = shorter->val;
                shorter = shorter->next;
            }
            int val = val1 + val2 + carry;
            longer->val = val%10;
            carry = val / 10;
            last = longer;
            longer = longer->next;
        }
        if(carry != 0){
            ListNode *node = new ListNode(carry);
            last->next = node;

        }
        return head;
    }
    int ListSize(ListNode *head){
        int n = 0;
        while(head != NULL){
            head = head->next;
            n++;
        }
        return n;
    }
};