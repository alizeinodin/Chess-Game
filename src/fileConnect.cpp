#include "fileConnect.h"
using namespace std;

FileConnect::FileConnect()
{
}

void FileConnect::addFile(string name)
{
    myFile.open(name, ios::out | ios::in);
    myFile.open(name, ios::app);
    if (!myFile.is_open())
    {
        cerr << "ERROR" << endl;
    }
}

string FileConnect::ReadFromFile()
{
    myFile.seekg(0);
    string result = "NULL";
    if (!myFile.eof())
        getline(myFile, result);
    return result;
}

void FileConnect::WriteToFile(string data)
{
    myFile << data << endl;
}

FileConnect::~FileConnect()
{
    myFile.close();
}

fstream &FileConnect::getFile()
{
    return myFile;
}

string FileConnect::undo()
{
    static int i = 0; // we must seek to -6 in every undo, a enter and 4 character for this example: Ed2b3
    i++;
    myFile.seekg(-6 * i, ios::end);
    string res;
    myFile >> res;
    if(res.empty())
    {
        throw runtime_error("ERROR: You can't undo becuse you are in first move");
    }
    return res;
}