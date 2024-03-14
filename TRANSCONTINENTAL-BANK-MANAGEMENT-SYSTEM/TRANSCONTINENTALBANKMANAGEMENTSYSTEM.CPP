#include<iostream>
#include<string>
#include<fstream>
#include <ctime>
#include <vector>


using namespace std;





void admin();
void employee();
void customer();
void mainMenu();
void adminlogin();
void adminSignUp();
void adminForgotPassword();
void employeelogin();
void employeeSignUp();
void employeeForgotPassword();
void customerlogin();
void customerSignUp();
void customerForgotPassword();
void customerMenu();
void mwanainchiAccountDetails();
void createCustomerAccount();
void logInExistingCustomerAccount();
void loan();
void applyCustomerCnDCard();
void choiceMenu();
void currencyExtchangeMenu();
void mwanainchiAccountActions();
void lockAndSavingsAccountActions();
void transferMoney();
void withdrawMoney();
void depositMoney();
void exit();
void loanMenu();
void applyLoan();
void repayLoan();
void loanBallance();
void recordTransaction();
void displayTransactionHistory(const std::string& accountNumber);




bool isLoggedIn = false;

int choiceMenuChoice;
int mainMenuChoice;
int customerLoginChoice;
int employeeLoginChoice;
int adminLoginChoice;
//int accountNumber;
int kraPin;
int fDeposit;
int phoneNumber;
int currentBalance;
int securityCode;
int loanAmmount;

string accountNumber;
string mwanainchiAccountPassword;
string lockandSavingsAccountPassword;
string customerPassword;
string employeePassword;
string adminPassword;
string user;
string adminUsername;
string employeeUsername;
string customerUsername;
string logedInCustomer;
string fName;
string sName;
string tName;
string tNamr;
string retrevePasswordNumber;
string dateOfBirth;


// ANSI escape codes for text colors
const string RESET_COLOR = "\033[0m";
const string BLACK_COLOR = "\033[30m";
const string RED_COLOR = "\033[31m";
const string GREEN_COLOR = "\033[32m";
const string YELLOW_COLOR = "\033[33m";
const string BLUE_COLOR = "\033[34m";
const string MAGENTA_COLOR = "\033[35m";
const string CYAN_COLOR = "\033[36m";
const string WHITE_COLOR = "\033[37m";

// ANSI escape codes for background colors
const string BLACK_BG = "\033[40m";
const string RED_BG = "\033[41m";
const string GREEN_BG = "\033[42m";
const string YELLOW_BG = "\033[43m";
const string BLUE_BG = "\033[44m";
const string MAGENTA_BG = "\033[45m";
const string CYAN_BG = "\033[46m";
const string WHITE_BG = "\033[47m";

// ANSI escape codes for text styles
const string BOLD_TEXT = "\033[1m";
const string UNDERLINE_TEXT = "\033[4m";
const string ITALIC_TEXT = "\033[3m";

// Additional effects
const string BLINK_TEXT = "\033[5m";
const string REVERSE_TEXT = "\033[7m";

// Reset all styles and colors
const string RESET_ALL = "\033[0;0m";

/*
    // Example 1: Success message with green text and bold style
    cout<< GREEN_COLOR << BOLD_TEXT << "Transaction successful." << RESET_ALL << endl;

    // Example 2: Error message with red text, bold style, and blinking effect
    cout<< RED_COLOR << BOLD_TEXT << BLINK_TEXT << "Error: Insufficient funds." << RESET_ALL << endl;

    // Example 3: Important message with yellow text and underline
    cout<< YELLOW_COLOR << UNDERLINE_TEXT << "Important Notice: Account will be upgraded." << RESET_ALL << endl;

    // Example 4: Blue background with white text
    cout<< BLUE_BG << WHITE_COLOR << "Welcome to XYZ Bank." << RESET_ALL << endl;

    // Example 5: Magenta text with cyan background and reverse text effect
    cout<< MAGENTA_COLOR << CYAN_BG << REVERSE_TEXT << "Account Locked: Contact Customer Support." << RESET_ALL << endl;

    // Example 6: Combined effects - Bold, italic, and underline text in red
    cout<< RED_COLOR << BOLD_TEXT << ITALIC_TEXT << UNDERLINE_TEXT << "Security Alert: Update Password." << RESET_ALL << endl;

*/


struct Transaction {
    std::string type;        // Transaction type: "Deposit", "Withdrawal", "Transfer", etc.
    double amount; 
	string accountNumber;          // Transaction amount
};

std::vector<Transaction> transactionHistory;


