#ifndef CACHEMANAGER_H
#define CACHEMANAGER_H

#include "filesaver.h"
#include "fileloader.h"
#include "misc.h"
#include "consts.h"



class CacheManager
{
public:
    CacheManager();

    void cacheSubscribe(cacheForm cf) {
        subscribers_deserfns[cf.name] = std::move(cf.desfn);
        subscribers_serfns[cf.name] = std::move(cf.sefn);
    }

    void loadCache();

    void saveCache();

    /**
     * @brief pickCache вызывает десериализующие функции у подписчиков (порядок не уточнён) из массива
     * json объектов
     */
    void distributeCache() {

        for (auto& pair : subscribers_deserfns) {
        }

    }

    /**
     * @brief pickCache вызывает сериализующие функции у подписчиков (порядок не уточнён) и сохраняет
     * их в массив json объектов.
     */
    void pickCache() {

        for (auto& pair : subscribers_serfns) {
            writeCache(pair.second(0));
        }

        // на пока что, до поялвения автосейвов
        saveCache();

    }


private:

    void writeCache(nlohmann::json payload);

    nlohmann::json cache = nlohmann::json::array();

    std::unordered_map<std::string, void_func> subscribers_deserfns {};
    std::unordered_map<std::string, std::function<nlohmann::json(const std::any&)>> subscribers_serfns {};

    FileLoader fileLoader;
    FileSaver fileSaver;

    // таблица icacheable - ссылка на функцию-десериализатор(payload)
};

#endif // CACHEMANAGER_H
