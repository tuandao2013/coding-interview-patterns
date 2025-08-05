#ifndef LINKED_LIST_PROBLEMS_H
#define LINKED_LIST_PROBLEMS_H

#include "libs.h"

struct ListNode;

class LinkedListProblems
{
public:
    ListNode *linkedListReversal(ListNode *head);
    ListNode *linkedListReversalRecursive(ListNode *head);
    ListNode *removeKthLastNode(ListNode *head, int k);
    ListNode *linkedListIntersection(ListNode *headA, ListNode *headB);

    ListNode *createSinglyLinkedList(const std::string &filename);
    void printSinglyLinkedList(ListNode *head);
};

inline ListNode *LinkedListProblems::linkedListReversal(ListNode *head)
{
    ListNode *currNode = head;
    ListNode *prevNode = nullptr;
    while (currNode != nullptr)
    {
        ListNode *nextNode = currNode->next_;
        currNode->next_ = prevNode;
        prevNode = currNode;
        currNode = nextNode;
    }
    return prevNode;
}

inline ListNode *LinkedListProblems::linkedListReversalRecursive(ListNode *head)
{
    if (head == nullptr || head->next_ == nullptr)
    {
        return head;
    }
    ListNode *newHead = linkedListReversalRecursive(head->next_);
    head->next_->next_ = head;
    head->next_ = nullptr;
    return newHead;
}

inline ListNode *LinkedListProblems::removeKthLastNode(ListNode *head, int k)
{
    ListNode *dummy = new ListNode(-1);
    dummy->next_ = head;
    ListNode *trailer = dummy;
    ListNode *leader = dummy;
    for (int i = 0; i < k; i++)
    {
        leader = leader->next_;
        if (leader == nullptr)
        {
            return head;
        }
    }
    while (leader->next_ != nullptr)
    {
        leader = leader->next_;
        trailer = trailer->next_;
    }
    trailer->next_ = trailer->next_->next_;
    return dummy->next_;
}

inline ListNode *LinkedListProblems::linkedListIntersection(ListNode *headA, ListNode *headB)
{
    ListNode *ptrA = headA;
    ListNode *ptrB = headB;

    while (ptrA != ptrB)
    {
        ptrA = ptrA != nullptr ? ptrA->next_ : headB;
        ptrB = ptrB != nullptr ? ptrB->next_ : headA;
    }

    return ptrA;
}

inline ListNode *LinkedListProblems::createSinglyLinkedList(const std::string &filename)
{
    std::ifstream file(filename);

    if (!file.is_open())
    {
        std::cerr << "Error: Cannot open file '" << filename << "'\n";
        return nullptr;
    }

    ListNode *head = nullptr;
    ListNode *tail = nullptr;

    int num;

    while (file >> num)
    {
        ListNode *newNode = new ListNode(num);
        if (!head)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next_ = newNode;
            tail = tail->next_;
        }
    }

    file.close();
    return head;
}

inline void LinkedListProblems::printSinglyLinkedList(ListNode *head)
{
    ListNode *curr = head;
    while (curr->next_)
    {
        std::cout << curr->value_ << " -> ";
        curr = curr->next_;
    }
    std::cout << curr->value_ << "\n";
}

#endif