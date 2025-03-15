//linear queue implementation
//
//#include<iostream>
//using namespace std;
//class queue {
//private:
//	int* arr;
//	int size;
//	int rear = -1;
//public:
//	queue(int size) {
//		arr = new int[size];
//		this->size = size;
//	}
//	~queue() {
//		delete[]arr;
//	}
// 
//	bool isempty() {
//		return rear == -1;
//	}
//	bool isfull() {
//		return rear == size - 1;
//	}
//	void add(int value) {
//		if (isfull()) {
//			cout << "queue overflow!!";
//			return;
//		}
//		rear++;
//		arr[rear] = value;
//	}
//	int remove() {
//		if (isempty()) {
//			cout << "queue underflow!!";
//			exit(1);
//		}
//		int front = arr[0];
//		for (int i = 0; i < rear; i++) {
//			arr[i] = arr[i + 1];
//		}
//		rear--;
//		return front;
//	}
//};
//int main() {
//	queue q(10);
//	for (int i = 1; i <= 10; i++) {
//		q.add(i);
//	}
//	while (!q.isempty()) {
//		cout << q.remove();
//	}
//	return 0;
//}
//
//
//circular queue implementation
//exercise 4.1
//
//#define maxQueue 100
//typedef int itemType;
//#include<iostream>
//using namespace std;
//class Queue {
//private:
//	int front, rear, count;
//	itemType items[maxQueue];
//public:
//	Queue();
//	bool isEmpty();
//	bool isFull();
//	void insert(itemType item);
//	int remove();
//	int peek();
//};
//Queue::Queue() {
//	front = 0;
//	rear = 0;
//	count = 0;
//}
//bool Queue::isEmpty() {
//	return count == 0;
//}
//bool Queue::isFull() {
//	return count == maxQueue;
//}
//void Queue::insert(itemType item) {
//	if (isFull()) {
//		cout << "Queue Overflow!!";
//		exit(1);
//	}
//	else {
//		items[rear] = item;
//		rear = (rear + 1) % maxQueue;
//		++count;
//	}
//}
//int Queue::remove() {
//	if (isEmpty()) {
//		cout << "Queue Underflow!!";
//		exit(1);
//	}
//	int newItem = items[front];
//	front = (front + 1) % maxQueue;
//	--count;
//	return newItem;
//}
//int Queue::peek() {
//	if (isEmpty()) {
//		cout << "No value:";
//		exit(1);
//	}
//	return items[front];
//}
//int main() {
//	Queue q;
//	for (int i = 1; i < 10; i++) {
//		q.insert(i);
//	}
//	cout<<q.remove();
//	cout<<q.remove();
//	q.insert(11);
//	q.insert(12);
//	while (!q.isEmpty()) {
//		cout << q.peek();
//		q.remove();
//	}
//	
//}

// Exercise 4.2
//
//#include<iostream>
//using namespace std;
//template<class ItemType>
//class Queue {
//private:
//	int front, rear, maxQueue, count;
//	ItemType* items;
//public:
//	Queue();
//	Queue(int max);
//	~Queue();
//	bool isEmpty();
//	bool isFull();
//	void insert(ItemType item);
//	int remove(ItemType& newItem);
//	ItemType peek();
//};
//template<class ItemType>
//Queue<ItemType>::Queue() {
//	front = 0;
//	rear = 0;
//	count = 0;
//	maxQueue = 500;
//	items = new ItemType[maxQueue];
//}
//template<class ItemType>
//Queue<ItemType>::Queue(int max) {
//	front = 0;
//	rear = 0;
//	count = 0;
//	maxQueue = max;
//	items = new ItemType[max];
//}
//template<class ItemType>
//Queue<ItemType>::~Queue() {
//	delete[]items;
//}
//template<class ItemType>
//bool Queue<ItemType>::isEmpty() {
//	return count == 0;
//}
//template<class ItemType>
//bool Queue<ItemType>::isFull() {
//	return count == maxQueue;
//}
//template<class ItemType>
//void Queue<ItemType>::insert(ItemType item) {
//	if (isFull()) {
//		cout << "Queue is already full!!";
//		exit(1);
//	}
//	else {
//		items[rear] = item;
//		rear = (rear + 1) % maxQueue;
//		++count;
//	}
//	
//}
//template<class ItemType>
//int Queue<ItemType>::remove(ItemType& newItem) {
//	if (isEmpty()) {
//		cout << "Queue is Empty!!";
//		exit(1);
//	}
//	else {
//		newItem = items[front];
//		front = (front + 1) % maxQueue;
//		--count;
//	}
//	return true;
//}
//template<class ItemType>
//ItemType Queue<ItemType>::peek() {
//	if (isEmpty()) {
//		cout << "No Element";
//		exit(1);
//	}
//	return items[front];
//}
//int main() {
//	Queue<string>q(10);
//	string friends[] = {"Razi","Ameen","Sohail","Aryan","Umar","Xavair","Idrees","Abdul Manan","Huzaifa","Ahmed" };
//	for (int i = 0; i < 10; i++) {
//		q.insert(friends[i]);
//	}
//	string removed;
//	q.remove(removed);
//	q.insert("Ahad");
//	q.remove(removed);
//	q.insert("Ibrahim");
//
//	while (!q.isEmpty()) {
//		string rem;
//		q.remove(rem);
//		cout << rem << "\t";
//	}
//	
//	return 0;
//}

