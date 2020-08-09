#include <regex>
#include <fstream>
#include "common/config.h"

bool common::Config::getBool(const std::string &name) {
    bool cfgItem(false);
    if(cfg.find(name) != cfg.end())
        std::istringstream(cfg[name]) >> std::boolalpha >> cfgItem;
    return cfgItem;
}

void common::Config::loadConfig(const std::string &filename) {
    std::string line;
    std::ifstream cfgFile(filename);

    if(cfgFile.is_open()) {
        while (std::getline(cfgFile, line)) {
            auto const re = std::regex{R"(:+)"};
            auto const tokens = std::vector<std::string>(
                std::sregex_token_iterator{begin(line), end(line), re, -1},
                std::sregex_token_iterator{}
            );

            if (tokens.size() == 2) {
                cfg[tokens[0]] = tokens[1];
            }
        }
    }
}
