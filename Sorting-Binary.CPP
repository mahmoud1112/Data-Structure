#include <iostream>
using namespace std;

//========== sort ===============
// 5,2,7,3,9,10,8,1,6,4

/*
Bubble sort - all cases (o(n^2)):
// comparing between 2 no and swap
// 2,5,3,7,9,8,10,6,4,1 => after first loop
// 2,3,5,7,8,1,6,4,9,10 => after second loop
// ....
// 1,2,3,4,5,6,7,8,9,10 => after loop no 10
*/

/* selection sort - all cases (o(n^2)): 
 looping on all array elements and order them*/

/*
Insertion sort :
-best case O(n) if array is ordered
-worst case o(n^2) if array is not ordered

// 2,5,

*/

/* merg sort - all cases (o(n*logn)):
divid and conquer concept*/

//============================================

/*
void bubbleSort(int* arr, int size) {

	for (int i = 0; i < size - 1; i++) {
		for (int j = 0; j < size - 1; j++) {
			if (arr[j] > arr[j+1]) {
				int temp = arr[j + 1];
				arr[j + 1] = arr[j];
				arr[j] = temp;
			}
		}
	}
}

void insertionSort(int* arr, int size) {

	for (int i = 0; i < size - 1; i++) {
		for (int j = i; j >= 0 && arr[j] > arr[j + 1]; j--) {
			int temp = arr[j + 1];
			arr[j + 1] = arr[j];
			arr[j] = temp;
		}
	}
}

int main() {
	
	int arr[] = { 5,2,7,3,9,10,8,1,6,4 };
	for (int i = 0; i < 10; i++) {
		cout << arr[i] << " ";
	}
	cout << "\n====================\n";

	//bubbleSort(arr, 10);
	//insertionSort(arr, 10);
	for (int i = 0; i < 10; i++) {
		cout << arr[i] << " ";
	}
}
*/

================ Merge Sort =====================
void mergeSort(int arr[], int left, int right, int mid) {
	//div olog(n)
	int leftSize = mid - left + 1;
	int rightSize = right - mid;

	int* leftArr = new int[leftSize];
	int* rightArr = new int[rightSize];

	for (int i = 0; i < leftSize; i++) {
		leftArr [i]= arr[left + i];
	}

	for (int i = 0; i < rightSize; i++) {
		rightArr[i] = arr[mid + 1 + i];
	}

	//merge o(n)
	int i = 0,
		j = 0,
		k = left;

	while (i < leftSize && j < rightSize) {
		if (leftArr[i] < rightArr[j]) {
			arr[k] = leftArr[i];
			i++;
			k++;
		}
		else {
			arr[k] = rightArr[j];
			j++;
			k++;
		}
	}

	while (i < leftSize) {
		arr[k] = leftArr[i];
		i++;
		k++;
	}
	while (j < rightSize) {
		arr[k] = rightArr[j];
		j++;
		k++;
	}
}

void mergeSortAlgo(int arr[], int left, int right) {
	if (left >= right)return;

	int mid = left + (right - left) / 2;
	mergeSortAlgo(arr, left, mid);
	mergeSortAlgo(arr, mid+1, right);
	mergeSort(arr, left, right, mid);
}

int main()
{
    	int arr[] = { 7 ,5 ,2 ,1 ,4 ,8 ,10  ,9 ,3 ,6 };

	cout << "Array Before Sorting:\n";
	for (int i = 0; i < 10; i++) {
		cout << arr[i] << " ";
	}
	cout << "\n============\n";

	mergeSortAlgo(arr, 0, 9);

	cout << "Array After Sorting:\n";
	for (int i = 0; i < 10; i++) {
		cout << arr[i] << " ";
	}
	cout << "\n============\n";
}

//======= Binary Search ===========

// Array Must be sorted :
// index : 0 1 2 3 4 5  6  7  8  9
// Array : 2,3,5,7,8,10,12,14,15,20

//to get 12
/*
start = 0 , end = size-1 =10-1=9
mid = (end+start)/2 = 4
arr[mid](8)<value => go right

start = mid + 1 = 4+1 =5
mid = (9+5)/2 = 7
arr[mid](14)>value => go left

end = mid - 1 = 7-1 = 6
mid = (6 + 5)/2 = 5
arr[mid](10)<value => go right

start = mid + 1 = 5+1 = 6
arr[mid] = value ok and start = end

search time O(n)
*/

