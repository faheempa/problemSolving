#ifndef _LL_H_
#define _LL_H_

#include <iostream>
#include <vector>

template <class T>
class LinkedList
{
    T *head;
    int length;

public:
    LinkedList()
        : head{nullptr}, length{0}
    {
    }
    LinkedList(std::vector<T> &nodes)
        : head{nullptr}, length{0}
    {
        for(auto a: nodes)
            push_back(new T(a));
    }
    void set_head(T *head)
    {
        this->head = head;
    }
    T *get_head() const
    {
        return this->head;
    }
    void push_back(T *node)
    {
        if (head == nullptr)
        {
            push_front(node);
            return;
        }
        T *ptr = head;
        while (ptr->next != nullptr)
            ptr = ptr->next;
        ptr->next = node;
        length++;
    }
    void push_back(T node)
    {
        this->push_back(new T(node));
    }
    void push_front(T *node)
    {
        node->next = head;
        head = node;
        length++;
    }
    void push_front(T node)
    {
        this->push_front(new T(node));
    }
    void insert_before(T *node, T target)
    {
        if (head == nullptr)
        {
            delete node;
            return;
        }
        if (*head == target)
        {
            push_front(node);
            return;
        }
        T *ptr = head;
        while (ptr->next != nullptr && not(*(ptr->next) == target))
            ptr = ptr->next;
        if (ptr->next == nullptr)
        {
            delete node;
            return;
        }
        node->next = ptr->next;
        ptr->next = node;
        length++;
    }
    void insert_before(T a, T b)
    {
        this->insert_before(new T(a), T(b));
    }
    void insert_after(T *node, T target)
    {
        if (head == nullptr)
        {
            delete node;
            return;
        }
        if (*head == target)
        {
            push_back(node);
            return;
        }
        T *ptr = head;
        while (ptr != nullptr && not(*(ptr) == target))
            ptr = ptr->next;
        if (ptr == nullptr)
        {
            delete node;
            return;
        }
        node->next = ptr->next;
        ptr->next = node;
        length++;
    }
    void insert_after(T a, T b)
    {
        this->insert_after(new T(a), T(b));
    }
    void print(std::string sep = "\n")
    {
        T *ptr = head;
        while (ptr != nullptr)
        {
            std::cout << *ptr << sep;
            ptr = ptr->next;
        }
    }
    void pop_front()
    {
        if (head == nullptr)
            return;
        T *del = head;
        head = head->next;
        delete del;
        length--;
    }
    void pop_back()
    {
        if (head == nullptr)
            return;
        T *ptr = head, *del = head;
        while (del->next != nullptr)
        {
            ptr = del;
            del = del->next;
        }
        if (ptr == del)
            head = nullptr;
        else
            ptr->next = nullptr;
        delete del;
        ptr->next = nullptr;
        length--;
    }
    void pop(T target)
    {
        if (head == nullptr)
            return;
        T *ptr = head, *del = head;
        while (del != nullptr && not(*(del) == target))
        {
            ptr = del;
            del = del->next;
        }
        if (del == nullptr)
            return;
        if (del == head)
            pop_front();
        else
        {
            ptr->next = del->next;
            delete del;
            length--;
        }
    }
    void clear()
    {
        if (head == nullptr)
            return;
        T *ptr = head;
        while (ptr->next != nullptr)
        {
            T *del = ptr;
            ptr = ptr->next;
            delete del;
        }
        delete ptr;
        head = nullptr;
        length = 0;
    }
    void replace(T target, T *node)
    {
        if (head == nullptr)
        {
            delete node;
            return;
        }
        if (*head == target)
        {
            pop_front();
            push_front(node);
            return;
        }
        T *ptr = head;
        while (ptr->next != nullptr && not(*(ptr->next) == target))
            ptr = ptr->next;
        if (ptr->next == nullptr)
        {
            delete node;
            return;
        }
        T *del = ptr->next;
        node->next = del->next;
        ptr->next = node;
        delete del;
    }
    void reverse()
    {
        T *pre = nullptr, *nex;
        while (head)
        {
            nex = head->next;
            head->next = pre;
            pre = head;
            head = nex;
        }
        head = pre;
    }
    int size() const
    {
        return length;
    }
    void extend(LinkedList<T> &other)
    {
        T *ptr = head;
        if (head != nullptr)
            while (ptr->next != nullptr)
                ptr = ptr->next;
        ptr->next=other.get_head();
        other.set_head(nullptr);
        length+=other.size();
    }
    ~LinkedList()
    {
        this->clear();
    }
    bool operator==(const LinkedList &a) const
    {
        return (this->get_head() == a.get_head());
    }
    T* find(T target)
    {
        if (head == nullptr)
            return nullptr;
        if (*head == target)
            return head;
        T *ptr = head;
        while (ptr != nullptr && not(*(ptr) == target))
            ptr = ptr->next;
        if (ptr == nullptr)
            return nullptr;
        return ptr;
    }
};
template <class T>
std::ostream &operator<<(std::ostream &o, LinkedList<T> &a)
{
    a.print();
    return o;
}

#endif