/*
class Node {
  public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};
*/

class Solution {
  public:
    void removeLoop(Node* head) {
        if (head == nullptr || head->next == nullptr)
            return;

        Node *slow = head, *fast = head;

        // Detect loop
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) {   // Loop detected
                slow = head;

                // If loop starts at head
                if (slow == fast) {
                    while (fast->next != slow)
                        fast = fast->next;
                } else {
                    while (slow->next != fast->next) {
                        slow = slow->next;
                        fast = fast->next;
                    }
                }

                // Remove loop
                fast->next = nullptr;
                return;
            }
        }
    }
};