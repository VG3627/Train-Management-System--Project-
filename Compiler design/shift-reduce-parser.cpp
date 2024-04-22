#include <bits/stdc++.h>
using namespace std;


bool reduce(string &stack,map<string,string>&grammar)
{
	int idx = -1 ;
	string check ;
	for(int i=stack.size()-1;i>=0;i--)
	{
       check.push_back(stack[i]) ;

	   if(grammar.count(check))
	   {
		idx = i ; break ;
	   }
	}

	

	if(idx == -1)
	{
		return false;
	}

	while(stack.size() != idx)
	{
		stack.pop_back() ;
	}
	stack += grammar[check] ;
	return true;
}


int main()
{
	string input ; cin>>input ;
	// grammar :-
	// E -> E + E
	// E -> E * E
	// E -> a

	string stack ;
	stack.push_back('$') ;

	map<string,string>grammar ;
	grammar["E+E"] = "E" ;
	grammar["E*E"] = "E" ;
	grammar["a"] = "E" ;

	for(int i=0;i<input.size();i++)
	{
		if(stack == "$E" && input[i] == '$')
		{
			cout<<"String Accepted"<<"\n" ; return 0;
		}
		stack.push_back(input[i]) ; // shift operation
        
		while(reduce(stack,grammar)) ;  
	}
    cout<<"String not Accepted"<<"\n" ; 
	return 0;
}
