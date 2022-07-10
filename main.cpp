#include <iostream>
using namespace std;

template <typename T>
class MyQueue
{
	T* arr;
	int capacity;
	int size = 0;
	int front;
	int back;

public:
	MyQueue(int NewSize = 1);
	~MyQueue();

	T Front();
	void PopFront();
	void Push(T element);
	int Size();
	void IsFull();
	void IsEmpty();
};

template<typename T>
MyQueue<T>::MyQueue(int NewCapacity)
{
	capacity = NewCapacity;
	arr = new T[capacity];
	size = 0;
	front = 0;
	back = 0;
}

template<typename T>
MyQueue<T>::~MyQueue()
{
	delete[] arr;
	arr = nullptr;
}

template<typename T>
T MyQueue<T>::Front()
{
	cout << arr[front] << endl;
	return arr[front];
}

template<typename T>
void MyQueue<T>::PopFront()
{
	if (size == 0)
	{
		cout << "Queue is empty, nothing to pop from the front" << endl;
	}
	else
	{
		front++;
		front = front % capacity;
		size--;
	}
}


template<typename T>
void MyQueue<T>::Push(T element)
{
	if (size == capacity)
	{
		cout << "Queue is already full" << endl;
	}
	else
	{
		arr[back] = element;
		back++;
		back = back % capacity;
		size++;
	}
}

template<typename T>
int MyQueue<T>::Size()
{
	cout << size << endl;
	return size;
}

template<typename T>
void MyQueue<T>::IsFull()
{
	if (size == capacity)
	{
		cout << "Queue is full" << endl;
	}
	else
	{
		cout << "Queue is not full" << endl;
	}
}

template<typename T>
void MyQueue<T>::IsEmpty()
{
	if (size == 0)
	{
		cout << "Queue is empty" << endl;
	}
	else
	{
		cout << "Queue is not empty" << endl;
	}
}

int main()
{
	MyQueue<int> TestQueue(3);
	TestQueue.IsEmpty();
	TestQueue.Push(3);
	TestQueue.Front();
	TestQueue.Push(1);
	TestQueue.PopFront();
	TestQueue.Front();
	TestQueue.Push(2);
	TestQueue.Push(3);
	TestQueue.IsFull();
	TestQueue.Size();
	TestQueue.PopFront();
	TestQueue.PopFront();
	TestQueue.PopFront();
	TestQueue.Push(10);
	TestQueue.Front();
	TestQueue.IsEmpty();

	return 0;
}