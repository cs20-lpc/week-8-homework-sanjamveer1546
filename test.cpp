#include <iostream>
#include <string>
#include "StackFactory.hpp"

using namespace std;

template <typename T>
void basicTest(Stack<T> *s, const string &name)
{
    cout << "Testing " << name << endl;

    cout << "Is empty? " << (s->isEmpty() ? "Yes" : "No") << endl;

    s->push(10);
    s->push(20);
    s->push(30);

    cout << "Length after 3 pushes: " << s->getLength() << endl;
    cout << "Top element: " << s->peek() << endl;

    s->print();

    s->pop();
    cout << "After one pop, top: " << s->peek() << endl;
    s->print();

    s->rotate(Stack<T>::RIGHT);
    cout << "After RIGHT rotate:" << endl;
    s->print();

    s->rotate(Stack<T>::LEFT);
    cout << "After LEFT rotate:" << endl;
    s->print();

    s->clear();
    cout << "After clear, length: " << s->getLength() << endl;
    cout << "Is empty? " << (s->isEmpty() ? "Yes" : "No") << endl;

    cout << "------------------------" << endl;
}

int main()
{
    try
    {
        Stack<int> *linked = StackFactory<int>::GetStack();
        Stack<int> *array = StackFactory<int>::GetStack(10);

        basicTest(linked, "LinkedListStack<int>");
        basicTest(array, "ArrayStack<int>");

        delete linked;
        delete array;

        Stack<string> *linkedStr = StackFactory<string>::GetStack();
        linkedStr->push("A");
        linkedStr->push("B");
        linkedStr->push("C");

        cout << "Testing LinkedListStack<string>" << endl;
        linkedStr->print();
        cout << "Peek: " << linkedStr->peek() << endl;

        linkedStr->rotate(Stack<string>::RIGHT);
        linkedStr->print();

        linkedStr->rotate(Stack<string>::LEFT);
        linkedStr->print();

        delete linkedStr;
    }
    catch (string err)
    {
        cout << err << endl;
    }

    return 0;
}