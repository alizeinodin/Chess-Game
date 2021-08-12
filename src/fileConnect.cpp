#include "../include/fileConnect.h"
#include <vector>
using namespace std;

FileConnect::FileConnect() {}

string FileConnect::ReadFromFile()
{
    string result = "NULL";
    if (!myFile.eof())
        getline(myFile, result);
    return result;
}

void FileConnect::WriteToFile(string data)
{
    cout << data <<endl;
    myFile << data << endl;
    cout << boolalpha << myFile.fail() <<endl;
    myFile.clear();
    cout << boolalpha << myFile.fail() <<endl;
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
    path.clear();
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
        path = name.toStdString();
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
        myFile.close();
        myFile.open(name.toStdString(), ios::app);
        ofstream writegamelist("gamelist.txt" , ios::app);
        path = name.toStdString();
        writegamelist << name.toStdString() << endl;
        writegamelist.close();
    }
    gamelist.close();
}


std::vector<std::string> FileConnect:: get_gamelist()
{
    vector<string> strlist;
    fstream gamelist;
    string temp;
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
    return strlist;
}

void FileConnect:: removelastline()
{
    ofstream s("temp.txt");
    string temp;
    vector<string> d;
    while (1)
    {
        getline(myFile, temp);
        if (myFile.eof())
        {
            break;
        }
        d.push_back(temp);
    }
    while( getline(myFile,temp) )
    {
        if(temp != d.back())
            s << temp << "\n";
    }
}
