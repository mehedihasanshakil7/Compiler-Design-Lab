/*
Build a lexical analyzer implementing the following regular expressions:
Float variable = (a-hA-Ho-zO-Z)(a-zA-Z0-9)*
Float Number = 0.(0-9)(0-9)|(1-9)(0-9)*.(0-9)(0-9)
Double Number = 0.(0-9)(0-9)(0-9)+|(1-9)(0-9)*.(0-9)(0-9)(0-9)+
Invalid Input or Undefined = Otherwise
*/
#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("05.input.txt", "r", stdin);
    string word;
    while (getline(cin, word))
    {
        bool isValid = true;
        // Check float variable: if word starts with [a-hA-Ho-zOZ]
        if (tolower(word[0]) >= 'a' && tolower(word[0]) <= 'h' || tolower(word[0]) >= 'o' && tolower(word[0]) <= 'z')
        {
            for (char c : word)
            {
                if (!isalnum(c)) // The remaining characters must be alphanumeric
                {
                    isValid = false; // if not, it is invalid
                    break;
                }
            }
            if (isValid) cout << word + " : "<< "Float variable\n";
        }
        else if (word[0] == '0') // if word starts with '0'
        {
            if (word.size() >= 4 and word[1] == '.') // word length must be 4 and dot at second position
            {                                        // like 0.34 for float and 0.345 for double                                                           
                for (int i = 2; i < word.size(); i++)
                {
                    if (!isdigit(word[i]))
                    {
                        isValid = false;
                        break;
                    }
                }
            }
            else {
                isValid = false;
            }
            if (isValid)
            {
                if (word.substr(2).size() < 3) cout << word + " : "<< "Float number\n";
                else cout << word + " : "<< "Double number\n";
            }
        }
        else if (word[0] >= '1' and word[0] <= '9')
        {
            int dot_position = word.find('.'); 
            string whole = word.substr(0, dot_position); // Split the word into two part
            string fraction = word.substr(dot_position + 1);
            for (char c : whole) // check if the whole part contains any character other than digit
            {
                if (!isdigit(c))
                {
                    isValid = false;
                    break;
                }
            }
            for (char c : fraction) // check if the fraction part contains any character other than digit
            {
                if (!isdigit(c))
                {
                    isValid = false;
                    break;
                }
            }
            if (isValid)
            {
                if (fraction.size() == 0) { // detect 54.
                    isValid = false;
                }
                else if (fraction.size() < 3) cout << word + " : "<< "Float number\n";
                else cout << word + " : "<< "Double number\n";
            }
        }
        else
            isValid = false;
        if (!isValid) cout << word + " : "<< "Invalid Input or Undefined\n";
    }
}