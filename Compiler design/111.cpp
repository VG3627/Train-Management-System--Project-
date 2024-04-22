#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Quadruple {
    string op;
    string arg1;
    string arg2;
    string result;
};

struct Triple {
    string op;
    string arg1;
    string arg2;
};

struct IndirectTriple {
    string op;
    int arg1;
    int arg2;
};

vector<Quadruple> generateQuadruples(const string& expression) {
    vector<Quadruple> quadruples;
    string a, b, c, d;
    a = expression.substr(0, 1);
    b = expression.substr(2, 1);
    c = expression.substr(4, 1);
    d = expression.substr(6, 1);

    quadruples.push_back({"*", c, d, "temp"});
    quadruples.push_back({"+", b, "temp", "temp"});
    quadruples.push_back({"=", "temp", "", a});

    return quadruples;
}

vector<Triple> generateTriples(const string& expression) {
    vector<Triple> triples;
    string a, b, c, d;
    a = expression.substr(0, 1);
    b = expression.substr(2, 1);
    c = expression.substr(4, 1);
    d = expression.substr(6, 1);

    triples.push_back({"*", c, d});
    triples.push_back({"+", b, "temp"});

    return triples;
}

vector<IndirectTriple> generateIndirectTriples(const string& expression) {
    vector<IndirectTriple> indirectTriples;
    string a, b, c, d;
    a = expression.substr(0, 1);
    b = expression.substr(2, 1);
    c = expression.substr(4, 1);
    d = expression.substr(6, 1);

    indirectTriples.push_back({"*", 2, 3});
    indirectTriples.push_back({"+", 1, 4});

    return indirectTriples;
}

int main() {
    string expression = "a=b+c-r";

    cout << "Quadruples:" << endl;
    vector<Quadruple> quadruples = generateQuadruples(expression);
    for(const auto& quad : quadruples) {
        cout << quad.op << " " << quad.arg1 << " " << quad.arg2 << " " << quad.result << endl;
    }

    cout << "\nTriples:" << endl;
    vector<Triple> triples = generateTriples(expression);
    for(const auto& trip : triples) {
        cout << trip.op << " " << trip.arg1 << " " << trip.arg2 << endl;
    }

    cout << "\nIndirect Triples:" << endl;
    vector<IndirectTriple> indirectTriples = generateIndirectTriples(expression);
    for(const auto& trip : indirectTriples) {
        cout << trip.op << " " << trip.arg1 << " " << trip.arg2 << endl;
    }

    return 0;
}
