#include <cctype>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(void) {
    int T;
    vector<string> res;
    // cout << "Please Enter the Number of Usernames to Be Checked: ";
    cin >> T;

    while(T--) {
        string username;
        // cout << "Please Enter a Username: ";
        cin >> username;

        // If the input is empty or the first character is not a letter
        // the username is invalid.
        if(!isalpha(username[0])) {
            res.push_back("Wrong");
            continue;
        }

        bool hasDigit = false, hasInvalidChar = false;
        for(char& c : username) {
            // If the username contains anything other than
            // alphabetical letters or digits, break from
            // the loop. 
            if(!isalnum(c)) {
                hasInvalidChar = true;
                break;
            }
            // If the current character is a digit, set
            // hasDigit to true
            if(isdigit(c)) {
                hasDigit = true;
            }
        }

        // If the username contains invalid character or doesn't
        // have digits, it's invalid. 
        if(hasInvalidChar || !hasDigit) {
            res.push_back("Wrong");
        }
        else {
            res.push_back("Accept");
        }
    }

    // Output the check result
    for(string& s : res) {
        cout << s << endl;
    }

    return 0;
}
