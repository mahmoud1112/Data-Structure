#include <iostream>
#include <vector>
#include <list>
#include <iterator>
using namespace std;


//============ Array List =============


/*
template<class T>
class ArrayList{
private:
	T* arr;
	int cap;
	int numOfItem;

	void expand(){
		cap *= 2;
		T* temp = new T[cap];
		for (int i = 0; i < numOfItem; i++){
			temp[i] = arr[i];
		}
		delete arr;
		arr = temp;
	}

public:
	ArrayList(){
		cap = 2;
		numOfItem = 0;
		arr = new T[cap];
	}

	~ArrayList(){
		delete arr;
	}

	void addToLast(T value){
		if (numOfItem == cap){
			expand();
		}
		arr[numOfItem] = value;
		numOfItem++;
	}

	void removeFromLast(){
		numOfItem--;
	}

	void addToFirst(T value){
		if (numOfItem == cap){
			expand();
		}

		for (int i = numOfItem - 1; i >= 0; i--){
			arr[i + 1] = arr[i];
		}

		arr[0] = value;
		numOfItem++;
	}

	void removeFromFirst(){
		for (int i = 0; i < numOfItem - 1; i++){
			arr[i] = arr[i + 1];
		}
		numOfItem--;
	}

	bool search(T value){
		for (int i = 0; i < numOfItem; i++){
			if (arr[i] == value){
				return true;
			}
		}
		return false;
	}

	void print(){
		for (int i = 0; i < numOfItem; i++){
			cout << arr[i] << " ";
		}
		cout << endl;

	}
	void setCap(int cap){
		this->cap = cap;
	}

};


int main() {
	ArrayList <int> l;
	for (int i = 1; i <= 5; i++) {
		l.addToLast(i);
	}

	l.addToFirst(100);
	l.print();
	cout << l.search(5)<<endl;
	l.removeFromLast();
	l.print();
	cout<<l.search(5)<<endl;
}
*/

//=============== Vectors ================
/*
int main() {
	vector<int> v;

	//filling vector
	for (int i = 1; i <= 10; i++) {
		v.push_back(i);
	}

	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}
	cout << endl;

	// removes the last element
	v.pop_back();
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}
	cout << endl;

	// inserts 100 at the beginning
	v.insert(v.begin(), 100);
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}
	cout << endl;

	// removes the first element
	v.erase(v.begin());
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}
	cout << endl;

	// Delete all the vector items
	v.clear();
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}
	cout << endl;
	cout << "\nVector size after erase(): " << v.size() <<endl;

	//check empty
	if (v.empty() == true)
		cout << "v is empty\n";
	else
		cout << "v is not empty\n";

	// fill the array with 10 five times
	v.assign(5, 10);
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}
	cout << endl;

	//check empty
	if (v.empty() == true)
		cout << "v is empty\n";
	else
		cout << "v is not empty\n";
}
*/

//========== Single Linked list ==========
/*
class Node{
public:
	int value;
	Node* next;
	Node(){
		value = 0;
		next = NULL;
	}
	Node(int val, Node* p){
		value = val;
		next = p;
	}
};

class LinkedList{
	Node* head;

public:
	LinkedList(){
		head = NULL;
	}

	void addToFirst(int value){
		Node* n = new Node();
		n->value = value;
		n->next = head;
		head = n;
	}

	void removeFromFirst(){
		if (head == NULL)return;

		head = head->next;
	}

	void addToLast(int value){
		if (head == NULL){
			addToFirst(value);
			return;
		}

		Node* n = new Node;
		n->value = value;
		n->next = nullptr;

		Node* p = head;
		while (p->next != NULL){
			p = p->next;
		}
		p->next = n;
	}

	void removeFromLast(){
		if (head == NULL) return;
		if (head->next == NULL){
			delete head;
			head = NULL;
			return;
		}

		Node* p = head;
		Node* parent = head;
		while (p->next != NULL){
			parent = p;
			p = p->next;
		}
		delete p;
		parent->next = NULL;
	}

	void print(){
		Node* p = head;
		while (p != NULL){
			cout << p->value << "->";
			p = p->next;
		}
		cout << "NULL" << endl;
	}
};

int main(){
	LinkedList myList;

	myList.addToFirst(5);
	myList.addToFirst(15);
	myList.addToFirst(50);
	myList.addToFirst(3);
	myList.print();
	myList.removeFromLast();
	myList.print();
	return 0;
}
*/

//=============== List ================

//function for printing list :

/*
void showList(list <int> l) {
	list <int> ::iterator it;
	for (it = l.begin(); it != l.end(); ++it)
		cout << *it << " ";
	cout << endl;
}

int main() {
	list<int> myList;

	//filling list
	for (int i = 1; i <= 10; i++) {
		myList.push_back(i);
	}

	//add to first
	myList.push_front(50);
	myList.push_front(-50);
	myList.push_front(-500);

	//printing list
	showList(myList);

	//print first and last element
	cout << "First item: " << myList.front() << endl;
	cout << "Last item: " << myList.back() << endl;

	//delete first and last element
	myList.pop_front();
	myList.pop_back();
	cout << "After Delete: ";
	showList(myList);

	//reverse list
	myList.reverse();
	cout << "After Reversing: ";
	showList(myList);

	//sorting list
	myList.sort();
	cout << "After Sorting: ";
	showList(myList);

	cout<<myList.size();
}
*/

// ============ Recursion =============

/*
int sum(int n) {
	if (n < 10)
		return n;
	return n % 10 + sum(n / 10);
}

int fact(int n) {
	if (n == 0 || n == 1)
		return 1;
	return n * fact(n - 1);
}

int main() {
	int x = 12356;
	cout << sum(x) << endl;
	int y = 5;
	cout << fact(y) << endl;
}
*/

// ========== fibonacci Function ======

/*
int fib(int n)
{
	if (n == 0)
		return 0;
	if (n == 1 || n == 2)
		return 1;
	// Recursion function
	else
		return (fib(n - 1) + fib(n - 2));
}
int main()
{
	int n = 10;
	cout << "Fibonacci series of "<< n <<" numbers is: ";

	for (int i = 0; i < n; i++)
	{
		cout << fib(i) << " ";
	}
	return 0;
}
*/
