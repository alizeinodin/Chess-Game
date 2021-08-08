#ifndef _FILECONNECT_H
#define _FILECONNECT_H
#include <iostream>
#include <fstream>
#include <QString>

class FileConnect
{
    private:
        std::fstream myFile;
    public:
        FileConnect(QString);
        void WriteToFile(std::string);
        std::string ReadFromFile();
        std::fstream & getFile();
        ~FileConnect();
};

#endif /* _FILECONNECT_H */
