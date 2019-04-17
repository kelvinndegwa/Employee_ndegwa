#include <iostream>
#include <string>
#include "employee.h"

using namespace std;
void menu() {
	cout << endl;
	cout << "1)" << "Enter Hourly Full TimeEmployee " << endl;
	cout << "2)" << "Enter Salaried Full TimeEmployee " << endl;
	cout << "3)" << "Enter Commissioned Full TimeEmployee " << endl;
	cout << "4)" << "Enter Salaried and Commissioned Full TimeEmployee " << endl;
	cout << "5)" << "Enter Hourly PartTime Employee " << endl;
	cout << "6)" << "Print checks for all employees " << endl;
	cout << "7)" << "Print report for all employees " << endl;
	cout << "8)" << "Update and employees pay data " << endl;
	cout << "9)" << "Quit" << endl << endl;;
}
void main()
{
	
	CEmployee * EArray[100];
	int index = 0;
	int choice;
	int counter = 0;
	char name1[1000], id1[1000];
	float p1,p2,p3;
	do {
		menu();
		cout << "Enter choice->";
		cin >> choice;
		switch (choice)
		{
		case 1:
			cout << "Enter name  ";
			cin >> name1;
			cout << "Enter id  ";
			cin >> id1;
			cout << "Enter hours ";
			cin >> p1;
			cout << "Enter rate  ";
			cin >> p2;
			EArray[index++] = new CHourlyFTEmployee(name1, id1, p1, p2);
			break;
		case 2:
			cout << "Enter name  ";
			cin >> name1;
			cout << "Enter id  ";
			cin >> id1;
			cout << "Enter salary  ";
			cin >> p1;
			EArray[index++] = new CSalariedFTEmployee(name1, id1, p1);
			break;

		case 3:
			cout << "Enter name  ";
			cin >> name1;
			cout << "Enter id  ";
			cin >> id1;
			cout << "Enter CommissionPercent  ";
			cin >> p1;
			cout << "Enter sales  ";
			cin >> p2;

			EArray[index++] = new CCommissionedFTEmployee(name1, id1, p1, p2);
			break;

		case 4:
			cout << "Enter name  ";
			cin >> name1;
			cout << "Enter id  ";
			cin >> id1;
			cout << "Enter salary  ";
			cin >> p1;
			cout << "Enter CommissionPercent  ";
			cin >> p2;
			cout << "Enter sales  ";
			cin >> p3;

			EArray[index++] = new CSalariedCommissionedFTEmployee(name1, id1, p1, p2, p3);
			break;
		case 5:
			cout << "Enter name  ";
			cin >> name1;
			cout << "Enter id  ";
			cin >> id1;
			cout << "Enter hours  ";
			cin >> p1;
			cout << "Enter rate ";
			cin >> p2;

			EArray[index++] = new CHourlyPTEmployee(name1, id1, p1, p2);
			break;
		case 6:
			
			cout << endl;
			cout << "*********Print check********" << endl;
			for (int m = 0; m < index; m++)
			{
			EArray[m]->PrintCheck();
			}
			cout << endl;
		break;
		case 7:
			
			cout << endl;
			cout << "*********Print report*********" << endl;
			for (int m = 0; m < index; m++)
			{
				EArray[m]->reportcheck();
				cout << endl;
				
			}
			break;

		case 8:
			cout << "Enter Empoyee id -> " << endl << endl;

			char *id;
			id = new char[100];
			cin.ignore();
			cin.getline(id, 100);
			int y = 0;
			bool found = false;
			for ( y = 0; y < index; y++) {
				//cout << EArray[y]->getid();
				//cout << id;
				
				if (strcmp(EArray[y]->getid(), id) == 0) 
				{
					found = true;
					break;
				}		
			}		
			if (found)
			{
				CHourlyFTEmployee * HourlyFTE;
				HourlyFTE = dynamic_cast<CHourlyFTEmployee*>(EArray[y]);

				CSalariedCommissionedFTEmployee * SalariedCommissionedFTE;
				SalariedCommissionedFTE = dynamic_cast<CSalariedCommissionedFTEmployee*>(EArray[y]);

				CHourlyPTEmployee * HourlyPTE;
				HourlyPTE = dynamic_cast<CHourlyPTEmployee*>(EArray[y]);

				CSalariedFTEmployee * salariedFTE;
				salariedFTE = dynamic_cast<CSalariedFTEmployee*>(EArray[y]);

				CCommissionedFTEmployee * CommissionedFTE;
				CommissionedFTE = dynamic_cast<CCommissionedFTEmployee*>(EArray[y]);

				if (SalariedCommissionedFTE != NULL) {
					float a, c, d;
				
					cout << "Enter salary  ";
					cin >>c;
					cout << "Enter commission";
					cin >> d;
					cout << "Enter sales";
					cin >> a;
				}
				
				else if (HourlyFTE != NULL)
				{
					float a, b;
					cout << "Hours->";
					cin >> a;
					cout << "Rate->";
					cin >> b;
					HourlyFTE->UpdatePayData(a, b);
				}
				
				else if (HourlyPTE != NULL)
				{
					float a, b;
					cout << "Hours->";
					cin >> a;
					cout << "Rate->";
					cin >> b;
					HourlyPTE->UpdatePayData(a, b);
				}
				
				else if (salariedFTE != NULL)
				{
					float a;
					cout << "Salary->";
					cin >> a;
					
					salariedFTE->UpdatePayData(a);
				}								
				
				else if (CommissionedFTE != NULL)
				{
					float a, b;
					cout << "Enter CommissionPercent  ";
					cin >> a;
					cout << "Enter sales  ";
					cin >> b;
					CommissionedFTE->UpdatePayData(a, b);
				}
		}
		}				
	}
	while (choice != 9);
	system("pause");
}