#include <iostream>
#include <stack>
#include <queue>
#include <iterator> 
#include <map>
#include <set>
using namespace std;

//==== Stack LIFO (Last In First Out) ====

//function to print stack
/*
void showstack(stack <int> s)
{
	while (!s.empty())
	{
		cout << '\t' << s.top();
		s.pop();
	}
	cout << '\n';
}

int main()
{
	stack <int> s;
	s.push(10);
	s.push(20);
	s.push(30);
	s.push(40);
	s.push(50);
	s.push(60);
	s.emplace(70);  //same as push 

	cout << "The stack s : ";
	showstack(s);

	//show size
	cout << "\ns.size() : " << s.size();

	// get stack top
	cout << "\ns.top() : " << s.top();

	//delete stack top
	cout << "\ns.pop() : ";
	s.pop();
	showstack(s);
	//show size
	cout << "\ns.size() : " << s.size();

	//swap stack in another stack
	stack<int> k;
	k.push(1000);
	k.push(2000);
	k.push(3000);

	cout << "\nk.size() : " << k.size() << endl << endl;
	//swaping
	s.swap(k);

	cout << "After Swaping : "<<endl;
	cout << "The stack s : ";
	showstack(s);
	cout << "The stack k : ";
	showstack(k);

	cout << "\ns.size() : " << s.size() ;
	cout << "\nk.size() : " << k.size() << endl;
	return 0;
}
*/


//==== Queue FIFO(First In First Out) ===========


//function to print queue
/*
void showqueue(queue<int> q)
{
	while (!q.empty()) {
		cout << '\t' << q.front();
		q.pop();
	}
	cout << '\n';
}

int main()
{
	queue<int> q;
	q.push(10);
	q.push(20);
	q.push(30);
	q.push(40);
	q.push(50);
	q.emplace(60);  //same as push
	cout << "The queue q is : ";
	showqueue(q);

	//show size
	cout << "\nq.size() : " << q.size();

	// get queue front
	cout << "\nq.front() : " << q.front();

	// get queue back
	cout << "\nq.back() : " << q.back();

	//delete queue front
	cout << "\nq.pop() : ";
	q.pop();
	showqueue(q);

	//show size
	cout << "\nq.size() : " << q.size();

	//swap stack in another stack
	queue<int> u;
	u.push(1000);
	u.push(2000);
	u.push(3000);

	cout << "\nu.size() : " << u.size() << endl << endl;
	//swaping
	q.swap(u);

	cout << "After Swaping : " << endl;
	cout << "The queue q : ";
	showqueue(q);
	cout << "The queue u : ";
	showqueue(u);

	cout << "\nq.size() : " << q.size();
	cout << "\nu.size() : " << u.size() << endl;

	return 0;
}
*/


// ================= Tree, BST ===================


