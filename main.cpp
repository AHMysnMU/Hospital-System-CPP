#include <iostream>    // cin/cout
#include <cstdlib>     // system("cls")
#include <thread>      // std::this_thread::sleep_for()
#include <chrono>      // std::chrono::seconds
#include <string>      // getline()
#include <algorithm>   // std::transform()
#include <cctype>      // tolower()
#include <iomanip>     // setw()
using namespace std;










string username = "admin", pass = "123";    // the initial username/pass

bool valid(string Uu, string Up) {
    return (Uu == username && Up == pass);    // check if user entered correct username and pass
}

void print(bool Valid) {

    if (Valid == true) {    // print if username/pass correct
        cout << "+=======================================+\n";
        cout << "|          LOGGED IN SUCCESSFULY        |\n";
        cout << "+=======================================+\n\n";
    }

    else {    // print if reach max attempts
        cout << "\n+---------------------------------------+\n";
        cout << "|    You reached the max attempts.      |\n";
        cout << "|      Please try again later.          |\n";
        cout << "+---------------------------------------+\n";
        exit(0);
    }
}

void Login() {
    string Uu, Up;    // to take username and password from user
    int counter = 0;    // to count attempts (max 3)

    cout << "+=======================================+\n";
    cout << "|     Welcome to the Hospital system    |\n";
    cout << "+=======================================+\n\n";

    do {
        cout << "+---------------------------------------+\n";
        cout << "|              Login Page               |\n";
        cout << "+---------------------------------------+\n";

        cout << "|   Username: ";
        cin >> Uu;
        cout << "|   Password: ";
        cin >> Up;

        cout << "+---------------------------------------+\n";

        if (valid(Uu, Up))
            break;    // stop the loop if username and pass are correct

        if (counter != 2) {    // to not print it after the last attempt
            cout << "|   Incorrect username or password.     |\n";
            cout << "|    Retrying in 3 seconds...           |\n";
            cout << "+---------------------------------------+\n\n";
            std::this_thread::sleep_for(chrono::seconds(3));
        }

        system("cls");    // clear output

        counter++;
    } while (counter < 3);

    print(valid(Uu, Up));
    std::this_thread::sleep_for(chrono::seconds(3));    // waiting 3s to see the output then clear it
    system("cls");
}






bool valid(string Upass) {
    return (Upass.size() >= 8);    // check if the password entered by the user is valid ( >= 8 )
}

void print2(bool Valid) {
    cout << "\n+------------------------------------------+\n";

    if (Valid == true)    // if pass valid print:
        cout << "|    Password changed successfully         |\n";

    else {    // if attempts finished print:
        cout << "|    Too many incorrect attempts           |\n";
        cout << "|     Please try again later               |\n";
    }
    cout << "+------------------------------------------+\n\n";
}

void ChangePass() {
    int counter = 1;
    string Upass;    // to take pass from user
    do {
        cout << "+==========================================+\n";
        cout << "|              Change Password             |\n";
        cout << "+==========================================+\n";

        cout << "|    Enter new password: ";
        cin >> Upass;

        if (valid(Upass)) {    // stop the loop if pass valid and make the main pass = the pass entered by the user
            pass = Upass;
            break;
        }
        if (counter != 5) {    // to not print it after the last attempt
            cout << "|     Password must be at least 8 characters\n";
            cout << "|     Attempts left: " << (5 - counter) << "\n";
            cout << "+------------------------------------------+\n";
            std::this_thread::sleep_for(chrono::seconds(2));
        }
        system("cls");

        counter++;
    } while (counter <= 5);

    print2(valid(Upass));
}






// array store the info of every patient with max size=100
int ids[100];
string names[100];
int ages[100];
string genders[100];
string diseases[100];
string phones[100];
int patientCount = 0;

