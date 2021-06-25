#include <iostream>
#include <conio.h>
#include <string>
#include <fstream>
#include <QList>

using namespace std;






class up;
class foodstuff;
void print_menu (QList<up>&);
void print_products_out (char);
int lar (char, QList<up>&);







//////class foodstuff interface//////////////////////////////////////////////////////////////


class foodstuff {

    private:

        string name, type, producer, group;
        int price, quantity;

    public:

        foodstuff ();

        void set_name (string);

        void set_type (string);

        void set_producer (string);

        void set_group (string);

        void set_price (int);

        void set_quantity (int);

        string get_name ();

        string get_type ();

        string get_producer ();

        string get_group ();

        int get_price ();

        int get_quantity ();

};


//////class foodstuff implementation////////////////////////////////////////////////////////


foodstuff :: foodstuff () {

    this->quantity = 0;

    this->price = -1;

}

void foodstuff :: set_name (string name) {

    this->name = name;

    return;

}

void foodstuff :: set_type (string type) {

    this->type = type;

    return;

}

void foodstuff :: set_producer (string producer) {

    this->producer = producer;

    return;

}

void foodstuff :: set_group (string group) {

    this->group = group;

    return;

}

void foodstuff :: set_price (int price) {

    this-> price = price;

    return;

}

void foodstuff :: set_quantity (int quantity) {

    this->quantity = quantity;

    return;

}

string foodstuff :: get_name () {

    return this->name;

}

string foodstuff :: get_type () {

    return this->type;

}

string foodstuff :: get_producer () {

    return this->producer;

}

string foodstuff :: get_group () {

    return this->group;

}

int foodstuff :: get_price () {

    return this->price;

}

int foodstuff :: get_quantity () {

    return this->quantity;

}


//////class foodstuff ends//////////////////////////////////////////////////////////////////




//////class up, interface///////////////////////////////////////////////////////////////////


//class for registration (stands for username and password)
class up {

    private:

        string username, password;
        bool admin_check;

    public:

        up ();

        void set_username (string);

        void set_password (string);

        void set_admin_check (bool);

        string get_username ();

        string get_password ();

        bool get_admin_check ();

};


//////class up, implementation///////////////////////////////////////////////////


up :: up () {

    this->username = '\0';

    this->password = '\0';

    this->admin_check = false;

}

void up :: set_username (string username) {

    this->username = username;

    return;

}

void up ::set_password (string password) {

    this->password = password;

    return;

}

void up :: set_admin_check (bool admin_check) {

    this->admin_check = admin_check;

    return;

}

string up :: get_username () {

    return this->username;

}

string up :: get_password () {

    return this->password;

}

bool up :: get_admin_check () {

    return this->admin_check;

}


//////class up ends///////////////////////////////////////////////////////////////////////




//////main function///////////////////////////////////////////////////////////////////////


int main () {

    QList<up> larlist;

    up u;

    u.set_username("abcd");
    u.set_password("1234");
    u.set_admin_check(true);

    larlist.push_front(u);

    print_menu(larlist);

    return 0;

}


//////main function ends///////////////////////////////////////////////////////////////////




//////print_menu function//////////////////////////////////////////////////////////////////


void print_menu (QList<up>& larlist) {

    cout << "\n------------------------------!Welcome to My Supermarket!";
    cout << "------------------------------\n\n\n\n";
    cout << "    1. Check the Store\n\n";
    cout << "\t2. Customer Login\n\n";
    cout << "\t    3. Customer Registration\n\n";
    cout << "\t\t4. Admins Login\n\n";
    cout << "\t\t    5. Admins Registration\n\n";
    cout << "\t\t\t6. Exit\n\n";
    cout << "\t\t\t    Enter One of Above Numbers: ";

    char ch;

    ch = getch();

    if(ch == '1') {

        system("cls");

        cout << "\n\n\n\n    1. Show All Products\n\n";
        cout << "\t2. Show All from a Group\n\n";
        cout << "\t    3. Back\n\n";
        cout << "\t\t4. Exit\n\n";
        cout << "\t\t    Enter One of Above Numbers: ";

        ch = getch();

        if(ch == '1') {

            print_products_out(ch);

        }
        else if(ch == '2') {

            print_products_out(ch);

        }
        else if(ch == '3') {

            system("cls");

            print_menu(larlist);

        }
        else if(ch == '4') {

            system("cls");

            cout << "\n\n\n\n\n\n\n\n------------------------------!Thanks for ";
            cout << "Passing By!------------------------------\n\n\n\n\n\n\n";

        }

    }
    else if(ch == '2') {

        lar(ch, larlist);

    }
    else if(ch == '3') {

        lar(ch, larlist);

    }
    else if(ch == '4') {

        lar(ch, larlist);

    }
    else if(ch == '5') {

        lar(ch, larlist);

    }
    else if(ch == '6') {

        system("cls");

        cout << "\n\n\n\n\n\n\n\n------------------------------!Thanks for ";
        cout << "Passing By!------------------------------\n\n\n\n\n\n\n";

    }

    return;

}


//////print_menu function ends////////////////////////////////////////////////////////////////




//////print_products function/////////////////////////////////////////////////////////////////


void print_products_out (char ch) {

    if(ch == '1') {} //show all
    else if(ch == '2') {} //show all group

    return;

}


//////print_products function ends////////////////////////////////////////////////////////////




//////lar function////////////////////////////////////////////////////////////////////////////


//a function for registration and login (stands for login and registration)

