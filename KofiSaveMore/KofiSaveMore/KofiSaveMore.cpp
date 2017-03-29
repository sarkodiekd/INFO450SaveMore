// KofiSaveMore.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <cctype>
#include <iomanip>

class Account {
	char cust_name[20];
	int acc_no;
	char acc_type[20];
public:
	void get_accinfo() {
		std::cout << "\n\nEnter Customer Name :- ";
		std::cin >> cust_name;
		std::cout << "Enter Account Number :- ";
		std::cin >> acc_no;
		std::cout << "Enter Account Type :- ";
		std::cin >> acc_type;
	}
	void display_accinfo() {
		std::cout << "\n\nCustomer Name :- " << cust_name;
		std::cout << "\nAccount Number :- " << acc_no;
		std::cout << "\nAccount Type :- " << acc_type;
	}
};

class cur_acct : public Account
{
	static float balance;
public:
	void disp_currbal() {
		std::cout << "\nBalance :- " << balance;
		std::cout << "\nPress any key to continue...";
		
	}

	void order_check() {


		std::cout << " Order processing....\n" << balance;

	}





	void deposit_currbal() {
		float deposit;
		std::cout << "\nEnter amount to Deposit :- ";
		std::cin >> deposit;
		balance = balance + deposit;
	}
	void withdraw_currbal() {
		float penalty, withdraw;
		std::cout << "\n\nBalance :- " << balance;
		std::cout << "\nEnter amount to be withdraw :-";
		std::cin >> withdraw;
		balance = balance - withdraw;
		if (balance < 500) {
			penalty = (500 - balance) / 10;
			balance = balance - penalty;
			std::cout << "\nYour new Balance is  : " << balance;
		}
		else if (withdraw > balance) {
			std::cout << "\n\nOverdraft detected \n";
			balance = balance + withdraw;
		}
		else
			std::cout << "\nYour Balance is : " << balance;
	}
};

class sav_acct : public Account {
	static float savbal;
public:
	void disp_savbal() {
		std::cout << "\n Balance :- " << savbal;
		std::cout << "\n Press any key to continue...\n";
		
	}

	void order_check() {



		std::cout << "Check Order Processed....\n" << savbal;

	}





	void deposit_savbal() {
		float deposit, interest;
		std::cout << "\nEnter Deposit Amount :- ";
		std::cin >> deposit;
		savbal = savbal + deposit;
		if (savbal <= 10000) {
			interest = savbal * 1 / 100;
		}
		if (savbal > 10000) {
			interest = savbal * 2 / 100;
		}
		savbal = savbal + interest;
	}
	void withdraw_savbal() {
		float withdraw;
		std::cout << "\nBalance :- " << savbal;
		std::cout << "\nEnter amount to be withdraw :-";
		std::cin >> withdraw;
		savbal = savbal - withdraw;
		if (withdraw > savbal) {
			std::cout << "\n\nBank Overdraft Detected\n";
			savbal = savbal + withdraw;
		}
		else
			savbal = savbal - 2;
		std::cout << "\nYour New Balance is : " << savbal;
	}
};

class cd_acct : public Account {
	static float cd;
public:
	void disp_cd() {
		std::cout << "\n Balance :- " << cd;
		std::cout << "\n Press any key to continue...\n";
		
	}

	void order_check() {


		std::cout << "Check ordered....\n" << cd;

	}


	void deposit_cd() {
		float deposit, interest;
		std::cout << "\nEnter amount to Deposit :- ";
		std::cin >> deposit;
		cd = cd + deposit;
		if (cd <= 10000) {
			interest = cd * 1 / 100;
		}
		if (cd > 10000) {
			interest = cd * 2 / 100;
		}
		cd = cd + interest;
	}
	void withdraw_cd() {
		float withdraw;
		std::cout << "\nBalance :- " << cd;
		std::cout << "\nEnter amount to be withdrawn :-";
		std::cin >> withdraw;
		cd = cd - withdraw;
		if (withdraw > cd) {
			std::cout << "\n\nBank Overdraft Detected\n";
			cd = cd + withdraw;
		}
		else
			cd = cd - 2;
		std::cout << "\nYour New Balance is : " << cd;
	}
};

float cur_acct::balance;
float sav_acct::savbal;
float cd_acct::cd;

int main() {
label:
	printf("\n...");
	cur_acct c1;
	sav_acct s1;
	cd_acct c2;

	std::cout << "\nEnter S for savings account and C1 for checkings and cd for CD Savings\n\n";
	char type;
	std::cin >> type;

	int choice;

	if (type == 's' || type == 'S') {
		s1.get_accinfo();
		while (1) {
			printf("\n...");
			std::cout << "\nPlease select an option\n";
			std::cout << "1) Deposit\n";

			std::cout << "11) Order a check\n";

			std::cout << "2) Withdraw\n";
			std::cout << "3) Display Balance\n";
			std::cout << "4) Display with Details\n";
			std::cout << "5) Exit\n";
			std::cout << "6) Please select an option:-";
			std::cin >> choice;
			switch (choice) {
			case 1:
				s1.deposit_savbal();
				break;
			case 11:
				s1.order_check();
				break;
			case 2:
				s1.withdraw_savbal();
				break;
			case 3:
				s1.disp_savbal();
				break;
			case 4:
				s1.display_accinfo();
				s1.disp_savbal();
				break;
			case 5:
				goto label;
			default:
				std::cout << "\n\nEntered choice is invalid,\"TRY AGAIN\"";
			}
		}
	}
	else if (type == 'c1' || type == 'C1') {
		c1.get_accinfo();
		while (1) {
			std::cout << "\nPlease select an option\n";
			std::cout << "1) Deposit\n";

			std::cout << "11) order a check\n";

			std::cout << "2) Withdraw\n";
			std::cout << "3) Display Balance\n";
			std::cout << "4) Display with full Details\n";
			std::cout << "5) Exit\n";
			std::cout << "6) Please select an option:-";
			std::cin >> choice;
			switch (choice) {
			case 1:
				c1.deposit_currbal();
				break;
			case 11:
				c1.order_check();
				break;
			case 2:
				c1.withdraw_currbal();
				break;
			case 3:
				c1.disp_currbal();
				break;
			case 4:
				c1.display_accinfo();
				c1.disp_currbal();
				break;
			case 5:
				goto label;
			default:
				std::cout << "\n\nSelection is invalid,\"TRY AGAIN\"";
			}
		}
	}


	else {
		c2.get_accinfo();
		while (1) {
			std::cout << "\nPlease select an option\n";
			std::cout << "1) Deposit\n";

			std::cout << "11) order a check\n";

			std::cout << "2) Withdraw\n";
			std::cout << "3) Display Balance\n";
			std::cout << "4) Display with full Details\n";
			std::cout << "5) Exit\n";
			std::cout << "6) Choose Your choice:-";
			std::cin >> choice;
			switch (choice) {
			case 1:
				c2.deposit_cd();
				break;
			case 11:
				c2.order_check();
				break;
			case 2:
				c2.withdraw_cd();
				break;
			case 3:
				c2.disp_cd();
				break;
			case 4:
				c2.display_accinfo();
				c2.disp_cd();
				break;
			case 5:
				goto label;




			default:
				std::cout << "\n\nEntered choice is invalid,\"TRY AGAIN\"";
			}
		}
	}

	return 0;
}

