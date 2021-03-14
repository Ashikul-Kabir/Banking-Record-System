#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

bool checkUniqueUser(string accountNum)
{
    fstream dataFile("register.txt");
    string line;
    while (getline(dataFile, line))
    {
        stringstream ssin(line);
        while (ssin.good())
        {
            string tmp;
            ssin >> tmp;
            if (tmp == accountNum)
            {
                return false;
            }
        }
    }
    return true;
}

string validateLogin(string accountNo, string password)
{
    string acc, p, type;
    fstream dataFile("register.txt");
    string line;
    while (getline(dataFile, line))
    {
        stringstream ssin(line);
        while (ssin.good())
        {
            ssin >> acc;
            if (acc == accountNo)
            {
                ssin >> p;
                ssin >> type;
                if (p == password)
                    return type;
                else
                    return "none";
            }
            else
                break;
        }
    }
    return "none";
}

class Account
{
public:
    string accNo;
    Account(string accountNumber)
    {
        accNo = accountNumber;
    }

    void showInfo()
    {

        fstream dataFile("register.txt");
        string line;
        while (getline(dataFile, line))
        {
            stringstream ssin(line);
            while (ssin.good())
            {
                string accNo, tmp, fname, lname, b;
                double balance;
                ssin >> accNo;
                if (accNo == this->accNo)
                {
                    ssin >> tmp;
                    ssin >> tmp;
                    ssin >> fname;
                    ssin >> lname;
                    ssin >> b;
                    balance = atof(b.c_str());
                    cout << accNo << " " << fname << " " << lname << " " << balance << endl;
                }
                else
                    break;
            }
        }
    }

    void withdraw()
    {
        cout << "Put withdraw amount: ";
        double wa;
        cin >> wa;
        fstream dataFile("register.txt");
        fstream tmpFile("tmp.txt", ios::app);
        string line;
        while (getline(dataFile, line))
        {
            stringstream ssin(line);
            while (ssin.good())
            {
                string accNo, p, t, f, l, b;
                ssin >> accNo;
                ssin >> p;
                ssin >> t;
                ssin >> f;
                ssin >> l;
                ssin >> b;
                double balance = atof(b.c_str());
                if (accNo == this->accNo)
                {
                    if (balance < wa)
                    {
                        cout << "Not enough balance!\n";
                        dataFile.close();
                        return;
                    }
                    balance = balance - wa;
                }
                tmpFile << accNo << " " << p << " " << t << " " << f << " " << l << " " << balance << endl;
            }
        }
        dataFile.close();
        tmpFile.close();
        remove("register.txt");
        rename("tmp.txt", "register.txt");
    }

    void search()
    {
        string searchKey;
        cout << "Enter account number to search: ";
        cin >> searchKey;
        fstream dataFile("register.txt");
        string line;
        while (getline(dataFile, line))
        {
            stringstream ssin(line);
            while (ssin.good())
            {
                string accNo, tp, fname, lname, tmp, balance;
                ssin >> accNo;
                if (accNo == searchKey)
                {
                    ssin >> tmp;
                    ssin >> tp;
                    ssin >> fname;
                    ssin >> lname;
                    ssin >> balance;
                    double bal = atof(balance.c_str());
                    cout << accNo << " " << fname << " " << lname << " " << bal << endl;
                }
                else
                {
                    break;
                }
            }
        }
    }

    void update()
    {
        double amt;
        cout << "Put amount of balance you want to add: ";
        cin >> amt;
        fstream dataFile("register.txt");
        fstream tmpFile("tmp.txt", ios::app);
        string line;
        while (getline(dataFile, line))
        {
            stringstream ssin(line);
            string accNo, p, t, f, l, b;
            double balance;
            while (ssin.good())
            {
                ssin >> accNo;
                ssin >> p;
                ssin >> t;
                ssin >> f;
                ssin >> l;
                ssin >> b;
                balance = atof(b.c_str());
                if (accNo == this->accNo)
                {
                    balance += amt;
                }
                tmpFile << accNo << " " << p << " " << t << " " << f << " " << l << " " << balance << endl;
            }
        }
        dataFile.close();
        tmpFile.close();
        rename("tmp.txt", "register.txt");
    }

