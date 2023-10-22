
#include "key_config_parser.h"
#include "./key_mapping.h"

#include <iostream>
#include <set>
#include <regex>


namespace game::fs::config {
    KeyConfig KeyConfigParser::parse(std::string_view text) {
        std::string delimiter = "\n";
        std::regex line_regex("^([A-Z]+)=([A-Za-z0-9]+)$");

        std::vector<std::string> lines;

        size_t last = 0;
        size_t next;
        while ((next = text.find(delimiter, last)) != std::string::npos) {
            lines.emplace_back(text.substr(last, next - last));
            last = next + 1;
        }
        lines.emplace_back(text.substr(last));

        std::map<sf::Keyboard::Key, ecs::MoveDirection::Enum> mapping;
        std::set < ecs::MoveDirection::Enum > usedDirections;

        for (const auto &item: lines) {
            if (!item.empty()) {
                std::smatch m;

                if (std::regex_match(item, m, line_regex) && m.size() == 3) {
                    auto groupCommand = m[1].str();
                    auto groupKey = m[2].str();

                    ecs::MoveDirection::Enum direction = ecs::MoveDirection::fromString(groupCommand);

                    if (direction == ecs::MoveDirection::Enum::null) {
                        throw std::logic_error("Failed to match direction: " + groupCommand + " in line: " + item);
                    }

                    std::optional<sf::Keyboard::Key> keyOpt = KeyMapping::instance().stringToKey(groupKey);

                    if (!keyOpt.has_value()) {
                        throw std::logic_error("Failed to match key: " + groupKey + " in line: " + item);
                    }

                    auto key = keyOpt.value();

                    if (mapping.contains(key)) {
                        throw std::logic_error("Duplicate key: " + groupCommand + " in line: " + item);
                    }

                    if (usedDirections.contains(direction)) {
                        throw std::logic_error("Duplicate key: " + groupKey + " in line: " + item);
                    }

                    mapping.insert({key, direction});
                    usedDirections.insert(direction);

                } else {
                    throw std::logic_error("Failed to match line: " + item);
                }
            }

        }

        ecs::MoveDirection::Enum requiredCommands[] = {
                ecs::MoveDirection::Enum::LEFT,
                ecs::MoveDirection::Enum::RIGHT,
                ecs::MoveDirection::Enum::UP,
                ecs::MoveDirection::Enum::DOWN,
        };

        for (const auto &item: requiredCommands) {
            if (!usedDirections.contains(item)) {
                throw std::logic_error("No key defined for command: " + ecs::MoveDirection::toString(item));
            }
        }

        return {mapping};
    }
} // config