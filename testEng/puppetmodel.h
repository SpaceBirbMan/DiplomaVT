#ifndef PUPPETMODEL_H
#define PUPPETMODEL_H
#include <vector>
#include <string>
#include <unordered_map>

using ctable = std::unordered_map<std::string, std::string>;

class PuppetModel
{
public:
    PuppetModel();

    void addFileExt(std::string ext) {
        if (fileExt.empty()) {
            fileExt.emplace_back(ext);
        }
    }

    std::vector<std::string> getFileExts() {
        return fileExt;
    }

    ctable getControls() {
        return controls;
    }


private:

    std::vector<std::string> fileExt {};

    ctable controls = ctable();
};

#endif // PUPPETMODEL_H
