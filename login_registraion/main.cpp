#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool IsLoggedIn()
{
    string username, password, un, pw;

    cout << "Enter Username: "; cin >> username;
    cout << "Enter Password: "; cin >> password;

    ifstream read("/home/sonai/cpp/fun_projects/login_registraion/username_list/" + username + ".txt");
    getline(read, un);
    getline(read, pw);

    if (un == username && pw == password)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    int choice;
    
    cout << "1. Register\n2: Login\nyour choice: "; cin >> choice;
    if (choice == 1)
    {
        string username, password;

        cout << "select a username: "; cin >> username;
        cout << "select a password: "; cin >> password;

        ofstream file;
        file.open("/home/sonai/cpp/fun_projects/login_registraion/username_list/"+ username+".txt");
        file << username << endl << password;
        file.close();


        main();

    }
    else if(choice==2)
    {
        bool status = IsLoggedIn();

        if(!status)
        {
            cout << "False Login!" << endl;
            system("PAUSE");
            return 0;
        }
        else
        {
            cout << "Successfully logged in!" << endl;
            system("PAUSE");
            return 1;
        }
    }
}