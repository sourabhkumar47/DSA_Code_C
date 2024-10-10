#include <iostream>
#include <list>
using namespace std;

int main()
{

    list<int> lst;
    lst.push_back(20);
    lst.push_back(10);
    lst.push_back(50);
    lst.push_back(10);
    lst.push_back(40);

    list<int>::iterator it = lst.begin();

    while (it != lst.end())
    {
        cout << *it << " ";
        it++;
    }
}