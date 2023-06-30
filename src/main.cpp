#include <iostream>
#include <fstream>
#include <string>
#include <ctime> // For srand(time(0))
#include <limits> // For cin.ignore(numeric_limits<streamsize>::max(), '\n')

using namespace std;

string real_password = "NBA";
string file_name = "stext.txt";

void Menu(); // Menu
bool CHECK_PASSWORD(); // Checks if given password is good
bool CHECK_IF_EMPTY(int& error); // Checks if file is empty
void PUT_TEXT_IN_FILE();
string GET_TEXT_FROM_FILE();

void DELETE_TEXT();
void MIXX(); // In one row (how many) elements
void RANDOM_MIXX(); // In one row (max number of) elements
void ADD_SYMBOLS(); // Adds symbols between each character

int main()
{
    int error;
    string choice;
    Menu();
    cout << ">>> "; cin >> choice;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    if (choice == "1"){
        if (CHECK_PASSWORD()){
            system("cls");
            PUT_TEXT_IN_FILE();
            cout << "\n[Console] Text were put in the file." << endl;
        } else {
            cout << "[Console] Wrong password." << endl;
        }
        goto loopend;
    }
    if (choice == "2"){
        if (CHECK_PASSWORD()){
            system("cls");
            if (CHECK_IF_EMPTY(error)){
                if (error == 1)
                    cout << "[Console] File does not exist." << endl; 
                else
                    cout << "[Console] The file has no text." << endl;
            } else {
                string text = GET_TEXT_FROM_FILE();
                cout << "[Console] The text from file:" << endl;
                cout << text << endl << endl;
            }
        } else {
            cout << "[Console] Wrong password." << endl;
        }
        goto loopend;
    }
    if (choice == "3"){
        if (CHECK_PASSWORD()){
            system("cls");
            if (CHECK_IF_EMPTY(error)){
                if (error == 1)
                    cout << "[Console] File does not exist." << endl; 
                else
                    cout << "[Console] No text to delete." << endl;
            } else {
                DELETE_TEXT();
                cout << "[Console] Deleted." << endl;
            }
        } else {
            cout << "[Console] Wrong password." << endl;
        }
        goto loopend;
    }
    if (choice == "4"){
        if (CHECK_PASSWORD()){
            system("cls");
            if (CHECK_IF_EMPTY(error)){
                if (error == 1)
                    cout << "[Console] File does not exist." << endl; 
                else
                    cout << "[Console] No text to mix." << endl;
            } else {
                MIXX();
                cout << "[Console] Mixed." << endl;
            }
        } else {
            cout << "[Console] Wrong password." << endl;
        }
        goto loopend;
    }
    if (choice == "5"){
        if (CHECK_PASSWORD()){
            system("cls");
            if (CHECK_IF_EMPTY(error)){
                if (error == 1)
                    cout << "[Console] File does not exist." << endl; 
                else
                    cout << "[Console] No text to random mix." << endl;
            } else {
                RANDOM_MIXX();
                cout << "[Console] Random mixed." << endl;
            }
        } else {
            cout << "[Console] Wrong password." << endl;
        }
        goto loopend;
    }
    if (choice == "6"){
        if (CHECK_PASSWORD()){
            system("cls");
            if (CHECK_IF_EMPTY(error)){
                if (error == 1)
                    cout << "[Console] File does not exist." << endl; 
                else
                    cout << "[Console] No text exist." << endl;
            } else {
                ADD_SYMBOLS();
                cout << "[Console] Symbols added." << endl;
            }
        } else {
            cout << "[Console] Wrong password." << endl;
        }
    }

    if (choice != "1" && choice != "2" && choice != "3" && choice != "4" && choice != "5" && choice != "6"){
        cout << "[Console] Wrong choice." << endl;
    } 

    loopend:
    cout << "[Console] The program has been closed." << endl;
    system("pause");

    return 0;
}

void Menu(){
    cout << "What do you want to do?" << endl;
    cout << "1. Put text in the file." << endl;
    cout << "2. Get text from the file." << endl;
    cout << "3. Delete text." << endl;
    cout << "4. Mix text." << endl;
    cout << "5. Random mix text." << endl;
    cout << "6. Add symbols." << endl;
}

bool CHECK_PASSWORD(){
    string entered_password;
    cout << "[Console] Enter the password: "; cin >> entered_password;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    if (entered_password == real_password)
        return true;
    return false;
}

bool CHECK_IF_EMPTY(int& error){
    ifstream myFile(file_name);
    if (!myFile.is_open()){
        error = 1;
        return true;
    }
    myFile.seekg(0, ios::end);
    if (myFile.tellg() == 0){
        myFile.close();
        error = 2;
        return true;
    }
    myFile.close();
    return false;
}

