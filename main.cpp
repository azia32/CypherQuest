#include <iostream>
#include <string>
#include <cstdlib>
#include <cctype>
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

string caesarLeft(string s, int shift) {
    for (char& c : s) {
        if (isalpha(static_cast<unsigned char>(c))) {
            char base = isupper(static_cast<unsigned char>(c)) ? 'A' : 'a';
            c = static_cast<char>(base + (c - base - shift + 26) % 26);
        }
    }
    return s;
}

// ---------- MENU & SUMMARY ----------
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

string getRank(int finalScore, bool won) {
    if (!won) {
        if (finalScore >= 50) return "Field Operative";
        if (finalScore >= 20) return "Novice Decoder";
        return "Uninitiated";
    }
    if (finalScore >= 115) return "Master Cryptbreaker";
    if (finalScore >= 90) return "Cipher Analyst";
    if (finalScore >= 65) return "Codebreaker";
    return "Survivor";
}

void showSummary(bool won) {
    cout << "\n========================================\n";
    cout << (won ? "           MISSION ACCOMPLISHED          \n" : "               GAME OVER                \n");
    cout << "========================================\n";
    cout << "Final Score : " << score << " / 125\n";
    cout << "Rank        : " << getRank(score, won) << "\n";
    cout << "========================================\n\n";
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

    cout << "--------LEVEL 3--------" << endl;
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

bool level4() {
    cout << "\n\n" << "Getting clever now... let's flip the direction on you." << endl;

    const string CORRECT = "SHADOW";
    string encrypted = caesarLeft(CORRECT, 2); // QFYBMU (2 shifts to the left)
    string guess;

    cout << "--------LEVEL 4--------" << endl;
    cout << "GUESSES PER LEVEL = 4" << endl;
    cout << "Word to Decrypt: " << encrypted << " " << endl;
    cout << "Cipher: Caesar";
    cout << "Hint: Opposite shift direction (left instead of right), and the shift is less than 5 \n";

    for (int i = 0; i < 4; i++) {
        cin >> guess;

        if (lowercase(guess) == lowercase(CORRECT)) {
            cout << "CORRECT ! LEVEL 4 complete" << endl;
            score += 25 - (5 * i);
            cout << "SCORE: " << score << endl;
            return true;
        }

        cout << "Incorrect! Guess again" << endl;
        cout << "Guesses Remaining: " << 4 - (i + 1) << endl;
    }

    return false;
}

bool level5() {
    cout << "\n\n" << "Final level. Every trick stacked together..." << endl;

    const string CORRECT = "LOCK CODE";
    string word1 = "LOCK";
    string word2 = "CODE";

    // Step 1: Last word comes first -> "CODE LOCK"
    string swappedWords = word2 + " " + word1;
    // Step 2: Invert each word -> "EDOC KCOL"
    string invertedWords = reversestring(word2) + " " + reversestring(word1);
    // Step 3: Caesar shift 1 to the left -> "DCNB JBNK"
    string encrypted = caesarLeft(invertedWords, 1);
    string guess;

    cout << "--------LEVEL 5--------" << endl;
    cout << "GUESSES PER LEVEL = 4" << endl;
    cout << "Phrase to Decrypt: " << encrypted << " " << endl;
    cout << "Cipher: Combined (Word Order + Word Invert + Caesar Left Shift)" << endl;
    cout << "Hint: Last word comes first, each word is inverted, and letters use a Caesar shift of 1 to the left \n";

    cin.ignore();
    for (int i = 0; i < 4; i++) {
        getline(cin, guess);

        if (lowercase(guess) == lowercase(CORRECT)) {
            cout << "CORRECT ! LEVEL 5 complete" << endl;
            score += 25 - (5 * i);
            cout << "SCORE: " << score << endl;
            return true;
        }

        cout << "Incorrect! Guess again" << endl;
        cout << "Guesses Remaining: " << 4 - (i + 1) << endl;
    }

    return false;
}

// ---------- MAIN ----------
int main() {
    if (mainMenu() == 2) {
        exit(0);
    }

    if (!level1()) {
        showSummary(false);
        system("pause");
        return 0;
    }

    if (!level2()) {
        showSummary(false);
        system("pause");
        return 0;
    }

    if (!level3()) {
        showSummary(false);
        system("pause");
        return 0;
    }

    if (!level4()) {
        showSummary(false);
        system("pause");
        return 0;
    }

    if (!level5()) {
        showSummary(false);
        system("pause");
        return 0;
    }

    showSummary(true);
    system("pause");
    return 0;
}