//Exercise 4.3 and 4.4
#include <iostream>
using namespace std;

template<class ItemType>
class DEqueue {
private:
    int front, rear, maxQue;
    ItemType* items;

public:
    DEqueue(int max = 100);
    ~DEqueue();
    bool isEmpty();
    bool isFull();
    void insertLeft(ItemType itemi);
    void removeLeft(ItemType& itemr);
    void insertRight(ItemType itemii);
    void removeRight(ItemType& itemrr);
};

template<class ItemType>
DEqueue<ItemType>::DEqueue(int max) {
    front = -1;
    rear = -1;
    maxQue = max;
    items = new ItemType[maxQue];
}

template<class ItemType>
DEqueue<ItemType>::~DEqueue() {
    delete[] items;
}

template<class ItemType>
bool DEqueue<ItemType>::isEmpty() {
    return (front == -1);
}

template<class ItemType>
bool DEqueue<ItemType>::isFull() {
    return ((rear + 1) % maxQue == front && front != -1);
}

template<class ItemType>
void DEqueue<ItemType>::insertLeft(ItemType itemi) {
    if (isFull()) {
        cout << "Queue is already Full!!" << endl;
        return;
    }
    if (isEmpty()) {
        front = rear = 0;
    }
    else if (front == 0) {
        front = maxQue - 1;
    }
    else {
        --front;
    }
    items[front] = itemi;
}

template<class ItemType>
void DEqueue<ItemType>::removeLeft(ItemType& itemr) {
    if (isEmpty()) {
        cout << "Queue is empty!!" << endl;
        return;
    }
    itemr = items[front];
    if (front == rear) {
        front = rear = -1;
    }
    else if (front == maxQue - 1) {
        front = 0;
    }
    else {
        front++;
    }
}

template<class ItemType>
void DEqueue<ItemType>::insertRight(ItemType itemii) {
    if (isFull()) {
        cout << "Queue is already Full!!" << endl;
        return;
    }
    if (isEmpty()) {
        front = rear = 0;
    }
    else if (rear == maxQue - 1) {
        rear = 0;
    }
    else {
        rear++;
    }
    items[rear] = itemii;
}

template<class ItemType>
void DEqueue<ItemType>::removeRight(ItemType& itemrr) {
    if (isEmpty()) {
        cout << "Queue is Empty!!" << endl;
        return;
    }
    itemrr = items[rear];
    if (front == rear) {
        front = rear = -1;
    }
    else if (rear == 0) {
        rear = maxQue - 1;
    }
    else {
        rear--;
    }
}

int main() {
    DEqueue<int> q(10);

    for (int i = 1; i <= 10; i++) {
        q.insertRight(i);
    }

    int k;
    for (int i = 1; i <= 10; i++) {
        q.removeLeft(k);
        cout << k << " ";
    }

    return 0;
}
