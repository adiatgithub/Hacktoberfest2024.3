#include <iostream>
using namespace std;

// Structure of a Node
struct ListNode {
    int data;
    ListNode* next;
    ListNode(int data) : data(data), next(nullptr) {}
};

// Euclidean function for GCD Calculation
int gcd(int x, int y) {
    if (y == 0)
        return x;
    return gcd(y, x % y);
}

// Insertion of GCD
ListNode* insertGreatestCommonDivisors(ListNode* head) {
    // Base Case
    if (head == nullptr || head->next == nullptr)
        return head;

    // Variable initialization
    ListNode* prev = nullptr;
    ListNode* curr = head;
    ListNode* n = curr->next;

    // Traversing linked list and simultaneously
    // inserting new node having gcd of both nodes
    while (n != nullptr) {
        int val = gcd(curr->data, n->data);
        ListNode* temp = new ListNode(val);
        prev = curr;
        curr = n;
        n = n->next;
        temp->next = curr;
        prev->next = temp;
    }
    return head;
}

// Driver Function
int main() {
    // Creating a linked list
    ListNode* head = new ListNode(30);
    head->next = new ListNode(6);
    head->next->next = new ListNode(14);
    head->next->next->next = new ListNode(3);

    // Function call for operation
    ListNode* ans = insertGreatestCommonDivisors(head);
    ListNode* temp = ans;

    // Traversing the final linked list
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    return 0;
}

