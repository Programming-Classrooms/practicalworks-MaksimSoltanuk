#ifndef LIST_HPP
#define LIST_HPP
#include <iostream>

template <typename T>
class List
{
public:
    List();             // по умолчанию создаёт пустой список
    List(const List &); // копирования
    ~List();            // деструктор

    void pushBack(T);                    // добавление в конец
    uint16_t getCountElements();         // получить количество элемнтов в списке
    T &operator[](const int);            // итерации
    void popFront();                     // удалить первый
    void popBack();                      // удалить последний
    void pushFront(T);                   // втсавка нового впрёд
    uint16_t FindElement(T);             // поиск по значению
    void deleteByValue(T);               // удаление по значению
    List<T> &operator=(const List<T> &); // оператор присваивания
    void outputList();                   // вывод списка
    void checkList(void func(T)) const;  // callback

private:
    uint16_t countElements; // количество элемнтов в списке
    struct Node
    {
        T info;
        Node *next;
        Node() : info(T()), next(nullptr){};
    };
    Node *head;
};

#include "list.inl"

#endif