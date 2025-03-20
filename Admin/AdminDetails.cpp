#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;

class AdminDetails{
private:
    string Name;
    string Email;
    string Password;
public:
    static unordered_map<string, AdminDetails*> AdminuserMap;
    AdminDetails(string Name, string Email, string Password){
        this->Name = Name;
        this->Email = Email;
        this->Password = Password;
    }

    void Setname(string Name){
        this->Name = Name;
    }

    void SetEmail(string Email){
        this->Email = Email;
    }

    string getDetails(){
        return "{\nName: " + this->Name + "\nEmail: "+ this->Email+"\n}";
    }

    string getPassword(){
        return Password;
    }
    string getName(){
        return Name;
    }

};