#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;
int score = 0;
string level1(string s);//level1 = reversed string

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
    
    return false;
}

bool level2() {
    return false;
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

    cout << "You win!\n";
    system("pause");
    return 0;
}
string level1(string s) {
    int left = 0;
    int right = s.length() - 1;
    while (left < right) {
        swap(s[left], s[right]);
        left++;
        right++;
    }
}