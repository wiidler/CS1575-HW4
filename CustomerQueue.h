#ifndef CUSTOMERQUEUE_H
#define CUSTOMERQUEUE_H

#include "abstractqueue.h"

template <class T>
class CustomerQueue : public AbstractQueue<T>
{
public:
    CustomerQueue()
    {
        m_size = 0;
        m_max = 10;
        m_data = new T[10];
    }
    CustomerQueue(const CustomerQueue<T> &copy);
    bool isEmpty() const;
    const T &front() const throw(Oops);
    const T &back() const throw(Oops);
    void enqueue(const T &x);
    void dequeue();
    void clear();
    ~CustomerQueue();
    T &operator[](int i);

private:
    void grow();
    void shrink();
    T *m_data;
    unsigned long m_size;
    unsigned long m_max;
};

#include "CustomerQueue.hpp"

#endif