/*
class Node
{
public:
	int value;
	Node* left;
	Node* right;
	Node()
	{
		value = 0;
		left = right = NULL;
	}
	Node(int val, Node* l, Node* r)
	{
		value = val;
		left = l;
		right = r;
	}
};


class BST
{
	Node* root;
public:

	BST()
	{
		root = NULL;
	}

	void addValue(int value)
	{
		if (search(value))return;
		Node* n = new Node(value, NULL, NULL);
		if (root == NULL)
		{
			root = n;
			return;
		}
		Node* p = root;

		//getting last node

		while (true)
		{//p stands at the root
			if (value > p->value)
			{
				if (p->right == NULL)break;
				p = p->right;
			}
			else
			{
				if (p->left == NULL)break;
				p = p->left;
			}
		}
		//p stands at the last node 
		if (value > p->value)
		{
			p->right = n;
		}
		else
		{
			p->left = n;
		}
	}

	bool search(int value)
	{
		Node* p = root;
		while (p != NULL)
		{
			if (p->value == value)return true;
			if (value > p->value)
				p = p->right;
			else
				p = p->left;
		}
		return false;
	}

	void DFS(Node* n)   //to visit all tree elements from leafs
	{
		if (n == NULL)return;

		//print sub left tree
		DFS(n->left);

		//print root
		cout << n->value << " -> ";

		//print sub right tree
		DFS(n->right);
	}

	void print()
	{
		DFS(root);
	}

	void BFS()		    //to visit all tree elements from root
	{
		queue <Node*> myQueue;
		myQueue.push(root);
		while (myQueue.empty() == false){
			cout << myQueue.front()->value << endl;
			if (myQueue.front()->left != NULL){
				myQueue.push(myQueue.front()->left);
			}
			if (myQueue.front()->right != NULL){
				myQueue.push(myQueue.front()->right);
			}
			myQueue.pop();
		}
	}

	void deleteBST(int value)
	{
		Node* p = root;
		Node* parent = NULL;

		//to get the wanted value
		while (p != NULL) {
			if (p->value == value)break;
			parent = p;
			if (value > p->value)
				p = p->right;
			else
				p = p->left;
		}
		//case 1 : the node is not exesting to be deleted
		if (p == NULL)return;

		//case 2 : a node with no children
		if (p->left == NULL && p->right == NULL) {
			//to know if it is on the right or left from parent
			if (p->value > parent->value) {
				parent->right = NULL;
			}
			else {
				parent->left = NULL;
			}
			delete p;
			return;
		}

		// case 3 : a node with no left child
		if (p->left == NULL) {
			if (p->value > parent->value) {
				parent->right = p->right;
			}
			else {
				parent->left = p->right;
			}
			delete p;
			return;
		}

		// case 4 : a node with no right child
		if (p->right == NULL) {
			if (p->value > parent->value) {
				parent->right = p->left;
			}
			else {
				parent->left = p->left;
			}
			delete p;
			return;
		}

		//case 5 : the node is the root it's self or
		//case 6 : a node with two children

		//to get the nearest value of the deleted point
		//we will get the smalest one one it's right

		if (p->right != NULL && p->left != NULL) {
			Node* p1 = p->right;

			//getting smallest value on right
			if (p1->left == NULL) {
				parent = p1;
				p->value = p1->value;
				p->right = parent->right;
				delete p1;
			}
			else {
				while (p1->left != NULL) {
					parent = p1;
					p1 = p1->left;
				}
				p->value = p1->value;
				parent->left = nullptr;
				delete p1;

			}
		}

	}
};


int main()
{
	BST myTree;
	myTree.addValue(50);
	myTree.addValue(40);
	myTree.addValue(45);
	myTree.addValue(47);
	myTree.addValue(43);
	myTree.addValue(30);
	myTree.addValue(42);
	myTree.addValue(41);
	myTree.addValue(55);
	myTree.addValue(60);
	myTree.addValue(57);
	myTree.addValue(66);


	myTree.print();
	cout << "\n\n";

	//Delete Cases:

	//case 1: not exist
	//myTree.deleteBST(100);

	//case 2: no child
	//myTree.deleteBST(30);

	//case 3: no left child
	//myTree.deleteBST(45);

	//case 4: no right child
	//myTree.deleteBST(60);

	//case 5: the root
	//myTree.deleteBST(50);

	//case 6: with 2 childeren
	//myTree.deleteBST(40);


	myTree.print();
	cout << "\n\n";
	return 0;
}
*/

//================= Set ========================

/*
void showSet(set<int> mySet) {

	set<int>::iterator it;

	cout << "The set is: \n";
	for (it = mySet.begin(); it != mySet.end(); it++) {
		cout << *it << " ";
	}
	cout << endl << endl;

}
int main()
{
	set<int> mySet;
	mySet.insert(10);
	mySet.insert(20);
	mySet.insert(30);
	mySet.insert(40);
	mySet.insert(50);
	mySet.insert(60);
//  only one 20 will be added to the set
	mySet.insert(20);

	//printing set
	showSet(mySet);

	// remove element with value 50 
	mySet.erase(50);
	showSet(mySet);

	// remove all elements less than 30 in s2
	mySet.erase(mySet.begin(), mySet.find(30));
	showSet(mySet);

	// assigning the elements from s1 to s2
	set<int> s2(mySet.begin(), mySet.end());
	showSet(s2);

}
*/


//==================== MAP =================
/*
void showMap(map<int, string> myMap) {

	map<int, string>::iterator itr;

	cout << "\nThe map is : \n";
	cout << "\tKEY\tELEMENT\n";

	for (itr = myMap.begin(); itr != myMap.end(); ++itr) {
		cout << '\t' << itr->first
			<< '\t' << itr->second << '\n';
	}
	cout << endl;
}

int main()
{
	map<int, string> myMap;

	myMap.insert(pair<int, string>(1, "ahmed"));
	myMap.insert(pair<int, string>(2, "abdo"));
	myMap.insert(pair<int, string>(3, "mohamed"));
	myMap.insert(pair<int, string>(4, "sara"));
	myMap.insert(pair<int, string>(5, "amr"));
	myMap.insert(pair<int, string>(6, "mai"));
	myMap.insert(pair<int, string>(7, "ibrahim"));
	myMap[8] = "sayed";

	// printing map myMap
	showMap(myMap);

	// remove all elements less than key=3 
	myMap.erase(4);
	showMap(myMap);

	// remove element key=4 
	myMap.erase(myMap.begin(), myMap.find(3));
	showMap(myMap);

	// assigning the elements from myMap to m2 
	map<int, string> m2(myMap.begin(), myMap.end());

	// printing map m2
	showMap(m2);

}
*/



//===================== Big O Notation =======================

