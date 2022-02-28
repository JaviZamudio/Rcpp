#include <windows.h>
#include <iostream>

using namespace std;

int main(int argc, char const *argv[]){
    string fileName = argv[1];
    string flag;
    string command;
    if(fileName == "-h"){
        cout<<"\tHelp\n";
        cout<<"To run directly a .exe file: rc++ [fileName] -r [arg1] [arg2] . . .\n";
        cout<<"To compile and run a .cpp file: rc++ [fileName] [arg1] [arg2] . . .\n";
        cout<<"To get this info: rc++ -h\n";
    }
    else{
        if(argv[2]) flag = argv[2];

        if(flag != "-r" || argc == 2){
            command = "g++ -o " + fileName + ".exe " + fileName + ".cpp";
            system(command.c_str());
        }

        command = ".\\" + fileName;
        for(int i = 2; i < argc; i++){
            flag = argv[i];
            if(flag != "-r"){
                command += " ";
                command += + argv[i];
            }
        }
        system(command.c_str());

    }
    return 0;
}