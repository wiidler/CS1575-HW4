#include "randomengine.h"
#include "Customer.h"
#include "CustomerQueue.h"
#include <iostream>

using namespace std;

int main()
{
    int totalPopplersEaten = 0;
    randomEngine dice;
    int customers = 0;
    cin >> customers;
    CustomerQueue<Customer> line;
    CustomerQueue<Customer> exit;
    for (int i = customers; i > 0; i--)
    {
        string name;
        int popplersWanted;
        cin >> name;
        cin >> popplersWanted;
        Customer person(name, popplersWanted);
        line.enqueue(person);
    }
    while (!line.isEmpty())
    {
        int boxesBought = 0;
        int popplersWanted = line.front().getPopplersWanted();
        while (popplersWanted > 0)
        {
            boxesBought++;
            popplersWanted -= 5;
        }
        int popplersEaten = boxesBought * 5;
        line[0].resetPopplersWanted();
        for (int i = boxesBought * 5; i > 0; i--)
        {
            int diceroll = dice.rollD(6);
            line[0].addPopplersEaten();
            totalPopplersEaten++;
            if (diceroll == 6)
                line[0].addPopplersWanted();
        }
        cout << line.front().getName() << " eats " << popplersEaten << " popplers. ";
        if (line.front().getPopplersWanted() == 0)
        {
            cout << line.front().getName() << " is satisfied after eating " << line.front().getPopplersEaten() << " popplers." << endl;
            exit.enqueue(line.front());
            line.dequeue();
        }
        else
        {
            if (line.front().getPopplersWanted() == 1)
                cout << line.front().getName() << " wants one more poppler!" << endl;
            else
                cout << line.front().getName() << " wants " << line.front().getPopplersWanted() << " more popplers!" << endl;
            line.enqueue(line.front());
            line.dequeue();
        }
    }
    cout << endl;
    cout << "A total of " << totalPopplersEaten << " popplers were eaten." << endl;
    int indexHigh = 0;
    int indexLow = 0;
    for (int i = 0; i < customers - 1; i++)
    {
        if (exit[i].getPopplersEaten() < exit[i + 1].getPopplersEaten())
            indexHigh = i + 1;
    }
    for (int i = 0; i < customers - 1; i++)
    {
        if (exit[i].getPopplersEaten() > exit[i + 1].getPopplersEaten())
            indexLow = i + 1;
    }
    cout << exit[indexHigh].getName() << " ate the most popplers: " << exit[indexHigh].getPopplersEaten() << endl;
    cout << exit[indexLow].getName() << " ate the fewer popplers: " << exit[indexLow].getPopplersEaten() << endl;
}
