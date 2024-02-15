/*
  Bomin Kim
  rec03_start.cpp
 */

// Provided
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

// Task 1
// Define an Account struct
struct Account{
  string name;
  int number;
};

// Task 2
// Define an Account class (use a different name than in Task 1)
class AccountClass { 
  friend ostream& operator<<(ostream& os, const AccountClass& ac); //private
public:
//constructor
  AccountClass(const string& iname, int inumber) : name(iname), number(inumber){};
//getters
  const string& getname() const; //& 넣는 이유?
  int getnum() const;
//inspector
  

private:
  string name;
  int number;

};


//getters function -2a
const string& AccountClass::getname() const{
  return name;
}
int AccountClass::getnum() const{ //얘는 리턴값에 const 필요없음
  return number;
}; 

//output operator -2b
/*ostream& operator<<(ostream& os, const AccountClass& ac){
  os << ac.getname() << "  " << ac.getnum();
  return os;
}
*/
//output operator -2c
ostream& operator<<(ostream& os, const AccountClass& ac){
  os << ac.name << "  " << ac.number;
  return os;
}




// Task 3
// Define an Account (use a different name than in Task 1&2) and
// Transaction classes
class Transaction{
  friend ostream& operator<<(ostream& os, const Transaction& ta);
public:
  Transaction(const string& itype, int iamount) : type(itype), amount(iamount){};
private:
  string type;
  int amount;
};

ostream& operator<< (ostream& os, const Transaction& ta){
  os << ta.type << ' ' << ta.amount;
  return os;
}

class AccountClass2 { 
  friend ostream& operator<< (ostream& os, const AccountClass2& ac2);
  public:
    AccountClass2(const string& iname, int inumber): name(iname), number(inumber){};
    void deposit(int amount){
      balance += amount;
      history.emplace_back("deposit", amount);
    }
    void withdraw(int amount){
      if (amount > balance){
        cout << "Account# " << number <<" has only " << balance << ". ";
        cout << "Insufficient for withdrawal of " << amount << endl;
      }else{
      balance -= amount;
      history.emplace_back("withdraw", amount);
      }

    }

  private:
    string name;
    int number;
    int balance = 0;
    vector <Transaction> history;
};

ostream& operator<< (ostream& os, const AccountClass2& ac2){
  os << ac2.name << " " << ac2.number << endl;
  for (const Transaction& ta: ac2.history){
    os << " " << ta << endl;
  }
  return os;
}




// Task 4
// Define an Account with a nested public Transaction class
// (use different names than in the previous Tasks)


class AccountClass3 { 

  friend ostream& operator<< (ostream& os, const AccountClass3& ac3);
  public:
    class Transaction3{
      friend ostream& operator<<(ostream& os, const Transaction3& ta);
    public:
      Transaction3(const string& itype, int iamount) : type(itype), amount(iamount){}
    private:
      string type;
      int amount;
    };
  public:
    AccountClass3(const string& iname, int inumber): name(iname), number(inumber){}
    
    void deposit(int amount){
      balance += amount;
      history.emplace_back("deposit", amount);
    }
    
    void withdraw(int amount){
      if (amount > balance){
        cout << "Account# " << number <<" has only " << balance << ". ";
        cout << "Insufficient for withdrawal of " << amount << endl;
      }else{
      balance -= amount;
      history.emplace_back("withdraw", amount);
      }
    }

  private:
    string name;
    int number;
    int balance = 0;
    vector <Transaction3> history;
};

ostream& operator<< (ostream& os, const AccountClass3::Transaction3& ta){
    os << ta.type << ' ' << ta.amount;
    return os;
  }

ostream& operator<< (ostream& os, const AccountClass3& ac3){
  os << ac3.name << " " << ac3.number << endl;
  for (const AccountClass3::Transaction3& ta: ac3.history){
    os << " " << ta << endl;
  }
  return os;
}




// Task 5
// Define an Account with a nested private Transaction class
// (use different names than in the previous Tasks)


