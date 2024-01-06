#include <bits/stdc++.h>

using namespace std;

/*
        INPUT type
    total letters t
    rows r
    columns c
    Letter l
    characters c
*/

int main()
{
    int t;
    // cout<<"total letters :\n";
    cin >> t;
    while (t--) {
        int rows, column;
        // cout << "number of rows :\n";
        cin >> rows;
        // cout << "number of column :\n";
        cin >> column;
        string letter;
        // cout << "Enter the Character you are typing : \n";
        cin >> letter;
        string char_types;
        // cout << "Enter type of characters used (Example #,( etc. (spacebar is already included), (no space in between)\n";
        cin.ignore();
        getline(cin, char_types);
        // cout<<"rows "<<rows<<" columns "<<column<<" types "<<char_types<<endl;
        int st = char_types.size();
        // cout<<"Enter line by line"
        // cout<<"size "<<st<<endl;
        // string for input line
        string s[rows];
        // column and row of spaces
        string c_, r_;
        // column and row of different types
        string cw[st], rw[st];

        for (int i = 0; i < rows; i++)
        {
            // cin.ignore();
            getline(cin, s[i]);
            // cout << s[i] << endl;
            // cout<<"a"<<s[i][5]<<"a"<<endl;
            for (int j = 0; j < column; j++)
            {
                if (s[i][j] == ' ')
                {
                    c_ += to_string(j);
                    r_ += to_string(i);
                }
                else
                {
                    for (int k = 0; k < st; k++)
                    {
                        if (s[i][j] == char_types[k])
                        {
                            // cout<<"matched "<<s[i][j]<<" with "<<char_types[k]<<endl;
                            cw[k] += to_string(j);
                            rw[k] += to_string(i);
                        }
                    }
                }
            }
        }
        // cin.ignore();
        // output buffer
        string _out;
        cout << "char** " << letter << "()\n";
        cout << "{\n";
        cout << "    char **character = getCharGrid();\n";
        for (int i = 0; i < c_.size(); i++)
        {
            _out += "    character[" + to_string(int(r_[i] - '0')) + "]" + "[" + to_string(int(c_[i] - '0')) + "]" + " = ";
        }
        _out += "\' \'";
        _out += ";";
        cout << _out << endl;
        // Do whatever you want with _out in this
        // we print it to console
        //  _out = "";
        for (int i = 0; i < st; i++)
        {
            _out = "";
            for (int j = 0; j < cw[i].size(); j++)
            {
                _out += "    character[" + to_string(int(rw[i][j] - '0')) + "]" + "[" + to_string(int(cw[i][j] - '0')) + "]" + " = ";
            }
            _out += '\'';
            if (char_types[i] == '\\') {
                _out += char_types[i];
            }
            _out += char_types[i];
            _out += '\'';
            // Do whatever you want with out in this
            cout << _out << ";" << endl;
        }
        cout << "    return character;\n";
        cout << "}\n";

    }
    return 0;
}