#include "llrec.h"

//*********************************************
// Provide your implementation of llpivot below
//*********************************************
 void llpivot(Node *&head, Node *&smaller, Node *&larger, int pivot)
 {
    // Base caes, head is null, set smaller & larger to null and quit
    if (head == nullptr)
    {
        smaller = nullptr;
        larger = nullptr;
        return;
    }
    // Helper node
    Node* temp = head -> next;
    // If head is more than pivot, then set to the larger pointer, and recursive call
    if (head->val > pivot)
    {
        larger = head;
        larger->next = nullptr;
        llpivot(temp, smaller, larger -> next, pivot);
    }
    // If head is less or equal to pivot, set smaller pointer to head, and recursive call
    else if (head->val <= pivot)
    {
        smaller = head;
        smaller->next = nullptr;
        llpivot(temp, smaller->next, larger, pivot);
    }
    // As stack unwinds this will set temp to null, and then the last head to null
    head = nullptr;
 }

//  * Given a linked list pointed to by head, creates two lists
//  * where all values less than or equal to the pivot value are
//  * placed in a linked list whose head will be pointed to by
//  * smaller and all values greater than the pivot
//  * value are placed in a linked list whose head will be pointed to
//  * by larger.  The input list pointed to by head should be empty
//  * upon return and head set to NULL (i.e. we are not making copies)
//  * in the smaller and larger lists but simply moving Nodes out of
//  * the input list and into the two other lists.