#include <iostream>
#include <vector>
#include <unordered_map>
#include <cstring>

using namespace std;

unordered_map<char, unordered_map<char, char>> precedenceTable;

unordered_map<char, unordered_map<char, char>> createPrecedenceTable(const vector<char>& operators) {
    unordered_map<char, unordered_map<char, char>> table;
    for (char op1 : operators) {
        for (char op2 : operators) {
            if (op1 == op2) {
                table[op1][op2] = '=';
            } else {
                table[op1][op2] = ' ';
            }
        }
    }
    return table;
}

void printPrecedenceTable(const unordered_map<char, unordered_map<char, char>>& table, const vector<char>& operators) {
    cout << "The Operator Precedence Relational Table\n=============================================" << endl;
    cout << " ";
    for (char op : operators) {
        cout << op << " ";
    }
    cout << endl;
    for (char op1 : operators) {
        cout << op1 << " ";
        for (char op2 : operators) {
            cout << table.at(op1).at(op2) << " ";
        }
        cout << endl;
    }
}

bool stringcheck(const vector<char>& operators) {
    string input;
    cout << "Enter the string to be checked (non-terminals should be in lowercase cursive letters): ";
    cin >> input;
    input += '$';

    vector<char> stack;
    stack.push_back('$');
    int stackIndex = 0;

    while (stack[stackIndex] != '$' || input[0] != '$') {
        char stackTop = stack[stackIndex];
        char inputTop = input[0];
        if (inputTop == operators[0]) {
            cout << "Error: Invalid input symbol '" << inputTop << "' at the beginning of the string." << endl;
            return false;
        }
        if (stackTop == inputTop) {
            stack.push_back(inputTop);
            stackIndex++;
            input.erase(0, 1);
        } else if (stackIndex > 0 && stackTop == operators[0] && inputTop == '$') {
            cout << "Error: Invalid input symbol '" << inputTop << "' at the end of the string." << endl;
            return false;
        } else if (stackTop == '$') {
            stack.push_back(inputTop);
            stackIndex++;
            input.erase(0, 1);
        } else {
            char precedence = precedenceTable.at(stackTop).at(inputTop);
            if (precedence == '<') {
                stack.push_back(inputTop);
                stackIndex++;
                input.erase(0, 1);
            } else if (precedence == '>') {
                stack.pop_back();
                stackIndex--;
            } else {
                cout << "Error: Invalid symbol combination between stack top '" << stackTop << "' and input top '" << inputTop << "'." << endl;
                return false;
            }
        }
    }

    cout << "String is accepted." << endl;
    return true;
}

bool grammarcheck() {
    string input;
    cout << "Enter the grammar (production) to be checked: ";
    getline(cin, input);

    size_t arrowPos = input.find("->");
    if (arrowPos == string::npos || arrowPos == 0 || arrowPos == input.length() - 2) {
        cout << "Error: Invalid grammar format." << endl;
        return false;
    }

    string production = input.substr(arrowPos + 2);
    for (char c : production) {
        if (!(c >= 'a' && c <= 'z') && c != '(' && c != ')' && c != '^' && c != '/' && c != '*' && c != '+' && c != '-' && c != '|') {
            cout << "Error: Invalid symbol '" << c << "' in the production." << endl;
            return false;
        }
    }

    cout << "Grammar is accepted." << endl;
    return true;
}

int main() {
    int numVariables;
    cout << "Enter the number of LHS variables: ";
    cin >> numVariables;

    vector<char> operators = {'$', '^', '/', '*', '+', '-', '|'};
    precedenceTable = createPrecedenceTable(operators);
    printPrecedenceTable(precedenceTable, operators);

    bool grammarAccepted = true;
    for (int i = 0; i < numVariables; ++i) {
        if (!grammarcheck()) {
            grammarAccepted = false;
            break;
        }
    }

    if (grammarAccepted) {
        if (!stringcheck(operators)) {
            cout << "String is not accepted." << endl;
        }
    } else {
        cout << "Grammar is not accepted." << endl;
    }

    return 0;
}
