#ifndef FILESAVER_H
#define FILESAVER_H

#include <string>
#include <any>

class FileSaver
{
public:
    FileSaver();

    void saveTxtFile(std::string name, std::string data);

    void saveBinFile(std::string name, std::any data);

    //void saveIniFIle(std::string name, std::)

    // json
};

#endif // FILESAVER_H