void FillArr() {    // to enter the info of a patient

    // take id
    bool notValid;
    int Uids;
    do {    // retake the id once it's used
        cout << "|    Enter Patient ID: ";
        cin >> Uids;
        cin.ignore();    // Discards the '\n' left in the buffer ( used befor getiline() )
        notValid = false;
        for (int i = 0; i < patientCount; i++) {    // to check if the id entered by the user is used
            if (Uids == ids[i]) {
                notValid = true;
                cout << "ID already used!\n";
                break;
            }
        }
    } while (notValid);
    ids[patientCount] = Uids;

    // take name
    cout << "|    Enter Name: ";
    getline(cin, names[patientCount]);    // to read an entire line of text, including spaces

    // take age
    cout << "|    Enter Age: ";
    cin >> ages[patientCount];
    cin.ignore();

    // take gender
    string Ugend;
    while (true) {    // to rteake gender if not accepted
        cout << "|    Enter Gender (male/female): ";
        getline(cin, Ugend);
        transform(Ugend.begin(), Ugend.end(), Ugend.begin(), ::tolower);    // to make the gender entered by the user correct in both (lower and upper case)

        if (Ugend == "male" || Ugend == "female") {    // check if user enter something else than male or female
            genders[patientCount] = Ugend;
            break;
        }
        cout << "INVALID INPUT\n";    // print if user enter something else than male or female
    }

    //take disease
    cout << "|    Enter Disease: ";
    getline(cin, diseases[patientCount]);

    // take number
    cout << "|    Enter Phone Number: ";
    getline(cin, phones[patientCount]);

    patientCount++;    // for the next time adding a patient

    cout << "+---------------------------------------------+\n";
    cout << "|    Patient added successfully!              |\n";
    cout << "+---------------------------------------------+\n";
}

void AddPatient() {
    char ans = 'n';

    do {    // if user want to add more patient

        if (patientCount >= 100) {    // max 100 patient
            cout << "\n+---------------------------------------------+\n";
            cout << "|    Cannot add more patients.                 |\n";
            cout << "|     Maximum limit reached!                   |\n";
            cout << "+---------------------------------------------+\n";
            return;
        }
        system("cls");    // clear output
        cout << "+==========================================+\n";
        cout << "|                ADD PATIENT               |\n";
        cout << "+==========================================+\n";
        FillArr();    // adding the patient

        // asking if user want to add more patient
        do {    //retake answer while it is not accepted
            cout << "\n|      add more? (y)es or (n)o: ";
            cin >> ans;
            if (ans == 'y' || ans == 'n')
                break;
            cout << "|        invalid input, try again.\n";    // print if user enter something else y or n
        } while (true);


    } while (ans == 'y');

    return;
}






void exit() {    // permit user to exit the page whenever he wants
    char exit;
    cout << "\nPRESS ANY KEY TO EXIT: ";
    cin >> exit;
}






void printTableBorder() {
    cout << "+------------+--------------------+--------+----------+--------------------+-----------------+" << endl;
}

void ListPatients() {
    cout << "+==========================================+\n";
    cout << "|               LIST PATIENTS              |\n";
    cout << "+==========================================+\n\n";
    cout << left;

    // Header border
    printTableBorder();

    // Column headers
    cout << "| " << setw(10) << "ID"
        << " | " << setw(18) << "Name"
        << " | " << setw(6) << "Age"
        << " | " << setw(8) << "Gender"
        << " | " << setw(18) << "Disease"
        << " | " << setw(15) << "Phone Number" << " |" << endl;

    // Header-bottom border
    printTableBorder();

    // Data rows
    for (int i = 0; i < patientCount; i++) {    // setw to sets the field width for the next output
        cout << "| " << setw(10) << ids[i]
            << " | " << setw(18) << names[i]
                << " | " << setw(6) << ages[i]
                    << " | " << setw(8) << genders[i]
                        << " | " << setw(18) << diseases[i]
                            << " | " << setw(15) << phones[i]
                                << " |" << endl;
    }

    // Bottom border
    printTableBorder();


    exit();
}






void printDetails(int index) {
    cout << left;

    // Print header border and header row
    printTableBorder();
    cout << "| " << setw(10) << "ID"
        << " | " << setw(18) << "Name"
        << " | " << setw(6) << "Age"
        << " | " << setw(8) << "Gender"
        << " | " << setw(18) << "Disease"
        << " | " << setw(15) << "Phone Number" << " |" << endl;
    printTableBorder();

    // Print patient data row
    cout << "| " << setw(10) << ids[index]
        << " | " << setw(18) << names[index]
            << " | " << setw(6) << ages[index]
                << " | " << setw(8) << genders[index]
                    << " | " << setw(18) << diseases[index]
                        << " | " << setw(15) << phones[index]
                            << " |" << endl;

                            // Print bottom border
                            printTableBorder();
}