/*
/*
// Ex : O(1)

int main() {
	int x;                 //1
	cin >> x;              //1
	int sum = (x * x/2);   //1
	cout << sum << endl;   //1
}

// time = 1+1+1+1 = 4 = O(1)
*/

//================
// Ex : O(n)
/*
int main() {
	int n;       //1
	cin >> n;    //1         
//             1      n      n
	for (int i = 1; i <= n; i++) {
		cout << i << endl; //n
	}
}

// time = 1+1+1+n+n+n = 3 + 3n = O(n)
// best senario (n = 1) , time = 6
// it gets worse when n increase
*/

//================
// Ex : O(n^power)
/*
int main() {
	int n;       //1
	cin >> n;    //1
//             1       n      n
	for (int i = 0 ; i < n ; i++) {
//                n		 n*n   n*n        
		for (int j = 1; j < n; j++) {
			cout << n << endl;  //n*n
		}
	}
}

// time = 1+1+1+n+n+n+n^2+n^2+n^2 = 
//      = 3 + 3n + 3n^2 = O(n^2)
*/

//================
// Ex : O(logn)
/*
int main() {
	int n;       //1
	cin >> n;    //1
//           n/2    n/2
	for ( ; n > 0 ; n/=2) {
		cout << n << endl; //n/2
	}
}

// time = 1+1+n/2+n/2+n/2 = 2 + 1.5n = O(logn)
*/


// ============= Binary Search O(logn) ================

/*
bool bSearch(int* arr, int size, int value) {
	int start = 0;
	int end = size - 1;
	while (start <= end) {
		int mid = (end + start) / 2;
		if (value == arr[mid]) return true;
		if (value > arr[mid]) {
			start = mid + 1;
		}
		else {
			end = mid - 1;
		}
	}
	return false;
}

int main() {
	int arr[5] = { 10,20,30,40,50 };
	cout << bSearch(arr, 5, 90) << endl;
}
*/







































// ======= Stack, Queue Implementation =======

/*
class DNode
{
public:
	int value;
	DNode* next;
	DNode* prev;
	DNode()
	{
		value = 0;
		next = prev = NULL;
	}

	DNode(int val, DNode* p, DNode* n)
	{
		value = val;
		next = n;
		prev = p;
	}
};


class MyStack
{
	DNode* head;
	DNode* tail;
	int size;
public:
	MyStack()
	{
		head = tail = NULL;
		size = 0;
	}
	void push(int val)
	{
		DNode* n = new DNode(val, NULL, NULL);
		if (head == NULL)
		{
			head = tail = n;
			return;
		}

		tail->next = n;
		n->prev = tail;
		tail = n;
		size++;
	}
	void pop()
	{
		if (head == NULL)return;
		DNode* temp = tail->prev;
		delete tail;
		tail = temp;
		tail->next = NULL;
		size--;
	}
	int top()
	{
		return tail->value;
	}
	bool isEmpty()
	{
		if (head == NULL || tail == NULL)return true;
		return false;
	}
	int getSize()
	{
		return size;
	}
};

class MyQueue
{
	DNode* head;
	DNode* tail;
	int size;
public:
	MyQueue()
	{
		head = tail = NULL;
		size = 0;
	}
	void push(int val)
	{
		DNode* n = new DNode(val, NULL, NULL);
		if (head == NULL)
		{
			head = tail = n;
			return;
		}
		tail->next = n;
		n->prev = tail;
		tail = n;
		size++;
	}
	void pop()
	{
		if (head == NULL)return;
		if (head->next == NULL)
		{
			delete head;
			head = tail = NULL;
		}

		DNode* temp = head->next;
		delete head;
		head = temp;
		head->prev = NULL;
		size--;
	}
	int front()
	{
		return head->value;
	}
	bool isEmpty()
	{
		if (head == NULL || tail == NULL)return true;
		return false;
	}
	int getSize()
	{
		return size;
	}
};

// Queue FIFO        push,pop,Front,isEmpty,size
// Stack FILO	     push,pop,Top  ,isEmpty,size


int main()

{
	//	
	//	MyQueue myQueue;
	//	myQueue.push(10);
	//	myQueue.push(20);
	//	myQueue.push(30);
	//	myQueue.push(40);
	//	myQueue.push(50);
	//	myQueue.push(60);
	//	while(myQueue.isEmpty()==false)
	//	{
	//		cout<<myQueue.front()<<endl;
	//		myQueue.pop();
	//	}
	//	



	//
	//MyStack myStack;
	//myStack.push(10);
	//myStack.push(20);
	//myStack.push(30);
	//myStack.push(40);
	//myStack.push(50);
	//myStack.push(60);
	//while (myStack.isEmpty() == false)
	//{
	//	cout << myStack.top() << endl;
	//	myStack.pop();
	//}
	//

}
*/













