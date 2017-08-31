// VizgList.cpp
// ��������� ��� ������ List.
// ������ ���������
// �.1093 ������� ��� ��������������� �� C++ 
// 2008 5 ������� 29 ������ 2015 �������� �.�.
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <string>
using std::string;
#include <windows.h>


class Node {
    friend class List; 
public:
    Node(const string &);     
    string getData() const;   
private:
    string data; 
    Node *pNext;  
};  

Node::Node(const string &info)
    : data(info), pNext(0)
{ }

string Node::getData() const
{
    return data;
}


class List {
public:
    List(); 
    ~List(); 

    void insertAtFront(const string &);
    void insertAtBack(const string &);
    bool removeFromFront(string &);
    bool removeFromBack(string &);

    bool isEmpty() const;
    void print() const;
private:
    Node *pFirst; 
    Node *pLast;  
  
    Node *getNewNode(const string &);
};  

List::List()
: pFirst(0), pLast(0)
{ }


List::~List()
{
    if (!isEmpty()) { 
        cout << "�������� ����� ������ ...\n";

        Node *pTemp;
        Node *p = pFirst;

        while (p != 0) { 
            pTemp = p;
            cout << p->data << '\n';
            p = p->pNext;
            delete pTemp;
        }
    }

    cout << "���������� - ����� ������ ���!\n\n";
} 

void List::insertAtFront(const string &value)
{
	Node *pNew = getNewNode(value);
	
	if (isEmpty())
	    pFirst = pLast = pNew;
	else {
		pNew->pNext = pFirst;
		pFirst = pNew;
	}    
} 

void List::insertAtBack(const string &value)
{
	Node *pNew = getNewNode(value);
	
	if (isEmpty())
	    pFirst = pLast = pNew;
	else {
		pLast -> pNext= pNew;
		pLast = pNew;
		}    
} 

bool List::removeFromFront(string &value)
{
	if (isEmpty())
	    return false;
	else {
		Node *pTemp = pFirst;
		
		if (pFirst == pLast)
		    pFirst = pLast = 0;
		else
		    pFirst = pFirst ->pNext;
		
		value = pTemp -> data;
		delete pTemp;
		return true;	    
	}    
} 

bool List::removeFromBack(string &value)
{
	if (isEmpty())
	    return false;
	else {
		Node *pTemp = pLast;
		
		if (pFirst == pLast)
		    pFirst = pLast = 0;
		else {
			Node *p = pFirst;
		}    
	} 
}

bool List::isEmpty() const
{
    return pFirst == 0;
}


Node *List::getNewNode(const string &value)
{
    return new Node(value);
}


void List::print() const
{
	if (isEmpty()) {
		cout << "������ ������ \n\n";
		return;
	}
	
	Node *p = pFirst;
	cout << "��� ������: ";
	
	while (p != 0) {
		cout << p->data << " ";
		p = p->pNext;
	}
	cout <<"\n\n";
} 

void instructions();  

void testList(List &listObject)
{
	cout << "���� ������ �� ����� \n"
	     << "====================\n";
	instructions();
	
	int choice;
	string value;
	
	do {
		cout << "?";
		cin >> choice;
		
		switch (choice) {
	    case 1:
	    	cout << "������� ������� � ������ ������: ";
	    	cin>> value;
	    	listObject.insertAtFront(value);
	    	listObject.print();
	    	break;
	    case 2:
	    	cout << "������� ������� � ����� ������: ";
	    	cin>> value;
	    	listObject.insertAtBack(value);
	    	listObject.print();
	    	break;
		case 3:
	        if (listObject.removeFromFront(value))
	           cout << value << "����� �� ������\n ";
	        
			listObject.print();
			break;
		case 4:
	        if (listObject.removeFromBack(value))
	           cout << value << "����� \n  ";
	        
			listObject.print();
			break;	   
		}
	} while (choice !=0);
	cout << "����� �������� ������ \n\n";   
} 

void instructions()
{
    cout << "������� ����� ��� ��������� �������1:\n"
            "  1 - ������ ������� � ������ ������\n"
            "  2 - � �����\n"
            "  3 - ������� ������� � ������ ������\n"
            "  4 - ������� � �����\n"
            "  0 - ����� �� �����\n";
} 

int main()
{
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

  
    List stringList;
    testList(stringList);
    cin.get(); cin.get();
    return 0;
} 
