class Solution {
public:
    // Reverse 'size' nodes starting from 'left' and return new head
    ListNode* reverse(ListNode* left, int size){
        ListNode* curr = left;
        ListNode* prev = nullptr;
        while(size--){
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev; // return new head after reversal
    }

    ListNode* reverseEvenLengthGroups(ListNode* head) {
        if(!head) return head;

        ListNode* left = head;
        ListNode* prevLeft = nullptr;
        int groupSize = 1;

        while(left) {
            // Find the actual size of the current group
            ListNode* right = left;
            int count = 0;
            for(int i = 0; i < groupSize && right; i++) {
                right = right->next;
                count++;
            }

            // If group size is even, reverse it
            if(count % 2 == 0) {
                ListNode* nextLeft = right; // next group's start
                ListNode* newHead = reverse(left, count);
                if(prevLeft) prevLeft->next = newHead;
                else head = newHead; // update head if first group reversed
                left->next = nextLeft;
                prevLeft = left;
                left = nextLeft;
            } else {
                // Move prevLeft and left pointers forward without reversing
                for(int i = 0; i < count; i++) {
                    prevLeft = left;
                    left = left->next;
                }
            }
            groupSize++;
        }

        return head;
    }
};

