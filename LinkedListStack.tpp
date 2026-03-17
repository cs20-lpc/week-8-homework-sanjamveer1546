template <typename T>
LinkedListStack<T>::LinkedListStack()
{
    top = nullptr;
    this->length = 0;
}

template <typename T>
LinkedListStack<T>::LinkedListStack(const LinkedListStack<T> &copyObj)
{
    top = nullptr;
    this->length = 0;
    copy(copyObj);
}

template <typename T>
LinkedListStack<T> &LinkedListStack<T>::operator=(const LinkedListStack<T> &rightObj)
{
    if (this != &rightObj)
    {
        clear();
        copy(rightObj);
    }
    return *this;
}

template <typename T>
LinkedListStack<T>::~LinkedListStack()
{
    clear();
}

template <typename T>
void LinkedListStack<T>::clear()
{
    while (top != nullptr)
    {
        Node<T> *temp = top;
        top = top->next;
        delete temp;
    }
    this->length = 0;
}

template <typename T>
void LinkedListStack<T>::copy(const LinkedListStack<T> &copyObj)
{
    if (copyObj.top == nullptr)
    {
        top = nullptr;
        this->length = 0;
        return;
    }

    top = new Node<T>(copyObj.top->data);
    Node<T> *currThis = top;
    Node<T> *currOther = copyObj.top->next;

    while (currOther != nullptr)
    {
        currThis->next = new Node<T>(currOther->data);
        currThis = currThis->next;
        currOther = currOther->next;
    }

    this->length = copyObj.length;
}

template <typename T>
int LinkedListStack<T>::getLength() const
{
    return this->length;
}

template <typename T>
bool LinkedListStack<T>::isEmpty() const
{
    return this->length == 0;
}

template <typename T>
T LinkedListStack<T>::peek() const
{
    if (isEmpty())
    {
        throw string("peek: error, stack is empty, cannot access the top");
    }
    return top->data;
}

template <typename T>
void LinkedListStack<T>::pop()
{
    if (isEmpty())
    {
        throw string("pop: error, stack is empty, avoiding underflow");
    }

    Node<T> *temp = top;
    top = top->next;
    delete temp;
    this->length--;
}

template <typename T>
void LinkedListStack<T>::push(const T &elem)
{
    Node<T> *newNode = new Node<T>(elem);
    newNode->next = top;
    top = newNode;
    this->length++;
}

template <typename T>
void LinkedListStack<T>::rotate(typename Stack<T>::Direction dir)
{
    if (isEmpty())
    {
        throw string("rotate: error, stack is empty, unable to rotate");
    }

    if (this->length == 1)
    {
        return;
    }

    if (dir == Stack<T>::RIGHT)
    {
        Node<T> *first = top;
        top = top->next;
        first->next = nullptr;

        Node<T> *curr = top;
        while (curr->next != nullptr)
        {
            curr = curr->next;
        }
        curr->next = first;
    }
    else if (dir == Stack<T>::LEFT)
    {
        Node<T> *prev = nullptr;
        Node<T> *curr = top;

        while (curr->next != nullptr)
        {
            prev = curr;
            curr = curr->next;
        }

        prev->next = nullptr;
        curr->next = top;
        top = curr;
    }
    else
    {
        throw string("rotate: error, unknown direction");
    }
}

template <typename T>
void LinkedListStack<T>::print()
{
    cout << "LinkedListStack contents: ";
    if (isEmpty())
    {
        cout << "Stack is empty, no elements to display.\n";
    }
    else
    {
        Node<T> *curr = top;
        while (curr != nullptr)
        {
            cout << curr->data << "\t";
            curr = curr->next;
        }
        cout << endl;
    }
}