int lar (char ch, QList<up>& larlist) {     //return values:
                                             //0: not successful
    up uptemp;                               //1: successful as a customer
    string uptemp_s;                         //2: successful as an admin
    bool u_check = false, p_check = false;

    //Customer Login

    if(ch == '2') {

        system("cls");

        cout << "\n-------------------------------------Customer";
        cout << " Login--------------------------------------\n\n\n";

        while(true) {

            while(true) {

                string :: size_type i = 0;

                cout << "\n    * Type Your Username and then Press Enter: ";

                getline(cin, uptemp_s);

                for(i = 0; i < uptemp_s.size(); i++) {

                    if(uptemp_s[i] == ' ') {

                        cout << "\n\t^ White Space Detected! Do Not Enter Any White Space Characters!\n\n\t    ";

                        break;

                    }

                }

                if(i == uptemp_s.size()) break;

            }

            //check if it exists

            QList<up> :: iterator i;

            for(i = larlist.begin(); i != larlist.end(); i++) {

                if(i->get_username() == uptemp_s) break;

            }

            if(i == larlist.end()) u_check = false;          //username doesn't exist --> F

            else if(i->get_admin_check()) u_check = false;   //username exists but is an admin's --> F

            else u_check = true;                             //username exists and is a customer's --> T

            cout << "\n    * Great! Now Your Password: ";

            getline(cin, uptemp_s);

            //check if true

            if(u_check == true) {

                if(i->get_password() == uptemp_s) p_check = true;        //password correct

                else p_check = false;                                   //password incorrect

            }

            else p_check = false;                     //username doesnt exist, no matter if password is correct

            if(!u_check || !p_check) {

                cout << "\n\t^ Your username or password is incorrect.";

                cin.get();

                return 0;

            }

            else break;

        }

    }

    return 1;

    //Customer Registration

    if(ch == '3') {

        system("cls");

        cout << "\n----------------------------------Customer";
        cout << " Registeration----------------------------------\n\n\n";

        while(true) {

            while(true) {

                cout << "\n    * Type Your Username and then Press Enter: ";

                string :: size_type i = 0;

                getline(cin, uptemp_s);

                for(i = 0; i < uptemp_s.size(); i++) {

                    if(uptemp_s[i] == ' ') {

                        cout << "\n\t^ White Space Detected! Do Not Enter Any White Space Characters!\n\n\t    ";

                        break;

                    }

                }

                if(i == uptemp_s.size()) break;

            }

            //check if it's unique

            QList<up> :: iterator i;

            for(i = larlist.begin(); i != larlist.end(); i++) {

                if(i->get_username() == uptemp_s) break;

            }

            if(i != larlist.end()) cout << "\n\t^ There is another account with this username!\n\n\t    ";

            else break;

        }

        uptemp.set_username(uptemp_s);

        cout << "\n    * Great! Now Your Password: ";

        getline(cin, uptemp_s);

        uptemp.set_password(uptemp_s);

        uptemp.set_admin_check(false);

        larlist.push_front(uptemp);

    }
    return 1;

    //Admins Login

    if(ch == '4') {

        system("cls");

        cout << "\n----------------------------------------Admins";
        cout << " Login--------------------------------------\n\n\n";

        while(true) {

            while(true) {

                string :: size_type i = 0;

                cout << "\n    * Type Your Username and then Press Enter: ";

                getline(cin, uptemp_s);

                for(i = 0; i < uptemp_s.size(); i++) {

                    if(uptemp_s[i] == ' ') {

                        cout << "\n\t^ White Space Detected! Do Not Enter Any White Space Characters!\n\n\t    ";

                        break;

                    }

                }

                if(i == uptemp_s.size()) break;

            }

            //check if it exists

            QList<up> :: iterator i;

            for(i = larlist.begin(); i != larlist.end(); i++) {

                if(i->get_username() == uptemp_s) break;

            }

            if(i == larlist.end()) u_check = false;          //username doesn't exist --> F

            else if(!i->get_admin_check()) u_check = false;   //username exists but is a customer's --> F

            else u_check = true;                             //username exists and is an admin's --> T

            cout << "\n    * Great! Now Your Password: ";

            getline(cin, uptemp_s);

            //check if true

            if(u_check == true) {

                if(i->get_password() == uptemp_s) p_check = true;        //password correct

                else p_check = false;                                   //password incorrect

            }

            else p_check = false;                     //username doesnt exist, no matter if password is correct

            if(!u_check || !p_check) {

                cout << "\n\t^ Your username or password is incorrect.";

                cin.get();

                return 0;

            }

            else break;

        }

    }

    return 2;

    //Admins Registeration

    if(ch == '5') {

        system("cls");

        cout << "\n-----------------------------------Admins";
        cout << " Registeration-----------------------------------\n\n\n\n";

        while(true) {

            while(true) {

                cout << "\n    * Type Your Username and then Press Enter: ";

                string :: size_type i = 0;

                getline(cin, uptemp_s);

                for(i = 0; i < uptemp_s.size(); i++) {

                    if(uptemp_s[i] == ' ') {

                        cout << "\n\t^ White Space Detected! Do Not Enter Any White Space Characters!\n\n\t    ";

                        break;

                    }

                }

                if(i == uptemp_s.size()) break;

            }

            //check if it's unique

            QList<up> :: iterator i;

            for(i = larlist.begin(); i != larlist.end(); i++) {

                if(i->get_username() == uptemp_s) break;

            }

            if(i != larlist.end()) cout << "\n\t^ There is another account with this username!\n\n\t    ";

            else break;

        }

        uptemp.set_username(uptemp_s);

        cout << "\n    * Great! Now Your Password: ";

        getline(cin, uptemp_s);

        uptemp.set_password(uptemp_s);

        uptemp.set_admin_check(true);

        larlist.push_front(uptemp);

    }

    return 2;

}


////// lar function ends//////////////////////////////////////////////////////////////////////