void recordTransaction(const std::string& type, double amount, const std::string& accountNumber) {
    Transaction transaction;
    transaction.type = type;
    transaction.amount = amount;
    transaction.accountNumber = accountNumber; // Add account number to the transaction
    transactionHistory.push_back(transaction);

    // Append transaction to the account's transaction history file
    std::ofstream outFile(("transaction_history_" + accountNumber + ".txt").c_str(), std::ios_base::app);
    if (outFile.is_open()) {
        outFile << "Type: " << type << ", Amount: $" << amount << std::endl;
        outFile.close();
    } else {
        std::cerr << "Error: Unable to open transaction history file." << std::endl;
    }
}

void displayTransactionHistory(const std::string& accountNumber) {
    std::ifstream inFile(("transaction_history_" + accountNumber + ".txt").c_str());
    if (inFile.is_open()) {
        std::cout << "Transaction History for Account Number " << accountNumber << ":" << std::endl;
        std::string line;
        while (std::getline(inFile, line)) {
            std::cout << line << std::endl;
        }
        inFile.close();
		mwanainchiAccountActions();
    } else {
        std::cerr << "Error: Unable to open transaction history file." << std::endl;
    }

	
}





void print(const string& message) {
  cout << message << RESET_COLOR << endl;
    // printMessage(GREEN_COLOR + BOLD_TEXT + "?? Welcome to our New Banking Experience!" + RESET_COLOR);
}

void exit(){
	
	
};

void mainMenu() {
	//print("how are you");
    cout << "\t\t\t--------------------------------------------------------------" << endl;
    cout << "\t\t\t|                 WELCOME TO YOUR BANK SYSTEM                |" << endl;
    cout << "\t\t\t|                                                            |" << endl;
    cout << "\t\t\t|                  --------------------------                |" << endl;
    cout << "\t\t\t|                  ********Main  Menu********                |" << endl;
    cout << "\t\t\t|                  *------------------------*                |" << endl;
    cout << "\t\t\t|                  * 1. Admin               *                |" << endl;
    cout << "\t\t\t|                  * 2. Employee            *                |" << endl;
    cout << "\t\t\t|                  * 3. Customer            *                |" << endl;
    cout << "\t\t\t|                  * 4. Exit                *                |" << endl;
    cout << "\t\t\t|                  *------------------------*                |" << endl;
    cout << "\t\t\t|                  * Enter your choice: "; cin >> mainMenuChoice;

    cout << "\t\t\t|                  *------------------------*                |" << endl;
    cout << "\t\t\t|                                                            |" << endl;
    cout << "\t\t\t--------------------------------------------------------------" << endl;

    switch (mainMenuChoice) {
        case 1:
           // admin();
            break;
        case 2:
           // employee();
            break;
        case 3:
            customer();
            break;
        case 4:
            cout << "\t\t\tThank you!!!";
            exit();
            
            break;
        default:
            cout << "\t\t\tEnter the correct choice" << endl;
            mainMenu();
            break;
    }
}



void choiceMenu() {
    if (mainMenuChoice == 1) {
        user = "ADMIN";
    }
    else if(mainMenuChoice == 2) {
		user = "EMPLOYEE";		
	}
	else if(mainMenuChoice == 3) {
		user = "CUSTOMER";
	}


    cout << "\t\t\t--------------------------------------------------------------" << endl;
    cout << "\t\t\t|                 WELCOME TO YOUR BANK SYSTEM                |" << endl;
    cout << "\t\t\t|                                                            |" << endl;
    cout << "\t\t\t|                  --------------------------                |" << endl;
    cout << "\t\t\t|                         "<< user <<"                       |" << endl;
    cout << "\t\t\t|                  *------------------------*                |" << endl;
    cout << "\t\t\t|                  * 1. Login               *                |" << endl;
    cout << "\t\t\t|                  * 2. Sign up             *                |" << endl;
    cout << "\t\t\t|                  * 3. Forgot password     *                |" << endl;
    cout << "\t\t\t|                  * 4. Exit to main menu   *                |" << endl;
    cout << "\t\t\t|                  *------------------------*                |" << endl;
    cout << "\t\t\t|                                                            |" << endl;
    cout << "\t\t\t--------------------------------------------------------------" << endl;
}




void customer(){
	
	
	int choiceMenuChoice;
	
	cout << "\t\t\t********************** WELCOME CUSTOMER **********************" << endl;
	choiceMenu();

    std::cout <<"Enter your choice : "; cin >> choiceMenuChoice;

    switch (choiceMenuChoice) {
        case 1:
        	customerlogin();
            break;
        case 2:
            customerSignUp();
            break;
        case 3:
            customerForgotPassword();
            break;
        case 4:
        	mainMenu();
            break;
        default:
            std::cout << "\t\t\tEnter a valid choice";
            customer();
    }

	
	
	
};


