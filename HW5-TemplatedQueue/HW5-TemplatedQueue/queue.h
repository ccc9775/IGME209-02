#pragma once
using namespace std;

template<class T>
class Queue
{
public:
	//default constructor of the queue
	Queue() {
		first = nullptr;
		count = 0;
	}
	//copy constructor
	/*Queue(const Queue& other) : data(new char[std::strlen(other.data) + 1]) {
		std::strcpy(data, other.data);
	}*/
	//operator constructor
	Queue& operator=(const Queue& other) {
		if (this != &other) {
			std::strcpy(data, other.data);
		}
		return *this;
	}
	//destructor
	~Queue() {
		while (!IsEmpty()) {
			Pop();
		}
	}
	//basic functions of the queue
	void Print();
	bool IsEmpty();
	void Push(T data);
	void PushFirst(T data);
	void Pop();
	void PopLast();

private:
	int count;

	//struct to make creating links between the queue easier
	struct Node {
		T info;
		Node* next;
		Node* prev;
	};

	Node* first;
	Node* last;

};


//prints all of the pieces of data within the queue to the console
template<class T>
void Queue<T>::Print() {
	if (IsEmpty()) {
		cout << "Queue is empty" << endl;
	}
	//if the queue isn't empty, loop through all elements and print their info to the console
	else {
		Node* tempNode;
		tempNode = first;

		if (first == last) {
			cout << tempNode->info << endl;
		}
		else {

			do {
				cout << tempNode->info << endl;
				tempNode = tempNode->next;
			} while (tempNode != nullptr);
		}


	}


}

//checks to see if the queue is empty
template<class T>
bool Queue<T>::IsEmpty() {
	return(count == 0);
}

//pushes the new data to the queue
template<class T>
void Queue<T>::Push(T data) {
	Node* newNode = new Node;
	newNode->info = data;
	newNode->next = NULL;

	if (IsEmpty()) {
		first = newNode;
	}
	//if the queue isn't empty, set the last node to the new data, and set the previous to the old last node
	else {
		last->next = newNode;
		newNode->prev = last;
	}
	//set the new node to last and increase the queue count
	last = newNode;
	count++;
}

//works the same as the Push function, but pushes to the first node, not te last node
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

//pops the first element of the queue out of the queue
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
		//if the queue isn't empty and the first node isn't the last node, set the first node to the next node, and set the previous node to null 
		else {
			first = first->next;

			first->prev = NULL;
		}
		//delete the old first node, and decrease the count of the queue
		delete tempNode;
		count--;
	}
}

//same as the Pop function, but removes from the last node not the first node
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