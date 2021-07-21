#include <iostream>
#include "fileConnect.h"
using namespace std;


int main(int argc, char const *argv[])
{
    FileConnect file;
    file.addFile(string("ali.acd"));
    file.WriteToFile("ED2B3");
    file.WriteToFile("PD2C3");
    cout << file.undo() << endl;
    cout << file.undo() << endl;
    cout << file.undo() << endl;
    
    return 0;
}