int main() {

    // Task 1: account as struct
    //      1a
    cout << "Task1a:\n";
    ifstream ifs("accounts.txt"); 
    if(!ifs){
      cout << "failed to open file" << endl;
    }

    vector <Account> va;
    string name;
    int number;
    while(ifs >> name >> number){
      Account ac;
      ac.name = name;
      ac.number = number;
      va.push_back(ac);
    }
    ifs.close();

    for(const Account& v: va){ //const & 빼먹지 않기 !!
      cout << v.name << "  " << v.number << endl;
    }

    //      1b
    cout << "Task1b:\n";
    cout << "Filling vector of struct objects, using {} initialization:\n";
    va.clear();
    ifs.open("accounts.txt");
    if(!ifs){
      cout << "failed to open file" << endl;
    }

    while(ifs >> name >> number){
      Account ac{name, number};
      va.push_back(ac);
    }

    ifs.close();

    for(const Account& v: va){
      cout << v.name << "  " << v.number << endl;
    }


    //==================================
    // Task 2: account as class

    //      2a
    cout << "==============\n";
    cout << "\nTask2a:";
    cout << "\nFilling vector of class objects, using local class object:\n";

    ifs.open("accounts.txt");
    if(!ifs){
      cout << "failed to open file" << endl;
      exit(1);
    }

    vector <AccountClass> vac;
    while(ifs >> name >> number){
      AccountClass ac(name, number);
      vac.push_back(ac);
    }

    ifs.close();

    for(const AccountClass& v: vac){
      cout << v.getname() << "  " << v.getnum() <<endl;
    }

    //2b
    cout << "\nTask2b:\n";
    cout << "output using output operator with getters\n";

    for(const AccountClass& v: vac){
      cout << v << endl;
    }



    // 2 c
    cout << "\nTask2c:\n";
    cout << "output using output operator as friend without getters\n";
    for(const AccountClass& v: vac){
      cout << v << endl;
    }

    // 2d
    cout << "\nTask2d:\n";
    cout << "Filling vector of class objects, using temporary class object:\n";

    vac.clear();
    ifs.open("accounts.txt");
    if(!ifs){
      cout << "failed to open file" << endl;
      exit(1);
    }

    while(ifs >> name >> number){
      vac.push_back(AccountClass(name, number));
    }
    for(const AccountClass& v: vac){
      cout << v << endl;
    }
    ifs.close();
    
    //2e
    cout << "\nTask2e:\n";
    cout << "Filling vector of class objects, using emplace_back:\n";
    vac.clear();

    ifs.open("accounts.txt");
    if(!ifs){
      cout << "failed to open file" << endl;
      exit(1);
    }

    while(ifs >> name >> number){
      vac.emplace_back(name, number);
    }
    for(const AccountClass& v: vac){
      cout << v << endl;
    }
    ifs.close();
    
    cout << "==============\n";
    cout << "\nTask 3:\nAccounts and Transaction:\n";

    ifs.open("transactions.txt");
    if(!ifs){
      cout << "failed to open file" << endl;
      exit(1);
    }

    vector <AccountClass2> vac2;
    string command;
    while (ifs >> command){
      if(command == "Account"){
        string name;
        int number;
        ifs >> name >> number;
        vac2.emplace_back(name, number);

      }else if(command == "Deposit"){
        string number;
        int amount;
        ifs >> number >> amount;
        vac2.back().deposit(amount);

      }else if(command == "Withdraw"){
        string number;
        int amount;
        ifs >> number >> amount;
        vac2.back().withdraw(amount);

      }else{
        cout << "wrong command" <<endl;

      }
    }
    ifs.close();

    for(AccountClass2 v : vac2){
      cout << v << endl;
    }

    cout << "==============\n";
    cout << "\nTask 4:\nTransaction nested in public section of Account:\n";
    
    ifs.open("transactions.txt");
    if(!ifs){
      cout << "failed to open file" << endl;
      exit(1);
    }

    vector <AccountClass3> vac3;
    while (ifs >> command){
      if(command == "Account"){
        string name;
        int number;
        ifs >> name >> number;
        vac3.emplace_back(name, number);

      }else if(command == "Deposit"){
        string number;
        int amount;
        ifs >> number >> amount;
        vac3.back().deposit(amount);

      }else if(command == "Withdraw"){
        string number;
        int amount;
        ifs >> number >> amount;
        vac3.back().withdraw(amount);

      }else{
        cout << "wrong command" <<endl;

      }
    }
    
    for(AccountClass3 v : vac3){
      cout << v << endl;
    }

    cout << "==============\n";
    cout << "\nTask 5:\nTransaction nested in private section of Account:\n";

    
}