void customerSignUp(){
		
	string customerUsername , customerPassword , retrevePasswordNumber;

	std::cout<< "Please enter your username : "; cin >> customerUsername;
	std::cout<< "Please enter your password : "; cin >> customerPassword;
	std::cout<< "Enter number to retreve password incase you forget password : "; cin >> retrevePasswordNumber;	
	
	ofstream cr("customerRecords.txt",ios::app);
	cr << customerUsername << "\t" << customerPassword << "\t" << retrevePasswordNumber << endl;
		
	std::cout<< "You have succesfully signed up" << endl;
	mainMenu();   	
	
};

void customerlogin(){
	
	string customerUsername, username ,customerPassword , password;
	int count = 0 ;
	
	std::cout<< "Please enter your USERNAME : "; cin >> username;
	std::cout<< "Please enter your PASSWORD : "; cin >> password;
	
	ifstream cr("customerRecords.txt");
	while (cr >> customerUsername >> customerPassword >> retrevePasswordNumber){
		
		if (username == customerUsername && password == customerPassword){
			count = 1;
			logedInCustomer = username;
			isLoggedIn = true;
			break;
		}
	}
	cr.close();
	
	if (count == 1){
		
		std::cout<< username << " : Your login is succesfull \nThanks for loging in" << endl;
		logedInCustomer = username;
		customerMenu();	
	}
	else
	{
		
		std::cout<< "\t\t\t\aError in login" << endl;
		customer();
		
	}

	
};

void customerForgotPassword(){
	
	
	int option;

	std::cout<< "\t\t\t====== No worries ======" << endl;
	std::cout<< "\t\t\t1 Search for password" << endl;
	std::cout<< "\t\t\t2 Register new customer" << endl;
	std::cout<< "\t\t\t00 Customer menu/n" << endl;
	std::cout<< "Enter your choice : ";
	cin >> option;
	
	switch(option){
		
		case 1:
		{	
			int count = 0;
			string username;
			string PasswordNumber;
			
			std::cout<< "Enter your username: "; cin >> username;
			std::cout<< "Enter number to retreve password"; cin >> PasswordNumber;
			
			ifstream cr("customerRecords.txt");
			while (cr >> customerUsername >> customerPassword >> retrevePasswordNumber)
			{
				if(username == customerUsername || PasswordNumber == retrevePasswordNumber)
				{
					   count = 1;
					   	
				}
					
			}
			cr.close();
			
			if(count == 1){
				std::cout<< "Your account has been found" << endl;
				std::cout<< "Your password is : " << customerPassword;
				customer();
			}
			else
			{
				std::cout<< "\aSorry your Account was not found" << endl;
				customer();
			}
			
			break;	
		}
		case 2:
		{
			customerSignUp();
			break;
			
		}
		case 00:
		{
			customer();
		}	
				
	}	
	
	
};



void customerMenu()
{
	if (!isLoggedIn){
		std::cout<< "You must be log-in first" << endl;
		return;
	}
	
	int customerMenuChoice; //local
	
	std::cout<< "\t\t\t=== Welcome : "<< logedInCustomer << " to the customer menu ===\n" << endl;
	std::cout<< "\t\t\t1 Create account" << endl; 
	std::cout<< "\t\t\t2 log in existing account" << endl; 
	std::cout<< "\t\t\t00 Main menu\n" << endl; 
	std::cout<< "Enter your choice : ";
	cin >> customerMenuChoice;
	
	switch(customerMenuChoice)
	{
		case 1:
			createCustomerAccount();
			break;
		case 2:
			logInExistingCustomerAccount();
			break;
		case 00:
			mainMenu();
			break;
		default :
			std::cout<< "\t\t\tEnter the correct option" << endl;
			customerMenu();
			break;
	}
	
	
};



