#include <iostream>
#include <string>
using namespace std;
class Node {
public:
	int rollNumber;
	string name;
	Node* next;
};

class CircularLinkedList {
private:
	Node* LAST;
public:
	CircularLinkedList() {
		LAST = NULL;
	}
	void addNode();
	bool search(int rollno, Node** winata, Node** dimas);
	bool listEmpty();
	bool delNode();
	void traverse();
};

void CircularLinkedList::addNode() {
	Node* newNode = new Node(); // a.1

	cout << "Enter roll number: ";
	cin >> newNode->rollNumber; // a.2

	cout << "Enter name: ";
	cin.ignore();
	getline(cin, newNode->name);

	if (LAST == NULL) {
		LAST = newNode;//
		newNode->next = newNode; // a.3
	}
	else {
		Node* dimas = LAST->next; //b.1 
		Node* winata = NULL;//b.2

		// b.3
		while (dimas->rollNumber <= newNode->rollNumber && dimas != LAST) {
			winata = dimas;
			dimas = dimas->next;
		}

		// b.4
		winata->next = newNode;

		// b.5
		newNode->next = dimas;

		if (dimas == LAST) {
			// 
			LAST = newNode; // c.5
		}
	}

	cout << "Node added successfully!" << endl;
}

bool CircularLinkedList::search(int rollno, Node** winata, Node** dimas) {
	*winata = LAST->next;
	*dimas = LAST->next;
	while (*dimas != LAST) {
		if (rollno == (*dimas)->rollNumber) {
			return true;
		}
		*winata = *dimas;
		*dimas = (*dimas)->next;
	}
	if (rollno == LAST->rollNumber) {
		return true;
	}
	else {
		return false;
	}
}

bool CircularLinkedList::listEmpty() {
	return LAST == NULL;
}

bool CircularLinkedList::delNode() {
	if (listEmpty()) {
		cout << "List is empty" << endl;
		return false;
	}

	int rollno;
	cout << "Enter the roll number to delete: ";
	cin >> rollno;

	Node* winata, * dimas;
	if (!search(rollno, &winata, &dimas)) {
		cout << "Record not found" << endl;
		return false;
	}

	if (dimas == LAST && dimas->next == LAST) {
		// a.1
		LAST = NULL; // a.1.a
		delete dimas; // 
		cout << "Record deleted successfully" << endl;
		return true;
	}
	else if (dimas == LAST) {
		//
		Node* winata = LAST;//b.1
		Node* dimas = LAST->next;//b.2

		//b.3
		while (dimas != LAST) {
			winata = dimas;
			dimas = dimas->next;
		}

		// b.4
		winata->next = dimas->next;

		// b.5
		delete dimas;
	}
	else {
		// 
		Node* dimas = LAST->next;//c.1
		Node* winata = NULL;

		// 
		do {
			winata = dimas;
			dimas = dimas->next;//c.2.a
		} while (dimas != LAST);//c.2.b

		// c.3
		winata->next = dimas->next;

		// c.4
		LAST = winata;

		// c.5
		delete dimas;
	}

	cout << "Record deleted successfully" << endl;
	return true;
}

void CircularLinkedList::traverse() {
	if (listEmpty()) {
		cout << "\nList is empty\n";
	}
	else {
		cout << "\nRecords in the list are:\n";
		Node* dimasNode = LAST->next;
		while (dimasNode != LAST) {
			cout << dimasNode->rollNumber << " " << dimasNode->name << endl;
			dimasNode = dimasNode->next;
		}
		cout << LAST->rollNumber << " " << LAST->name << endl;
	}
}

int main() {
	CircularLinkedList obj;
	while (true) {
		try {
			cout << "\nMenu" << endl;
			cout << "1. Add a record to the list" << endl;
			cout << "2. Delete a record from the list" << endl;
			cout << "3. View all the records in the list" << endl;
			cout << "4. Exit" << endl;
			cout << "\nEnter your choice (1-5): ";
			char ch;
			cin >> ch;
			switch (ch) {
			case '1': {
				obj.addNode();
			}
			case '2': {
				obj.delNode();
			}
			case '3': {
				obj.traverse();
				break;
			}
			case '4': {
				return 0;
			}
			default: {
				cout << "Invalid option" << endl;
				break;
			}
			}
		}
		catch (exception& e) {
			cout << e.what() << endl;
		}
	}
	return 0;
}




