#include "core.h"

Core::Core(AppCore* appcptr) {
    this->acptr = appcptr;

    this->acptr->getEventManager().subscribe("build_model", &Core::modelDataRequest, this);
    this->acptr->getEventManager().subscribe("model_markdown_respond", &Core::buildModel, this);
    this->puppet->addFileExt("tExt");

    this->acptr->getEventManager().sendMessage(AppMessage(name, "send_control_table", this->puppet->getControls()));
}

void Core::modelDataRequest() {
    this->acptr->getEventManager().sendMessage(AppMessage(name, "model_markdown_request", this->puppet->getFileExts()));
}

void Core::buildModel(std::any data) {
    ///
}

// штука из obs

// void Core::buildGui() {



// }


