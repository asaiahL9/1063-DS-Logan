// Asaiah Logan
// DS 1063
// 9/17/2019
// This program reads employee information from a file, then organizes it in categories 
// of ID, first name, last name, gender, email, and pay. You can then add, delete and find employees
// by selecting an option from a menu.
#include <iostream>
#include <fstream>
#include <string>
using namespace std;


struct Employee {
	string emp_id;
	string first_name;
	string last_name;
	string gender;
	string email;
	double hourly_pay;
	Employee *Next;

	Employee() {
		emp_id = "";
		first_name = "";
		last_name = "";
		gender = "";
		email = "";
		hourly_pay = 0.0;

		Next = NULL;
	}

	Employee(string id, string first, string last, string sex, string mail, double pay) 
	{
		emp_id = id;
		first_name = first;
		last_name = last;
		gender = sex;
		email = mail;
		hourly_pay = pay;
	}
};

class LinkedList
{
private:
	Employee* Head;

public:
	LinkedList() 
	{
		Head = NULL;
	}


	void push(string id, string first, string last, string sex, string mail, double pay) // adds new employee node to the front of the list
	{
		Employee* temp = new Employee(id, first, last, sex, mail, pay);

		if (Head == NULL)
		{
			Head = temp;
		}
		else
		{
			temp->Next = Head;
			Head = temp;
		}

	}

	Employee* pop(struct Employee* Head) // deletes first employee node
	{
		if (Head == NULL)
		{
			return NULL;
			Employee* temp = Head;
			Head = Head->Next;
			delete temp;
			return Head;
		}


	}

	Employee deleteNode()
	{
		//could not work out function
	}
	// series of functions to match strings in order to search for employees in list
	bool string_match(string big, string small) // could not work out method
	{
		int index = big.find(small);
		return index >= 0;
	}

	string lower_string(string orig)
	{
		string result = "";
		for (int i = 0; i < orig.size(); i++)
		{
			result += tolower(orig[i]);
		}
		return result;
	}

	bool find(struct Employee)
	{
		Employee* temp = Head;
		while (temp != NULL)
		{

			if (string_match(lower_string(temp->email), lower_string(temp->email)))
			{
				return true;
			}
			else
			{
				temp = temp->Next;
			}
		}
		return false;
	}

	// prints first 30 employee IDs into an output file
	void print() {
		ofstream outfile;
		outfile.open("outfile.txt");
		Employee* Temp = Head;

		for (int i = 0; i < 30; i++)
		{
			outfile << Temp->emp_id ;
			if (Temp->Next) {
				outfile << endl;
			}
			Temp = Temp->Next;
		}
	}
};

int menu() 
{
	int choice = 0;
	while (choice < 1 || choice > 3) {
		cout << "\nMenu of Operations:\n";
		cout << "    1 - Find Employee\n";
		cout << "    2 - Delete Employee\n";
		cout << "    3 - Add Employee";
		cout << "    4 - Quit";
		cout << "Choice: ";
		cin >> choice;
	}
	return choice;
}

int main() 
{
	//organizes data for LinkedList
	LinkedList EmpList;
	string empid;
	string first;
	string last;
	string email;
	string gender;
	double pay;
	int choice = 0, count = 0;
	string line;
	ifstream fin("employees.dat");
	Employee* Head = NULL;

	ofstream outfile;
	

	// reads in employee data from file
	while (!fin.eof()) {

		fin >> empid >> first >> last >> email >> gender >> pay;



		EmpList.push(empid, first, last, email, gender, pay);
	
	}
	menu();
	if (choice == 1)
	{
		EmpList.find("");
	}
	else if (choice == 2)
	{
		EmpList.deleteNode();
	}
	else if (choice == 3)
	{
		EmpList.push( empid, first,last, email, gender, pay);
	}
	else if (choice == 4)
	{
		EmpList.print();
	}

	return 0;

}