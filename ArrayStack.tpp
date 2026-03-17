template <typename T>
ArrayStack<T>::ArrayStack(int i)
    : buffer(new T[i]), maxSize(i) {}

template <typename T>
ArrayStack<T>::ArrayStack(const ArrayStack<T> &copyObj)
{
    copy(copyObj);
}

template <typename T>
ArrayStack<T> &ArrayStack<T>::operator=(const ArrayStack<T> &rightObj)
{
    if (this != &rightObj)
    {
        clear();
        copy(rightObj);
    }
    return *this;
}

template <typename T>
ArrayStack<T>::~ArrayStack()
{
    clear();
}

template <typename T>
void ArrayStack<T>::clear()
{
    delete[] buffer;
    buffer = nullptr;
    this->length = 0;
}

template <typename T>
void ArrayStack<T>::copy(const ArrayStack<T> &copyObj)
{
    this->length = copyObj.length;
    maxSize = copyObj.maxSize;
    buffer = new T[maxSize];

    for (int i = 0; i < copyObj.length; i++)
    {
        buffer[i] = copyObj.buffer[i];
    }
}

template <typename T>
int ArrayStack<T>::getLength() const
{
    return this->length;
}

template <typename T>
int ArrayStack<T>::getMaxSize() const
{
    return maxSize;
}

template <typename T>
bool ArrayStack<T>::isEmpty() const
{
    return this->length == 0;
}

template <typename T>
bool ArrayStack<T>::isFull() const
{
    return this->length == maxSize;
}

template <typename T>
T ArrayStack<T>::peek() const
{
    if (isEmpty())
    {
        throw string("peek: error, stack is empty, cannot access the top");
    }

    return buffer[this->length - 1];
}

template <typename T>
void ArrayStack<T>::pop()
{
    if (isEmpty())
    {
        throw string("pop: error, stack is empty, avoiding underflow");
    }

    this->length--;
}

template <typename T>
void ArrayStack<T>::push(const T &elem)
{
    if (isFull())
    {
        throw string("push: error, stack is full, avoiding overflow");
    }

    if (buffer == nullptr)
    {
        buffer = new T[maxSize];
    }

    buffer[this->length++] = elem;
}

template <typename T>
void ArrayStack<T>::print()
{
    cout << "ArrayStack contents: ";
    if (isEmpty())
    {
        cout << "Stack is empty, no elements to display.\n";
    }
    else
    {
        for (int i = this->length - 1; i >= 0; i--)
        {
            cout << (i == this->length - 1 ? "top\t" : "\t")
                 << buffer[i];
        }
    }
    cout << endl;
}

template <typename T>
void ArrayStack<T>::rotate(typename Stack<T>::Direction dir)
{
    if (isEmpty())
    {
        throw string("rotate: error, stack is empty, unable to rotate");
    }
    else if (dir == Stack<T>::RIGHT)
    {
        T top = peek();
        for (int i = this->length - 2; i >= 0; i--)
        {
            buffer[i + 1] = buffer[i];
        }
        buffer[0] = top;
    }
    else if (dir == Stack<T>::LEFT)
    {
        T bottom = buffer[0];
        for (int i = 1; i < this->length; i++)
        {
            buffer[i - 1] = buffer[i];
        }
        buffer[this->length - 1] = bottom;
    }
    else
    {
        throw string("rotate: error, unknown direction");
    }
}

template <typename T>
ostream &operator<<(ostream &outStream, const ArrayStack<T> &myObj)
{
    if (myObj.isEmpty())
    {
        outStream << "Stack is empty, no elements to display.\n";
    }
    else
    {
        for (int i = myObj.length - 1; i >= 0; i--)
        {
            outStream << (i == myObj.length - 1 ? "top\t" : "\t")
                      << myObj.buffer[i] << endl;
        }
    }

    return outStream;
}
