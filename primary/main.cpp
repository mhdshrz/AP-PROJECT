#include <iostream>
#include <conio.h>
#include <string>
#include <fstream>
#include <list>
#include <set>

using namespace std;








//////prototypes/////////////////////////////////////////////////////////////////////////


class fslist;

class up;

class up_s;

class foodstuff;

void print_menu (list<up_s>&, fslist&);

void show (fslist&);
//show the whole products

void show (string, fslist&);
//show the whole products within a group

void print_products_out (char, fslist&, list<up_s>&);

int print_products_in (char, fslist&, list<up_s>&);

int lar (char, list<up_s>&);
//0: not successful
//1: successful as a customer
//2: successful as an admin
//3: !EXCEPTION!

string :: size_type digit_cnt (int);

void exit_m (list<up_s>&, fslist&);
//exit manually, exits manually and updates the program's needed files

void sortfslist (fslist&);

void search (fslist&, list<up_s>&);
//to search all while out of your account

void search (fslist&, string, list<up_s>&);
//to search within a group while out of your account

int search_in (fslist&, list<up_s>&);
//to search all while in your account

int search_in (fslist&, string, list<up_s>&);
//to search within a group while in your account

bool findsubstr (string, string);

void showfs (fslist&);

void showup (list<up_s>&);

void buy (fslist&);

void add (fslist&);

void edit (fslist&);

void fdelete (fslist&);


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

        bool operator > (foodstuff&);

        bool operator < (foodstuff&);

        bool operator == (foodstuff&);

        void operator = (foodstuff&);

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

bool foodstuff :: operator > (foodstuff& F) {

    if(this->type > F.type) return true;
    else if(this->type < F.type) return false;

    if(this->group > F.group) return true;
    else if(this->group < F.group) return false;

    if(this->producer > F.producer) return true;
    else if(this->producer < F.producer) return false;

    if(this->name > F.name) return true;
    else if(this->name < F.name) return false;

    if(this->price > F.price) return true;
    else if(this->price < F.price) return false;

    if(this->quantity > F.quantity) return true;
    else if(this->quantity < F.quantity) return false;

    return false;

}

bool foodstuff :: operator < (foodstuff& F) {

    if(this->type < F.type) return true;
    else if(this->type > F.type) return false;

    if(this->group < F.group) return true;
    else if(this->group > F.group) return false;

    if(this->producer < F.producer) return true;
    else if(this->producer > F.producer) return false;

    if(this->name < F.name) return true;
    else if(this->name > F.name) return false;

    if(this->price < F.price) return true;
    else if(this->price > F.price) return false;

    if(this->quantity < F.quantity) return true;
    else if(this->quantity > F.quantity) return false;

    return false;

}

bool foodstuff :: operator == (foodstuff& F) {

    if(this->type > F.type) return false;
    else if(this->type < F.type) return false;

    if(this->group > F.group) return false;
    else if(this->group < F.group) return false;

    if(this->producer > F.producer) return false;
    else if(this->producer < F.producer) return false;

    if(this->name > F.name) return false;
    else if(this->name < F.name) return false;

    if(this->price > F.price) return false;
    else if(this->price < F.price) return false;

    if(this->quantity > F.quantity) return false;
    else if(this->quantity < F.quantity) return false;

    return true;

}

void foodstuff :: operator = (foodstuff& F) {

    this->name = F.name;
    this->type = F.type;
    this->group = F.group;
    this->producer = F.producer;
    this->price = F.price;
    this->quantity = F.quantity;

    return;

}


//////class foodstuff ends//////////////////////////////////////////////////////////////////




//////class fslist, interface///////////////////////////////////////////////////////////////


class fslist : public list<foodstuff> {

    public:

        foodstuff& operator [] (int i) {

            list<foodstuff> :: iterator itr;
            itr = this->begin();

            for(int j = 0; j < i; j++) itr++;

            return *itr;

        }

};


//////class fslist ends////////////////////////////////////////////////////////////////////




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

    list<up_s> larlist;
    fslist prodlist;

    //products file stream

    ifstream rfile;

    rfile.open("E:\\C++ Programs\\PROJECT\\Files\\products_list.txt", ios :: in);

    if(rfile.is_open()) {

        foodstuff fstemp;

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

            rfile.get();

            prodlist.push_front(fstemp);

        }

        rfile.close();

        sortfslist(prodlist);

        cout << endl << "\n    Products file was opened successfully!\n\n\n\n";
        cout << "    Press enter to proceed: ";

        cin.get();

        system("cls");

    }

    else {

        cout << "\n\n    Products file was not found. So we are creating the products file ...\n\n\n\n";
        cout << "    Press enter to proceed: ";

        cin.get();

        fstream file;
        file.open("E:\\C++ Programs\\PROJECT\\Files\\products_list.txt", ios :: out);

        system("cls");

        if(file.is_open()) {

            cout << "\n\n    Products file was successfully created.\n\n\n\n";

            file.close();

            cout << "    Press enter to proceed: ";

            cin.get();

            system("cls");

        }

        else {

            cout << "\n\n    Sorry, we're having a problem...\n\n";

            exit(0);

        }

    }

    //usernames and passwords file streams

    ifstream rfile_up;

    rfile_up.open("E:\\C++ Programs\\PROJECT\\Files\\ups_list.txt", ios :: in | ios :: out);

    if(rfile_up.is_open()) {

        up_s uptemp;

        string stemp;
        bool btemp;

        while(!rfile_up.eof()) {

            getline(rfile_up, stemp);
            uptemp.set_username(stemp);
            getline(rfile_up, stemp);
            uptemp.set_password(stemp);

            rfile_up >> btemp;
            uptemp.set_admin_check(btemp);

            rfile_up.get();

            larlist.push_front(uptemp);

        }

        rfile_up.close();

        cout << endl << "\n    U&P file was opened successfully!\n\n\n\n";
        cout << "    Press enter to proceed: ";

        cin.get();

        system("cls");

    }

    else {

        cout << "\n\n    U&P file was not found. So we are creating the U&P file ...\n\n\n\n";
        cout << "    Press Enter to proceed: ";

        cin.get();

        fstream file_up;
        file_up.open("E:\\C++ Programs\\PROJECT\\Files\\ups_list.txt", ios :: out);

        system("cls");

        if(file_up.is_open()) {

            cout << "\n\n    U&P file was successfully created.\n\n\n\n";

            file_up.close();

            cout << "    Press enter to proceed: ";

            cin.get();

            system("cls");

        }

        else {

            cout << "\n\n    Sorry, we're having a problem...\n\n";

            exit(0);

        }

    }

    system("cls");

    cout << "\n\n    We're all set!\n\n\n\n";
    cout << "    Press enter to run the program: ";

    cin.get();

    //program starts

    system("cls");

    print_menu(larlist, prodlist);

    //program ends
    //updating the files

    ofstream ofile, ofile_up;

    ofile.open("E:\\C++ Programs\\PROJECT\\Files\\products_list.txt", ios :: out | ios :: trunc);
    ofile_up.open("E:\\C++ Programs\\PROJECT\\Files\\ups_list.txt", ios :: out | ios :: trunc);

    for(fslist :: iterator itr = prodlist.begin(); itr != prodlist.end(); itr++) {

        ofile << itr->get_name() << endl;
        ofile << itr->get_type() << endl;
        ofile << itr->get_group() << endl;
        ofile << itr->get_producer() << endl;
        ofile << itr->get_price() << endl;
        ofile << itr->get_quantity() << endl;

    }

    ofile.close();

    for(list<up_s> :: iterator itr = larlist.begin(); itr != larlist.end(); itr++) {

        ofile_up << itr->get_username() << endl;
        ofile_up << itr->get_password() << endl;
        ofile_up << itr->get_admin_check() << endl;

    }

    ofile_up.close();

    return 0;

}


//////main function ends///////////////////////////////////////////////////////////////////




//////print_menu function//////////////////////////////////////////////////////////////////


void print_menu (list<up_s>& larlist, fslist& prodlist) {

    while(true) {

        system("cls");

        cout << "\n------------------------------!Welcome to My Supermarket!";
        cout << "------------------------------\n\n\n\n";
        cout << "    1. Check the Store\n\n";
        cout << "\t2. Customer Login\n\n";
        cout << "\t    3. Customer Registration\n\n";
        cout << "\t\t4. Admins Login\n\n";
        cout << "\t\t    5. Admins Registration\n\n";
        cout << "\t\t\t6. Exit\n\n";
        cout << "\t\t\t    Enter one of above numbers: ";

        char ch;

        ch = getch();

        //check the store

        if(ch == '1') {

            char cha;

            while(true) {

                system("cls");

                cout << "\n\n\n\n    1. Show All Products\n\n";
                cout << "\t2. Show All from a Group\n\n";
                cout << "\t    3. Back\n\n";
                cout << "\t\t4. Exit\n\n";
                cout << "\t\t    Enter one of above numbers: ";

                cha = getch();

                if(cha == '1') {

                    print_products_out(cha, prodlist, larlist);

                }

                else if(cha == '2') {

                    print_products_out(cha, prodlist, larlist);

                }

                //back

                else if(cha == '3') {

                    system("cls");

                    break;

                }

                //exit

                else if(cha == '4') {

                    exit_m(larlist, prodlist);

                }

            }

        }

        //customer login

        else if(ch == '2') {

            int x1;

            x1 = lar(ch, larlist);

            if(x1 == 1) {

                char cha;

                while(true) {

                    system("cls");

                    cout << "\n\n\n\n    1. Show All Products\n\n";
                    cout << "\t2. Show All from a Group\n\n";
                    cout << "\t    3. Log out\n\n";
                    cout << "\t\t4. Exit\n\n";
                    cout << "\t\t    Enter one of above numbers: ";

                    cha = getch();

                    if(cha == '1') {

                        int x2;

                        x2 = print_products_in(cha, prodlist, larlist);

                        if(x2 == 1) break;

                    }

                    else if(cha == '2') {

                        int x2;

                        x2 = print_products_in(cha, prodlist, larlist);

                        if(x2 == 1) break;

                    }

                    //log out

                    else if(cha == '3') {

                        break;

                    }

                    //exit

                    else if(cha == '4') {

                        exit_m(larlist, prodlist);

                    }

                }

            }

        }

        //customer registration

        else if(ch == '3') {

            int x1;

            x1 = lar(ch, larlist);

            if(x1 == 1) {

                char cha;

                while(true) {

                    system("cls");

                    cout << "\n\n\n\n    1. Show All Products\n\n";
                    cout << "\t2. Show All from a Group\n\n";
                    cout << "\t    3. Log out\n\n";
                    cout << "\t\t4. Exit\n\n";
                    cout << "\t\t    Enter one of above numbers: ";

                    cha = getch();

                    if(cha == '1') {

                        int x2;

                        x2 = print_products_in(cha, prodlist, larlist);

                        if(x2 == 1) break;

                    }

                    else if(cha == '2') {

                        int x2;

                        x2 = print_products_in(cha, prodlist, larlist);

                        if(x2 == 1) break;

                    }

                    //log out

                    else if(cha == '3') {

                        break;

                    }

                    //exit

                    else if(cha == '4') {

                        exit_m(larlist, prodlist);

                    }

                }

            }

        }

        //admins login

        else if(ch == '4') {

            int x1;

            x1 = lar(ch, larlist);

            if(x1 == 2) {

                char cha;

                while(true) {

                    system("cls");

                    cout << "\n\n\n\n    1. Add\n\n";
                    cout << "\t2. Edit\n\n";
                    cout << "\t    3. Delete\n\n";
                    cout << "\t\t4. Log out\n\n";
                    cout << "\t\t    5.Exit\n\n";
                    cout << "\t\t\tEnter one of above numbers: ";

                    cha = getch();

                    //add

                    if(cha == '1') {

                        add(prodlist);

                    }

                    //edit

                    else if(cha == '2') {

                        edit (prodlist);

                    }

                    //delete

                    else if(cha == '3') {

                        fdelete(prodlist);

                    }

                    //log out

                    else if(cha == '4') {

                        break;

                    }

                    //exit

                    else if(cha == '5') {

                        exit_m(larlist, prodlist);

                    }

                }

            }

        }

        else if(ch == '5') {

            int x1;

            x1 = lar(ch, larlist);

            if(x1 == 2) {

                char cha;

                while(true) {

                    system("cls");

                    cout << "\n\n\n\n    1. Add\n\n";
                    cout << "\t2. Edit\n\n";
                    cout << "\t    3. Delete\n\n";
                    cout << "\t\t4. Log out\n\n";
                    cout << "\t\t    5.Exit\n\n";
                    cout << "\t\t\tEnter one of above numbers: ";

                    cha = getch();

                    //add

                    if(cha == '1') {

                        add(prodlist);

                    }

                    //edit

                    else if(cha == '2') {

                        edit (prodlist);

                    }

                    //delete

                    else if(cha == '3') {

                        fdelete(prodlist);

                    }

                    //log out

                    else if(cha == '4') {

                        break;

                    }

                    //exit

                    else if(cha == '5') {

                        exit_m(larlist, prodlist);

                    }

                }

            }

        }

        else if(ch == '6') {

            exit_m(larlist, prodlist);

        }

    }

    return;

}