void createCustomerAccount(){

     if (!isLoggedIn)
	{
        std::cout<< "You must be logged in to create customer account.\n";
        return;
    }
	

	
    int choice;
    
	std::cout<< "\t\t\t which type of account do you want to create\n" << endl;
	std::cout<< "1 Mwanainchi account" << endl;
	std::cout<< "2 Lock savings account" << endl;
	std::cout<< "3 Customer menu\n" << endl;
	std::cout<< "Enter your choice : "; cin >> choice;
	
	
	switch(choice)
	{
		case 1:
		{
			std::cout<< "\t\t\tWelcome " <<   logedInCustomer << " to mwanainchi account registration" << endl;
			std::cout<< "\t\t\tThank you for choosing our bank\n" << endl;
	   	   	std::cout<< "\t\t\tEnter your details make sure they are correct !!!\n" << endl;
			std::cout<< "\t\t\tPersonal details" << endl;
			std::cout<< "First name : "; cin >> fName;
			std::cout<< "Second name : "; cin >> sName;
			std::cout<< "Third name : "; cin >> tName;
		
			std::cout<< "Enter your mwanainchi account password";
			std::cout<< RED_COLOR << UNDERLINE_TEXT << " Account password can only be retrived by goint to the bank : " << RESET_ALL; cin >> mwanainchiAccountPassword;  
			std::cout<< RED_COLOR << "Enter security code incase you forget password : " << RESET_COLOR; cin >> securityCode;
				
			std::cout<< "Account number : "; cin >> accountNumber;
			std::cout<< "Date of birth : "; cin >> dateOfBirth;
			std::cout<< "Kra pin : "; cin >> kraPin;
			
			std::cout<< "\n\t\t\tCONTACTS/n" << endl;
			std::cout<< "Phone number : "; cin >> phoneNumber;
			
			std::cout<< "First deposit : "; cin >> fDeposit;

			loanAmmount = 0;
			
			ofstream file("mwanainchi_accounts.txt",ios::app);
			file << fName << "\t" << sName << "\t" << tName << "\t" << mwanainchiAccountPassword << "\t" << securityCode << "\t" << accountNumber << "\t" << dateOfBirth<< "\t" << kraPin << "\t" << phoneNumber << "\t" << fDeposit << "\t" << loanAmmount << endl; 
			
			file.close();
			
			customerMenu();
			
			break;
		}	
		case 2:
		{	
			std::cout<< "\t\t\tWelcome " <<   logedInCustomer << " to lock and savings account registration" << endl;
			std::cout<< "\t\t\tThank you for choosing our bank\n" << endl;
	   	   	std::cout<< "\t\t\tEnter your details make sure they are correct !!!\n" << endl;
			std::cout<< "\t\t\tPersonal details" << endl;
			std::cout<< "First name : "; cin >> fName;
			std::cout<< "Second name : "; cin >> sName;
			std::cout<< "Third name : "; cin >> tName;
		
			std::cout<< "Enter your mwanainchi account password";
			std::cout<< BLINK_TEXT << RED_COLOR << UNDERLINE_TEXT << " Account password can only be retrived by goint to the bank : " << RESET_ALL; cin >> lockandSavingsAccountPassword;  
			std::cout<< RED_COLOR << "Enter security code incase you forget password : " << RESET_COLOR; cin >> securityCode;
				
			std::cout<< "Account number : "; cin >> accountNumber;
			std::cout<< "Date of birth : "; cin >> dateOfBirth;
			std::cout<< "Kra pin : "; cin >> kraPin;
			
			std::cout<< "\n\t\t\tCONTACTS/n" << endl;
			std::cout<< "Phone number : "; cin >> phoneNumber;
			
			std::cout<< "First deposit : "; cin >> fDeposit;
			
			ofstream file("lockAndSavingsAcounts.txt" , ios::app);
			file << fName << "\t" << sName << "\t" << tName << "\t" << lockandSavingsAccountPassword << "\t" << securityCode << "\t" << accountNumber << "\t" << dateOfBirth<< "\t" << kraPin << "\t" << phoneNumber << "\t" << fDeposit << endl; 
			
			file.close();
			
			customerMenu();
			break;
		}	
		case 3:
			customerMenu();
			break;
		default :
			std::cout<<"Enter the correct choice" << endl;
			createCustomerAccount();
			break;	
	}
		
};


