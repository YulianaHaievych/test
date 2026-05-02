#pragma once
#include <map>
#include <memory>
#include <functional>
#include <string>

class Container {
    std::map<std::string, std::function<std::shared_ptr<void>()>> services;

public:
    template<typename T>
    void registerService(std::string name,
        std::function<std::shared_ptr<T>()> f) {
        services[name] = f;
    }

    template<typename T>
    std::shared_ptr<T> resolve(std::string name) {
        return std::static_pointer_cast<T>(services[name]());
    }
};