//////print_menu function ends////////////////////////////////////////////////////////////////




//////show function (1 parameter)///////////////////////////////////////////////////////////////////////////


void show (fslist& prodlist) {

    fslist :: iterator itr1;

    while(true) {

        for(itr1 = prodlist.begin(); itr1 != prodlist.end(); itr1++) {

            if(itr1->get_name() == "") {

                break;

            }

        }

        if(itr1 == prodlist.end()) break;

        else prodlist.erase(itr1);

    }

    cout << endl << "All Products:\n\n";

    cout << "\tName:\t\t\t\t    Type:\t       Group:\t\t   Producer:     Price:     Quantity:\n\n\n";

    for(int j = 0; j < prodlist.size(); j++) {

        if(j < 9) {

            cout << "    0" << j + 1 << ". " << prodlist[j].get_name();

            for(string :: size_type i = 0; i < 35 - prodlist[j].get_name().size(); i++) cout << ' ';

            cout << ' ' << prodlist[j].get_type();

            for(string :: size_type i = 0; i < 18 - prodlist[j].get_type().size(); i++) cout << ' ';

            cout << ' ' << prodlist[j].get_group();

            for(string :: size_type i = 0; i < 19 - prodlist[j].get_group().size(); i++) cout << ' ';

            cout << ' ' << prodlist[j].get_producer();

            for(string :: size_type i = 0; i < 13 - prodlist[j].get_producer().size(); i++) cout << ' ';

            cout << ' ' << prodlist[j].get_price() << " T";

            for(string :: size_type i = 0; i < 8 - digit_cnt(prodlist[j].get_price()); i++) cout << ' ';

            cout << ' ' << prodlist[j].get_quantity() << ' ' << endl;

            cout << "    -----------------------------------------------------";
            cout << "-------------------------------------------------------\n";

        }

        else {

            cout << "    " << j + 1 << ". " << prodlist[j].get_name();

            for(string :: size_type i = 0; i < 35 - prodlist[j].get_name().size(); i++) cout << ' ';

            cout << ' ' << prodlist[j].get_type();

            for(string :: size_type i = 0; i < 18 - prodlist[j].get_type().size(); i++) cout << ' ';

            cout << ' ' << prodlist[j].get_group();

            for(string :: size_type i = 0; i < 19 - prodlist[j].get_group().size(); i++) cout << ' ';

            cout << ' ' << prodlist[j].get_producer();

            for(string :: size_type i = 0; i < 13 - prodlist[j].get_producer().size(); i++) cout << ' ';

            cout << ' ' << prodlist[j].get_price() << " T";

            for(string :: size_type i = 0; i < 8 - digit_cnt(prodlist[j].get_price()); i++) cout << ' ';

            cout << ' ' << prodlist[j].get_quantity() << ' ' << endl;

            cout << "    -----------------------------------------------------";
            cout << "-------------------------------------------------------\n";

        }

    }

    return;

}


//////show function (1 parameter) ends////////////////////////////////////////////////////////////////////////




//////show function (2 parameters)//////////////////////////////////////////////////////////////


void show (string group, fslist& prodlist) {

    fslist :: iterator itr1;

    while(true) {

        for(itr1 = prodlist.begin(); itr1 != prodlist.end(); itr1++) {

            if(itr1->get_name() == "") {

                break;

            }

        }

        if(itr1 == prodlist.end()) break;

        else prodlist.erase(itr1);

    }

    cout << endl << "All Products from \"" << group << "\" group:\n\n";

    cout << "\tName:\t\t\t\t    Type:\t       Group:\t\t   Producer:     Price:     Quantity:\n\n\n";

    for(int j = 0; j < prodlist.size(); j++) {

        if(prodlist[j].get_group() == group) {

            if(j < 9) {

                cout << "    0" << j + 1 << ". " << prodlist[j].get_name();

                for(string :: size_type i = 0; i < 35 - prodlist[j].get_name().size(); i++) cout << ' ';

                cout << ' ' << prodlist[j].get_type();

                for(string :: size_type i = 0; i < 18 - prodlist[j].get_type().size(); i++) cout << ' ';

                cout << ' ' << prodlist[j].get_group();

                for(string :: size_type i = 0; i < 19 - prodlist[j].get_group().size(); i++) cout << ' ';

                cout << ' ' << prodlist[j].get_producer();

                for(string :: size_type i = 0; i < 13 - prodlist[j].get_producer().size(); i++) cout << ' ';

                cout << ' ' << prodlist[j].get_price() << " T";

                for(string :: size_type i = 0; i < 8 - digit_cnt(prodlist[j].get_price()); i++) cout << ' ';

                cout << ' ' << prodlist[j].get_quantity() << ' ' << endl;

                cout << "    -----------------------------------------------------";
                cout << "-------------------------------------------------------\n";

            }

            else {

                cout << "    " << j + 1 << ". " << prodlist[j].get_name();

                for(string :: size_type i = 0; i < 35 - prodlist[j].get_name().size(); i++) cout << ' ';

                cout << ' ' << prodlist[j].get_type();

                for(string :: size_type i = 0; i < 18 - prodlist[j].get_type().size(); i++) cout << ' ';

                cout << ' ' << prodlist[j].get_group();

                for(string :: size_type i = 0; i < 19 - prodlist[j].get_group().size(); i++) cout << ' ';

                cout << ' ' << prodlist[j].get_producer();

                for(string :: size_type i = 0; i < 13 - prodlist[j].get_producer().size(); i++) cout << ' ';

                cout << ' ' << prodlist[j].get_price() << " T";

                for(string :: size_type i = 0; i < 8 - digit_cnt(prodlist[j].get_price()); i++) cout << ' ';

                cout << ' ' << prodlist[j].get_quantity() << ' ' << endl;

                cout << "    -----------------------------------------------------";
                cout << "-------------------------------------------------------\n";

            }

        }

    }

    return;

}


//////show function (2 parameters) ends///////////////////////////////////////////////////////////////////




//////print_products_out function/////////////////////////////////////////////////////////////////


