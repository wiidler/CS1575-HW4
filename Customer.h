#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <iostream>

using namespace std;

class Customer
{
public:
    Customer()
    {
        m_name = "";
        m_popplersWanted = 0;
        m_popplersEaten = 0;
    }
    Customer(string name, int popplersWanted)
    {
        m_name = name;
        m_popplersWanted = popplersWanted;
        m_popplersEaten = 0;
    }
    void addPopplersEaten()
    {
        m_popplersEaten++;
    }
    void addPopplersWanted()
    {
        m_popplersWanted++;
    }
    void resetPopplersWanted()
    {
        m_popplersWanted = 0;
    }
    string getName() const
    {
        return m_name;
    }
    int getPopplersWanted() const
    {
        return m_popplersWanted;
    }
    int getPopplersEaten() const
    {
        return m_popplersEaten;
    }

private:
    string m_name;
    int m_popplersWanted;
    int m_popplersEaten;
};

#endif