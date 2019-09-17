// Asaiah Logan
// DS 1063
// 9/17/2019
// This program reads employee information from a file, then organizes it in categories 
// of ID, first name, last name, gender, email, and pay. You can then add, delete and find employees
// by selecting an option from a menu.
#include <iostream>
#include <fstream>

using namespace std;


struct Employee
{
    string emp_id; 
    string first_name;
    string last_name;
    string gender;
    string email;
    double hourly_pay;
    Employee *Next;

    Employee()
	{
        emp_id = "";
        first_name = "";
        last_name = "";
        gender = "";
        email = "";
        hourly_pay = 0.0;
    }

    Employee(string id,string first,string last,string sex,string mail, double pay)// prganizes employee info
	{
        emp_id = id;
        first_name = first;
        last_name = last;
        gender = sex;
        email = mail;
        hourly_pay = pay;
    }
};

class LinkedList // holds info from file
{
private:
	Employee* Head;

public:
	LinkedList() {
		Head = NULL;
	}


	void push(string id, string first, string last, string sex, string mail, double pay) // adds new employee node to the front
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



	void pop(string id, string first, string last, string sex, string mail, double pay) // deletes first employee node
	{
		if (Head)
		{
			Employee* temp = Head;
			delete Head;
			Head = temp;
		}
	}


	



	void print() // prints information in the linked list
	{
		int count = 0;
		Employee* Temp = Head;

		while (Temp != NULL)
		{
			cout << Temp->emp_id;
			if (Temp->Next) {
				cout << "->\n";
			}
			Temp = Temp->Next;
			count++;
		}

	}
};

bool find(string macro, string micro)// find employee function to activate search for employee info
{

	return (macro.find(micro) != std::string::npos);
}
int menu() // displays an interactive menu to find and delete employees
{
	int choice = 0;
	while (choice < 1 || choice > 4)
	{
		cout << "\nMenu of Operations:\n";
		cout << "    1 - Find Employee\n";
		cout << "    2 - Add Employee\n";
		cout << "    2 - Delete Employee\n";
		cout << "    4 - Quit\n";
		cout << "Choice: ";
		cin >> choice;
		string search;
		if (choice == 1) // find employee command to search for employee info
		{
			cin >> search;
			cout << find(email, search) << endl;
		}
		else if (choice == 2)
		{
			cout << ;
		}
		else
		{
			cout << ;
		}
		return choice;
	}
}


int main(){

    LinkedList EmpList;
    string empid;
    string first;
    string last;
    string email;
    string gender;
    double pay;
	int choice = 0, count = 0;
    string line;
    string *tokens;
    ifstream fin("employees.dat");

	
    while(!fin.eof()) // end of file loop to input employee info from file
	{

        fin>>empid>>first>>last>>email>>gender>>pay;



        EmpList.push(empid,first,last,email,gender,pay);
    }
	while (choice != 3) {
		choice = menu();
	}
	while (count < 30)
	{
		EmpList.print();
		count++;
	}

    return 0;
}