int TakeID() {    // function to take id frome user and check if it exists
    int Uid;    // to take id from user
    char ans;

    do {    // to retake the id frome user

        cout << "\n+---------------------------------------------+\n";
        cout << "|    Enter the ID of the patient: ";
        cin >> Uid;

        // check if id exists
        for (int i = 0; i < patientCount; i++) {
            if (Uid == ids[i]) {
                return i;
            }
        }
        // if id doesnt exists, ask user if he want tor try again or leave the page
        do {
            cout << "\n\n+---------------------------------------------+\n";
            cout << "|    Error: Invalid ID entered.                 |\n";
            cout << "+---------------------------------------------+\n";
            cout << "|    Do you want to:                          |\n";
            cout << "|     (t) Try again                           |\n";
            cout << "|     (l) Leave                               |\n";
            cout << "+---------------------------------------------+\n";
            cout << "|    Enter your choice: ";
            cin >> ans;

            if (ans == 'l')
                return -1;

            if (ans == 't')
                break;

            cout << "\ninvalid input, try again.\n";

        } while (true);    // while answer is not accepted

    } while (ans == 't');

    return -1;
}






void ViewPatient() {

    cout << "+==========================================+\n";
    cout << "|               VIEW PATIENT               |\n";
    cout << "+==========================================+\n\n";
    int indexView = TakeID();    // take id
    if (indexView != -1) {    // if id exists print details and use exit() func.
        printDetails(indexView);
        exit();
    }
}






void EditPatient() {

    char ans, ans2;
    cout << "+==========================================+\n";
    cout << "|               EDIT PATIENT               |\n";
    cout << "+==========================================+\n\n";

    int IndexChange = TakeID();    // take the id from user
    if (IndexChange == -1)
        return;

    do {
        system("cls");  // clear output

        cout << "+==========================================+\n";
        cout << "|               EDIT PATIENT               |\n";
        cout << "+==========================================+\n\n";
        printDetails(IndexChange);    // always desplay patient info

        do {    // loop if user want edit more
            cout << "\n+---------------------------------------------+\n";
            cout << "|     What do you want to edit?               |\n";
            cout << "|---------------------------------------------|\n";
            cout << "| (i) ID                                      |\n";
            cout << "| (n) Name                                    |\n";
            cout << "| (a) Age                                     |\n";
            cout << "| (g) Gender                                  |\n";
            cout << "| (d) Disease                                 |\n";
            cout << "| (p) Phone Number                            |\n";
            cout << "+---------------------------------------------+\n";
            cout << "|    Enter your choice: ";
            cin >> ans;
            cout << endl;

            // BREAK THE LOOP AFTER ANY CHANGE

            // edit id
            if (ans == 'i') {
                bool notValid;
                int Uid;
                do {
                    cout << "|    enter new id: ";
                    cin >> Uid;
                    notValid = false;
                    for (int i = 0; i < patientCount; i++) {    // check if id is used
                        if (Uid == ids[i] && i != IndexChange) {
                            notValid = true;
                            cout << "ups, this id is used!\n";
                            break;
                        }
                    }
                    if (notValid == false) {    // print if id accepted
                        ids[IndexChange] = Uid;    // change the id
                        cout << "+---------------------------------------------+\n";
                        cout << "|    ID CHANGED SUCCESSFULLY!                 |\n";
                        cout << "+---------------------------------------------+\n";
                    }

                } while (notValid);    // retake the id if is used
                break;
            }

            // edit name
            else if (ans == 'n') {
                cout << "|    enter new name: ";
                cin.ignore();
                getline(cin, names[IndexChange]);
                cout << "+---------------------------------------------+\n";
                cout << "|    NAME CHANGED SUCCESSFULLY!               |\n";
                cout << "+---------------------------------------------+\n";
                break;
            }

            // edit age
            else if (ans == 'a') {
                cout << "|    enter new age: ";
                cin >> ages[IndexChange];
                cout << "+---------------------------------------------+\n";
                cout << "|    AGE CHANGED SUCCESSFULLY!                |\n";
                cout << "+---------------------------------------------+\n";
                break;

            }

            // edit gender
            else if (ans == 'g') {
                string Ugend;
                while (true) {    // check if gender male or female
                    cout << "|    Enter new Gender: ";
                    cin >> Ugend;
                    transform(Ugend.begin(), Ugend.end(), Ugend.begin(), ::tolower);

                    if (Ugend == "male" || Ugend == "female") {
                        genders[IndexChange] = Ugend;
                        break;
                    }
                    cout << "INVALID INPUT\n";
                }
                cout << "+---------------------------------------------+\n";
                cout << "|    GENDER CHANGED SUCCESSFULLY!             |\n";
                cout << "+---------------------------------------------+\n";
                break;
            }

            // edit disease
            else if (ans == 'd') {
                cout << "|    enter new disease: ";
                cin.ignore();
                getline(cin, diseases[IndexChange]);
                cout << "+---------------------------------------------+\n";
                cout << "|    DISEASE CHANGED SUCCESSFULLY!            |\n";
                cout << "+---------------------------------------------+\n";
                break;

            }

            // edit phone number
            else if (ans == 'p') {
                cout << "|    enter new phone number: ";
                cin.ignore();
                getline(cin, phones[IndexChange]);
                cout << "+---------------------------------------------+\n";
                cout << "|    PHONE NUMBER CHANGED SUCCESSFULLY!       |\n";
                cout << "+---------------------------------------------+\n";
                break;

            }

            // invalid input
            else {
                cout << "invalid input, try again.\n";
            }
        } while (true);    // while invalid input

        printDetails(IndexChange);    // print the new info table
        do {
            cout << "edit more ? (y)es or (n)o: ";    // ask the user if he want to enter more
            cin >> ans2;

            if (ans2 == 'n')
                return;    // end the function if answer is no

            if (ans2 == 'y')
                break;

            cout << "invalid input, try again.\n";
        } while (true);    // while invalid answer




    } while (ans2 == 'y');
}






