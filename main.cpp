#include <iostream>
#include <fstream>
using namespace std;
class temp
{
    string username, email, password;
    string searchname, searchpass, searchemail;
    fstream file;

public:
    void login();
    void signup();
    void forgot();
    string getHiddenPasswordSimple();
};
string temp:: getHiddenPasswordSimple() {
    string pass;
    system("stty -echo");
    getline(cin, pass);
    system("stty echo");
    cout << endl;
    return pass;
}

void temp::signup()
{
    cout << "\n Enter your user name :: ";
    getline(cin, username);
    cout << "\n enter you email :: ";
    getline(cin, email);
    cout << "\n Enter the password :: ";
    password=getHiddenPasswordSimple();
    file.open("loginData.txt", ios::out | ios::app);
    file << username << "*" << email << "*" << password << endl;
    file.close();
}
void temp::login()
{
    cout << "------------LOGIN---------" << endl;
    cout << "Enter the username ::" << endl;
    getline(cin, searchname);
    cout << "Enter the password ::" << endl;
    searchpass=getHiddenPasswordSimple() ;

    file.open("loginData.txt", ios::in);
    if (!file) {
        cout << "Could not open loginData.txt" << endl;
        return;
    }

    bool found = false;

    // Read each record (line) from the file
    while (getline(file, username, '*') &&
           getline(file, email, '*') &&
           getline(file, password, '\n')) {
            


        if (username == searchname) {
            found = true;
            if (password == searchpass) {
                cout << "\n\nAccount successfully logged in!";
                cout << "\nUsername :: " << username << endl;
                cout << "\nEmail    :: " << email << endl;
            } else {
                cout << "Password is incorrect." << endl;
            }
            break;  // stop after finding the username
        }
    }

    if (!found) {
        cout << "No account found with that username." << endl;
    }

    file.close();
}

void temp :: forgot()
{
    cout<<"Enter the username :: "<<endl;
    getline(cin,searchname);
    cout<<"Enter the Emai:: "<<endl;
    getline(cin,searchemail);
    file.open("loginData.txt",ios :: in);
    getline(file,username,'*');
    getline(file,email,'*');
    getline(file,password,'\n');
    while(!file.eof()){
        if(searchname==username){
            if(email==searchemail)
            {
                cout<<"Acoount found ";
                cout<<"Passord is ::"<<password<<endl;
            }
            else{
                cout<<"email not match";
            }
        }
        else{
            cout<<"Result not found";
        }
    }

} 

int main()
{
    temp obj;
    char choice;
    cout << "\n1. LOGIN";
cout << "\n2. SIGN-UP";
cout << "\n3. FORGET PASSWORD";
cout << "\n4. EXIT";
cout << "\n\nENTER YOUR CHOICE: ";
cin >> choice;
cin.ignore(); // to clear newline before getline()


    switch (choice)
    {
    case '1':

        obj.login();
        break;
    case '2':
        obj.signup();
        break;
    case '3':
    obj .forgot();

        break;
    case '4':
     return 0;

        break;

    default:
        cout << "\n Invalid function";
        break;
    }
    return 0;
}