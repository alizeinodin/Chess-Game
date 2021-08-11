#include "../include/fileConnect.h"
#include <vector>
using namespace std;

FileConnect::FileConnect() {}

string FileConnect::ReadFromFile()
{
    // string result = "NULL";
    // if (!myFile.eof())
    //     getline(myFile, result);
    // return result;
}

void FileConnect::WriteToFile(string data)
{
    cout << data <<endl;
    myFile << data << endl;
    cout << boolalpha << myFile.fail() <<endl;
    myFile.clear();
}

FileConnect::~FileConnect()
{
    myFile.close();
}

fstream &FileConnect::getFile()
{
    //return myFile;
}


void FileConnect::openFile(QString name)
{
    string temp;
    vector<string> strlist;
    fstream gamelist;
    gamelist.open("gamelist.txt", ios::in | ios::app);
    if (!gamelist.is_open())
    {
        cerr << "ERROR game list" << endl;
    }
    while (1)
    {
        getline(gamelist, temp);
        if (gamelist.eof())
        {
            break;
        }
        strlist.push_back(temp);
        gamelist.close();
    }
    if (find(strlist.cbegin(), strlist.cend(), name.toStdString()) != strlist.cend())
    {
        myFile.open(name.toStdString(), ios::app);
        if (!myFile.is_open())
        {
            cerr << "ERROR game file 1" << endl;
        }
    }
    else
    {
        myFile.open(name.toStdString(), ios::out);
        if (!myFile.is_open())
        {
            cerr << "ERROR game file 2" << endl;
        }
        ofstream writegamelist("gamelist.txt" , ios::app);
        writegamelist << name.toStdString() << endl;
        writegamelist.close();
    }
    gamelist.close();
}
