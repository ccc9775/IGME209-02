#pragma once
using namespace std;

template<class T>
class Queue
{
public:
	Queue() {
		first = nullptr;
		count = 0;
	}
	/*Queue(const Queue& other) : data(new char[std::strlen(other.data) + 1]) {
		std::strcpy(data, other.data);
	}*/
	Queue& operator=(const Queue& other) {
		if (this != &other) {
			std::strcpy(data, other.data);
		}
		return *this;
	}
	~Queue() {
		while (!IsEmpty()) {
			Pop();
		}
	}
	void Print();
	bool IsEmpty();
	void Push(T data);
	void PushFirst(T data);
	void Pop();
	void PopLast();

private:
	int count;

	struct Node {
		T info;
		Node* next;
		Node* prev;
	};

	Node* first;
	Node* last;

};


template<class T>
void Queue<T>::Print() {
	if (IsEmpty()) {
		cout << "Queue is empty" << endl;
	}
	else {
		Node* tempNode;
		tempNode = first;
		T tempData;
		tempData = tempNode->info;

		if (first == last) {
			cout << tempData << endl;
		}
		else {
			/*for (int i = 1; i < count; i++) {
				cout << tempData << endl;
				tempNode = tempNode->next;
				tempData = tempNode->info;
			}*/

			do {
				cout << tempNode->info << endl;
				tempNode = tempNode->next;
				//tempData = tempNode->info;
			} while (tempNode != nullptr);
		}


	}


}

template<class T>
bool Queue<T>::IsEmpty() {
	return(count == 0);
}

template<class T>
void Queue<T>::Push(T data) {
	Node* newNode = new Node;
	newNode->info = data;
	newNode->next = NULL;

	if (IsEmpty()) {
		first = newNode;
	}
	else {
		last->next = newNode;
		newNode->prev = last;
	}
	last = newNode;
	count++;
}

template<class T>
void Queue<T>::PushFirst(T data) {
	Node* newNode = new Node;
	newNode->info = data;
	newNode->next = NULL;

	if (IsEmpty()) {
		first = newNode;
	}
	else {
		newNode->next = first;
		first->prev = newNode;
	}
	first = newNode;
	count++;
}

template<class T>
void Queue<T>::Pop() {
	if (IsEmpty()) {
		cout << "The Queue is empty" << endl;
	}
	else {
		Node* tempNode = first;
		if (first == last) {
			first = NULL;
			last = NULL;
		}
		else {
			first = first->next;
			/*Node* newFirst = first->next;
			newFirst->prev = NULL;*/
			first->prev = NULL;
		}
		delete tempNode;
		count--;
	}
}

template<class T>
void Queue<T>::PopLast() {
	if (IsEmpty()) {
		cout << "The Queue is empty" << endl;
	}
	else {
		Node* tempNode = last;
		if (first == last) {
			first = NULL;
			last = NULL;
		}
		else {
			last = last->prev;
			last->next = NULL;
		}
		delete tempNode;
		count--;
	}
}