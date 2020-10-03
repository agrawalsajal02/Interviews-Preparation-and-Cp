/* v.v. imp
string input


theory:-when take input by cin>> autimatically '\n' is appended in inout buffer and if you uses getline after it then getline see the '\n' as white spaces and then it saves the string with while space 
causing falult in program

sol:-
1)use cin.ignore(1,'\n')
cin.ignore(INT_MAX, '\n'); 
    it will ignore all the appended '\n' from the input buffer before using getline

2)use cin>>ws
 it is also a manipulator tell the getline function to skip all the leading (startng) spaces in string
 
 3)or use another dummy varable befire getline
           ex:- getline(cin,dummy);   ->this withh take the '\n' input buffer as white space
                getline(cin,string);   -> this will take original string
                
                
                
                now why this all problem not happen with cin>>s;
                because althoush all the data is already loaded in input bufffer it skips all the traling whitespaces , all '\n' , tabs etc until variable is not found
                cin treat '\n' as delemeter (special charactet) thereefore not treat it and remain as it is in input buffer	
                
                



or use this ://use for input sentnnce of string :-  char s[1005];
   // scanf(" %[^\n]s",s);
