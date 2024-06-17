#include "TDeque.hpp"

template <typename TInfo>
void TDeque<TInfo>::Erase()
{
    while (front)
    {
        TDequeItem *temp = front;
        front = front->next;
        delete temp;
    }
    rear = nullptr;
    size = 0;
}

template <typename TInfo>
void TDeque<TInfo>::Clone(const TDeque &rhs)
{
    TDequeItem *temp = rhs.front;
    while (temp)
    {
        this->InsRear(temp->Info);
        temp = temp->next;
    }
}

template <typename TInfo>
void TDeque<TInfo>::DeleteItem(TDequeItem *item)
{
    if (item->prev)
    {
        item->prev->next = item->next;
    }
    if (item->next)
    {
        item->next->prev = item->prev;
    }
    delete item;
    --size;
}

template <typename TInfo>
void *TDeque<TInfo>::PtrByIndex(unsigned index) const
{
    if (index >= size)
    {
        return nullptr;
    }
    TDequeItem *temp = front;
    while (index--)
    {
        temp = temp->next;
    }
    return temp;
}

template <typename TInfo>
TDeque<TInfo>::TDeque() : front(nullptr), rear(nullptr), size(0) {}

template <typename TInfo>
TDeque<TInfo>::TDeque(const TDeque &rhs) : TDeque()
{
    Clone(rhs);
}

template <typename TInfo>
TDeque<TInfo>::~TDeque()
{
    Erase();
}

template <typename TInfo>
void TDeque<TInfo>::InsFront(TInfo info)
{
    TDequeItem *temp = new TDequeItem{info, front, nullptr};
    if (front)
    {
        front->prev = temp;
    }
    front = temp;
    if (!rear)
    {
        rear = temp;
    }
    ++size;
}

template <typename TInfo>
void TDeque<TInfo>::InsRear(TInfo info)
{
    TDequeItem *temp = new TDequeItem{info, nullptr, rear};
    if (rear)
    {
        rear->next = temp;
    }
    rear = temp;
    if (!front)
    {
        front = temp;
    }
    ++size;
}

template <typename TInfo>
bool TDeque<TInfo>::DelFront(TInfo &info)
{
    if (!front)
    {
        return false;
    }
    info = front->Info;
    TDequeItem *temp = front;
    front = front->next;
    if (front)
    {
        front->prev = nullptr;
    }
    else
    {
        rear = nullptr;
    }
    delete temp;
    --size;
    return true;
}

template <typename TInfo>
bool TDeque<TInfo>::DelRear(TInfo &info)
{
    if (!rear)
    {
        return false;
    }
    info = rear->Info;
    TDequeItem *temp = rear;
    rear = rear->prev;
    if (rear)
    {
        rear->next = nullptr;
    }
    else
    {
        front = nullptr;
    }
    delete temp;
    --size;
    return true;
}

template <typename TInfo>
const TDeque<TInfo> &TDeque<TInfo>::operator=(const TDeque &rhs)
{
    if (this != &rhs)
    {
        Erase();
        Clone(rhs);
    }
    return *this;
}

template <typename TInfo>
const TInfo &TDeque<TInfo>::GetByIndex(unsigned index) const
{
    TDequeItem *temp = static_cast<TDequeItem *>(PtrByIndex(index));
    if (temp)
    {
        return temp->Info;
    }
    throw std::out_of_range("Обращение к элементу за границами");
}

template <typename TInfo>
void TDeque<TInfo>::SetByIndex(TInfo info, unsigned index)
{
    TDequeItem *temp = static_cast<TDequeItem *>(PtrByIndex(index));
    if (temp)
    {
        temp->Info = info;
    }
    else
    {
        throw std::out_of_range("Обращение к элементу за границами");
    }
}

template <typename TInfo>
inline void TDeque<TInfo>::Browse(void (*func)(TInfo &))
{
    TDequeItem *temp = front;
    while (temp)
    {
        func(temp->Info);
        temp = temp->next;
    }
}

template <typename TInfo>
inline void TDeque<TInfo>::Browse(void (*func)(TInfo)) const
{
    TDequeItem *temp = front;
    while (temp)
    {
        func(temp->Info);
        temp = temp->next;
    }
}
