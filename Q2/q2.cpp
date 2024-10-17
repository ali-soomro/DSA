#include "q2.h"
#include <iostream>
#include <gtest/gtest.h>
#include <vector>

using std::vector;
using std::cout;
using std::endl;

// Function to print the elements of the list using iterators
void printStandardLibraryLinkedList(const list<int>& linkedList) {
    cout << "Linked list elements: ";
    
    // Use an iterator to traverse the list
    for (auto it = linkedList.begin(); it != linkedList.end(); ++it) {
        cout << *it << " -> ";  // Dereference the iterator to get the value
    }

    for (int node : linkedList) {
        cout << node << endl;
    }
    
    cout << "nullptr" << endl;  // For termination of the linked list
}

void Solution::printLinkedList(ListNode* head) {
    ListNode* current = head;
    cout << "Values in Linked List" << endl;
    while (current->next != nullptr) {
        current = current->next;
        std::cout << " ";
    }
}

ListNode* Solution::createLinkedList(vector<int> inputs) {
    if (inputs.empty()) {
        cout << "Empty inputs" << endl;
        ListNode* empty;
        return empty;
    }

    ListNode* head = new ListNode(inputs[0]);
    ListNode* tail = head;
    for (int i = 1; i < inputs.size(); i++) {
        ListNode* newNode = new ListNode(inputs[i]);
        tail->next = newNode;
        tail = newNode;
    }
    return head;
}

int main(int argc, char **argv) {
    // CUSTOM INPUT: CUSTOM VALUES
    vector<int> inputs = {2, 7, 11, 15};
    Solution sol;
    ListNode* singlyLinkedList = sol.createLinkedList(inputs);

    // Print the Singly Linked List
    sol.printLinkedList(singlyLinkedList);

    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
    return 0;
}