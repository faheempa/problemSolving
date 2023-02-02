// Implementing a generic linked list
// making a linked list that can store id, name, age % healthy(boolean value)

#include "ll.h"
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

template <typename... T>
void read(T &...args)
{
    ((cin >> args), ...);
}

struct Node
{
    int id;
    string name;
    int age;
    bool healthy;
    Node *next;
    Node(int i, string a = "", int b = 0, bool c = false) : name(a), age(b), healthy(c), id(i), next(nullptr) {}
    bool operator==(const Node &a) const
    {
        return (id == a.id);
    }
};
std::ostream &operator<<(std::ostream &o, const Node &a)
{
    o << "ID: " << a.id << "\t Name: " << a.name << "\t Age: " << a.age << "\t Healthy: " << std::boolalpha << a.healthy;
    return o;
}

int main()
{
    LinkedList<Node> ll;
    for (int i = 1; i <= 3; i++)
    {
        int id;
        string name;
        int age;
        bool healthy;
        read(id, name, age, healthy);
        ll.push_back(new Node(id, name, age, healthy));
    }
    cout << ll;
    cout << "size : " << ll.size() << endl;

    return 0;
}
