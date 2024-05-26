#include "List.hpp"

template <typename T>
List<T>::List() : head(nullptr), tail(nullptr) {}

template <typename T>
List<T>::List(const List &rhs) : head(nullptr), tail(nullptr)
{
    for (Node<T> *node = rhs.head; node; node = node->next)
    {
        this->pushBack(node->data);
    }
}

template <typename T>
List<T>::~List()
{
    Node<T> *current = head;
    while (current)
    {
        Node<T> *next = current->next;
        delete current;
        current = next;
    }
}

template <typename T>
List<T> &List<T>::operator=(const List &rhs)
{
    if (this != &rhs)
    {
        this->~List();
        for (Node<T> *node = rhs.head; node; node = node->next)
        {
            this->pushBack(node->data);
        }
    }
    return *this;
}

template <typename T>
T &List<T>::operator[](size_t index)
{
    Node<T> *current = head;
    while (index-- && current)
    {
        current = current->next;
    }
    if (!current)
    {
        throw std::out_of_range("Обращение к элементу за границами");
    }
    return current->data;
}

template <typename T>
void List<T>::pushFront(const T &data)
{
    Node<T> *node = new Node<T>{data, head, nullptr};
    if (head)
    {
        head->prev = node;
    }
    else
    {
        tail = node;
    }
    head = node;
}

template <typename T>
void List<T>::pushBack(const T &data)
{
    Node<T> *node = new Node<T>{data, nullptr, tail};
    if (tail)
    {
        tail->next = node;
    }
    else
    {
        head = node;
    }
    tail = node;
}

template <typename T>
void List<T>::deleteByValue(const T &data)
{
    for (Node<T> *node = head; node; node = node->next)
    {
        if (node->data == data)
        {
            if (node->prev)
            {
                node->prev->next = node->next;
            }
            else
            {
                head = node->next;
            }
            if (node->next)
            {
                node->next->prev = node->prev;
            }
            else
            {
                tail = node->prev;
            }
            delete node;
            return;
        }
    }
    throw std::invalid_argument("Значение не найдено");
}

template <typename T>
void List<T>::printingFromTheBeginning(std::ostream &outStream) const
{
    for (Node<T> *node = head; node; node = node->next)
    {
        outStream << node->data << ' ';
    }
    outStream << '\n';
}

template <typename T>
void List<T>::printingFromTheEnd(std::ostream &outStream) const
{
    for (Node<T> *node = tail; node; node = node->prev)
    {
        outStream << node->data << ' ';
    }
    outStream << '\n';
}