void logInExistingCustomerAccount(){

    if (!isLoggedIn) 
	{
        std::cout<< "You must be logged in to log in to your existing account.\n";
        return;
    }
	
	int choice;

	std::cout<< "\t\t\tThank you for choosing to bank with us" << endl;
	std::cout<< "\t\t\tWhich account do you have\n" << endl;
	std::cout<< "1 MWANAINCHI ACCOUNT" << endl;
	std::cout<< "2 LOCK AND SAVINGS ACCOUNT" << endl;
	std::cout<< "3 main menu\n" << endl;
	std::cout<< "Enter your choice : "; cin >> choice;
	
	switch(choice)
	{
		case 1:
		{
			int count;
			string inputPassword, inputName , inputAccountNumber;
			
			std::cout<< "\t\t\tWelcome to mwanainchi account login" << endl;
			std::cout<< "\t\t\tPlease enter your details correctly !!!\n" << endl;
			std::cout<< "Enter your first name : "; cin >> inputName;
			std::cout<< "Enter your account number : "; cin >> inputAccountNumber;
			std::cout<< "Enter your mwanainchi account password : "; cin >> inputPassword;
			
			ifstream file("mwanainchi_accounts.txt");
			while (file >> fName >>  sName >> tName >> mwanainchiAccountPassword >> securityCode >> accountNumber >> dateOfBirth >> kraPin >> phoneNumber >> fDeposit >> loanAmmount)
			{
				if(inputName == fName && inputAccountNumber == accountNumber && inputPassword == mwanainchiAccountPassword)
				{
					count = 1;
					break;
				}
			}
			file.close();
			if(count == 1)
			{
				std::cout<< "\t\t\tYou have succesfully loged in" << endl;
				fDeposit = fDeposit;
				mwanainchiAccountActions();
			}	
			else
			{
				int retryChoice;
                std::cout<< "\t\t\tYou have entered the wrong details\n" << endl;
                std::cout<< "1. Try again\n";
                std::cout<< "00. Customer menu\n";
                cin >> retryChoice;

                switch (retryChoice)
				 {
                    case 1:
                        logInExistingCustomerAccount();
                        break;
                    case 00:
                        customerMenu();
                    default:
                        std::cout<< "Enter the correct choice\n";
                        logInExistingCustomerAccount();
                        break;	
				}
			}
		}
		case 2:
		{
			int count;
			string inputPassword, inputName , inputAccountNumber;
			
			std::cout<< "\t\t\tWelcome to lock and savings account login" << endl;
			std::cout<< "\t\t\tPlease enter your details correctly !!!\n" << endl;
			std::cout<< "Enter your first name : "; cin >> inputName;
			std::cout<< "Enter your account number : "; cin >> inputAccountNumber;
			std::cout<< "Enter your mwanainchi account password : "; cin >> inputPassword;
			
			ifstream file("lockAndSavingsAcounts.txt");
			while (file >> fName >>  sName >> tName >> lockandSavingsAccountPassword >> securityCode >> accountNumber >> dateOfBirth >> kraPin >> phoneNumber >> fDeposit)
			{
				if(inputName == fName && inputAccountNumber == accountNumber && inputPassword == lockandSavingsAccountPassword)
				{
					count = 1;
					break;
				}
			}
			file.close();
			if(count == 1)
			{
				std::cout<< "\t\t\tYou have succesfully loged in" << endl;
				fDeposit = fDeposit;
				lockAndSavingsAccountActions();
			}	
			
			else
			{
				int retryChoice;
                std::cout<< "\t\t\tYou have entered the wrong details\n" << endl;
                std::cout<< "1. Try again\n";
                std::cout<< "00. Customer menu\n";
                cin >> retryChoice;

                switch (retryChoice)
				 {
                    case 1:
                        logInExistingCustomerAccount();
                        break;
                    case 00:
                        customerMenu();
                    default:
                        std::cout<< "Enter the correct choice\n";
                        logInExistingCustomerAccount();
                        break;	
				}
			}
			
			break;
		}
		case 00:
            customerMenu();
 	    break;
		
	}
		
};

	



void mwanainchiAccountActions()
{
       int choice;
	    


	
 	   std::cout<< "\t\t\t|*************************Account menu****************************|"<< endl;
 	   std::cout<< "\t\t\t******************************************************************" << endl;
	   std::cout<< "\t\t\t|	Chose what action to do                                         " << endl;
	   std::cout<< "\t\t\t|	1 transfer money             6 account                          " << endl;
	   std::cout<< "\t\t\t|	2 withdraw money               details                          " << endl;
	   std::cout<< "\t\t\t|	3 Deposit money              7 transaction                      " << endl;
	   std::cout<< "\t\t\t|	4 loan                         history                          " << endl; 
       std::cout<< "\t\t\t|	5 credit or debit card                                          " << endl; //lokk if credit card is active in account detai
	   std::cout<< "\t\t\t|	00 log out                                                      " << endl;
       std::cout<< "\t\t\t******************************************************************" << endl; //look at loan balance in 	
	   std::cout<< "\t\t\t|Enter your choice : ";
	   cin >> choice;
       std::cout<< "\n\t\t\t******************************************************************" << endl;
	   
	   switch (choice)
	   {
	   	
	   	case 1:
	   		transferMoney();
	   		break;
	   	case 2 :
	   		withdrawMoney();
	   		break;
	   	case 3:
	   		depositMoney();
	   		break;
	   	case 00:
	   		customerMenu();
	   		break;
	   	case 6:
			mwanainchiAccountDetails();
			mwanainchiAccountActions();   
			   
	   		break;
		case 7:
			displayTransactionHistory(accountNumber);
			break;
	   	case 4:
			loan();
			break;
		case 5:
			applyCustomerCnDCard();
			break;
	   	default :
	   		std::cout<< "Enter the correct choice" << endl;
	   		mwanainchiAccountActions();
	   		break;
	   	
	   }
	   
	   	
	
};

