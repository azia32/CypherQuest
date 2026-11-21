#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;
int score = 0;

string lowercase(string s) {
    for (char& c : s) { //means that each letter "char &c" is looked at and this occurs for lengh of string 
        c = tolower(static_cast<unsigned char>(c)); //static_cast converts input into safe range for tolower
   
    }
    return s; //unsigned char allows letters with negative ASCI values to be ignored
}
string reversestring(string s) { // used for level 1
    int left = 0;
    int right = s.length() - 1;
    while (left < right) {
        swap(s[left], s[right]);
        left++;
        right--;

    }
    return s;
}

// ---------- MENU ----------
void showTitle() {
    // R for raw text (outpouts as is)
    // used https://patorjk.com to get ASCII art
    cout << R"(
    CRYPTGAME 
//     __      _____________.____   _________  ________      _____  ___________                                      
//    /  \    /  \_   _____/|    |  \_   ___ \ \_____  \    /     \ \_   _____/                                      
//    \   \/\/   /|    __)_ |    |  /    \  \/  /   |   \  /  \ /  \ |    __)_                                       
//     \        / |        \|    |__\     \____/    |    \/    Y    \|        \                                      
//      \__/\  / /_______  /|_______ \______  /\_______  /\____|__  /_______  /                                      
//           \/          \/         \/      \/         \/         \/        \/                                       
//      __                                                                                                           
//    _/  |_  ____                                                                                                   
//    \   __\/  _ \                                                                                                  
//     |  | (  <_> )                                                                                                 
//     |__|  \____/                                                                                                  
//                                                                                                                   
//    ______________.___.__________  ___ ________________________ ________   ____ ______________ ____________________
//    \_   ___ \__  |   |\______   \/   |   \_   _____/\______   \\_____  \ |    |   \_   _____//   _____/\__    ___/
//    /    \  \//   |   | |     ___/    ~    \    __)_  |       _/ /  / \  \|    |   /|    __)_ \_____  \   |    |   
//    \     \___\____   | |    |   \    Y    /        \ |    |   \/   \_/.  \    |  / |        \/        \  |    |   
//     \______  / ______| |____|    \___|_  /_______  / |____|_  /\_____\ \_/______/ /_______  /_______  /  |____|   
//            \/\/                        \/        \/         \/        \__>                \/        \/            
)";
}

int mainMenu() {
    showTitle();
    cout << "Press 1 to start \n";
    cout << "Press 2 to quit \n";

    int select;
    cin >> select;
    // Input validation - it can only be 1 or 2
    while (select != 1 && select != 2) {
        cout << "Please enter a valid input! \n";
        cin >> select;
    }
    return select;
}

// ---------- LEVELS ----------
bool level1() {
    string original = "Hello";
    string correct = reversestring(original); // will reverse the word hello
    cout << "--------LEVEL 1--------" << endl;
    cout << "GUESSES PER LEVEL = 5" << endl;
    cout << "Word to Decrypt: " << correct << endl;
    string guess;
    for (int i = 0;i < 5;i++) {
        cin >> guess;
        
            if (lowercase(guess) == lowercase(original)) {
                cout << "CORRECT ! LEVEL 1 complete" << endl;
                score += 25 - (5 * i);
                cout << "SCORE: " << score << endl;
                return true;
            }
          
                cout << "Incorrect! Guess again" << endl;
                cout << "Guesses Remaining: " << 5 - (i+1) << endl;
           }
   
    return false;
}

bool level2() {
    cout << "\n\n" << "Impressive! But let's see how long you can keep this up...." << endl;

    const string CORRECT = "SECRET";
    string guess;

    cout << "--------LEVEL 2--------" << endl;
    cout << "GUESSES PER LEVEL = 4" << endl;
    cout << "Word to Decrypt: VHFUHW " << endl;
    cout << "Cipher: Caesar";
    cout << "Hint: shift is 3 :) \n";

    for (int i = 0; i < 4; i++) {
        cin >> guess;

        if (lowercase(guess) == lowercase(CORRECT)) {
            cout << "CORRECT ! LEVEL 2 complete" << endl;
            score += 25 - (5 * i);;
            cout << "SCORE: " << score << endl;
            return true;
        }

        cout << "Incorrect! Guess again" << endl;
        cout << "Guesses Remaining: " << 4 - (i + 1) << endl;
    }
  
    return false;
}

bool level3() {
    cout << "\n\n" << "You're really good at this aren't you... Well, not for long..." << endl;

        const string CORRECT = "CIPHER";
    string guess;

    cout << "--------LEVEL 2--------" << endl;
    cout << "GUESSES PER LEVEL = 4" << endl;
    cout << "Word to Decrypt: GMTLIV " << endl;
    cout << "Cipher: Caesar";
    cout << "Hint: Hint: The shift is less than 5 \n";


    for (int i = 0; i < 4; i++) {
        cin >> guess;

        if (lowercase(guess) == lowercase(CORRECT)) {
            cout << "CORRECT ! LEVEL 3 complete" << endl;
            score += 25 - (5 * i);;
            cout << "SCORE: " << score << endl;
            return true;
        }

        cout << "Incorrect! Guess again" << endl;
        cout << "Guesses Remaining: " << 4 - (i + 1) << endl;
    }
}

// ---------- MAIN ----------
int main() {
    if (mainMenu() == 2) {
        exit(0);
    }

    if (!level1()) {
        cout << "Game over.\n";
        system("pause");
        return 0;
    }

    if (!level2()) {
        cout << "Game over.\n";
        system("pause");
        return 0;
    }

    if (!level3()) {
        cout << "Game over.\n";
        system("pause");
        return 0;
    }

    cout << "You win!\n";
    system("pause");
    return 0;
}
