#ifndef CORE_H
#define CORE_H

#include "../appcore.h"
#include <string>
#include "puppetmodel.h"

class Core
{
public:
    Core(AppCore* appcptr);

private:

    AppCore* acptr;

    std::string name = "engcore";

    PuppetModel *puppet = new PuppetModel();

    void buildModel(std::any data);

    void modelDataRequest();

};

#endif // CORE_H

// здесь можно сделать всю логику вообще