void print_products_out (char ch, fslist& prodlist, list<up_s>& larlist) {

    //show the whole products

    if(ch == '1') {

        while(true) {

            system("cls");

            show(prodlist);

            cout << "\n\n    1.Search\n\n    2.Back\n\n    3.Exit\n\n";
            cout << "    Enter one of above numbers: ";

            char cha;

            cha = getch();

            if(cha == '1') {

                search(prodlist, larlist);

            }

            else if(cha == '2') {

                return;

            }

            else if(cha == '3') {

                exit_m(larlist, prodlist);

            }

        }

    }

    //show all within a group

    else if(ch == '2') {

        set<string> glist;

        for(fslist :: iterator itr = prodlist.begin(); itr != prodlist.end(); itr++) {

            glist.insert(itr->get_group());

        }

        while(true) {

            system("cls");

            cout <<"\nThese are all groups listed:\n\n";

            int x = 1, itr_cnt;

            set<string> :: iterator itr1;

            while(true) {

                for(itr1 = glist.begin(); itr1 != glist.end(); itr1++) {

                    if(*itr1 == "") {

                        break;

                    }

                }

                if(itr1 == glist.end()) break;

                else glist.erase(itr1);

            }

            for(set<string> :: iterator itr = glist.begin(); itr != glist.end(); itr++) {

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

            cout << endl << endl << "    " << x << ". Back\n\n\n";

            cout << "Enter the number before the wanted group: ";

            char cha;

            cha = getch();

            itr_cnt = (int) (cha-48);

            if(itr_cnt == x) break;

            set<string> :: iterator itr;

            while(true) {

                itr = glist.begin();

                for(int i = 0; i < itr_cnt - 1; i++) itr++;

                system("cls");

                //showing all from the specific group

                show(*itr, prodlist);

                cout << "\n\n    1.Search\n\n    2.Back\n\n    3.Exit\n\n";
                cout << "    Enter one of above numbers: ";

                cha = getch();

                if(cha == '1') {

                    search(prodlist, *itr, larlist);

                }

                else if(cha == '2') {

                    break;

                }

                else if(cha == '3') {

                    exit_m(larlist, prodlist);

                }

            }

        }

    }

    return;

}


//////print_products_out function ends////////////////////////////////////////////////////////////




//////print_products_in function//////////////////////////////////////////////////////////////////


int print_products_in (char ch, fslist& prodlist, list<up_s>& larlist) {

    //show the whole products

    if(ch == '1') {

        while(true) {

            system("cls");

            show(prodlist);

            cout << "\n\n    1.Buy\n\n    2.Search\n\n    3.Back\n\n    4.Log out\n\n    5.Exit\n\n";
            cout << "    Enter one of above numbers: ";

            char cha;

            cha = getch();

            //Buy

            if(cha == '1') {

                buy(prodlist);

            }

            //search

            else if(cha == '2') {

                int x;

                x = search_in(prodlist, larlist);

                if(x == 1) return 1;

            }

            //back

            else if(cha == '3') {

                return 0;

            }

            //log out

            else if(cha == '4') {

                return 1;

            }

            //exit

            else if(cha == '5') {

                exit_m(larlist, prodlist);

            }

        }

    }

    //show all within a group

    else if(ch == '2') {

        set<string> glist;

        for(fslist :: iterator itr = prodlist.begin(); itr != prodlist.end(); itr++) {

            glist.insert(itr->get_group());

        }

        while(true) {

            system("cls");

            cout <<"\nThese are all groups listed:\n\n";

            int x = 1, itr_cnt;

            set<string> :: iterator itr1;

            while(true) {

                for(itr1 = glist.begin(); itr1 != glist.end(); itr1++) {

                    if(*itr1 == "") {

                        break;

                    }

                }

                if(itr1 == glist.end()) break;

                else glist.erase(itr1);

            }

            for(set<string> :: iterator itr = glist.begin(); itr != glist.end(); itr++) {

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

            cout << endl << endl << "    " << x << ". Back\n\n\n";

            cout << "Enter the number before the wanted group: ";

            char cha;

            cha = getch();

            itr_cnt = (int) (cha-48);

            if(itr_cnt == x) break;

            set<string> :: iterator itr;

            while(true) {

                itr = glist.begin();

                for(int i = 0; i < itr_cnt - 1; i++) itr++;

                system("cls");

                //showing all from the specific group

                show(*itr, prodlist);

                cout << "\n\n    1.Buy\n\n    2.Search\n\n    3.Back\n\n    4.Log out\n\n    5.Exit\n\n";
                cout << "    Enter one of above numbers: ";

                cha = getch();

                //buy

                if(cha == '1') {

                    buy(prodlist);

                }

                //search

                else if(cha == '2') {

                    int xx;

                    xx = search_in(prodlist, *itr, larlist);

                    if(xx == 1) return 1;

                }

                //back

                else if(cha == '3') {

                    break;

                }

                //log out

                else if(cha == '4') {

                    return 1;

                }

                //exit

                else if(cha == '5') {

                    exit_m(larlist, prodlist);

                }

            }

        }

    }

    return 0;

}


//////print_products_in function ends/////////////////////////////////////////////////////////////




//////search function (2 parameters)/////////////////////////////////////////////////////////////////////////////


void search (fslist& prodlist, list<up_s>& larlist) {

    string search;
    char ch, ch_by_ch;

    while(true) {

        system("cls");

        cout << "\n    Based on:\n\n\t1. Name\n\n\t2. Type\n\n";
        cout << "\t3. Group\n\n\t4. Producer\n\n\t5. Price\n\n";
        cout << "\t6. Back\n\n\t7. Exit\n\n\tEnter one of above numbers: ";

        ch = getch();

        //search based on name

        if(ch == '1') {

            while(true) {

                system("cls");

                cout << "\n\n    (Search here) Enter: " << search;
                cout << "\n    ----------------------------------------------------";
                cout << "-------------------------------------------------------\n\n";

                for(int j = 0; j < prodlist.size(); j++) {

                    if(findsubstr(prodlist[j].get_name(), search)) {

                        if(j < 9) {

                            cout << "    0" << j + 1 << ". " << prodlist[j].get_name();

                            for(string :: size_type i = 0; i < 35 - prodlist[j].get_name().size(); i++) cout << ' ';

                            cout << ' ' << prodlist[j].get_type();

                            for(string :: size_type i = 0; i < 18 - prodlist[j].get_type().size(); i++) cout << ' ';

                            cout << ' ' << prodlist[j].get_group();

                            for(string :: size_type i = 0; i < 19 - prodlist[j].get_group().size(); i++) cout << ' ';

                            cout << ' ' << prodlist[j].get_producer();

                            for(string :: size_type i = 0; i < 13 - prodlist[j].get_producer().size(); i++) cout << ' ';

                            cout << ' ' << prodlist[j].get_price() << " T";

                            for(string :: size_type i = 0; i < 8 - digit_cnt(prodlist[j].get_price()); i++) cout << ' ';

                            cout << ' ' << prodlist[j].get_quantity() << ' ' << endl;

                            cout << "    -----------------------------------------------------";
                            cout << "-------------------------------------------------------\n";

                        }

                        else {

                            cout << "    " << j + 1 << ". " << prodlist[j].get_name();

                            for(string :: size_type i = 0; i < 35 - prodlist[j].get_name().size(); i++) cout << ' ';

                            cout << ' ' << prodlist[j].get_type();

                            for(string :: size_type i = 0; i < 18 - prodlist[j].get_type().size(); i++) cout << ' ';

                            cout << ' ' << prodlist[j].get_group();

                            for(string :: size_type i = 0; i < 19 - prodlist[j].get_group().size(); i++) cout << ' ';

                            cout << ' ' << prodlist[j].get_producer();

                            for(string :: size_type i = 0; i < 13 - prodlist[j].get_producer().size(); i++) cout << ' ';

                            cout << ' ' << prodlist[j].get_price() << " T";

                            for(string :: size_type i = 0; i < 8 - digit_cnt(prodlist[j].get_price()); i++) cout << ' ';

                            cout << ' ' << prodlist[j].get_quantity() << ' ' << endl;

                            cout << "    -----------------------------------------------------";
                            cout << "-------------------------------------------------------\n";


                        }

                    }

                }

                ch_by_ch = getch();

                if(ch_by_ch == '^') break;

                if(ch_by_ch == '*' && search != "") search.erase(search.size()-1);
                else if(ch_by_ch == '*' && search == "");
                else search += ch_by_ch;

            }

        }

        //search based on type

        else if(ch == '2') {

            while(true) {

                system("cls");

                cout << "\n\n    (Search here) Enter: " << search;
                cout << "\n    ----------------------------------------------------";
                cout << "-------------------------------------------------------\n\n";

                for(int j = 0; j < prodlist.size(); j++) {

                    if(findsubstr(prodlist[j].get_type(), search)) {

                        if(j < 9) {

                            cout << "    0" << j + 1 << ". " << prodlist[j].get_name();

                            for(string :: size_type i = 0; i < 35 - prodlist[j].get_name().size(); i++) cout << ' ';

                            cout << ' ' << prodlist[j].get_type();

                            for(string :: size_type i = 0; i < 18 - prodlist[j].get_type().size(); i++) cout << ' ';

                            cout << ' ' << prodlist[j].get_group();

                            for(string :: size_type i = 0; i < 19 - prodlist[j].get_group().size(); i++) cout << ' ';

                            cout << ' ' << prodlist[j].get_producer();

                            for(string :: size_type i = 0; i < 13 - prodlist[j].get_producer().size(); i++) cout << ' ';

                            cout << ' ' << prodlist[j].get_price() << " T";

                            for(string :: size_type i = 0; i < 8 - digit_cnt(prodlist[j].get_price()); i++) cout << ' ';

                            cout << ' ' << prodlist[j].get_quantity() << ' ' << endl;

                            cout << "    -----------------------------------------------------";
                            cout << "-------------------------------------------------------\n";

                        }

                        else {

                            cout << "    " << j + 1 << ". " << prodlist[j].get_name();

                            for(string :: size_type i = 0; i < 35 - prodlist[j].get_name().size(); i++) cout << ' ';

                            cout << ' ' << prodlist[j].get_type();

                            for(string :: size_type i = 0; i < 18 - prodlist[j].get_type().size(); i++) cout << ' ';

                            cout << ' ' << prodlist[j].get_group();

                            for(string :: size_type i = 0; i < 19 - prodlist[j].get_group().size(); i++) cout << ' ';

                            cout << ' ' << prodlist[j].get_producer();

                            for(string :: size_type i = 0; i < 13 - prodlist[j].get_producer().size(); i++) cout << ' ';

                            cout << ' ' << prodlist[j].get_price() << " T";

                            for(string :: size_type i = 0; i < 8 - digit_cnt(prodlist[j].get_price()); i++) cout << ' ';

                            cout << ' ' << prodlist[j].get_quantity() << ' ' << endl;

                            cout << "    -----------------------------------------------------";
                            cout << "-------------------------------------------------------\n";


                        }

                    }

                }

                ch_by_ch = getch();

                if(ch_by_ch == '^') break;

                if(ch_by_ch == '*' && search != "") search.erase(search.size()-1);
                else if(ch_by_ch == '*' && search == "");
                else search += ch_by_ch;

            }

        }

        //search based on group

        else if(ch == '3') {

            while(true) {

                system("cls");

                cout << "\n\n    (Search here) Enter: " << search;
                cout << "\n    ----------------------------------------------------";
                cout << "-------------------------------------------------------\n\n";

                for(int j = 0; j < prodlist.size(); j++) {

                    if(findsubstr(prodlist[j].get_group(), search)) {

                        if(j < 9) {

                            cout << "    0" << j + 1 << ". " << prodlist[j].get_name();

                            for(string :: size_type i = 0; i < 35 - prodlist[j].get_name().size(); i++) cout << ' ';

                            cout << ' ' << prodlist[j].get_type();

                            for(string :: size_type i = 0; i < 18 - prodlist[j].get_type().size(); i++) cout << ' ';

                            cout << ' ' << prodlist[j].get_group();

                            for(string :: size_type i = 0; i < 19 - prodlist[j].get_group().size(); i++) cout << ' ';

                            cout << ' ' << prodlist[j].get_producer();

                            for(string :: size_type i = 0; i < 13 - prodlist[j].get_producer().size(); i++) cout << ' ';

                            cout << ' ' << prodlist[j].get_price() << " T";

                            for(string :: size_type i = 0; i < 8 - digit_cnt(prodlist[j].get_price()); i++) cout << ' ';

                            cout << ' ' << prodlist[j].get_quantity() << ' ' << endl;

                            cout << "    -----------------------------------------------------";
                            cout << "-------------------------------------------------------\n";

                        }

                        else {

                            cout << "    " << j + 1 << ". " << prodlist[j].get_name();

                            for(string :: size_type i = 0; i < 35 - prodlist[j].get_name().size(); i++) cout << ' ';

                            cout << ' ' << prodlist[j].get_type();

                            for(string :: size_type i = 0; i < 18 - prodlist[j].get_type().size(); i++) cout << ' ';

                            cout << ' ' << prodlist[j].get_group();

                            for(string :: size_type i = 0; i < 19 - prodlist[j].get_group().size(); i++) cout << ' ';

                            cout << ' ' << prodlist[j].get_producer();

                            for(string :: size_type i = 0; i < 13 - prodlist[j].get_producer().size(); i++) cout << ' ';

                            cout << ' ' << prodlist[j].get_price() << " T";

                            for(string :: size_type i = 0; i < 8 - digit_cnt(prodlist[j].get_price()); i++) cout << ' ';

                            cout << ' ' << prodlist[j].get_quantity() << ' ' << endl;

                            cout << "    -----------------------------------------------------";
                            cout << "-------------------------------------------------------\n";


                        }

                    }

                }

                ch_by_ch = getch();

                if(ch_by_ch == '^') break;

                if(ch_by_ch == '*' && search != "") search.erase(search.size()-1);
                else if(ch_by_ch == '*' && search == "");
                else search += ch_by_ch;

            }

        }

        //search based on producer

        else if(ch == '4') {

            while(true) {

                system("cls");

                cout << "\n\n    (Search here) Enter: " << search;
                cout << "\n    ----------------------------------------------------";
                cout << "-------------------------------------------------------\n\n";

                for(int j = 0; j < prodlist.size(); j++) {

                    if(findsubstr(prodlist[j].get_producer(), search)) {

                        if(j < 9) {

                            cout << "    0" << j + 1 << ". " << prodlist[j].get_name();

                            for(string :: size_type i = 0; i < 35 - prodlist[j].get_name().size(); i++) cout << ' ';

                            cout << ' ' << prodlist[j].get_type();

                            for(string :: size_type i = 0; i < 18 - prodlist[j].get_type().size(); i++) cout << ' ';

                            cout << ' ' << prodlist[j].get_group();

                            for(string :: size_type i = 0; i < 19 - prodlist[j].get_group().size(); i++) cout << ' ';

                            cout << ' ' << prodlist[j].get_producer();

                            for(string :: size_type i = 0; i < 13 - prodlist[j].get_producer().size(); i++) cout << ' ';

                            cout << ' ' << prodlist[j].get_price() << " T";

                            for(string :: size_type i = 0; i < 8 - digit_cnt(prodlist[j].get_price()); i++) cout << ' ';

                            cout << ' ' << prodlist[j].get_quantity() << ' ' << endl;

                            cout << "    -----------------------------------------------------";
                            cout << "-------------------------------------------------------\n";

                        }

                        else {

                            cout << "    " << j + 1 << ". " << prodlist[j].get_name();

                            for(string :: size_type i = 0; i < 35 - prodlist[j].get_name().size(); i++) cout << ' ';

                            cout << ' ' << prodlist[j].get_type();

                            for(string :: size_type i = 0; i < 18 - prodlist[j].get_type().size(); i++) cout << ' ';

                            cout << ' ' << prodlist[j].get_group();

                            for(string :: size_type i = 0; i < 19 - prodlist[j].get_group().size(); i++) cout << ' ';

                            cout << ' ' << prodlist[j].get_producer();

                            for(string :: size_type i = 0; i < 13 - prodlist[j].get_producer().size(); i++) cout << ' ';

                            cout << ' ' << prodlist[j].get_price() << " T";

                            for(string :: size_type i = 0; i < 8 - digit_cnt(prodlist[j].get_price()); i++) cout << ' ';

                            cout << ' ' << prodlist[j].get_quantity() << ' ' << endl;

                            cout << "    -----------------------------------------------------";
                            cout << "-------------------------------------------------------\n";

                        }

                    }

                }

                ch_by_ch = getch();

                if(ch_by_ch == '^') break;

                if(ch_by_ch == '*' && search != "") search.erase(search.size()-1);
                else if(ch_by_ch == '*' && search == "");
                else search += ch_by_ch;

            }

        }

        //search based on price

        else if(ch == '5') {

            while(true) {

                system("cls");

                cout << "\n\n    (Search here) Enter: " << search;
                cout << "\n    ----------------------------------------------------";
                cout << "-------------------------------------------------------\n\n";

                string int_string;

                for(int j = 0; j < prodlist.size(); j++) {

                    int_string = to_string(prodlist[j].get_price());

                    if(findsubstr(int_string, search)) {

                        if(j < 9) {

                            cout << "    0" << j + 1 << ". " << prodlist[j].get_name();

                            for(string :: size_type i = 0; i < 35 - prodlist[j].get_name().size(); i++) cout << ' ';

                            cout << ' ' << prodlist[j].get_type();

                            for(string :: size_type i = 0; i < 18 - prodlist[j].get_type().size(); i++) cout << ' ';

                            cout << ' ' << prodlist[j].get_group();

                            for(string :: size_type i = 0; i < 19 - prodlist[j].get_group().size(); i++) cout << ' ';

                            cout << ' ' << prodlist[j].get_producer();

                            for(string :: size_type i = 0; i < 13 - prodlist[j].get_producer().size(); i++) cout << ' ';

                            cout << ' ' << prodlist[j].get_price() << " T";

                            for(string :: size_type i = 0; i < 8 - digit_cnt(prodlist[j].get_price()); i++) cout << ' ';

                            cout << ' ' << prodlist[j].get_quantity() << ' ' << endl;

                            cout << "    -----------------------------------------------------";
                            cout << "-------------------------------------------------------\n";

                        }

                        else {

                            cout << "    " << j + 1 << ". " << prodlist[j].get_name();

                            for(string :: size_type i = 0; i < 35 - prodlist[j].get_name().size(); i++) cout << ' ';

                            cout << ' ' << prodlist[j].get_type();

                            for(string :: size_type i = 0; i < 18 - prodlist[j].get_type().size(); i++) cout << ' ';

                            cout << ' ' << prodlist[j].get_group();

                            for(string :: size_type i = 0; i < 19 - prodlist[j].get_group().size(); i++) cout << ' ';

                            cout << ' ' << prodlist[j].get_producer();

                            for(string :: size_type i = 0; i < 13 - prodlist[j].get_producer().size(); i++) cout << ' ';

                            cout << ' ' << prodlist[j].get_price() << " T";

                            for(string :: size_type i = 0; i < 8 - digit_cnt(prodlist[j].get_price()); i++) cout << ' ';

                            cout << ' ' << prodlist[j].get_quantity() << ' ' << endl;

                            cout << "    -----------------------------------------------------";
                            cout << "-------------------------------------------------------\n";

                        }

                    }

                }

                ch_by_ch = getch();

                if(ch_by_ch == '^') break;

                if(ch_by_ch == '*' && search != "") search.erase(search.size()-1);
                else if(ch_by_ch == '*' && search == "");
                else search += ch_by_ch;

            }

        }

        //back

        else if(ch == '6') {

            return;

        }

        //exit

        else if(ch == '7') {

            exit_m(larlist, prodlist);

        }

    }

    return;

}


//////search function (2 parameters) ends////////////////////////////////////////////////////////////////////////




//////search function (3 parameters)////////////////////////////////////////////////////////////////////////////


void search (fslist& prodlist, string group, list<up_s>& larlist) {

    string search;
    char ch, ch_by_ch;

    while(true) {

        system("cls");

        cout << "\n    Based on:\n\n\t1. Name\n\n\t2. Type\n\n";
        cout << "\t3. Group\n\n\t4. Producer\n\n\t5. Price\n\n";
        cout << "\t6. Back\n\n\t7. Exit\n\n\tEnter one of above numbers: ";

        ch = getch();

        //search based on name

        if(ch == '1') {

            while(true) {

                system("cls");

                cout << "\n\n    (Search here) Enter: " << search;
                cout << "\n    ----------------------------------------------------";
                cout << "-------------------------------------------------------\n\n";

                for(int j = 0; j < prodlist.size(); j++) {

                    if(findsubstr(prodlist[j].get_name(), search) && prodlist[j].get_group() == group) {

                        if(j < 9) {

                            cout << "    0" << j + 1 << ". " << prodlist[j].get_name();

                            for(string :: size_type i = 0; i < 35 - prodlist[j].get_name().size(); i++) cout << ' ';

                            cout << ' ' << prodlist[j].get_type();

                            for(string :: size_type i = 0; i < 18 - prodlist[j].get_type().size(); i++) cout << ' ';

                            cout << ' ' << prodlist[j].get_group();

                            for(string :: size_type i = 0; i < 19 - prodlist[j].get_group().size(); i++) cout << ' ';

                            cout << ' ' << prodlist[j].get_producer();

                            for(string :: size_type i = 0; i < 13 - prodlist[j].get_producer().size(); i++) cout << ' ';

                            cout << ' ' << prodlist[j].get_price() << " T";

                            for(string :: size_type i = 0; i < 8 - digit_cnt(prodlist[j].get_price()); i++) cout << ' ';

                            cout << ' ' << prodlist[j].get_quantity() << ' ' << endl;

                            cout << "    -----------------------------------------------------";
                            cout << "-------------------------------------------------------\n ";

                        }

                        else {

                            cout << "    " << j + 1 << ". " << prodlist[j].get_name();

                            for(string :: size_type i = 0; i < 35 - prodlist[j].get_name().size(); i++) cout << ' ';

                            cout << ' ' << prodlist[j].get_type();

                            for(string :: size_type i = 0; i < 18 - prodlist[j].get_type().size(); i++) cout << ' ';

                            cout << ' ' << prodlist[j].get_group();

                            for(string :: size_type i = 0; i < 19 - prodlist[j].get_group().size(); i++) cout << ' ';

                            cout << ' ' << prodlist[j].get_producer();

                            for(string :: size_type i = 0; i < 13 - prodlist[j].get_producer().size(); i++) cout << ' ';

                            cout << ' ' << prodlist[j].get_price() << " T";

                            for(string :: size_type i = 0; i < 8 - digit_cnt(prodlist[j].get_price()); i++) cout << ' ';

                            cout << ' ' << prodlist[j].get_quantity() << ' ' << endl;

                            cout << "    -----------------------------------------------------";
                            cout << "-------------------------------------------------------\n";

                        }

                    }

                }

                ch_by_ch = getch();

                if(ch_by_ch == '^') break;

                if(ch_by_ch == '*' && search != "") search.erase(search.size()-1);
                else if(ch_by_ch == '*' && search == "");
                else search += ch_by_ch;

            }

        }

        //search based on type

        else if(ch == '2') {

            while(true) {

                system("cls");

                cout << "\n\n    (Search here) Enter: " << search;
                cout << "\n    ----------------------------------------------------";
                cout << "-------------------------------------------------------\n\n";

                for(int j = 0; j < prodlist.size(); j++) {

                    if(findsubstr(prodlist[j].get_type(), search) && prodlist[j].get_group() == group) {

                        if(j < 9) {

                            cout << "    0" << j + 1 << ". " << prodlist[j].get_name();

                            for(string :: size_type i = 0; i < 35 - prodlist[j].get_name().size(); i++) cout << ' ';

                            cout << ' ' << prodlist[j].get_type();

                            for(string :: size_type i = 0; i < 18 - prodlist[j].get_type().size(); i++) cout << ' ';

                            cout << ' ' << prodlist[j].get_group();

                            for(string :: size_type i = 0; i < 19 - prodlist[j].get_group().size(); i++) cout << ' ';

                            cout << ' ' << prodlist[j].get_producer();

                            for(string :: size_type i = 0; i < 13 - prodlist[j].get_producer().size(); i++) cout << ' ';

                            cout << ' ' << prodlist[j].get_price() << " T";

                            for(string :: size_type i = 0; i < 8 - digit_cnt(prodlist[j].get_price()); i++) cout << ' ';

                            cout << ' ' << prodlist[j].get_quantity() << ' ' << endl;

                            cout << "    -----------------------------------------------------";
                            cout << "-------------------------------------------------------\n";

                        }

                        else {

                            cout << "    " << j + 1 << ". " << prodlist[j].get_name();

                            for(string :: size_type i = 0; i < 35 - prodlist[j].get_name().size(); i++) cout << ' ';

                            cout << ' ' << prodlist[j].get_type();

                            for(string :: size_type i = 0; i < 18 - prodlist[j].get_type().size(); i++) cout << ' ';

                            cout << ' ' << prodlist[j].get_group();

                            for(string :: size_type i = 0; i < 19 - prodlist[j].get_group().size(); i++) cout << ' ';

                            cout << ' ' << prodlist[j].get_producer();

                            for(string :: size_type i = 0; i < 13 - prodlist[j].get_producer().size(); i++) cout << ' ';

                            cout << ' ' << prodlist[j].get_price() << " T";

                            for(string :: size_type i = 0; i < 8 - digit_cnt(prodlist[j].get_price()); i++) cout << ' ';

                            cout << ' ' << prodlist[j].get_quantity() << ' ' << endl;

                            cout << "    -----------------------------------------------------";
                            cout << "-------------------------------------------------------\n";


                        }

                    }

                }

                ch_by_ch = getch();

                if(ch_by_ch == '^') break;

                if(ch_by_ch == '*' && search != "") search.erase(search.size()-1);
                else if(ch_by_ch == '*' && search == "");
                else search += ch_by_ch;

            }

        }

        //search based on group

        else if(ch == '3') {

            while(true) {

                system("cls");

                cout << "\n\n    (Search here) Enter: " << search;
                cout << "\n    ----------------------------------------------------";
                cout << "-------------------------------------------------------\n\n";

                for(int j = 0; j < prodlist.size(); j++) {

                    if(findsubstr(prodlist[j].get_group(), search) && prodlist[j].get_group() == group) {

                        if(j < 9) {

                            cout << "    0" << j + 1 << ". " << prodlist[j].get_name();

                            for(string :: size_type i = 0; i < 35 - prodlist[j].get_name().size(); i++) cout << ' ';

                            cout << ' ' << prodlist[j].get_type();

                            for(string :: size_type i = 0; i < 18 - prodlist[j].get_type().size(); i++) cout << ' ';

                            cout << ' ' << prodlist[j].get_group();

                            for(string :: size_type i = 0; i < 19 - prodlist[j].get_group().size(); i++) cout << ' ';

                            cout << ' ' << prodlist[j].get_producer();

                            for(string :: size_type i = 0; i < 13 - prodlist[j].get_producer().size(); i++) cout << ' ';

                            cout << ' ' << prodlist[j].get_price() << " T";

                            for(string :: size_type i = 0; i < 8 - digit_cnt(prodlist[j].get_price()); i++) cout << ' ';

                            cout << ' ' << prodlist[j].get_quantity() << ' ' << endl;

                            cout << "    -----------------------------------------------------";
                            cout << "-------------------------------------------------------\n";

                        }

                        else {

                            cout << "    " << j + 1 << ". " << prodlist[j].get_name();

                            for(string :: size_type i = 0; i < 35 - prodlist[j].get_name().size(); i++) cout << ' ';

                            cout << ' ' << prodlist[j].get_type();

                            for(string :: size_type i = 0; i < 18 - prodlist[j].get_type().size(); i++) cout << ' ';

                            cout << ' ' << prodlist[j].get_group();

                            for(string :: size_type i = 0; i < 19 - prodlist[j].get_group().size(); i++) cout << ' ';

                            cout << ' ' << prodlist[j].get_producer();

                            for(string :: size_type i = 0; i < 13 - prodlist[j].get_producer().size(); i++) cout << ' ';

                            cout << ' ' << prodlist[j].get_price() << " T";

                            for(string :: size_type i = 0; i < 8 - digit_cnt(prodlist[j].get_price()); i++) cout << ' ';

                            cout << ' ' << prodlist[j].get_quantity() << ' ' << endl;

                            cout << "    -----------------------------------------------------";
                            cout << "-------------------------------------------------------\n";


                        }

                    }

                }

                ch_by_ch = getch();

                if(ch_by_ch == '^') break;

                if(ch_by_ch == '*' && search != "") search.erase(search.size()-1);
                else if(ch_by_ch == '*' && search == "");
                else search += ch_by_ch;

            }

        }

        //search based on producer

        else if(ch == '4') {

            while(true) {

                system("cls");

                cout << "\n\n    (Search here) Enter: " << search;
                cout << "\n    ----------------------------------------------------";
                cout << "-------------------------------------------------------\n\n";

                for(int j = 0; j < prodlist.size(); j++) {

                    if(findsubstr(prodlist[j].get_producer(), search) && prodlist[j].get_group() == group) {

                        if(j < 9) {

                            cout << "    0" << j + 1 << ". " << prodlist[j].get_name();

                            for(string :: size_type i = 0; i < 35 - prodlist[j].get_name().size(); i++) cout << ' ';

                            cout << ' ' << prodlist[j].get_type();

                            for(string :: size_type i = 0; i < 18 - prodlist[j].get_type().size(); i++) cout << ' ';

                            cout << ' ' << prodlist[j].get_group();

                            for(string :: size_type i = 0; i < 19 - prodlist[j].get_group().size(); i++) cout << ' ';

                            cout << ' ' << prodlist[j].get_producer();

                            for(string :: size_type i = 0; i < 13 - prodlist[j].get_producer().size(); i++) cout << ' ';

                            cout << ' ' << prodlist[j].get_price() << " T";

                            for(string :: size_type i = 0; i < 8 - digit_cnt(prodlist[j].get_price()); i++) cout << ' ';

                            cout << ' ' << prodlist[j].get_quantity() << ' ' << endl;

                            cout << "    -----------------------------------------------------";
                            cout << "-------------------------------------------------------\n";

                        }

                        else {

                            cout << "    " << j + 1 << ". " << prodlist[j].get_name();

                            for(string :: size_type i = 0; i < 35 - prodlist[j].get_name().size(); i++) cout << ' ';

                            cout << ' ' << prodlist[j].get_type();

                            for(string :: size_type i = 0; i < 18 - prodlist[j].get_type().size(); i++) cout << ' ';

                            cout << ' ' << prodlist[j].get_group();

                            for(string :: size_type i = 0; i < 19 - prodlist[j].get_group().size(); i++) cout << ' ';

                            cout << ' ' << prodlist[j].get_producer();

                            for(string :: size_type i = 0; i < 13 - prodlist[j].get_producer().size(); i++) cout << ' ';

                            cout << ' ' << prodlist[j].get_price() << " T";

                            for(string :: size_type i = 0; i < 8 - digit_cnt(prodlist[j].get_price()); i++) cout << ' ';

                            cout << ' ' << prodlist[j].get_quantity() << ' ' << endl;

                            cout << "    -----------------------------------------------------";
                            cout << "-------------------------------------------------------\n";

                        }

                    }

                }

                ch_by_ch = getch();

                if(ch_by_ch == '^') break;

                if(ch_by_ch == '*' && search != "") search.erase(search.size()-1);
                else if(ch_by_ch == '*' && search == "");
                else search += ch_by_ch;

            }

        }

        //search based on price

        else if(ch == '5') {

            while(true) {

                system("cls");

                cout << "\n\n    (Search here) Enter: " << search;
                cout << "\n    ----------------------------------------------------";
                cout << "-------------------------------------------------------\n\n";

                string int_string;

                for(int j = 0; j < prodlist.size(); j++) {

                    int_string = to_string(prodlist[j].get_price());

                    if(findsubstr(int_string, search) && prodlist[j].get_group() == group) {

                        if(j < 9) {

                            cout << "    0" << j + 1 << ". " << prodlist[j].get_name();

                            for(string :: size_type i = 0; i < 35 - prodlist[j].get_name().size(); i++) cout << ' ';

                            cout << ' ' << prodlist[j].get_type();

                            for(string :: size_type i = 0; i < 18 - prodlist[j].get_type().size(); i++) cout << ' ';

                            cout << ' ' << prodlist[j].get_group();

                            for(string :: size_type i = 0; i < 19 - prodlist[j].get_group().size(); i++) cout << ' ';

                            cout << ' ' << prodlist[j].get_producer();

                            for(string :: size_type i = 0; i < 13 - prodlist[j].get_producer().size(); i++) cout << ' ';

                            cout << ' ' << prodlist[j].get_price() << " T";

                            for(string :: size_type i = 0; i < 8 - digit_cnt(prodlist[j].get_price()); i++) cout << ' ';

                            cout << ' ' << prodlist[j].get_quantity() << ' ' << endl;

                            cout << "    -----------------------------------------------------";
                            cout << "-------------------------------------------------------\n";

                        }

                        else {

                            cout << "    " << j + 1 << ". " << prodlist[j].get_name();

                            for(string :: size_type i = 0; i < 35 - prodlist[j].get_name().size(); i++) cout << ' ';

                            cout << ' ' << prodlist[j].get_type();

                            for(string :: size_type i = 0; i < 18 - prodlist[j].get_type().size(); i++) cout << ' ';

                            cout << ' ' << prodlist[j].get_group();

                            for(string :: size_type i = 0; i < 19 - prodlist[j].get_group().size(); i++) cout << ' ';

                            cout << ' ' << prodlist[j].get_producer();

                            for(string :: size_type i = 0; i < 13 - prodlist[j].get_producer().size(); i++) cout << ' ';

                            cout << ' ' << prodlist[j].get_price() << " T";

                            for(string :: size_type i = 0; i < 8 - digit_cnt(prodlist[j].get_price()); i++) cout << ' ';

                            cout << ' ' << prodlist[j].get_quantity() << ' ' << endl;

                            cout << "    -----------------------------------------------------";
                            cout << "-------------------------------------------------------\n";

                        }

                    }

                }

                ch_by_ch = getch();

                if(ch_by_ch == '^') break;

                if(ch_by_ch == '*' && search != "") search.erase(search.size()-1);
                else if(ch_by_ch == '*' && search == "");
                else search += ch_by_ch;

            }

        }

        //back

        else if(ch == '6') {

            return;

        }

        //exit

        else if(ch == '7') {

            exit_m(larlist, prodlist);

        }

    }

    return;

}


//////search function (3 parameters) ends///////////////////////////////////////////////////////////////////////





//////search_in function (2  parameters)////////////////////////////////////////////////////////////////////////////////////////


//0 means just back, while 1 means logging out

int search_in (fslist& prodlist, list<up_s>& larlist) {

    string search;
    char ch, ch_by_ch;

    while(true) {

        system("cls");

        cout << "\n    Based on:\n\n\t1. Name\n\n\t2. Type\n\n";
        cout << "\t3. Group\n\n\t4. Producer\n\n\t5. Price\n\n";
        cout << "\t6. Back\n\n\t7. Log out\n\n\t8. Exit\n\n\tEnter one of above numbers: ";

        ch = getch();

        //search based on name

        if(ch == '1') {

            while(true) {

                system("cls");

                cout << "\n\n    (Search here) Enter: " << search;
                cout << "\n    ----------------------------------------------------";
                cout << "-------------------------------------------------------\n\n";

                for(int j = 0; j < prodlist.size(); j++) {

                    if(findsubstr(prodlist[j].get_name(), search)) {

                        if(j < 9) {

                            cout << "    0" << j + 1 << ". " << prodlist[j].get_name();

                            for(string :: size_type i = 0; i < 35 - prodlist[j].get_name().size(); i++) cout << ' ';

                            cout << ' ' << prodlist[j].get_type();

                            for(string :: size_type i = 0; i < 18 - prodlist[j].get_type().size(); i++) cout << ' ';

                            cout << ' ' << prodlist[j].get_group();

                            for(string :: size_type i = 0; i < 19 - prodlist[j].get_group().size(); i++) cout << ' ';

                            cout << ' ' << prodlist[j].get_producer();

                            for(string :: size_type i = 0; i < 13 - prodlist[j].get_producer().size(); i++) cout << ' ';

                            cout << ' ' << prodlist[j].get_price() << " T";

                            for(string :: size_type i = 0; i < 8 - digit_cnt(prodlist[j].get_price()); i++) cout << ' ';

                            cout << ' ' << prodlist[j].get_quantity() << ' ' << endl;

                            cout << "    -----------------------------------------------------";
                            cout << "-------------------------------------------------------\n";

                        }

                        else {

                            cout << "    " << j + 1 << ". " << prodlist[j].get_name();

                            for(string :: size_type i = 0; i < 35 - prodlist[j].get_name().size(); i++) cout << ' ';

                            cout << ' ' << prodlist[j].get_type();

                            for(string :: size_type i = 0; i < 18 - prodlist[j].get_type().size(); i++) cout << ' ';

                            cout << ' ' << prodlist[j].get_group();

                            for(string :: size_type i = 0; i < 19 - prodlist[j].get_group().size(); i++) cout << ' ';

                            cout << ' ' << prodlist[j].get_producer();

                            for(string :: size_type i = 0; i < 13 - prodlist[j].get_producer().size(); i++) cout << ' ';

                            cout << ' ' << prodlist[j].get_price() << " T";

                            for(string :: size_type i = 0; i < 8 - digit_cnt(prodlist[j].get_price()); i++) cout << ' ';

                            cout << ' ' << prodlist[j].get_quantity() << ' ' << endl;

                            cout << "    -----------------------------------------------------";
                            cout << "-------------------------------------------------------\n";


                        }

                    }

                }

                ch_by_ch = getch();

                if(ch_by_ch == '^') break;

                if(ch_by_ch == '*' && search != "") search.erase(search.size()-1);
                else if(ch_by_ch == '*' && search == "");
                else search += ch_by_ch;

            }

        }

        //search based on type

        else if(ch == '2') {

            while(true) {

                system("cls");

                cout << "\n\n    (Search here) Enter: " << search;
                cout << "\n    ----------------------------------------------------";
                cout << "-------------------------------------------------------\n\n";

                for(int j = 0; j < prodlist.size(); j++) {

                    if(findsubstr(prodlist[j].get_type(), search)) {

                        if(j < 9) {

                            cout << "    0" << j + 1 << ". " << prodlist[j].get_name();

                            for(string :: size_type i = 0; i < 35 - prodlist[j].get_name().size(); i++) cout << ' ';

                            cout << ' ' << prodlist[j].get_type();

                            for(string :: size_type i = 0; i < 18 - prodlist[j].get_type().size(); i++) cout << ' ';

                            cout << ' ' << prodlist[j].get_group();

                            for(string :: size_type i = 0; i < 19 - prodlist[j].get_group().size(); i++) cout << ' ';

                            cout << ' ' << prodlist[j].get_producer();

                            for(string :: size_type i = 0; i < 13 - prodlist[j].get_producer().size(); i++) cout << ' ';

                            cout << ' ' << prodlist[j].get_price() << " T";

                            for(string :: size_type i = 0; i < 8 - digit_cnt(prodlist[j].get_price()); i++) cout << ' ';

                            cout << ' ' << prodlist[j].get_quantity() << ' ' << endl;

                            cout << "    -----------------------------------------------------";
                            cout << "-------------------------------------------------------\n";

                        }

                        else {

                            cout << "    " << j + 1 << ". " << prodlist[j].get_name();

                            for(string :: size_type i = 0; i < 35 - prodlist[j].get_name().size(); i++) cout << ' ';

                            cout << ' ' << prodlist[j].get_type();

                            for(string :: size_type i = 0; i < 18 - prodlist[j].get_type().size(); i++) cout << ' ';

                            cout << ' ' << prodlist[j].get_group();

                            for(string :: size_type i = 0; i < 19 - prodlist[j].get_group().size(); i++) cout << ' ';

                            cout << ' ' << prodlist[j].get_producer();

                            for(string :: size_type i = 0; i < 13 - prodlist[j].get_producer().size(); i++) cout << ' ';

                            cout << ' ' << prodlist[j].get_price() << " T";

                            for(string :: size_type i = 0; i < 8 - digit_cnt(prodlist[j].get_price()); i++) cout << ' ';

                            cout << ' ' << prodlist[j].get_quantity() << ' ' << endl;

                            cout << "    -----------------------------------------------------";
                            cout << "-------------------------------------------------------\n";


                        }

                    }

                }

                ch_by_ch = getch();

                if(ch_by_ch == '^') break;

                if(ch_by_ch == '*' && search != "") search.erase(search.size()-1);
                else if(ch_by_ch == '*' && search == "");
                else search += ch_by_ch;

            }

        }

        //search based on group

        else if(ch == '3') {

            while(true) {

                system("cls");

                cout << "\n\n    (Search here) Enter: " << search;
                cout << "\n    ----------------------------------------------------";
                cout << "-------------------------------------------------------\n\n";

                for(int j = 0; j < prodlist.size(); j++) {

                    if(findsubstr(prodlist[j].get_group(), search)) {

                        if(j < 9) {

                            cout << "    0" << j + 1 << ". " << prodlist[j].get_name();

                            for(string :: size_type i = 0; i < 35 - prodlist[j].get_name().size(); i++) cout << ' ';

                            cout << ' ' << prodlist[j].get_type();

                            for(string :: size_type i = 0; i < 18 - prodlist[j].get_type().size(); i++) cout << ' ';

                            cout << ' ' << prodlist[j].get_group();

                            for(string :: size_type i = 0; i < 19 - prodlist[j].get_group().size(); i++) cout << ' ';

                            cout << ' ' << prodlist[j].get_producer();

                            for(string :: size_type i = 0; i < 13 - prodlist[j].get_producer().size(); i++) cout << ' ';

                            cout << ' ' << prodlist[j].get_price() << " T";

                            for(string :: size_type i = 0; i < 8 - digit_cnt(prodlist[j].get_price()); i++) cout << ' ';

                            cout << ' ' << prodlist[j].get_quantity() << ' ' << endl;

                            cout << "    -----------------------------------------------------";
                            cout << "-------------------------------------------------------\n";

                        }

                        else {

                            cout << "    " << j + 1 << ". " << prodlist[j].get_name();

                            for(string :: size_type i = 0; i < 35 - prodlist[j].get_name().size(); i++) cout << ' ';

                            cout << ' ' << prodlist[j].get_type();

                            for(string :: size_type i = 0; i < 18 - prodlist[j].get_type().size(); i++) cout << ' ';

                            cout << ' ' << prodlist[j].get_group();

                            for(string :: size_type i = 0; i < 19 - prodlist[j].get_group().size(); i++) cout << ' ';

                            cout << ' ' << prodlist[j].get_producer();

                            for(string :: size_type i = 0; i < 13 - prodlist[j].get_producer().size(); i++) cout << ' ';

                            cout << ' ' << prodlist[j].get_price() << " T";

                            for(string :: size_type i = 0; i < 8 - digit_cnt(prodlist[j].get_price()); i++) cout << ' ';

                            cout << ' ' << prodlist[j].get_quantity() << ' ' << endl;

                            cout << "    -----------------------------------------------------";
                            cout << "-------------------------------------------------------\n";


                        }

                    }

                }

                ch_by_ch = getch();

                if(ch_by_ch == '^') break;

                if(ch_by_ch == '*' && search != "") search.erase(search.size()-1);
                else if(ch_by_ch == '*' && search == "");
                else search += ch_by_ch;

            }

        }

        //search based on producer

        else if(ch == '4') {

            while(true) {

                system("cls");

                cout << "\n\n    (Search here) Enter: " << search;
                cout << "\n    ----------------------------------------------------";
                cout << "-------------------------------------------------------\n\n";

                for(int j = 0; j < prodlist.size(); j++) {

                    if(findsubstr(prodlist[j].get_producer(), search)) {

                        if(j < 9) {

                            cout << "    0" << j + 1 << ". " << prodlist[j].get_name();

                            for(string :: size_type i = 0; i < 35 - prodlist[j].get_name().size(); i++) cout << ' ';

                            cout << ' ' << prodlist[j].get_type();

                            for(string :: size_type i = 0; i < 18 - prodlist[j].get_type().size(); i++) cout << ' ';

                            cout << ' ' << prodlist[j].get_group();

                            for(string :: size_type i = 0; i < 19 - prodlist[j].get_group().size(); i++) cout << ' ';

                            cout << ' ' << prodlist[j].get_producer();

                            for(string :: size_type i = 0; i < 13 - prodlist[j].get_producer().size(); i++) cout << ' ';

                            cout << ' ' << prodlist[j].get_price() << " T";

                            for(string :: size_type i = 0; i < 8 - digit_cnt(prodlist[j].get_price()); i++) cout << ' ';

                            cout << ' ' << prodlist[j].get_quantity() << ' ' << endl;

                            cout << "    -----------------------------------------------------";
                            cout << "-------------------------------------------------------\n";

                        }

                        else {

                            cout << "    " << j + 1 << ". " << prodlist[j].get_name();

                            for(string :: size_type i = 0; i < 35 - prodlist[j].get_name().size(); i++) cout << ' ';

                            cout << ' ' << prodlist[j].get_type();

                            for(string :: size_type i = 0; i < 18 - prodlist[j].get_type().size(); i++) cout << ' ';

                            cout << ' ' << prodlist[j].get_group();

                            for(string :: size_type i = 0; i < 19 - prodlist[j].get_group().size(); i++) cout << ' ';

                            cout << ' ' << prodlist[j].get_producer();

                            for(string :: size_type i = 0; i < 13 - prodlist[j].get_producer().size(); i++) cout << ' ';

                            cout << ' ' << prodlist[j].get_price() << " T";

                            for(string :: size_type i = 0; i < 8 - digit_cnt(prodlist[j].get_price()); i++) cout << ' ';

                            cout << ' ' << prodlist[j].get_quantity() << ' ' << endl;

                            cout << "    -----------------------------------------------------";
                            cout << "-------------------------------------------------------\n";

                        }

                    }

                }

                ch_by_ch = getch();

                if(ch_by_ch == '^') break;

                if(ch_by_ch == '*' && search != "") search.erase(search.size()-1);
                else if(ch_by_ch == '*' && search == "");
                else search += ch_by_ch;

            }

        }

        //search based on price

        else if(ch == '5') {

            while(true) {

                system("cls");

                cout << "\n\n    (Search here) Enter: " << search;
                cout << "\n    ----------------------------------------------------";
                cout << "-------------------------------------------------------\n\n";

                string int_string;

                for(int j = 0; j < prodlist.size(); j++) {

                    int_string = to_string(prodlist[j].get_price());

                    if(findsubstr(int_string, search)) {

                        if(j < 9) {

                            cout << "    0" << j + 1 << ". " << prodlist[j].get_name();

                            for(string :: size_type i = 0; i < 35 - prodlist[j].get_name().size(); i++) cout << ' ';

                            cout << ' ' << prodlist[j].get_type();

                            for(string :: size_type i = 0; i < 18 - prodlist[j].get_type().size(); i++) cout << ' ';

                            cout << ' ' << prodlist[j].get_group();

                            for(string :: size_type i = 0; i < 19 - prodlist[j].get_group().size(); i++) cout << ' ';

                            cout << ' ' << prodlist[j].get_producer();

                            for(string :: size_type i = 0; i < 13 - prodlist[j].get_producer().size(); i++) cout << ' ';

                            cout << ' ' << prodlist[j].get_price() << " T";

                            for(string :: size_type i = 0; i < 8 - digit_cnt(prodlist[j].get_price()); i++) cout << ' ';

                            cout << ' ' << prodlist[j].get_quantity() << ' ' << endl;

                            cout << "    -----------------------------------------------------";
                            cout << "-------------------------------------------------------\n";

                        }

                        else {

                            cout << "    " << j + 1 << ". " << prodlist[j].get_name();

                            for(string :: size_type i = 0; i < 35 - prodlist[j].get_name().size(); i++) cout << ' ';

                            cout << ' ' << prodlist[j].get_type();

                            for(string :: size_type i = 0; i < 18 - prodlist[j].get_type().size(); i++) cout << ' ';

                            cout << ' ' << prodlist[j].get_group();

                            for(string :: size_type i = 0; i < 19 - prodlist[j].get_group().size(); i++) cout << ' ';

                            cout << ' ' << prodlist[j].get_producer();

                            for(string :: size_type i = 0; i < 13 - prodlist[j].get_producer().size(); i++) cout << ' ';

                            cout << ' ' << prodlist[j].get_price() << " T";

                            for(string :: size_type i = 0; i < 8 - digit_cnt(prodlist[j].get_price()); i++) cout << ' ';

                            cout << ' ' << prodlist[j].get_quantity() << ' ' << endl;

                            cout << "    -----------------------------------------------------";
                            cout << "-------------------------------------------------------\n";

                        }

                    }

                }

                ch_by_ch = getch();

                if(ch_by_ch == '^') break;

                if(ch_by_ch == '*' && search != "") search.erase(search.size()-1);
                else if(ch_by_ch == '*' && search == "");
                else search += ch_by_ch;

            }

        }

        //back

        else if(ch == '6') {

            return 0;

        }

        //log out

        else if(ch == '7') {

            return 1;

        }

        //exit

        else if(ch == '8') {

            exit_m(larlist, prodlist);

        }

    }

}


//////search_in function (2 parameters) ends///////////////////////////////////////////////////////////////////////////////////




//////search_in function (3 parameters)////////////////////////////////////////////////////////////////////////////////////////


//0 means just back, while 1 means logging out

int search_in (fslist& prodlist, string group, list<up_s>& larlist) {

    string search;
    char ch, ch_by_ch;

    while(true) {

        system("cls");

        cout << "\n    Based on:\n\n\t1. Name\n\n\t2. Type\n\n";
        cout << "\t3. Group\n\n\t4. Producer\n\n\t5. Price\n\n";
        cout << "\t6. Back\n\n\t7. Log out\n\n\t8. Exit\n\n\tEnter one of above numbers: ";

        ch = getch();

        //search based on name

        if(ch == '1') {

            while(true) {

                system("cls");

                cout << "\n\n    (Search here) Enter: " << search;
                cout << "\n    ----------------------------------------------------";
                cout << "-------------------------------------------------------\n\n";

                for(int j = 0; j < prodlist.size(); j++) {

                    if(findsubstr(prodlist[j].get_name(), search) && prodlist[j].get_group() == group) {

                        if(j < 9) {

                            cout << "    0" << j + 1 << ". " << prodlist[j].get_name();

                            for(string :: size_type i = 0; i < 35 - prodlist[j].get_name().size(); i++) cout << ' ';

                            cout << ' ' << prodlist[j].get_type();

                            for(string :: size_type i = 0; i < 18 - prodlist[j].get_type().size(); i++) cout << ' ';

                            cout << ' ' << prodlist[j].get_group();

                            for(string :: size_type i = 0; i < 19 - prodlist[j].get_group().size(); i++) cout << ' ';

                            cout << ' ' << prodlist[j].get_producer();

                            for(string :: size_type i = 0; i < 13 - prodlist[j].get_producer().size(); i++) cout << ' ';

                            cout << ' ' << prodlist[j].get_price() << " T";

                            for(string :: size_type i = 0; i < 8 - digit_cnt(prodlist[j].get_price()); i++) cout << ' ';

                            cout << ' ' << prodlist[j].get_quantity() << ' ' << endl;

                            cout << "    -----------------------------------------------------";
                            cout << "-------------------------------------------------------\n ";

                        }

                        else {

                            cout << "    " << j + 1 << ". " << prodlist[j].get_name();

                            for(string :: size_type i = 0; i < 35 - prodlist[j].get_name().size(); i++) cout << ' ';

                            cout << ' ' << prodlist[j].get_type();

                            for(string :: size_type i = 0; i < 18 - prodlist[j].get_type().size(); i++) cout << ' ';

                            cout << ' ' << prodlist[j].get_group();

                            for(string :: size_type i = 0; i < 19 - prodlist[j].get_group().size(); i++) cout << ' ';

                            cout << ' ' << prodlist[j].get_producer();

                            for(string :: size_type i = 0; i < 13 - prodlist[j].get_producer().size(); i++) cout << ' ';

                            cout << ' ' << prodlist[j].get_price() << " T";

                            for(string :: size_type i = 0; i < 8 - digit_cnt(prodlist[j].get_price()); i++) cout << ' ';

                            cout << ' ' << prodlist[j].get_quantity() << ' ' << endl;

                            cout << "    -----------------------------------------------------";
                            cout << "-------------------------------------------------------\n";

                        }

                    }

                }

                ch_by_ch = getch();

                if(ch_by_ch == '^') break;

                if(ch_by_ch == '*' && search != "") search.erase(search.size()-1);
                else if(ch_by_ch == '*' && search == "");
                else search += ch_by_ch;

            }

        }

        //search based on type

        else if(ch == '2') {

            while(true) {

                system("cls");

                cout << "\n\n    (Search here) Enter: " << search;
                cout << "\n    ----------------------------------------------------";
                cout << "-------------------------------------------------------\n\n";

                for(int j = 0; j < prodlist.size(); j++) {

                    if(findsubstr(prodlist[j].get_type(), search) && prodlist[j].get_group() == group) {

                        if(j < 9) {

                            cout << "    0" << j + 1 << ". " << prodlist[j].get_name();

                            for(string :: size_type i = 0; i < 35 - prodlist[j].get_name().size(); i++) cout << ' ';

                            cout << ' ' << prodlist[j].get_type();

                            for(string :: size_type i = 0; i < 18 - prodlist[j].get_type().size(); i++) cout << ' ';

                            cout << ' ' << prodlist[j].get_group();

                            for(string :: size_type i = 0; i < 19 - prodlist[j].get_group().size(); i++) cout << ' ';

                            cout << ' ' << prodlist[j].get_producer();

                            for(string :: size_type i = 0; i < 13 - prodlist[j].get_producer().size(); i++) cout << ' ';

                            cout << ' ' << prodlist[j].get_price() << " T";

                            for(string :: size_type i = 0; i < 8 - digit_cnt(prodlist[j].get_price()); i++) cout << ' ';

                            cout << ' ' << prodlist[j].get_quantity() << ' ' << endl;

                            cout << "    -----------------------------------------------------";
                            cout << "-------------------------------------------------------\n";

                        }

                        else {

                            cout << "    " << j + 1 << ". " << prodlist[j].get_name();

                            for(string :: size_type i = 0; i < 35 - prodlist[j].get_name().size(); i++) cout << ' ';

                            cout << ' ' << prodlist[j].get_type();

                            for(string :: size_type i = 0; i < 18 - prodlist[j].get_type().size(); i++) cout << ' ';

                            cout << ' ' << prodlist[j].get_group();

                            for(string :: size_type i = 0; i < 19 - prodlist[j].get_group().size(); i++) cout << ' ';

                            cout << ' ' << prodlist[j].get_producer();

                            for(string :: size_type i = 0; i < 13 - prodlist[j].get_producer().size(); i++) cout << ' ';

                            cout << ' ' << prodlist[j].get_price() << " T";

                            for(string :: size_type i = 0; i < 8 - digit_cnt(prodlist[j].get_price()); i++) cout << ' ';

                            cout << ' ' << prodlist[j].get_quantity() << ' ' << endl;

                            cout << "    -----------------------------------------------------";
                            cout << "-------------------------------------------------------\n";


                        }

                    }

                }

                ch_by_ch = getch();

                if(ch_by_ch == '^') break;

                if(ch_by_ch == '*' && search != "") search.erase(search.size()-1);
                else if(ch_by_ch == '*' && search == "");
                else search += ch_by_ch;

            }

        }

        //search based on group

        else if(ch == '3') {

            while(true) {

                system("cls");

                cout << "\n\n    (Search here) Enter: " << search;
                cout << "\n    ----------------------------------------------------";
                cout << "-------------------------------------------------------\n\n";

                for(int j = 0; j < prodlist.size(); j++) {

                    if(findsubstr(prodlist[j].get_group(), search) && prodlist[j].get_group() == group) {

                        if(j < 9) {

                            cout << "    0" << j + 1 << ". " << prodlist[j].get_name();

                            for(string :: size_type i = 0; i < 35 - prodlist[j].get_name().size(); i++) cout << ' ';

                            cout << ' ' << prodlist[j].get_type();

                            for(string :: size_type i = 0; i < 18 - prodlist[j].get_type().size(); i++) cout << ' ';

                            cout << ' ' << prodlist[j].get_group();

                            for(string :: size_type i = 0; i < 19 - prodlist[j].get_group().size(); i++) cout << ' ';

                            cout << ' ' << prodlist[j].get_producer();

                            for(string :: size_type i = 0; i < 13 - prodlist[j].get_producer().size(); i++) cout << ' ';

                            cout << ' ' << prodlist[j].get_price() << " T";

                            for(string :: size_type i = 0; i < 8 - digit_cnt(prodlist[j].get_price()); i++) cout << ' ';

                            cout << ' ' << prodlist[j].get_quantity() << ' ' << endl;

                            cout << "    -----------------------------------------------------";
                            cout << "-------------------------------------------------------\n";

                        }

                        else {

                            cout << "    " << j + 1 << ". " << prodlist[j].get_name();

                            for(string :: size_type i = 0; i < 35 - prodlist[j].get_name().size(); i++) cout << ' ';

                            cout << ' ' << prodlist[j].get_type();

                            for(string :: size_type i = 0; i < 18 - prodlist[j].get_type().size(); i++) cout << ' ';

                            cout << ' ' << prodlist[j].get_group();

                            for(string :: size_type i = 0; i < 19 - prodlist[j].get_group().size(); i++) cout << ' ';

                            cout << ' ' << prodlist[j].get_producer();

                            for(string :: size_type i = 0; i < 13 - prodlist[j].get_producer().size(); i++) cout << ' ';

                            cout << ' ' << prodlist[j].get_price() << " T";

                            for(string :: size_type i = 0; i < 8 - digit_cnt(prodlist[j].get_price()); i++) cout << ' ';

                            cout << ' ' << prodlist[j].get_quantity() << ' ' << endl;

                            cout << "    -----------------------------------------------------";
                            cout << "-------------------------------------------------------\n";


                        }

                    }

                }

                ch_by_ch = getch();

                if(ch_by_ch == '^') break;

                if(ch_by_ch == '*' && search != "") search.erase(search.size()-1);
                else if(ch_by_ch == '*' && search == "");
                else search += ch_by_ch;

            }

        }

        //search based on producer

        else if(ch == '4') {

            while(true) {

                system("cls");

                cout << "\n\n    (Search here) Enter: " << search;
                cout << "\n    ----------------------------------------------------";
                cout << "-------------------------------------------------------\n\n";

                for(int j = 0; j < prodlist.size(); j++) {

                    if(findsubstr(prodlist[j].get_producer(), search) && prodlist[j].get_group() == group) {

                        if(j < 9) {

                            cout << "    0" << j + 1 << ". " << prodlist[j].get_name();

                            for(string :: size_type i = 0; i < 35 - prodlist[j].get_name().size(); i++) cout << ' ';

                            cout << ' ' << prodlist[j].get_type();

                            for(string :: size_type i = 0; i < 18 - prodlist[j].get_type().size(); i++) cout << ' ';

                            cout << ' ' << prodlist[j].get_group();

                            for(string :: size_type i = 0; i < 19 - prodlist[j].get_group().size(); i++) cout << ' ';

                            cout << ' ' << prodlist[j].get_producer();

                            for(string :: size_type i = 0; i < 13 - prodlist[j].get_producer().size(); i++) cout << ' ';

                            cout << ' ' << prodlist[j].get_price() << " T";

                            for(string :: size_type i = 0; i < 8 - digit_cnt(prodlist[j].get_price()); i++) cout << ' ';

                            cout << ' ' << prodlist[j].get_quantity() << ' ' << endl;

                            cout << "    -----------------------------------------------------";
                            cout << "-------------------------------------------------------\n";

                        }

                        else {

                            cout << "    " << j + 1 << ". " << prodlist[j].get_name();

                            for(string :: size_type i = 0; i < 35 - prodlist[j].get_name().size(); i++) cout << ' ';

                            cout << ' ' << prodlist[j].get_type();

                            for(string :: size_type i = 0; i < 18 - prodlist[j].get_type().size(); i++) cout << ' ';

                            cout << ' ' << prodlist[j].get_group();

                            for(string :: size_type i = 0; i < 19 - prodlist[j].get_group().size(); i++) cout << ' ';

                            cout << ' ' << prodlist[j].get_producer();

                            for(string :: size_type i = 0; i < 13 - prodlist[j].get_producer().size(); i++) cout << ' ';

                            cout << ' ' << prodlist[j].get_price() << " T";

                            for(string :: size_type i = 0; i < 8 - digit_cnt(prodlist[j].get_price()); i++) cout << ' ';

                            cout << ' ' << prodlist[j].get_quantity() << ' ' << endl;

                            cout << "    -----------------------------------------------------";
                            cout << "-------------------------------------------------------\n";

                        }

                    }

                }

                ch_by_ch = getch();

                if(ch_by_ch == '^') break;

                if(ch_by_ch == '*' && search != "") search.erase(search.size()-1);
                else if(ch_by_ch == '*' && search == "");
                else search += ch_by_ch;

            }

        }

        //search based on price

        else if(ch == '5') {

            while(true) {

                system("cls");

                cout << "\n\n    (Search here) Enter: " << search;
                cout << "\n    ----------------------------------------------------";
                cout << "-------------------------------------------------------\n\n";

                string int_string;

                for(int j = 0; j < prodlist.size(); j++) {

                    int_string = to_string(prodlist[j].get_price());

                    if(findsubstr(int_string, search) && prodlist[j].get_group() == group) {

                        if(j < 9) {

                            cout << "    0" << j + 1 << ". " << prodlist[j].get_name();

                            for(string :: size_type i = 0; i < 35 - prodlist[j].get_name().size(); i++) cout << ' ';

                            cout << ' ' << prodlist[j].get_type();

                            for(string :: size_type i = 0; i < 18 - prodlist[j].get_type().size(); i++) cout << ' ';

                            cout << ' ' << prodlist[j].get_group();

                            for(string :: size_type i = 0; i < 19 - prodlist[j].get_group().size(); i++) cout << ' ';

                            cout << ' ' << prodlist[j].get_producer();

                            for(string :: size_type i = 0; i < 13 - prodlist[j].get_producer().size(); i++) cout << ' ';

                            cout << ' ' << prodlist[j].get_price() << " T";

                            for(string :: size_type i = 0; i < 8 - digit_cnt(prodlist[j].get_price()); i++) cout << ' ';

                            cout << ' ' << prodlist[j].get_quantity() << ' ' << endl;

                            cout << "    -----------------------------------------------------";
                            cout << "-------------------------------------------------------\n";

                        }

                        else {

                            cout << "    " << j + 1 << ". " << prodlist[j].get_name();

                            for(string :: size_type i = 0; i < 35 - prodlist[j].get_name().size(); i++) cout << ' ';

                            cout << ' ' << prodlist[j].get_type();

                            for(string :: size_type i = 0; i < 18 - prodlist[j].get_type().size(); i++) cout << ' ';

                            cout << ' ' << prodlist[j].get_group();

                            for(string :: size_type i = 0; i < 19 - prodlist[j].get_group().size(); i++) cout << ' ';

                            cout << ' ' << prodlist[j].get_producer();

                            for(string :: size_type i = 0; i < 13 - prodlist[j].get_producer().size(); i++) cout << ' ';

                            cout << ' ' << prodlist[j].get_price() << " T";

                            for(string :: size_type i = 0; i < 8 - digit_cnt(prodlist[j].get_price()); i++) cout << ' ';

                            cout << ' ' << prodlist[j].get_quantity() << ' ' << endl;

                            cout << "    -----------------------------------------------------";
                            cout << "-------------------------------------------------------\n";

                        }

                    }

                }

                ch_by_ch = getch();

                if(ch_by_ch == '^') break;

                if(ch_by_ch == '*' && search != "") search.erase(search.size()-1);
                else if(ch_by_ch == '*' && search == "");
                else search += ch_by_ch;

            }

        }

        //back

        else if(ch == '6') {

            return 0;

        }

        //log out

        else if(ch == '7') {

            return 1;

        }

        //exit

        else if(ch == '8') {

            exit_m(larlist, prodlist);

        }

    }

    //return;

}


//////search_in function (3 parameters)////////////////////////////////////////////////////////////////////////////////////////




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




//////findsubstr function///////////////////////////////////////////////////////////////////////////


bool findsubstr (string str, string substr) {



    for(int j = 0, i = 0; i < str.size(); i++) {

        if(str[i] != substr[j]) j = 0;
        else j++;

        if(j == substr.size()) return true;


    }

    return false;

}


//////findsubstr function ends//////////////////////////////////////////////////////////////////////




//////exit_m function///////////////////////////////////////////////////////////////////////////////


void exit_m (list<up_s>& larlist, fslist& prodlist) {

    fslist :: iterator itr1;
    list<up_s> :: iterator itr2;

    while(true) {

        for(itr1 = prodlist.begin(); itr1 != prodlist.end(); itr1++) {

            if(itr1->get_name() == "") {

                break;

            }

        }

        if(itr1 == prodlist.end()) break;

        else prodlist.erase(itr1);

    }

    while(true) {

        for(itr2 = larlist.begin(); itr2 != larlist.end(); itr2++) {

            if(itr2->get_username() == "") {

                break;

            }

        }

        if(itr2 == larlist.end()) break;

        else larlist.erase(itr2);

    }

    //updating the file

    ofstream ofile, ofile_up;

    ofile.open("E:\\C++ Programs\\PROJECT\\Files\\products_list.txt", ios :: out | ios :: trunc);
    ofile_up.open("E:\\C++ Programs\\PROJECT\\Files\\ups_list.txt", ios :: out | ios :: trunc);

    for(fslist :: iterator itr = prodlist.begin(); itr != prodlist.end(); itr++) {

        ofile << itr->get_name() << endl;
        ofile << itr->get_type() << endl;
        ofile << itr->get_group() << endl;
        ofile << itr->get_producer() << endl;
        ofile << itr->get_price() << endl;
        ofile << itr->get_quantity() << endl;

    }

    ofile.close();

    for(list<up_s> :: iterator itr = larlist.begin(); itr != larlist.end(); itr++) {

        ofile_up << itr->get_username() << endl;
        ofile_up << itr->get_password() << endl;
        ofile_up << itr->get_admin_check() << endl;

    }

    ofile_up.close();

    system("cls");

    cout << "\n\n\n\n\n\n\n\n------------------------------!Thanks for ";
    cout << "Passing By!------------------------------\n\n\n\n\n\n\n";

    exit(0);

}


//////exit_m function ends//////////////////////////////////////////////////////////////////////////




//////lar function////////////////////////////////////////////////////////////////////////////


//a function for registration and login (stands for login and registration)

int lar (char ch, list<up_s>& larlist) {

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

        list<up_s> :: iterator i;

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

            list<up_s> :: iterator itr;

            for(itr = larlist.begin(); itr != larlist.end(); itr++) {

                if(itr->get_username() == uptemp_s) break;

            }

            if(itr != larlist.end()) cout << "\n\t^ There is another account with this username!\n\n\t    ";

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

        list<up_s> :: iterator i;

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

            list<up_s> :: iterator itr;

            for(itr = larlist.begin(); itr != larlist.end(); itr++) {

                if(itr->get_username() == uptemp_s) break;

            }

            if(itr != larlist.end()) cout << "\n\t^ There is another account with this username!\n\n\t    ";

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


//////lar function ends//////////////////////////////////////////////////////////////////////




//////sortfslist function///////////////////////////////////////////////////////////////////////////


void sortfslist (fslist& prodlist) {

    //insertion sort

    int i;

    for(int j = 1; j < prodlist.size(); j++) {

        foodstuff temp;

        temp = prodlist[j];

        i = j - 1;

        while(temp < prodlist[i]) {

            prodlist[i + 1] = prodlist[i];

            i--;

            if(i < 0) break;

        }

        prodlist[i + 1] = temp;

    }

    return;

}


//////sortfslist function ends//////////////////////////////////////////////////////////////////////




//////buy function//////////////////////////////////////////////////////////////////////////////////


void buy (fslist& prodlist) {

    int x, y;
    char ch;

    while(true) {

        while(true) {

            system("cls");

            cout << "\n\n    Enter the product number and then press enter (enter 0 to exit buying): ";

            cin >> x;

            cin.get();

            if(x == 0) return;

            if(prodlist[x - 1].get_quantity() < 1) {

                cout << "\n\n    Sorry, it is sold out :(";
                cout << "\n\n    Press enter to continue: ";

                cin.get();

            }

            else {

                cout << "\n\n    A " << prodlist[x - 1].get_name() << ", " << prodlist[x - 1].get_producer() << " ?";
                cout << "\n\n    Enter \"y\" if so, and enter \"n\" if not: ";

                ch = getch();

                if(ch == 'y') break;

            }

        }

        system("cls");

        cout << "\n\n    Now enter how many you want to purchase and then press enter (enter 0 to exit buying): ";

        cin >> y;

        cin.get();

        if(y == 0) return;

        prodlist[x - 1].set_quantity(prodlist[x - 1].get_quantity()-y);

        system("cls");

        cout << "\n\n    Do you want to continue: ";
        cout << "\n\n    Enter \"y\" if so, and enter \"n\" if not: ";

        ch = getch();

        if(ch == 'n') break;

    }

    return;

}


//////buy function ends/////////////////////////////////////////////////////////////////////////////




//////add function/////////////////////////////////////////////////////////////////////////////////


void add (fslist& prodlist) {

    string s;
    int x;
    foodstuff temp;
    char ch;

    //name

    system("cls");

    cout << "\n\n    Enter the name (press 0 and then enter to exit adding): ";

    getline(cin, s);

    if(s == "0") return;

    temp.set_name(s);

    //type

    system("cls");

    cout << "\n\n    Enter the type (press 0 and then enter to exit adding): ";

    getline(cin, s);

    if(s == "0") return;

    temp.set_type(s);

    //group

    system("cls");

    cout << "\n\n    Enter the group (press 0 and then enter to exit adding): ";

    getline(cin, s);

    if(s == "0") return;

    temp.set_group(s);

    //producer

    system("cls");

    cout << "\n\n    Enter the producer (press 0 and then enter to exit adding): ";

    getline(cin, s);

    if(s == "0") return;

    temp.set_producer(s);

    //price

    system("cls");

    cout << "\n\n    Enter the price (press 0 and then enter to exit adding): ";

    cin >> x;

    cin.get();

    if(x == 0) return;

    temp.set_price(x);

    //quantity

    system("cls");

    cout << "\n\n    Enter the quantity (press 0 and then enter to exit adding): ";

    cin >> x;

    cin.get();

    if(x == 0) return;

    temp.set_quantity(x);

    //adding

    system("cls");

    cout << "\n\n    Name: " << temp.get_name() << endl;
    cout << "    Type: " << temp.get_type() << endl;
    cout << "    Group: " << temp.get_group() << endl;
    cout << "    Producer: " << temp.get_producer() << endl;
    cout << "    Price: " << temp.get_price() << endl;
    cout << "    Quantity: " << temp.get_quantity() << endl;

    cout << "\n\n\n    Is that right?";
    cout << "\n\n    Enter \"y\" if so, and enter \"n\" if not: ";

    ch = getch();

    if(ch == 'n') {

        system("cls");

        cout << "\n\n    Alright! It wasn't added. Press Enter to continue: ";

        cin.get();

        return;

    }

    prodlist.push_front(temp);

    sortfslist(prodlist);

    system("cls");

    cout << "\n\n    It was added!";
    cout << "\n\n    Press enter to continue: ";

    cin.get();

    return;

}


//////add function ends////////////////////////////////////////////////////////////////////////////




//////edit function////////////////////////////////////////////////////////////////////////////////


void edit (fslist& prodlist) {

    string s;
    int i, x;
    foodstuff temp;
    char ch;

    while(true) {

        system("cls");

        cout << "\n\n    Enter the number of the product you want to edit (press 0 and then enter to exit editing): ";

        cin >> i;

        cin.get();

        if(i == 0) return;

        system("cls");

        cout << "\n\n    A " << prodlist[i - 1].get_name() << ", " << prodlist[i - 1].get_producer() << " ?";
        cout << "\n\n    Enter \"y\" if so, and enter \"n\" if not: ";

        ch = getch();

        if(ch == 'y') break;

    }

    //name

    system("cls");

    cout << "\n\n    Enter the name (press 0 and then enter to exit editing): ";

    getline(cin, s);

    if(s == "0") return;

    temp.set_name(s);

    //type

    system("cls");

    cout << "\n\n    Enter the type (press 0 and then enter to exit editing): ";

    getline(cin, s);

    if(s == "0") return;

    temp.set_type(s);

    //group

    system("cls");

    cout << "\n\n    Enter the group (press 0 and then enter to exit editing): ";

    getline(cin, s);

    if(s == "0") return;

    temp.set_group(s);

    //producer

    system("cls");

    cout << "\n\n    Enter the producer (press 0 and then enter to exit editing): ";

    getline(cin, s);

    if(s == "0") return;

    temp.set_producer(s);

    //price

    system("cls");

    cout << "\n\n    Enter the price (press 0 and then enter to exit editing): ";

    cin >> x;

    cin.get();

    if(x == 0) return;

    temp.set_price(x);

    //quantity

    system("cls");

    cout << "\n\n    Enter the quantity (press 0 and then enter to exit editing): ";

    cin >> x;

    cin.get();

    if(x == 0) return;

    temp.set_quantity(x);

    //editing

    system("cls");

    cout << "\n\n    Name: " << temp.get_name() << endl;
    cout << "    Type: " << temp.get_type() << endl;
    cout << "    Group: " << temp.get_group() << endl;
    cout << "    Producer: " << temp.get_producer() << endl;
    cout << "    Price: " << temp.get_price() << endl;
    cout << "    Quantity: " << temp.get_quantity() << endl;

    cout << "\n\n\n    Is that right?";
    cout << "\n\n    Enter \"y\" if so, and enter \"n\" if not: ";

    ch = getch();

    if(ch == 'n') {

        system("cls");

        cout << "\n\n    Alright! It wasn't edited. Press Enter to continue: ";

        cin.get();

        return;

    }

    prodlist[i - 1].set_name(temp.get_name());
    prodlist[i - 1].set_type(temp.get_type());
    prodlist[i - 1].set_group(temp.get_group());
    prodlist[i - 1].set_producer(temp.get_producer());
    prodlist[i - 1].set_price(temp.get_price());
    prodlist[i - 1].set_quantity(temp.get_quantity());

    sortfslist(prodlist);

    system("cls");

    cout << "\n\n    It was edited!";
    cout << "\n\n    Press enter to continue: ";

    cin.get();

    return;

}


//////edit function ends///////////////////////////////////////////////////////////////////////////




//////fdelete function//////////////////////////////////////////////////////////////////////////////


void fdelete (fslist& prodlist) {

    int i;
    char ch;

    while(true) {

        system("cls");

        cout << "\n\n    Enter the number of the product you want to delete (press 0 and then enter to exit deletion): ";

        cin >> i;

        cin.get();

        if(i == 0) return;

        system("cls");

        cout << "\n\n    A " << prodlist[i - 1].get_name() << ", " << prodlist[i - 1].get_producer() << " ?";
        cout << "\n\n    Enter \"y\" if so, and enter \"n\" if not: ";

        ch = getch();

        if(ch == 'y') break;

    }

    system("cls");

    cout << "\n\n\n    Are you sure?";
    cout << "\n\n    Enter \"y\" if so, and enter \"n\" if not: ";

    ch = getch();

    if(ch == 'n') {

        system("cls");

        cout << "\n\n    Alright! It wasn't deleted. Press Enter to continue: ";

        cin.get();

        return;

    }

    fslist :: iterator itr;

    itr = prodlist.begin();

    for(int j = 0; j < i - 1; j++) itr++;

    prodlist.erase(itr);

    system("cls");

    cout << "\n\n    It was deleted!";
    cout << "\n\n    Press enter to continue: ";

    cin.get();

    return;

}


//////fdelete function ends/////////////////////////////////////////////////////////////////////////




//////showfs function///////////////////////////////////////////////////////////////////////////////


void showfs (fslist& prodlist) {

    for(fslist :: iterator itr = prodlist.begin(); itr != prodlist.end(); itr++) {

        cout << itr->get_name() << "  " << itr->get_type() << "  " << itr->get_group() << "  ";
        cout << itr->get_producer() << "  " << itr->get_price() << "  " << itr->get_quantity();
        cout << endl << endl;

    }

    return;

}


//////showfs function ends//////////////////////////////////////////////////////////////////////////




//////showup function///////////////////////////////////////////////////////////////////////////////


void showup (list<up_s>& larlist) {

    for(list<up_s> :: iterator itr = larlist.begin(); itr != larlist.end(); itr++) {

        cout << itr->get_username() << "  " << itr->get_password() << "  " << itr->get_admin_check();
        cout << endl << endl;

    }

    return;

}


//////showup function ends//////////////////////////////////////////////////////////////////////////
