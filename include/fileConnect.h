#ifndef _FILECONNECT_H
#define _FILECONNECT_H
#include <iostream>
#include <fstream>

class FileConnect
{
    private:
        std::fstream myFile;
    public:
        FileConnect();
        void addFile(std::string);
        void WriteToFile(std::string);
        std::string ReadFromFile();
        std::fstream & getFile();
        std::string undo();
        ~FileConnect();
};

#endif /* _FILECONNECT_H */
