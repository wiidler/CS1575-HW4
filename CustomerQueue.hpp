template <class T>
CustomerQueue<T>::CustomerQueue(const CustomerQueue<T> &copy)
{
    m_size = copy.m_size;
    m_max = copy.m_capacity;
    m_data = new T[copy._capacity];
    for (int i = 0; i < m_size; i++)
    {
        m_data[i] = copy.m_data[i];
    }
}

template <class T>
bool CustomerQueue<T>::isEmpty() const
{
    return m_size == 0;
}

template <class T>
const T &CustomerQueue<T>::front() const throw(Oops)
{
    if (isEmpty())
        throw Oops("ERROR: Empty Queue!");
    else
        return m_data[0];
}

template <class T>
const T &CustomerQueue<T>::back() const throw(Oops)
{
    if (isEmpty())
        throw Oops("ERROR: Empty Queue!");
    else
        return m_data[m_size - 1];
}

template <class T>
void CustomerQueue<T>::enqueue(const T &x)
{
    if (m_size == m_max)
        grow();
    m_data[m_size] = x;
    m_size++;
}

template <class T>
void CustomerQueue<T>::dequeue()
{
    for (int i = 0; i < m_size - 1; i++)
    {
        m_data[i] = m_data[i + 1];
    }
    m_size--;
}

template <typename T>
void CustomerQueue<T>::clear()
{
    delete[] m_data;
    m_max = 0;
    m_size = 0;
}

template <typename T>
CustomerQueue<T>::~CustomerQueue()
{
    delete[] m_data;
}

template <typename T>
T &CustomerQueue<T>::operator[](int i)
{
    if ((i >= m_size) || (i < 0))
    {
        throw Oops("ERROR: Index out of range!");
    }
    else
    {
        return m_data[i];
    }
}

template <class T>
void CustomerQueue<T>::grow()
{
    m_max = m_max * 2;
    T *tmp = new T[m_max];
    for (int i = 0; i < m_size; i++)
    {
        tmp[i] = m_data[i];
    }
    delete[] m_data;
    m_data = tmp;
}

template <class T>
void CustomerQueue<T>::shrink()
{
    m_max = m_max / 2;
    T *tmp = new T[m_max];
    for (int i = 0; i < m_size; i++)
    {
        tmp[i] = m_data[i];
    }
    delete[] m_data;
    m_data = tmp;
}
