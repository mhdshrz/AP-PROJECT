#include <iostream>
#include <conio.h>
#include <string>
#include <fstream>
#include <QList>
#include <set>

using namespace std;








//////prototypes/////////////////////////////////////////////////////////////////////////


class up;

class up_s;

class foodstuff;

void print_menu (QList<up_s>&, QList<foodstuff>&);

void show (QList<foodstuff>&);
//show the whole products

void show (string, QList<foodstuff>&);
//show the whole products within a group

void print_products_out (char, QList<foodstuff>&);

int lar (char, QList<up_s>&);
//0: not successful
//1: successful as a customer
//2: successful as an admin
//3: !EXCEPTION!

string :: size_type digit_cnt (int);


//////prototypes end/////////////////////////////////////////////////////////////////////







//////class foodstuff interface//////////////////////////////////////////////////////////////


class foodstuff {

    private:

        string name, type, group, producer;
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

    public:

        up ();

        void set_username (string);

        void set_password (string);

        string get_username ();

        string get_password ();

};


//////class up, implementation///////////////////////////////////////////////////


up :: up () {

    this->username = '\0';

    this->password = '\0';

}

void up :: set_username (string username) {

    this->username = username;

    return;

}

void up ::set_password (string password) {

    this->password = password;

    return;

}

string up :: get_username () {

    return this->username;

}

string up :: get_password () {

    return this->password;

}


//////class up ends///////////////////////////////////////////////////////////////////////




//////class up_s, interface//////////////////////////////////////////////////////////////////////////


class up_s : public up {

    private:

        bool admin_check;

    public:

        up_s ();

        void set_admin_check (bool);

        bool get_admin_check ();

};


//////class up_s, implementation////////////////////////////////////////////////////////////////////


up_s :: up_s () {


    this->admin_check = false;

}

void up_s :: set_admin_check (bool admin_check) {

    this->admin_check = admin_check;

    return;

}


bool up_s :: get_admin_check () {

    return this->admin_check;

}


//////class up_s ends/////////////////////////////////////////////////////////////////////////////////




//////main function///////////////////////////////////////////////////////////////////////


int main () {

    QList<up_s> larlist;
    QList<foodstuff> prodlist;

    foodstuff fstemp;

    ifstream rfile;
    rfile.open("E:\\C++ Programs\\PROJECT\\products_list.txt", ios :: in);

    if(rfile.is_open()) {

        string stemp;
        int itemp;

        while(!rfile.eof()) {

            getline(rfile, stemp);
            fstemp.set_name(stemp);
            getline(rfile, stemp);
            fstemp.set_type(stemp);
            getline(rfile, stemp);
            fstemp.set_group(stemp);
            getline(rfile, stemp);
            fstemp.set_producer(stemp);

            rfile >> itemp;
            fstemp.set_price(itemp);
            rfile >> itemp;
            fstemp.set_quantity(itemp);

            prodlist.push_front(fstemp);

            rfile.get();

        }

//        int x = 1;

//        for(auto i = prodlist.begin(); i != prodlist.end(); i++) {

//            cout << x << ". " << i->get_name() << ' ' << i->get_type() << ' ' << i->get_group() << ' ';
//            cout << i->get_producer() << ' ' << i->get_price() << ' ' << i->get_quantity() << ' ' << endl;

//            x++;
//        }

        cout << endl << "Files were opened successfully!" << endl << endl;
        cout << "Press Enter to continue: ";

        cin.get();

        system("cls");

        //files end

        print_menu(larlist, prodlist);

    }

    else cout << "Files had problems being opened :(" << endl << endl;

    return 0;

}


//////main function ends///////////////////////////////////////////////////////////////////




//////print_menu function//////////////////////////////////////////////////////////////////


