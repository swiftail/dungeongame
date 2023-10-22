
#include "config_serializer.h"

namespace game::fs::config {
    KeyConfig ConfigSerializer::read() {
        try {
            std::string data = Files::readToString(_path);
            return _parser.parse(data);
        } catch (const std::logic_error& err) {
            std::cerr << "Failed to parse config, using defaults: " << err.what() << '\n';
            return KeyConfig::getDefault();
        }
    }

    ConfigSerializer::ConfigSerializer(std::string_view path) : _path(std::string(path)) {}
} // config