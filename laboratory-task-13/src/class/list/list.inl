#include "list.hpp"

// создание пстого списка
template <typename T>
List<T>::List() : head(nullptr), countElements(0) {}

// конструктор 
template <typename T>
List<T>::List(const List &second)
{
    this->head = nullptr;
    countElements = 0;
    Node *temp = second.head;
    while (temp != nullptr)
    {
        this->pushBack(temp->info);
        temp = temp->next;
    }
}

// деструктор
template <typename T>
List<T>::~List()
{
    while (head != nullptr)
    {
        popFront();
    }
}

// вставка в конец
template <typename T>
void List<T>::pushBack(T data)
{
    if (head == nullptr)
    {
        head = new Node;
        head->info = data;
    }
    else
    {
        Node *temp = head;
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }
        temp->next = new Node;
        temp->next->info = data;
    }
    ++countElements;
}

// количество элемнтов в списке
template <typename T>
uint16_t List<T>::getCountElements()
{
    return countElements;
}

// перемещение по списку
template <typename T>
T &List<T>::operator[](const int index)
{
    Node *temp = head;
    uint16_t count = 0;
    while (temp != nullptr)
    {
        if (count == index)
        {
            return temp->info;
        }
        temp = temp->next;
        ++count;
    }
}

// удалить перывый
template <typename T>
void List<T>::popFront()
{
    if (head == nullptr)
    {
        return;
    }
    Node *temp = head;
    head = head->next;
    delete temp;
    --countElements;
}

// удалить сзади
template <typename T>
void List<T>::popBack()
{
    if (head == nullptr)
    {
        return;
    }
    if (head->next == nullptr)
    {
        delete head;
        head = nullptr;
        return;
    }
    Node *temp = head;
    while (temp->next->next != nullptr)
    {
        temp = temp->next;
    }
    delete temp->next;
    temp->next = nullptr;
    --countElements;
}

// добавить в начало
template <typename T>
void List<T>::pushFront(T data)
{
    Node *newNode = new Node;
    newNode->info = data;
    newNode->next = head;
    head = newNode;
    ++countElements;
}

// поиск элемента
template <typename T>
uint16_t List<T>::FindElement(T data)
{
    uint16_t ind = 0;
    Node *temp = head;
    while (temp != nullptr)
    {
        if (temp->info == data)
        {
            return ind;
        }
        temp = temp->next;
        ++ind;
    }
    std::cout << "list haven't this element";
    return -1;
}

// удалить по значению
template <typename T>
void List<T>::deleteByValue(T data)
{
    Node *temp = head;
    if (temp != nullptr && temp->info == data)
    {
        head = temp->next;
        delete temp;
        --countElements;
        return;
    }

    Node *prev = nullptr;
    while (temp != nullptr && temp->info != data)
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp == nullptr)
    {
        return;
    }

    prev->next = temp->next;
    delete temp;
    --countElements;
}

// присвоить
template <typename T>
List<T> &List<T>::operator=(const List<T> &second)
{
    if (&second == this || second.head == this->root)
    {
        return *this;
    }
    this->~List();
    this->head = nullptr;
    countElements = 0;
    for (size_t i = 0; i < second.getCountElements(); ++i)
    {
        pushBack(second[i]);
    }

    return *this;
}

// вывод списка
template <typename T>
void List<T>::outputList()
{
    if (this->getCountElements() == 0)
    {
        throw std::logic_error("list is empty");
    }
    else
    {
        for (size_t i = 0; i < this->getCountElements(); ++i)
        {
            std::cout << (*this)[i] << '\n';
        }
    }
}

// callback
template<typename T>
void List<T>::checkList(void func(T)) const
{
	Node* temp = head;
	for (size_t i = 0; temp != nullptr; ++i, temp = temp->next) {
		func(temp->info);	
	}
}
