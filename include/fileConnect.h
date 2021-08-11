#ifndef _FILECONNECT_H
#define _FILECONNECT_H
#include <iostream>
#include <fstream>
#include <QString>

class FileConnect
{
    private:
        std::ofstream myFile;
    public:
        FileConnect();
        void openFile(QString);
        void WriteToFile(std::string);
        std::string ReadFromFile();
        std::fstream & getFile();
        ~FileConnect();
};

#endif /* _FILECONNECT_H */
