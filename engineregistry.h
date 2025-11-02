#ifndef ENGINEREGISTRY_H
#define ENGINEREGISTRY_H

#include <vector>
#include <string>

class EngineRegistry
{
public:
    EngineRegistry();

    /**
     * @brief getLinks Возвращащет строки-пути к файлам с функцией входа в код движка
     * @return массив строк (vector)
     */
    std::vector<std::string> getLinks() { return enginesLinks; }

private:

    std::vector<std::string> enginesLinks {};

};

#endif // ENGINEREGISTRY_H