    void deleteInfo()
    {
        string accNo;
        cout << "Put account number you want to delete: ";
        cin >> accNo;
        fstream dataFile("register.txt");
        fstream tmpFile("tmp.txt", ios::app);
        string line;
        while (getline(dataFile, line))
        {
            stringstream ssin(line);
            string a, p, t, f, l, b;
            double balance;
            while (ssin.good())
            {
                ssin >> a;
                ssin >> p;
                ssin >> t;
                ssin >> f;
                ssin >> l;
                ssin >> b;
                balance = atof(b.c_str());
                if (a == accNo)
                {
                    cout << "Entry deleted!\n";
                }
                else
                {
                    tmpFile << a << " " << p << " " << t << " " << f << " " << l << " " << balance << endl;
                }
            }
        }
        dataFile.close();
        tmpFile.close();
        remove("register.txt");
        rename("tmp.txt", "register.txt");
    }
};

void showCustomerMenu(string accNo)
{
    Account a(accNo);
    while (true)
    {
        cout << "\n--->>> Customer Panel <<<---\n";
        cout << "1. View account information.\n";
        cout << "2. Withdraw cash amount.\n";
        cout << "3. Search information.\n";
        cout << "4. Update account information.\n";
        cout << "5. Delete account\n";
        cout << "6. Exit\n";
        cout << "\nChoose an option: ";
        int choice;
        cin >> choice;

        switch (choice)
        {
        case 1:
            a.showInfo();
            break;
        case 2:
            a.withdraw();
            break;
        case 3:
            a.search();
            break;
        case 4:
            a.update();
            break;
        case 5:
            a.deleteInfo();
            break;
        case 6:
            cout << "Signing out!\n";
            return;

        default:
            cout << "Please choose a valid option.\n";
            break;
        }
    }
}

void entry(char ch)
{
    string accNo, p, type;
    if (ch == 'L' || ch == 'l')
    {
        cout << "---|Login|---\n";
        cout << "Enter Account Number: ";
        cin >> accNo;
        cout << "\nEnter Password: ";
        cin >> p;
        string userType = validateLogin(accNo, p);
        if (userType == "customer")
        {
            showCustomerMenu(accNo);
        }
        // else if (userType == 'admin') {
        //     showAdminMenu();
        // }
        else
        {
            cout << "Login failed!\n";
            return;
        }
    }
    else if (ch == 'S' || ch == 's')
    {
        string accNo, fname, lname, p, confirmPass;
        const string type = "customer";
        const double balance = 0;
        cout << "---|Signup|---\n";
        cout << "Enter First Name: ";
        cin >> fname;
        cout << "\nEnter Last Name:  ";
        cin >> lname;
        cout << "\nEnter Account Number: ";
        cin >> accNo;
        cout << "\nEnter Password: ";
        cin >> p;
        cout << "\nEnter Confirm Password: ";
        cin >> confirmPass;

        if (!checkUniqueUser(accNo))
        {
            cout << "Account number already exists! Please enter a valid one." << endl;
            return;
        }

        if (p != confirmPass)
        {
            cout << "Passwords did not match.\n";
            return;
        }

        fstream Register("register.txt", ios::app);
        Register << accNo << " " << p << " " << type << " " << fname << " " << lname << " " << balance << endl;
        Register.close();
    }
    else
    {
        cout << "Invalid Input!\n";
    }
}

int main()
{
    char ch;
    while (true)
    {
        cout << "\n***** Welcome to SAM Banking Management System *****\n";
        cout << "----------------------------------------------------\n";

        cout << "Press: \nL to Login\nS to Signup\nQ to exit\n";
        cin >> ch;
        if (ch == 'Q' || ch == 'q')
        {
            return 0;
        }
        entry(ch);
    }

    return 0;
}