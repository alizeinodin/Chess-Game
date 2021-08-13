#ifndef _FILECONNECT_H
#define _FILECONNECT_H
#include <iostream>
#include <fstream>
#include <QString>
#include <vector>
class FileConnect
{
    private:
        std::fstream myFile;
        std::string path;
    public:
        FileConnect();
        void openFile(QString);
        void WriteToFile(std::string);
        std::string ReadFromFile();
        std::fstream & getFile();
        ~FileConnect();
        std::vector<std::string> get_gamelist();
        void removelastline();
        void setendgame();
};

#endif /* _FILECONNECT_H */