void transferMoney()
{
	
	int amount;
    double newBalance = 0;

    std::cout<< "Your current balance is: $" << fDeposit << endl;
    std::cout<< "Welcome, " << logedInCustomer << "\nHow much do you want to transfe: $";
    cin >> amount;

    if (amount <= 0 || amount > fDeposit) 
    {
        std::cout<< "Please enter a valid amount to transfer.\n";
        mwanainchiAccountActions();
        return;
    }

    newBalance = fDeposit - amount;

    ifstream inFile("mwanainchi_accounts.txt");
    ofstream outFile("temp_mwanainchi_accounts.txt");

    if (!inFile || !outFile) 
    {
        std::cout<< "Error: Unable to open files for transfer please try again later sorry for the inconvinience.\n";
        return;
    }

    while (inFile >> fName >> sName >> tName >> mwanainchiAccountPassword >> securityCode >> accountNumber >> dateOfBirth >> kraPin >> phoneNumber >> fDeposit >> loanAmmount) 
    {
        if (accountNumber == ::accountNumber) 
        {
            outFile << fName << "\t" << sName << "\t" << tName << "\t" << mwanainchiAccountPassword << "\t"
                     << securityCode << "\t" << accountNumber << "\t" << dateOfBirth << "\t" << kraPin << "\t"
                     << phoneNumber << "\t" << newBalance << "\t" << loanAmmount << "\t";
                     
                    
                     
        } 
        else 
        {
            outFile << fName << "\t" << sName << "\t" << tName << "\t" << mwanainchiAccountPassword << "\t"
                     << securityCode << "\t" << accountNumber << "\t" << dateOfBirth << "\t" << kraPin << "\t"
                     << phoneNumber << "\t" << fDeposit << "\t" << loanAmmount << "\t";
        }
    }

    inFile.close();
    outFile.close();

    std::remove("mwanainchi_accounts.txt");
    std::rename("temp_mwanainchi_accounts.txt", "mwanainchi_accounts.txt");

    std::cout<< "transfer successful. New balance: $" << newBalance << "\n";
	
	recordTransaction("Transaction" , amount , accountNumber );

	mwanainchiAccountDetails();
    mwanainchiAccountActions();

}




void loan(){
	
	  if (!isLoggedIn) {
        std::cout<< "You must be logged in to apply for a customer loan.\n";
        return;
    }
	string password;
	string username;
	int count = 0 ;
	std::cout<< "Enter your first name :"; cin >> username;
	std::cout<< "Enter your password : "; cin >> password;

	ifstream file("mwanainchi_accounts.txt");
	while (file >> fName >>  sName >> tName >> mwanainchiAccountPassword >> securityCode >> accountNumber >> dateOfBirth >> kraPin >> phoneNumber >> fDeposit >> loanAmmount)
	{
		if(username == fName && password == mwanainchiAccountPassword)
		count = 1;
	}
	file.close();
	if (count == 1)
	{
		int choice;		
		while(true)
		{	


			std::cout<< "\t\t\tWelcome to the loan menu\n\n" << endl;
			std::cout<< "1. Repay loan " << endl;
			std::cout<< "2. Apply loan " << endl;
			std::cout<< "3. Main menu" << endl;
			cin >> choice;



			switch(choice)
			{
			case 1:
			repayLoan();
			break;
			case 2:
			applyLoan();
			break;
			case 3:
			return;
			break;
			default :
			std::cout<< "Enter the correct choice" << endl;
			continue;
			break;
			}

		}
	}
	else
	{
		std::cout<< "wrong password";
		mwanainchiAccountActions();
	}
}

