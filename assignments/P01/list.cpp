// Asaiah Logan
// DS 1063
// 9/17/2019
#include <iostream>
#include <fstream>

using namespace std;


struct Employee{
    string emp_id; 
    string first_name;
    string last_name;
    string gender;
    string email;
    double hourly_pay;
    Employee *Next;

    Employee(){
        emp_id = "";
        first_name = "";
        last_name = "";
        gender = "";
        email = "";
        hourly_pay = 0.0;
    }

    Employee(string id,string first,string last,string sex,string mail, double pay){
        emp_id = id;
        first_name = first;
        last_name = last;
        gender = sex;
        email = mail;
        hourly_pay = pay;
    }
};

class LinkedList {
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


	



	void print() 
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

bool find(string macro, string micro)
{

	return (macro.find(micro) != std::string::npos);
}
int menu() // displays an interactive menu to find and delete employees
{
	int choice = 0;
	while (choice < 1 || choice > 3)
	{
		cout << "\nMenu of Operations:\n";
		cout << "    1 - Find Employee\n";
		cout << "    2 - Delete Employee\n";
		cout << "    3 - Quit\n";
		cout << "Choice: ";
		cin >> choice;
		string search;
		if (choice == 1)
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

	
    while(!fin.eof()){

        fin>>empid>>first>>last>>email>>gender>>pay;

        //cout<<empid<<", "<<first<<", "<<last<<", "<<email<<", "<<gender<<", "<<pay<<endl;

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