void DeletePatient() {
    cout << "+==========================================+\n";
    cout << "|               DELETE PATIENT             |\n";
    cout << "+==========================================+\n\n";

    int IndexDelete = TakeID();    // take id
    if (IndexDelete == -1)
        return;

    printDetails(IndexDelete);
    // Copy each element from the next position (i + 1) into the current position (i).
    // This effectively overwrites the record we want to delete and shifts all others left by one
    for (int i = IndexDelete; i < patientCount - 1; i++) {
        ids[i] = ids[1 + i];
        names[i] = names[1 + i];
        ages[i] = ages[1 + i];
        diseases[i] = diseases[1 + i];
        genders[i] = genders[1 + i];
        phones[i] = phones[1 + i];
    }
    patientCount--;    //decrease the count of total patients, since one has been removed

    cout << "+---------------------------------------------+\n";
    cout << "|    PATIENT DELETED SUCCESSFULLY!             |\n";
    cout << "+---------------------------------------------+\n";
}






void mainGo() {    // to clear the output and go to main with a delay of 4s
    cout << "\n GOING TO MAIN..";
    std::this_thread::sleep_for(chrono::seconds(4));
    system("cls");
}









int main() {


    Login();

    ChangePass();

    mainGo();

    do {
        char ans;
        cout << "\n+==========================================+\n";
        cout << "|         HOSPITAL MANAGEMENT SYSTEM       |\n";
        cout << "+==========================================+\n";
        cout << "|    Menu Options:                         |\n";
        cout << "|------------------------------------------|\n";
        cout << "| (c) Change Password                      |\n";
        cout << "| (a) Add Patient                          |\n";                // the style of the main
        cout << "| (e) Edit Patient                         |\n";
        cout << "| (l) List Patients                        |\n";
        cout << "| (v) View Patient                         |\n";
        cout << "| (d) Delete Patient                       |\n";
        cout << "| (E) Exit Program                         |\n";
        cout << "+==========================================+\n";
        cout << "|    Enter your choice: ";
        cin >> ans;
        switch (ans) {

        case 'c': system("cls"); ChangePass(); mainGo(); break;

        case 'a': system("cls"); AddPatient(); mainGo(); break;

        case 'e': system("cls"); EditPatient(); mainGo(); break;                        // clear the output in the begin of every function

        case 'l': system("cls"); ListPatients(); mainGo(); break;                      // going to main after every function

        case 'v': system("cls"); ViewPatient(); mainGo(); break;

        case 'd': system("cls"); DeletePatient(); mainGo(); break;

        case 'E':    // logging out if user want to exit the programm
            cout << "\n\n\n+=======================================+\n";
            cout << "|             LOGGING OUT...             |\n";
            cout << "+=======================================+\n\n";
            std::this_thread::sleep_for(chrono::seconds(2));
            return 0;

            // if the user enter an invalid input print message and wait 2s befor clearing the output
        default: cout << "invalid input, try again in 2s!\n"; std::this_thread::sleep_for(chrono::seconds(2)); system("cls");
        }
    } while (true);


        cout << endl;
}