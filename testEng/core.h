#ifndef CORE_H
#define CORE_H

#include "../appcore.h"
#include <string>
#include "puppetmodel.h"
#include "../abstractuinodes.h"

class Core
{
public:
    Core(AppCore* appcptr);

private:

    AppCore* acptr;

    std::string name = "engcore";

    PuppetModel *puppet = new PuppetModel(); // todo: ВНИМАНИЕ, указатели лучше не писать по простому
    //std::unique_ptr<PuppetModel> puppet = std::make_unique<PuppetModel>();

    void buildModel(std::any data);

    void modelDataRequest();

    void buildGui();

    std::shared_ptr<UiPage> rootPage;

};

#endif // CORE_H

// здесь можно сделать всю логику вообще, на время
