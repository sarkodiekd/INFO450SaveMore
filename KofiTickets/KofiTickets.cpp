// KofiTickets.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;

class Ticket
{
private:
	char issueType;
    string issueStatus;
	char issuePriority[25];
	char description[1000];
	char callerName[100];
	int impactUsers;
	unsigned int id;
	static unsigned int id_num;
public:
	Ticket()
	{
		id = id_num;
		id_num++;
		issueStatus = "OPEN";
	};
	void ShowTicket();
	void CaptureTicket();
	void CloseTicket();
};
unsigned int Ticket::id_num = 1; //initialized outside class

								 /*Ticket::Ticket()
								 {
								 issueStatus = true;
								 }*/

void Ticket::CloseTicket()
{
	issueStatus = "CLOSED";
	cout << "The ticket number" << " " << id << " " << "is" << " " << issueStatus << endl;

}
void Ticket::ShowTicket()
{
	cout << " Issue id: " << id;
	switch (issueType)
	{
	case 'S':
	case 's':
		cout << "Type: Server \n";
		break;

	case 'C':
	case 'c':
		cout << "Type: Access \n";
		break;
	case 'A':
	case 'a':
		cout << "Type: Application \n";
		break;

	default:
		cout << "Not Valid Input. Try Again.";
		break;
	}
	cout << "Status:" << issueStatus << endl;
	cout << " Description: " << description << endl;
	cout << " User: " << callerName << endl;
	cout << "Users Impacted:" << impactUsers << endl;
	if (impactUsers < 10)
		cout << "Priority: LOW \n";
	if (impactUsers >= 10 && impactUsers < 50)
	{
		cout << "Priority: MEDIUM \n";
	}
	else
	{
		cout << "Priority: HIGH \n";
	}
}

void Ticket::CaptureTicket()
{
	//unsigned int Ticket::id_num = 1; //must be initialized outside class
	cin.clear();
	cin.ignore();
	cout << "What is the name of the caller?" << endl;
	gets_s(callerName);
	cout << "Issue Type? S=Server, A=Application, C=access" << endl;
	cin >> issueType;
	cin.ignore();
	cout << "Description of issue?" << endl;
	gets_s(description);
	cout << " Users impacted?" << endl;
	cin >> impactUsers;
	cin.clear();
	cin.ignore();
	cout << "Your issue id  is " << id << endl;
}

int main()
{
	const int maxTickets = 100;
	bool newTicket = true;
	char choice;
	Ticket myTicket[maxTickets];
	int numTickets = 0;
	bool notDone = true;
	while (notDone)
	{
		cout << "Enter in new ticket? Press Y to continue." << endl;
		cin >> choice;
		switch (choice)
		{
		case 'Y':
		case 'y':
			myTicket[numTickets].CaptureTicket();
			++numTickets;
			break;
		case 'N':
		case 'n':
			notDone = false;
			break;
		default:
			cout << " Try again" << endl
				;
			break;
		}
	}
	for (int i = 0; i < numTickets; ++i)
	{
		myTicket[i].ShowTicket();
	}
	myTicket[0].CloseTicket();
	return 0;
}
