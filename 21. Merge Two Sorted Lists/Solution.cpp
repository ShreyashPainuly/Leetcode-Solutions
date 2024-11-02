// You are given the heads of two sorted linked lists list1 and list2.
// Merge the two lists into one sorted list. The list should be made by splicing together the nodes of the first two lists.
// Return the head of the merged linked list.

// Example 1:
// Input: list1 = [1,2,4], list2 = [1,3,4]
// Output: [1,1,2,3,4,4]
  
// Example 2:
// Input: list1 = [], list2 = []
// Output: []
  
// Example 3:
// Input: list1 = [], list2 = [0]
// Output: [0]

class Solution {
public:
    ListNode* solve(ListNode* list1, ListNode* list2) {
        //Single Element list handling
        if(list1 -> next == NULL) {
            list1 -> next = list2;
            return list1;
        }

        ListNode* curr1 = list1;
        ListNode* next1 = curr1 -> next;
        ListNode* curr2 = list2;
        ListNode* next2 = NULL;

        while(next1 != NULL && curr2 != NULL) {
            if((curr2 -> val >= curr1 -> val) && (curr2 -> val <= next1 -> val)) {
                //Add the node in between
                curr1 -> next = curr2;
                next2 = curr2 -> next;
                curr2 -> next = next1;

                curr1 = curr2;
                curr2 = next2;
            }
            else {
                curr1 = next1;
                next1 = next1 -> next;

                if(next1 == NULL) {
                    curr1 -> next = curr2;
                    return list1;
                }
            }
        }
        return list1;
    }

    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1 == NULL) {
            return list2;
        }
        if(list2 == NULL) {
            return list1;
        }
        if(list1 -> val <= list2 -> val) {
            return solve(list1, list2);
        }
        else {
            return solve(list2, list1);
        }
    }
};