void PUT_TEXT_IN_FILE(){
    string text;
    cout << "[Console] Enter your text:\n>>> "; getline(cin, text);
    ofstream myFile(file_name, ios::app);
    for (char x : text){
        myFile << (int)x;
    }
    myFile.close();
}

string GET_TEXT_FROM_FILE(){
    string text = "", numbersTXT = "";
    char n, numbers[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
    int con, con2;
    ifstream myFile(file_name);
    while (myFile >> n){
        for (char x : numbers){
            if (x == n){
                numbersTXT = numbersTXT + n;
            }
        }
    }
    myFile.close();
    for (string::size_type i = 0; i < numbersTXT.size(); i++){
        n = numbersTXT[i];
        if (n == '3'){ // 32 - 39
            i++;
            n = numbersTXT[i]; con = int(n) - 48;
            text = text + char(30+con);
        } else if (n == '4'){ // 40 - 49
            i++;
            n = numbersTXT[i]; con = int(n) - 48;
            text = text + char(40+con);
        } else if (n == '5'){ // 50 - 59
            i++;
            n = numbersTXT[i]; con = int(n) - 48;
            text = text + char(50+con);
        } else if (n == '6'){ // 60 - 69
            i++;
            n = numbersTXT[i]; con = int(n) - 48;
            text = text + char(60+con);
        } else if (n == '7'){ // 70 - 79
            i++;
            n = numbersTXT[i]; con = int(n) - 48;
            text = text + char(70+con);
        } else if (n == '8'){ // 80 - 89
            i++;
            n = numbersTXT[i]; con = int(n) - 48;
            text = text + char(80+con);
        } else if (n == '9'){ // 90 - 99
            i++;
            n = numbersTXT[i]; con = int(n) - 48;
            text = text + char(90+con);
        } else if (n == '1'){ // 100 - 199
            i++;
            n = numbersTXT[i]; con = int(n) - 48;
            i++;
            n = numbersTXT[i]; con2 = int(n) - 48;
            text = text + char(100+con*10+con2);
        }
    }
    return text;
}

void DELETE_TEXT(){
    ofstream myFile(file_name);
    myFile.close();
}

void MIXX(){
    int k, s = 0;
    string text;
    char x;
    cout << "[Console] How many in a row: "; cin >> k;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    if (k <= 0){
        k = 1;
    }
    fstream myFile(file_name, ios::in);
    while (myFile >> x){
        s = s + 1;
        text = text + x;
    }
    myFile.close();
    myFile.open(file_name, ios::out);
    for (int i = 1; i <= s; i++){
        myFile << text[i - 1];
        if (i % k == 0){
            myFile << '\n';
        }
    }
    myFile.close();
}

void RANDOM_MIXX(){
    int k, s = 0, kiek, kint = 1;
    string text;
    char x;
    cout << "[Console] Max size in a row: "; cin >> k;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    if (k < 1){
        k = 1;
    }
    fstream myFile(file_name, ios::in);
    while (myFile >> x){
        s = s + 1;
        text = text + x;
    }
    myFile.close();
    myFile.open(file_name, ios::out);
    srand(time(0));
    kiek = 1 + rand() % k;
    for (int i = 1; i <= s; i++){
        myFile << text[i - 1];
        if (kint % kiek == 0 && kint != 0){
            myFile << '\n';
            kint = 0;
            kiek = 1 + rand() % k;
        }
        kint++;
    }
    myFile.close();
}

void ADD_SYMBOLS(){
    int k, symbol, s = 44, randLetter;
    char x, symbols[] = {'Q', 'A', 'Z', 'W', 'X', 'S', 'C', 'F', 'D', 'E', 'R', 'V', 'G', 'T', 'B', 'y', 'n', 'h', 'l', 'k', 'i', 'o', 'p',
    'u', 'j', 'm', '.', ']', '[', '-', '+', '*', '`', '~', '}', '{', ')', '(', '#', '@', '%', '^', '&', '|'};
    string text = "";
    cout << "[Console] Max symbols next to each other: "; cin >> k;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    if (k < 1){
        k = 1;
    }
    fstream myFile(file_name, ios::in);
    while (myFile >> x){
        text = text + x;
    }
    myFile.close();
    myFile.open(file_name, ios::out);
    srand(time(0));
    symbol = 1 + rand() % k;
    for (string::size_type i = 0; i < text.size(); i++){
        myFile << text[i];
        for (int j = 0; j < symbol; j++){
            randLetter = rand() % s;
            myFile << symbols[randLetter];
        }
        symbol = 1 + rand() % k;
    }
    myFile.close();
}