/*
bool bSearch(int* arr, int size, int value) {
	int start = 0;
	int end = size - 1;

	while (start <= end) {
		int mid = (end + start) / 2;
		if (value == arr[mid]) {
			return true;
		}
		if (value > arr[mid]) {
			start = mid + 1;
		}
		else if (value < arr[mid]) {
			end = mid - 1;
		}
	}
	return false;
}

int main() {

	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };

	if (bSearch(arr, 10, 5))
		cout << "Found\n";
	else
		cout << "Not Found\n";
}
*/

//========== Dynamic Programming =============
// fib:
// 1 1 2 3 5 8 13 21 34 55
// 1 2 3 4 5 6 7  8  9  10
// Dp: 
/*
	if(value != empty ) return value;
	else calculate value => and save;
	store in a structure (vector, map,...)

	EX : n = 6
	( 1,  1, -1, -1, -1, -1)
	  1   2   3   4   5   6

Calc fib(3) and fib(4)
	( 1,  1,  2,  3, -1, -1)
	  1   2   3   4   5   6

Calc fib(5) and fib (6) 
Without calc fib(3) and fib(4) again:
	( 1,  1,  2,  3,  5,  8)
	  1   2   3   4   5   6
*/

/*
int fibOrdinary(int n) {
	if (n == 1 || n == 2)
		return 1;
	else
		return fibOrdinary(n - 1) + fibOrdinary(n - 2);
}

int fibDynamic(int n, int* arr) {
	if (arr[n] != -1) return arr[n];
	arr[n] = fibDynamic(n - 1, arr) + fibDynamic(n - 2, arr);
	return arr[n];
}

int main() {
	int n = 40;
	//cout << fibOrdinary(n);

	int* arr = new int[n];
	arr[1] = arr[2] = 1;
	for (int i = 3; i <= n; i++) {
		arr[i] = -1;
	}
	cout << fibDynamic(n,arr)<<endl;
}
*/


============== Single tone by C++ ===============

//========= DP : Single Tone ================

//======== Setting.ccp file =============

#include "Setting.h"
Setting* Setting::mySetting = nullptr;


//============== Setting.h file ==========

class Setting {
private:
	// private constractor
	Setting() {

	}
	// private static object
	static Setting* mySetting;

	int value = 10;
	bool darkMood = false;

public:

	// public get instance method
	static Setting* getSetting() {

		if (mySetting == nullptr) {
			mySetting = new Setting;
		}
		return mySetting;
	}

	void setValue(int value) {
		this->value = value;
	}
	void setDarkMood(bool darkMode) {
		this->darkMood = darkMood;
	}
	int getValue() {
		return this->value;
	}
	bool getDarkMood() {
		return this->darkMood;
	}
};

======= main file ==============

int main() {
	Setting* s1 = Setting::getSetting();
	s1->setValue(22);
	s1->setDarkMood(true);

	Setting* s2 = Setting::getSetting();
	s2->setValue(500);
	s2->setDarkMood(false);

	cout << s1->getValue() << endl;
	cout << s1->getDarkMood() << endl;

	cout << s2->getValue() << endl;
	cout << s2->getDarkMood() << endl;
}

================= single tone by Java ==============

package dp;

public class Settings {
    private int value = 10;
    private boolean darkMood = false;

    //before ST
    /*
    public Settings() {
    }
    */
    
    //After ST
    
    private static Settings mySettings;
    
    private Settings() {
    }   
    
    public static Settings getSettings(){
        if(mySettings == null){
            mySettings = new Settings();
        }
        return mySettings;
    }
    
    public void setValue(int value) {
        this.value = value;
    }

    public void setDarkMood(boolean darkMood) {
        this.darkMood = darkMood;
    }

    public int getValue() {
        return value;
    }

    public boolean isDarkMood() {
        return darkMood;
    }
    
}

