#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

template <typename T>
class LinkedList
{
public:
    virtual bool empty() const = 0;
    virtual int size() const = 0;
    virtual void push_front(const T &value) = 0;
    virtual T pop_front() = 0;
    virtual void push_back(const T &value) = 0;
    virtual T pop_back() = 0;
    virtual int remove(const T &value) = 0;
    virtual void clear() = 0;
    virtual void reverse() = 0;
};

template <typename T>
class SinglyLinkedList : public LinkedList
{
    struct Node;
    class Iterator;

public:
    SinglyLinkedList();
    SinglyLinkedList(const T &intialElement);
    SinglyLinkedList(std::vector<T> arr);
    ~SinglyLinkedList();
    Iterator begin() const;
    Iterator end() const;
    T front() const;
    T back() const;
    bool empty() const;
    int size() const;
    void push_front(const T &value);
    T pop_front();
    void push_back(const T &value);
    T pop_back();
    void insert(Iterator pos, const T &value);
    void erase(Iterator pos);
    void erase(Iterator pos1, Iterator pos2);
    void remove(const T &value);
    int removeAll(const T &value);
    void clear();
    void reverse();

private:
    Node *pHead_;
    int listSize_;

protected:
    struct Node
    {
        friend class SinglyLinkedList;
        friend class Iterator;

    public:
        Node(const T &value, Node *pNext = nullptr);

    private:
        T value_;
        Node *pNext_;
    };

    class Iterator
    {
        friend class SinglyLinkedList;

    public:
        Iterator();
        Iterator(const Node *pNode);
        Iterator operator=(const Node *node);
        Iterator &operator++();   // prefix
        Iterator operator++(int); // postfix
        bool operator!=(const Iterator *itr);
        T operator*();

    private:
        Node *pCurr_;
    }
};

template <typename T>
inline SinglyLinkedList<T>::SinglyLinkedList()
{
    pHead_ = nullptr;
    listSize_ = 0;
}

template <typename T>
inline SinglyLinkedList<T>::SinglyLinkedList(const T &intialElement)
{
    pHead_ = new Node(intialElement);
    listSize_ = 1;
}

template <typename T>
inline SinglyLinkedList<T>::SinglyLinkedList(std::vector<T> arr)
{
    pHead_ = nullptr;
    listSize_ = 0;
    for (auto ele : arr)
    {
        push_back(ele);
    }
}

template <typename T>
inline SinglyLinkedList<T>::~SinglyLinkedList()
{
    clear();
}

template <class T>
inline SinglyLinkedList<T>::Iterator SinglyLinkedList<T>::begin() const
{
    return Iterator(pHead_);
}

template <class T>
inline SinglyLinkedList<T>::Iterator SinglyLinkedList<T>::end() const
{
    return Iterator(nullptr);
}

template <class T>
inline T SinglyLinkedList<T>::front() const
{
    return *begin();
}

template <class T>
inline T SinglyLinkedList<T>::back() const
{
    Node *temp = pHead_;
    while (temp->pNext_ != nullptr)
    {
        temp = temp->pNext_;
    }
    return temp->value_;
}

template <class T>
inline bool SinglyLinkedList<T>::empty() const
{
    return size() == 0;
}

template <class T>
inline int SinglyLinkedList<T>::size() const
{
    return listSize_;
}

template <typename T>
inline void SinglyLinkedList<T>::push_front(const T &value)
{
    pHead_ = new Node(value, pHead_);
    listSize_ += 1;
}

template <typename T>
inline T SinglyLinkedList<T>::pop_front()
{
    if (empty())
    {
        throw std::logic_error("Linked list is empty!!!");
    }

    T result = pHead_->value_;
    Node *pTemp = pHead_;
    if (size() == 1)
    {
        pHead_ = nullptr;
    }
    else
    {
        pHead_ = pHead_->pNext_;
    }
    delete pTemp;
    listSize_ -= 1;
    return result;
}

template <typename T>
inline void SinglyLinkedList<T>::push_back(const T &value)
{
    if (empty())
    {
        pHead_ = new Node(value);
    }
    else
    {
        Node *temp = pHead_;
        while (temp->pNext_ != nullptr)
        {
            temp = temp->pNext_;
        }
        temp->pNext_ = new Node(value);
    }
    listSize_ += 1;
}

