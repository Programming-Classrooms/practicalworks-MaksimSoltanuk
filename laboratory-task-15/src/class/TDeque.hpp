#ifndef TDEQUE_HPP
#define TDEQUE_HPP

template <typename TInfo>
class TDeque /* дек – двустороння очередь */
{
private:
    struct TDequeItem // элемент дека
    {
        TInfo Info;       // данные
        TDequeItem *next; // указатель на следующий элемент
        TDequeItem *prev; // указатель на предыдущий элемент
    };

    TDequeItem *front, *rear; /* указатели на первый и последний элементы в списке */
    int size;                 // количество элементов в деке

    void Erase();                           //  удаление всех элементов
    void Clone(const TDeque &other);        //  клонирование другого дека
    void DeleteItem(TDequeItem *item);      //  удаление элемента по указателю
    void *PtrByIndex(unsigned index) const; //  получение указателя на элемент с заданным индексом

public:
    TDeque();                                      // конструктор
    TDeque(const TDeque &other);                   // конструктор копирования
    ~TDeque();                                     // деструктор
    void InsFront(TInfo info);                     // включение элемента в голову дека
    void InsRear(TInfo info);                      // включение элемента в хвост дека
    bool DelFront(TInfo &info);                    // исключение элемента из головы дека
    bool DelRear(TInfo &info);                     // исключение элемента из хвоста дека
    const TDeque &operator=(const TDeque &other);  // оператор присваивания
    const TInfo &GetByIndex(unsigned index) const; // получение элемента по индексу
    void SetByIndex(TInfo info, unsigned index);   // изменение элемента по индексу
    void Browse(void(*func)(TInfo &));                    // просмотр с изменением элементов
    void Browse(void(*func)(TInfo)) const;                // просмотр без изменения элементов
};

#include "TDeque.inl"

#endif
