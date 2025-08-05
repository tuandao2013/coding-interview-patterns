#ifndef LIBS_H
#define LIBS_H

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

#include "../utils/utils.h"

struct ListNode
{
    friend class LinkedListProblems;
    friend class FastSlowPointers;

public:
    ListNode(int value, ListNode *nextNode = nullptr) : value_(value), next_(nextNode) {}
    int getValue() const { return value_; }
    ListNode *getNext() const { return next_; }
    void setNext(ListNode *nextNode) { next_ = nextNode; }

private:
    int value_;
    ListNode *next_;
};

#endif