package dp;
public class DP {

    
    public static void main(String[] args) {
        
        
        //main before ST:
        /*
        Settings s1 = new Settings();
        s1.setValue(25);
        System.out.println(s1.getValue());
        
        Settings s2 = new Settings();
        s2.setValue(11);
        System.out.println(s2.getValue());
        */
        
        //main after ST:
        
        Settings s1 = Settings.getSettings();
        s1.setValue(1000);
        
        
        Settings s2 = Settings.getSettings();
        s2.setValue(555);
        
        System.out.println(s1.getValue());
        System.out.println(s2.getValue());
    }
    
}

//================ SOLID ======================
//========== Single resposiblity ======

/*
int power(int x, int y) {
	int res = 1;
	for (int i = 1; i <= y; i++) {
		res *= x;
	}
	cout << x << " ^ " << y << " = ";
	return res;
}

int multiply(int x, int y) {
	cout << x << " * " << y << " = ";
	return x * y;
}

int moduls(int x, int y) {
	cout << x << " % " << y << " = ";
	return x % y;
}

int calc(int x, char c, int y) {
	if (c == '^') {
		power(x, y);
	}
	else if (c == '*') {
		multiply(x, y);
	}
	else if (c == '%') {
		moduls(x, y);
	}
}

int test(int x, int y) {
	//some code, then calling power function
	power(x, y);
}

int main() {
	cout << calc(100, '^', 2) << endl;
	cout << calc(100, '*', 2) << endl;
	cout << calc(100, '%', 2) << endl;
}
*/

//========== Open Close ===========

/*
int power(int x, int y) {
	int res = 1;
	for (int i = 1; i <= y; i++) {
		res *= x;
	}
	cout << x << " ^ " << y << " = ";
	return res;
}

int power(int x, int y, int z) {
	int p = power(x, y);
	int res = power(p, z);
	return res;
}

int calc(int x, char c, int y) {
	if (c == '^') {
		power(x, y);
	}
	// .
	// .
	// .
	// .
}

int test(int x, int y,int z) {
	//some code, then calling power function
	power(x, y, z);
}

//=======

class Client {

	//Client code

};

class VIPClient : public Client{

	//Client code

	//+ VIP features

};
*/

//========== Liskov substitution ===========

/*
class Parent{
public:
	void print() {

		// Parent code print
	}
	void move() {

		// Parent code print
	}
};

class Child : public Parent{
public:
	void print() {

		// child code print
	}
	void move() {

		// child code print
	}
};

int main() {
	Parent p;
	p.print();
	p.move();
}
*/

//========== Interface segregation ===========

/*
class Parent1 {
public:
	virtual void print() = 0;
};

class Parent2 {
public:
	virtual void moveRight() = 0;
};

class Parent3 {
public:
	virtual void moveLeft() = 0;
};

class Parent4 {
public:
	virtual void talk() = 0;
};

class Child : public Parent1, Parent2, Parent3 {
public:
	void print() {
		cout << " Child " << endl;
	}
	void moveRight() {
		cout << "Child Moving right" << endl;
	}
	void moveLeft() {
		cout << "Child Moving Left" << endl;
	}
};

int main() {
	Child c;
	c.print();
}
*/

//========== Dependency inversion ===========

/*
class Player {
	string name;
	char op;
};

class BoardInterface {
	virtual void draw() = 0;
	virtual bool is_win(Player p) = 0;
};

class Board3X3 : public BoardInterface {
public:
	void draw() {
		/*
		* 
		1 | 2 | 3
		---------
		4 | 5 | 6
		---------
		7 | 8 | 9

		*/
//	}
//
//	bool is_win(Player p) {
//		// 8 cases to win
//	}
//};
//
//class Board4X4 : public BoardInterface {
//public:
//	void draw() {
//		/*
//		
//		1  | 2  | 3  | 4
//		-----------------
//		5  | 6  | 7  | 8
//		-----------------
//		9  | 10 | 11 | 12
//		-----------------
//		13 | 14 | 15 | 16
//
//		*/
//	}
//
//	bool is_win(Player p) {
//		// 10 cases to win
//	}
//};
//
//
//class GameXO {
//public:
//	Player p1;
//	Player p2;
//	Board3X3 myBoard;
//
//	void play() {
//		myBoard.draw();
//		myBoard.is_win(p1);
//	}
//};
//*/
