// Write a program to find the node at which the 
// intersection of two singly linked lists begins.


// For example, the following two linked lists:

// A:          a1 → a2
//                    ↘
//                      c1 → c2 → c3
//                    ↗            
// B:     b1 → b2 → b3
// begin to intersect at node c1.


// Notes:

// If the two linked lists have no intersection at all, 
// return null.The linked lists must retain their original 
// structure after the function returns.
// You may assume there are no cycles anywhere 
// in the entire linked structure.
// Your code should preferably run in O(n) time and use only O(1) memory.
// Credits:
// Special thanks to @stellari for adding this problem and creating all test cases.

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA == NULL || headB == NULL) return NULL;
        if(headA == headB) return headA;
        ListNode *head = headA;
        ListNode *last = NULL;
        while(head != NULL){
            last = head;
            head = head ->next;
        }
        last->next = headA;
        
        ListNode *fast = headB;
        ListNode *slow = headB;
        
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast){
                ListNode *head = headB;
                while(head != slow){
                    head = head->next;
                    slow = slow->next;
                }
                last->next = NULL;
                return head;
            }
                
        }
        last->next = NULL;
        return NULL;
    }


    ListNode *getIntersectionNode1(ListNode *headA, ListNode *headB){
        if(headA == NULL || headB == NULL) return NULL;
        int lenA= ListLen(headA);
        int lenB = ListLen(headB);
        int count = (lenA > lenB)? (lenA - lenB): (lenB - lenA);
        ListNode *longHead, *shortHead;
        if(lenA >= lenB){
            longHead = headA;
            shortHead = headB;
        }else{
            longHead = headB;
            shortHead = headA;
        }

        while(count){
            longHead = longHead->next;
            count--;
        }

        while(longHead != NULL){
            if(longHead == shortHead){
                return longHead;
            }
            longHead = longHead->next;
            shortHead = shortHead->next;
        }
        return NULL;
    };

    int ListLen(ListNode *head){
        int n = 0;
        while(head != NULL){
            n = n + 1;
            head = head->next;
        }
        return n;
    }

};


class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB){
    if(headA == NULL || headB == NULL) return NULL;
    int lenA= ListLen(headA);
    int lenB = ListLen(headB);
    int count = (lenA > lenB)? (lenA - lenB): (lenB - lenA);
    ListNode *longHead, *shortHead;
    if(lenA >= lenB){
        longHead = headA;
        shortHead = headB;
    }else{
        longHead = headB;
        shortHead = headA;
    }

    while(count){
        longHead = longHead->next;
        count--;
    }

    while(longHead != NULL){
        if(longHead == shortHead){
            return longHead;
        }
        longHead = longHead->next;
        shortHead = shortHead->next;
    }
    return NULL;
};

int ListLen(ListNode *head){
    int n = 0;
    while(head != NULL){
        n = n + 1;
        head = head->next;
    }
    return n;
}
};