void repayLoan()
{
	int amount;
    double newBalance = 0;

    std::cout<< "Your current balance is: $" << loanAmmount << endl;
    std::cout<< "Welcome, " << logedInCustomer << "\nHow much do you want to repay: $";
    cin >> amount;

    if (amount <= 0 || amount > loanAmmount) 
    {
        std::cout<< "Transaction failed!!!.\n";
        mwanainchiAccountActions();
        return;
    }

    newBalance = loanAmmount - amount;

    ifstream inFile("mwanainchi_accounts.txt");
    ofstream outFile("temp_mwanainchi_accounts.txt");

    if (!inFile || !outFile) 
    {
        std::cout<< "Error: Unable to open files for repayment.\n";
        return;
    }

    while (inFile >> fName >> sName >> tName >> mwanainchiAccountPassword >> securityCode >> accountNumber >> dateOfBirth >> kraPin >> phoneNumber >> fDeposit >> loanAmmount) 
    {
        if (accountNumber == ::accountNumber) 
        {
            outFile << fName << "\t" << sName << "\t" << tName << "\t" << mwanainchiAccountPassword << "\t"
                     << securityCode << "\t" << accountNumber << "\t" << dateOfBirth << "\t" << kraPin << "\t"
                     << phoneNumber << "\t" << fDeposit << "\t" << newBalance << "\t";
                     
                    
        } 
        else 
        {
            outFile << fName << "\t" << sName << "\t" << tName << "\t" << mwanainchiAccountPassword << "\t"
                     << securityCode << "\t" << accountNumber << "\t" << dateOfBirth << "\t" << kraPin << "\t"
                     << phoneNumber << "\t" << fDeposit << "\t" << loanAmmount << "\t";
        }
    }

    inFile.close();
    outFile.close();

    remove("mwanainchi_accounts.txt");
    rename("temp_mwanainchi_accounts.txt", "mwanainchi_accounts.txt");

    std::cout<< "Repayement successful. New balance: $" << newBalance << "\n";
	 
	recordTransaction("Repay loan" , amount , accountNumber );

	mwanainchiAccountDetails();
    mwanainchiAccountActions();

}

void applyLoan()
{

	int amount;
    double newBalance = 0;

    std::cout<< "Your current balance is: $" << loanAmmount << endl;
    std::cout<< "Welcome, " << logedInCustomer << "\nHow much loan do you want: $";
    cin >> amount;

    if (amount <= 0 && loanAmmount > 0) 
    {
        std::cout<< "Failed loan cannot be less or equal 0.\n";
        mwanainchiAccountActions();
        return;
    }

    newBalance = loanAmmount + amount;
	

    ifstream inFile("mwanainchi_accounts.txt");
    ofstream outFile("temp_mwanainchi_accounts.txt");

    if (!inFile || !outFile) 
    {
        std::cout<< "Error: Unable to open files for loan.\n";
        return;
    }

    while (inFile >> fName >> sName >> tName >> mwanainchiAccountPassword >> securityCode >> accountNumber >> dateOfBirth >> kraPin >> phoneNumber >> fDeposit >> loanAmmount) 
    {
        if (accountNumber == ::accountNumber) 
        {
            outFile << fName << "\t" << sName << "\t" << tName << "\t" << mwanainchiAccountPassword << "\t"
                     << securityCode << "\t" << accountNumber << "\t" << dateOfBirth << "\t" << kraPin << "\t"
                     << phoneNumber << "\t" << fDeposit << "\t" << newBalance << "\t";
                     
                     
        } 
        else 
        {
            outFile << fName << "\t" << sName << "\t" << tName << "\t" << mwanainchiAccountPassword << "\t"
                     << securityCode << "\t" << accountNumber << "\t" << dateOfBirth << "\t" << kraPin << "\t"
                     << phoneNumber << "\t" << fDeposit << "\t" << loanAmmount << "\t";
        }
    }

    inFile.close();
    outFile.close();

    remove("mwanainchi_accounts.txt");
    rename("temp_mwanainchi_accounts.txt", "mwanainchi_accounts.txt");

    std::cout<< "loan successful. New balance: $" << newBalance << "\n";

	recordTransaction("Loan" , amount , accountNumber );
	mwanainchiAccountDetails();
    mwanainchiAccountActions();
	
}

void applyCustomerCnDCard(){
	
	  if (!isLoggedIn) {
        std::cout<< "You must be logged in to apply for a credit or debit card.\n";
        return;
    }
	
	customerMenu();
}

void withdrawMoney()
{
   int amount;
    double newBalance = 0;

    std::cout<< "Your current balance is: $" << fDeposit << endl;
    std::cout<< "Welcome, " << logedInCustomer << "\nHow much do you want to withdraw: $";
    cin >> amount;

    if (amount <= 0 || amount > fDeposit) 
    {
        std::cout<< "Transaction failed!!!.\n";
        mwanainchiAccountActions();
        return;
    }

    newBalance = fDeposit - amount;

    ifstream inFile("mwanainchi_accounts.txt");
    ofstream outFile("temp_mwanainchi_accounts.txt");

    if (!inFile || !outFile) 
    {
        std::cout<< "Error: Unable to open files for withdrawal.\n";
        return;
    }

    while (inFile >> fName >> sName >> tName >> mwanainchiAccountPassword >> securityCode >> accountNumber >> dateOfBirth >> kraPin >> phoneNumber >> fDeposit >> loanAmmount) 
    {
        if (accountNumber == ::accountNumber) 
        {
            outFile << fName << "\t" << sName << "\t" << tName << "\t" << mwanainchiAccountPassword << "\t"
                     << securityCode << "\t" << accountNumber << "\t" << dateOfBirth << "\t" << kraPin << "\t"
                     << phoneNumber << "\t" << newBalance << "\t" << loanAmmount << "\t";
                     
                    
        } 
        else 
        {
            outFile << fName << "\t" << sName << "\t" << tName << "\t" << mwanainchiAccountPassword << "\t"
                     << securityCode << "\t" << accountNumber << "\t" << dateOfBirth << "\t" << kraPin << "\t"
                     << phoneNumber << "\t" << fDeposit << "\t" << loanAmmount << "\t";
        }
    }

    inFile.close();
    outFile.close();

    remove("mwanainchi_accounts.txt");
    rename("temp_mwanainchi_accounts.txt", "mwanainchi_accounts.txt");

    std::cout<< "withdrawal successful. New balance: $" << newBalance << "\n";
	 
	recordTransaction("Withdrawal" , amount , accountNumber );
	mwanainchiAccountDetails();
    mwanainchiAccountActions();
}