template <typename T>
inline T SinglyLinkedList<T>::pop_back()
{
    if (empty())
    {
        throw std::logic_error("Linked list is empty!!!");
    }
    if (size() == 1)
    {
        T result = pHead_->value_;
        Node *temp = pHead_;
        pHead = nullptr;
        delete temp;
        listSize_ -= 1;

        return result;
    }

    Node *temp = pHead_;
    while (temp->pNext_ != nullptr)
    {
        temp = temp->pNext_;
    }
    T result = temp->value_;
    delete temp;
    listSize_ -= 1;
    return result;
}

template <typename T>
inline void SinglyLinkedList<T>::insert(Iterator pos, const T &value)
{
    pos->pCurr_->pNext_ = new Node(value, pos->pCurr_->pNext_);
    listSize_ += 1;
}

template <typename T>
inline void SinglyLinkedList<T>::erase(Iterator pos)
{
    if (pos->pCurr_ == pHead_)
    {
        pop_front();
        return;
    }
    Node *temp = pHead_;
    while (temp->pNext_ = pos->pCurr_)
    {
        temp = temp->pNext_;
    }
    Node *del = pos->pCurr_;
    temp->pNext_ = del->pNext_;
    delete del;
    listSize_ -= 1;
}

template <typename T>
inline void SinglyLinkedList<T>::erase(Iterator pos1, Iterator pos2)
{
    while (pos1 != pos2)
    {
        erase(pos1);
        pos1++;
    }
}

template <typename T>
inline void SinglyLinkedList<T>::remove(const T &value)
{
    if (empty())
    {
        return;
    }
    for (Iterator itr = begin(); itr != end(); itr++)
    {
        if (*itr == value)
        {
            erase(itr);
            return;
        }
    }
}

template <typename T>
inline int SinglyLinkedList<T>::removeAll(const T &value)
{
    if (empty())
    {
        return 0;
    }
    int numDel = 0;
    for (Iterator itr = begin(); itr != end(); itr++)
    {
        if (*itr == value)
        {
            erase(itr);
            numDel += 1;
        }
    }

    return numDel;
}

template <class T>
void SinglyLinkedList<T>::clear()
{
    while (!empty())
    {
        pop_front();
    }
}

template <class T>
void SinglyLinkedList<T>::reverse()
{
    Node *currNode = pHead_;
    Node *prevNode = nullptr;
    while (currNode != nullptr)
    {
        Node *nextNode = currNode->pNext_;
        currNode->pNext_ = prevNode;
        prevNode = currNode;
        currNode = nextNode;
    }
    pHead_ = prevNode;
}

template <typename T>
inline SinglyLinkedList<T>::Node::Node(const T &value, Node *pNext)
{
    this->value_ = value;
    this->pNext_ = pNext;
}

template <typename T>
inline SinglyLinkedList<T>::Iterator::Iterator()
{
    pCurr_ = pHead_;
}

template <typename T>
inline SinglyLinkedList<T>::Iterator::Iterator(const Node *pNode)
{
    pCurr_ = pNode;
}

template <class T>
inline SinglyLinkedList<T>::Iterator SinglyLinkedList<T>::Iterator::operator=(const SinglyLinkedList<T>::Node *node)
{
    this->pCurr_ = node;
    return *this;
}

template <class T>
inline SinglyLinkedList<T>::Iterator &SinglyLinkedList<T>::Iterator::operator++()
{
    if (this->pCurr_ != nullptr)
    {
        this->pCurr_ = this->pCurr_->pNext_;
    }
    return *this;
}

template <class T>
inline SinglyLinkedList<T>::Iterator SinglyLinkedList<T>::Iterator::operator++(int)
{
    Iterator itr = *this;
    ++*this;
    return itr;
}

template <class T>
inline bool SinglyLinkedList<T>::Iterator::operator!=(const SinglyLinkedList<T>::Iterator *itr)
{
    return this->pCurr_ != itr->pCurr_;
}

template <class T>
inline T SinglyLinkedList<T>::Iterator::operator*()
{
    return this->pCurr_->value_;
}
#endif
