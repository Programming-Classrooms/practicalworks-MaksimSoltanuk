#ifndef LIST_HPP
#define LIST_HPP

#include <string>
#include <iostream>

struct Student
{
    std::string name;
    size_t course;
    friend std::ostream &operator<<(std::ostream &outStream, const Student &rhs)
    {
        outStream << rhs.name << " " << rhs.course << '\n';
        return outStream;
    }
};

template <typename T>
struct Node
{
    T data;
    Node *next;
    Node *prev;
};

template <typename T>
class List
{
private:
    Node<T> *head;
    Node<T> *tail;

public:
    // Конструктор по умолчанию
    List();
    // Конструктор копирования
    List(const List &);
    // Деструткор
    ~List();

    // Оператор присваивания
    List &operator=(const List &);
    // Оператор обращения
    T &operator[](size_t);
    // Добавление элемента в начало
    void pushFront(const T &);
    // Добавление элемента в конец
    void pushBack(const T &);
    // Удаление по значению
    void deleteByValue(const T &);
    // метод, выводящий содержимое списка от первого до последнего элемента в указанный поток
    void printingFromTheBeginning(std::ostream &) const;
    // метод, выводящий содержимое списка от последнего до первого элемента в указанный поток
    void printingFromTheEnd(std::ostream &) const;
};

#include "List.inl"

#endif
