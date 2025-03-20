#include<iostream>
#include "Admin/AdminDetails.cpp"
#include <unordered_map>
using namespace std;
unordered_map<string, AdminDetails*> AdminDetails::AdminuserMap;
int main(){

    while(true){
        string input;
        cout << "Select option:\n 1.Admin registration\n2.Admin login\n";
        cin >> input;
        if(input == "1"){
            string name;
            cout << "Enter the user name: ";
            cin >> name;
            string email = "";
            cout << "\nEnter the email: ";
            cin >> email;
            string password = "";
            cout << "\nEnter the password: ";
            cin >> password;
            AdminDetails* newAdmin = new AdminDetails(name, email, password);
            AdminDetails::AdminuserMap[email] = newAdmin;
            cout << "New Admin Added: "+newAdmin->getDetails() << endl; 
        }
        else if(input == "2"){
            string email;
            cout << "Enter email_id: ";
            cin >> email;
            if(AdminDetails::AdminuserMap[email]){
                AdminDetails* ref = AdminDetails::AdminuserMap[email];
                string password;
                retry:
                cout << "Enter your password: ";
                cin >> password;
                if(password == ref->getPassword()){
                    cout << "Welcome "<< ref->getName() <<". You're logged in..."<<endl;
                }else{
                    cout << "Wrong password..." << endl;
                    goto retry; 
                }
            }
        }
    }
}