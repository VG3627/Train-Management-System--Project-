 Display quadruples
    cout << "Quadruples:" << endl;
    int c = 0 ;
    for (const auto& quad : quadruples) {
        cout << c << ".)  " <<quad.op<< " " << quad.arg1 << " " << quad.arg2 << " = " << quad.result << endl;
        c++ ;
    }

    // Display triples
    cout << "\nTriples:" << endl;
    c = 0 ;
    for (const auto& triple : triples) {
        cout << c << ".)  " << triple.op << " " << triple.arg1 << " " << triple.arg2 << endl;
        c++ ;
    }