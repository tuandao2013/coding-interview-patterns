#ifndef FAST_SLOW_POINTERS_H
#define FAST_SLOW_POINTERS_H

#include "libs.h"
#include <unordered_set>

class FastSlowPointers
{
public:
    bool linkedListLoopNaive(ListNode *head);
    bool linkedListLoop(ListNode *head);
    ListNode *linkedListMidPoint(ListNode *head);
    bool happyNumber(int n);
};

int getNextNumber(int x);

inline bool FastSlowPointers::linkedListLoopNaive(ListNode *head)
{
    std::unordered_set<ListNode *> visited;
    ListNode *curr = head;
    while (curr != nullptr)
    {
        if (visited.count(curr) != 0)
        {
            return true;
        }
        visited.insert(curr);
        curr = curr->next_;
    }

    return false;
}

inline bool FastSlowPointers::linkedListLoop(ListNode *head)
{
    ListNode *slow = head;
    ListNode *fast = head;

    while (fast != nullptr && fast->next_ != nullptr)
    {
        slow = slow->next_;
        fast = fast->next_->next_;
        if (fast == slow)
        {
            return true;
        }
    }

    return false;
}

inline ListNode *FastSlowPointers::linkedListMidPoint(ListNode *head)
{
    ListNode *slow = head;
    ListNode *fast = head;
    while (fast != nullptr && fast->next_ != nullptr)
    {
        slow = slow->next_;
        fast = fast->next_->next_;
    }
    return slow;
}

inline bool FastSlowPointers::happyNumber(int n)
{
    int fast = n;
    int slow = n;
    while (true)
    {
        slow = getNextNumber(slow);
        fast = getNextNumber(getNextNumber(fast));
        if (fast == 1)
        {
            return true;
        }
        else if (fast == slow)
        {
            return false;
        }
    }
}

int getNextNumber(int x)
{
    int nextNumber = 0;
    while (x > 0)
    {
        int digit = x % 10;
        x /= 10;
        nextNumber += digit * digit;
    }
    return nextNumber;
}

#endif