void print_menu (QList<up_s>& larlist, QList<foodstuff>& prodlist) {

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

        while(true) {

            system("cls");

            cout << "\n\n\n\n    1. Show All Products\n\n";
            cout << "\t2. Show All from a Group\n\n";
            cout << "\t    3. Back\n\n";
            cout << "\t\t4. Exit\n\n";
            cout << "\t\t    Enter One of Above Numbers: ";

            char cha;

            cha = getch();

            if(cha == '1') {

                print_products_out(cha, prodlist);

            }

            else if(cha == '2') {

                print_products_out(cha, prodlist);

            }

            else if(cha == '3') {

                system("cls");

                break;

            }

            else if(cha == '4') {

                system("cls");

                cout << "\n\n\n\n\n\n\n\n------------------------------!Thanks for ";
                cout << "Passing By!------------------------------\n\n\n\n\n\n\n";

                exit(0);

            }

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




//////show function (1 parameter)///////////////////////////////////////////////////////////////////////////


void show (QList<foodstuff>& prodlist) {

    int x = 1;

    cout << endl << "All Products:\n\n";

    cout << "\tName:\t\t\t\t    Type:\t       Group:\t\t   Producer:     Price:     Quantity:\n\n\n";

    for(QList<foodstuff> :: iterator itr = prodlist.begin(); itr != prodlist.end(); itr++) {

        if(x < 10) {

            cout << "    0" << x << ". " << itr->get_name();

            for(string :: size_type i = 0; i < 35 - itr->get_name().size(); i++) cout << ' ';

            cout << ' ' << itr->get_type();

            for(string :: size_type i = 0; i < 18 - itr->get_type().size(); i++) cout << ' ';

            cout << ' ' << itr->get_group();

            for(string :: size_type i = 0; i < 19 - itr->get_group().size(); i++) cout << ' ';

            cout << ' ' << itr->get_producer();

            for(string :: size_type i = 0; i < 13 - itr->get_producer().size(); i++) cout << ' ';

            cout << ' ' << itr->get_price() << " T";

            for(string :: size_type i = 0; i < 8 - digit_cnt(itr->get_price()); i++) cout << ' ';

            cout << ' ' << itr->get_quantity() << ' ' << endl;

            cout << "    -----------------------------------------------------";
            cout << "-------------------------------------------------------\n";

            x++;

        }

        else {

            cout << "    " << x << ". " << itr->get_name();

            for(string :: size_type i = 0; i < 35 - itr->get_name().size(); i++) cout << ' ';

            cout << ' ' << itr->get_type();

            for(string :: size_type i = 0; i < 18 - itr->get_type().size(); i++) cout << ' ';

            cout << ' ' << itr->get_group();

            for(string :: size_type i = 0; i < 19 - itr->get_group().size(); i++) cout << ' ';

            cout << ' ' << itr->get_producer();

            for(string :: size_type i = 0; i < 13 - itr->get_producer().size(); i++) cout << ' ';

            cout << ' ' << itr->get_price() << " T";

            for(string :: size_type i = 0; i < 8 - digit_cnt(itr->get_price()); i++) cout << ' ';

            cout << ' ' << itr->get_quantity() << ' ' << endl;

            cout << "    -----------------------------------------------------";
            cout << "-------------------------------------------------------\n";

            x++;

        }

    }

    return;

}


//////show function (1 parameter) ends////////////////////////////////////////////////////////////////////////




//////show function (2 parameters)//////////////////////////////////////////////////////////////


void show (string group, QList<foodstuff>& prodlist) {

    int x = 1;

    cout << endl << "All Products from \"" << group << "\" group:\n\n";

    cout << "\tName:\t\t\t\t    Type:\t       Group:\t\t   Producer:     Price:     Quantity:\n\n\n";

    for(QList<foodstuff> :: iterator itr = prodlist.begin(); itr != prodlist.end(); itr++) {

        if(itr->get_group() == group) {

            if(x < 10) {

                cout << "    0" << x << ". " << itr->get_name();

                for(string :: size_type i = 0; i < 35 - itr->get_name().size(); i++) cout << ' ';

                cout << ' ' << itr->get_type();

                for(string :: size_type i = 0; i < 18 - itr->get_type().size(); i++) cout << ' ';

                cout << ' ' << itr->get_group();

                for(string :: size_type i = 0; i < 19 - itr->get_group().size(); i++) cout << ' ';

                cout << ' ' << itr->get_producer();

                for(string :: size_type i = 0; i < 13 - itr->get_producer().size(); i++) cout << ' ';

                cout << ' ' << itr->get_price() << " T";

                for(string :: size_type i = 0; i < 8 - digit_cnt(itr->get_price()); i++) cout << ' ';

                cout << ' ' << itr->get_quantity() << ' ' << endl;

                cout << "    -----------------------------------------------------";
                cout << "-------------------------------------------------------\n";

                x++;

            }

            else {

                cout << "    " << x << ". " << itr->get_name();

                for(string :: size_type i = 0; i < 35 - itr->get_name().size(); i++) cout << ' ';

                cout << ' ' << itr->get_type();

                for(string :: size_type i = 0; i < 18 - itr->get_type().size(); i++) cout << ' ';

                cout << ' ' << itr->get_group();

                for(string :: size_type i = 0; i < 19 - itr->get_group().size(); i++) cout << ' ';

                cout << ' ' << itr->get_producer();

                for(string :: size_type i = 0; i < 13 - itr->get_producer().size(); i++) cout << ' ';

                cout << ' ' << itr->get_price() << " T";

                for(string :: size_type i = 0; i < 8 - digit_cnt(itr->get_price()); i++) cout << ' ';

                cout << ' ' << itr->get_quantity() << ' ' << endl;

                cout << "    -----------------------------------------------------";
                cout << "-------------------------------------------------------\n";

                x++;

            }

        }

    }

    return;

}


//////show function (2 parameters) ends///////////////////////////////////////////////////////////////////




//////print_products_out function/////////////////////////////////////////////////////////////////


void print_products_out (char ch, QList<foodstuff>& prodlist) {

    if(ch == '1') {

        system("cls");

        show(prodlist);

        cout << "\n\n    1.Search\n\n    2.Back\n\n    3.Exit\n\n";
        cout << "    Enter one of above numbers: ";

        cin.get();

    }
    else if(ch == '2') {

        set<string> gl;

        for(QList<foodstuff> :: iterator itr = prodlist.begin(); itr != prodlist.end(); itr++) gl.insert(itr->get_group());

        system("cls");

        cout <<"\nThese are all groups listed:\n\n";

        int x = 1;

        for(set<string> :: iterator itr = gl.begin(); itr != gl.end(); itr++) {

            if(x < 10) {

                cout << "    0" << x << ". " << *itr << endl;
                cout << "    --------------------------------------\n";

                x++;

            }

            else {

                cout << "    " << x << *itr << endl;
                cout << "    --------------------------------------\n";

                x++;

            }

        }

        cout << "\n\n\nEnter the number before the wanted group: ";

        char cha;

        cha = getch();

        x = (int) (cha-48);

        set<string> :: iterator itr;
        itr = gl.begin();

        for(int i = 0; i < x-1; i++) itr++;

        system("cls");

        show(*itr, prodlist);

        cout << "\n\n    1.Search\n\n    2.Back\n\n    3.Exit\n\n";
        cout << "    Enter one of above numbers: ";

        cin.get();

    }

    return;

}


//////print_products_out function ends////////////////////////////////////////////////////////////




//////digit_cnt function//////////////////////////////////////////////////////////////////////////


string :: size_type digit_cnt (int nmbr) {

    string :: size_type ans;

    ans = 0;

    while(nmbr != 0) {

        nmbr /= 10;

        ans += 1;

    }

    return ans;

}


//////digit_cnt function ends///////////////////////////////////////////////////////////////////////




//////lar function////////////////////////////////////////////////////////////////////////////


//a function for registration and login (stands for login and registration)

int lar (char ch, QList<up_s>& larlist) {

    up_s uptemp;
    string uptemp_s;
    bool u_check = false, p_check = false;

    //Customer Login

    if(ch == '2') {

        system("cls");

        cout << "\n-------------------------------------Customer";
        cout << " Login--------------------------------------\n\n\n";

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

        QList<up_s> :: iterator i;

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

        else return 1;

    }

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

            QList<up_s> :: iterator i;

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

        return 1;

    }

    //Admins Login

    if(ch == '4') {

        system("cls");

        cout << "\n----------------------------------------Admins";
        cout << " Login--------------------------------------\n\n\n";

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

        QList<up_s> :: iterator i;

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

        else return 2;

    }

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

            QList<up_s> :: iterator i;

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

        return 2;

    }

    return 3;

}


////// lar function ends//////////////////////////////////////////////////////////////////////
