#ifndef Q2_H
#define Q2_H

#include <list>

using std::list;
using std::vector;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

class Solution {
public:
    ListNode* reverseLinkedList(ListNode* head);
    ListNode* createLinkedList(vector <int> inputs);
    void printLinkedList(ListNode* head);
    void printStandardLibraryLinkedList(const list<int>& linkedList);
};

#endif  // Q2_H