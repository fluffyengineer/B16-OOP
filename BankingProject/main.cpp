//
//  main.cpp
//  BankingProject
//
//  Created by Tom Rawlinson on 08/03/2016.
//  Copyright © 2016 Tom Rawlinson. All rights reserved.
//

#include<iostream>
#include<cstring>
#include<fstream> //ofstream
//#include<cctype>
#include<iomanip> //setw(int)
//#include<stdio.h>

using namespace std;

class account {
    
    
private:
    
    double value;
    int acctNumber;
    char acctName[50]; //E.g. Thomas Rawlinson (17 characters)
    char type; //Either Current (C) or Saving (S)
    
    
public:
    
    void createAcct();
    
    void showAcct() const;
    
    void modify();
    
    void deposit(double amount);
    
    void withdraw(double amount);
    
    void report() const; //Report in tabular format
    
    int getAcctNumber() const; //Function to return account number
    
    double getValue() const; //Function to return account value
    
    char getAcctType() const;
    

    
    
};

void account::createAcct(){
    double amount;
    
    cout << "Enter The Account Number: \n";
    cin >> acctNumber;
    cout << "Enter The Account Name: \n";
    cin.ignore();
    cin.getline(acctName,50);
    cout << "Enter The Account Type: \n";
    cin >> type;
    type = toupper(type);
    cout<< "Enter The Initial Amount: \n";
    cin>>amount;
    value = amount;
    cout << "Account Created...";
    cout<< acctName << "," <<acctNumber;
    
}

void account::showAcct() const {
    cout<<"\nAccount Number is :" << acctNumber;
    cout<<"\nAccount Name is :" << acctName;
    cout<<"\nType of account is : " << type;
    cout<<"\nBalance is : " << value;
    
    
}

void account::modify()
{
    cout<<"\nAccount No. : " << acctNumber;
    cout<<"\nModify Account Holder Name : ";
    cin.ignore();
    cin.getline(acctName,50);
    cout<<"\nModify Type of Account : ";
    cin>>type;
    type=toupper(type);
    cout<<"\nModify Balance amount : ";
    cin>>value;
}

void account::deposit(double amount){
    value = value + amount;
    cout << "New Value is : " << value << endl;
    
}

void account::withdraw(double amount){
    value = value - amount;
    cout << "New Value is : " << value << endl;
    
}

void account::report() const{
    
    cout<<acctNumber<<setw(10)<<" "<<acctName<<setw(10)<<" "<<type << setw(10) <<value<<endl;
}

int account::getAcctNumber() const {
    return acctNumber;
}

double account::getValue() const
{
        return value;
}

char account::getAcctType() const{
    return type;
}


void write_account();	//function to write record in binary file
void display_sp(int);	//function to display account details given by user
void modify_account(int);	//function to modify record of file
void delete_account(int);	//function to delete record of file
void display_all();		//function to display all account details
void deposit_withdraw(int, int); // function to desposit/withdraw amount for given account
void intro();	//introductory screen function






int main(int argc, const char * argv[]) {
    
    account myAccountSavings;
    
    account myAccountCurrent;
    
    account AccountInUse;
    
    int option;
        
    
        
        cout<< "Which Option? \n";
        cout << " 1 - Create Account \n";
        cout << " 2 - Deposit \n";
        cout << " 3 - Withdraw \n";
        cout << " 4 - Show Value \n ";
        cin >> option;
        
        if (option == 1){
            
            char type;
            
            cout << "Select Type (C/S) : \n";
            cin >> type;
            
            if( type == 'C') {
                cout << " - Current" << endl;
                myAccountCurrent.createAcct();
                AccountInUse = myAccountCurrent;
                
            }
            else if( type == 'S') {
                cout << " - Savings" << endl;
                myAccountSavings.createAcct();
                AccountInUse = myAccountSavings;
            };
            

            
        }
        
        else if (option == 2){
            

            
        }

    
    
    
    return 0;
}

void writeaccount(){
    account myAccount;
    ofstream outputFile;
    
    outputFile.open("account.dat", ios::binary|ios::app);
    myAccount.createAcct();
    
    outputFile.write(reinterpret_cast<char *> (&myAccount), sizeof(account));
    outputFile.close();
};

void display_sp(int n)
{
    account ac;
    bool flag=false;
    ifstream inFile;
    inFile.open("account.dat",ios::binary);
    if(!inFile)
    {
        cout<<"File could not be open !! Press any Key...";
        return;
    }
    cout<<"\nBALANCE DETAILS\n";
    
    while(inFile.read(reinterpret_cast<char *> (&ac), sizeof(account)))
    {
        if(ac.getAcctNumber()==n)
        {
            ac.showAcct();
            flag=true;
        }
    }
    inFile.close();
    if(flag==false)
        cout<<"\n\nAccount number does not exist";
}

void modify_account(int){
    
}



