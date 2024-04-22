#include<bits/stdc++.h>

using namespace std;

// Structure to hold quadruple
struct Quadruple {
    string op;
    string arg1;
    string arg2;
    string result;
};

// Structure to hold triple
struct Triple {
    string op;
    string arg1;
    string arg2;
};

// Structure to hold indirect triple
struct IndirectTriple {
    string op;
    int arg1_index;
    int arg2_index;
};

// Function to generate quadruple
Quadruple generateQuadruple(string op, string arg1, string arg2, string result) {
    Quadruple quad;
    quad.op = op;
    quad.arg1 = arg1;
    quad.arg2 = arg2;
    quad.result = result;
    return quad;
}

int main() {
    vector<string> code = {"a = b * c"};

    vector<Quadruple> quadruples;
    vector<Triple> triples;
    vector<IndirectTriple> indirectTriples;

   

    int temp_index = 1; // Index for generating temporary variables

    for (const auto& line : code) {
        stringstream ss(line);
        string dest, assign, src1,op, src2;
        ss >> dest >> assign >> src1 >> op >> src2;
        // cout<<dest<< " "<<assign<<" "<<src1<<" "<<op<<" "<<src2<<"\n" ;

        Quadruple quad = generateQuadruple(op, src1, src2, dest);
        quadruples.push_back(quad);

        Triple triple = {op, src1, src2};
        triples.push_back(triple);

        // IndirectTriple indirectTriple = {op, temp_index, temp_index + 1};
        // indirectTriples.push_back(indirectTriple);
        // temp_index += 2; // Increment temp_index for next iteration
    }

    //Display quadruples
    cout << "Quadruples:" << endl;
    int c = 0 ;
    for (const auto& quad : quadruples) {
        cout << c << ".)  " <<quad.op<< " " << quad.arg1 << " " << quad.arg2 << " " << quad.result << endl;
        c++ ;
    }

    // Display triples
    cout << "\nTriples:" << endl;
    c = 0 ;
    for (const auto& triple : triples) {
        cout << c << ".)  " << triple.op << " " << triple.arg1 << " " << triple.arg2 << endl;
        c++ ;
    }

    // Display indirect triples
    // cout << "\nIndirect Triples:" << endl;
    // for (const auto& indirectTriple : indirectTriples) {
    //     cout << indirectTriple.op << " " << indirectTriple.arg1_index << " " << indirectTriple.arg2_index << endl;
    // }

    return 0;
}

