#ifndef INVADERS_CONFIG_H
#define INVADERS_CONFIG_H

#include <map>
#include <string>
#include <sstream>

namespace common {
    class Config {
    public:
        Config() = default;
        ~Config() = default;

        bool getBool(const std::string& name);
        void loadConfig(const std::string& filename);

    private:
        std::map<std::string, std::string> cfg;
    };
}
#endif
