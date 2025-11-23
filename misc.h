#ifndef MISC_H
#define MISC_H

#include <string>
#include <functional>
#include <any>
#include <nlohmann/json.hpp>

using json = nlohmann::json;
using payload = std::vector<uint8_t>; //байт-буфер для payload
using void_func = std::function<void(const std::any&)>;

struct cacheForm {
    std::string name;
    void_func desfn; // сюда помещается функция десериализации кеша
    std::function<nlohmann::json(const std::any&)> sefn; // сюда помещается функция сериализации кеша
};

struct subStruct {
    std::string name;
    std::function<void(const std::any&)> callback; // todo: Мб ссылка нужна

    subStruct(std::string m, std::function<void(const std::any&)> cb)
        : name(std::move(m)), callback(std::move(cb)) {}
};

enum UIElements {
    CONTROL_TABLE,
    COMPONENT_TREE,
    SLIDER,
    BUTTON
};

#endif // MISC_H