void depositMoney() 
{
    int amount;
    double newBalance = 0;

    std::cout<< "Your current balance is: $" << fDeposit << endl;
    std::cout<< "Welcome, " << logedInCustomer << "\nHow much do you want to deposit: $";
    cin >> amount;

    if (amount <= 0) 
    {
        std::cout<< "Failed deposit cannot be less or equal 0.\n";
        mwanainchiAccountActions();
        return;
    }

    newBalance = fDeposit + amount;
	

    ifstream inFile("mwanainchi_accounts.txt");
    ofstream outFile("temp_mwanainchi_accounts.txt");

    if (!inFile || !outFile) 
    {
        std::cout<< "Error: Unable to open files for deposit.\n";
        return;
    }

    while (inFile >> fName >> sName >> tName >> mwanainchiAccountPassword >> securityCode >> accountNumber >> dateOfBirth >> kraPin >> phoneNumber >> fDeposit >> loanAmmount) 
    {
        if (accountNumber == ::accountNumber) 
        {
            outFile << fName << "\t" << sName << "\t" << tName << "\t" << mwanainchiAccountPassword << "\t"
                     << securityCode << "\t" << accountNumber << "\t" << dateOfBirth << "\t" << kraPin << "\t"
                     << phoneNumber << "\t" << newBalance << "\t" << loanAmmount << "\t";
                     
                     
        } 
        else 
        {
            outFile << fName << "\t" << sName << "\t" << tName << "\t" << mwanainchiAccountPassword << "\t"
                     << securityCode << "\t" << accountNumber << "\t" << dateOfBirth << "\t" << kraPin << "\t"
                     << phoneNumber << "\t" << fDeposit << "\t" << loanAmmount << "\t";
        }
    }

    inFile.close();
    outFile.close();

    remove("mwanainchi_accounts.txt");
    rename("temp_mwanainchi_accounts.txt", "mwanainchi_accounts.txt");

    std::cout<< "Deposit successful. New balance: $" << newBalance << "\n";
	
	recordTransaction("Deposit" , amount , accountNumber );
	mwanainchiAccountDetails();
    mwanainchiAccountActions();
}



void lockAndSavingsAccountActions()
{
	   
	   std::cout<< "HURRAY !!" << endl;
	   customerMenu();
	   
	   	
};



void mwanainchiAccountDetails(){	
	
	ifstream file("mwanainchi_accounts.txt");
	while (file >> fName >>  sName >> tName >> mwanainchiAccountPassword >> securityCode >> accountNumber >> dateOfBirth >> kraPin >> phoneNumber >> fDeposit >> loanAmmount)
	{
		if(accountNumber == accountNumber)
	    std::cout<< "\t\t\t**************************  WELCOME   *****************************\n"<< endl;
		std::cout<< "\t\t\t**********************Personal details*****************************" << endl;
	  	std::cout<< "\t\t\tFirst name	: " << fName << endl;
		std::cout<< "\t\t\tSecond name	: " << sName << endl;
		std::cout<< "\t\t\tThird name	: " << tName << endl;
		std::cout<< "\t\t\tAccount number	: " << accountNumber << endl;
		std::cout<< "\t\t\tDate of birth	: " << dateOfBirth << endl;
		std::cout<< "\t\t\tKra pin		:" << kraPin << endl;
		std::cout<< "\t\t\tPhone number	: " << phoneNumber << endl;		
		std::cout<< "\t\t\tCurrent ballance : " << fDeposit << endl;
		std::cout<< "\t\t\tLoan ballance :" << loanAmmount << endl;
		std::cout<< "\n\n" << endl;
	}
	file.close();
	
	
	
};


int main()
{

    
    mainMenu();


    return 0;
}