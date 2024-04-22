#include <bits/stdc++.h>
using namespace std;


map<char,int> precedenceMap = {{'$', 1}, {'+', 2}, {'*', 3}, {'t', 4}};


int comparePrecedence(char &op1, char &op2){
    return  (precedenceMap[op1] - precedenceMap[op2]);
}


char previousOperator(stack<char> st){
    char prev = '#';
    while(!st.empty()){
        char x = st.top();
        if(precedenceMap.count(x)){
            prev = x; break;
        }else{
            st.pop();
        }
    }
    return prev;
}


int main()
{
    int m; cin >> m;
    map<string,char> prod;
    for(int i{};i<m;i++){
        string s; cin >> s;
        prod[s] = 'T';
    }


    string s; cin >> s;
    stack<char> st;
    st.push('$');
    int i{};
    string ans = "rejected";
    int c{};
    while(!st.empty()){
        char a = previousOperator(st);
        if(a == '#') break;
        char b = s[i];
        if(a == '$' && b == '$'){
            ans = "Accepted";
            break;
        }
        if(comparePrecedence(a,b) < 0) {
            st.push(b);
            i++;
        }else{
            string temp = "";
            if(st.top() == 't'){
                temp += 't';
                st.pop();
            }else{
                if (!st.empty()) { temp += st.top();  st.pop(); } else { break; }
                if (!st.empty()) { temp += st.top();  st.pop(); } else { break; }
                if (!st.empty()) { temp += st.top();  st.pop(); } else { break; }
            }
            if(!prod.count(temp)) break;
            st.push(prod[temp]);
        }
    }
    cout << ans << "\n";
    return 0;
}
