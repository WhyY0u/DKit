#include "KeyBoardUtils.h"

std::string codepoint_to_utf8(unsigned int codepoint) {
    std::stringstream ss;
    if (codepoint <= 0x7F) {
        ss << static_cast<char>(codepoint);
    }
    else if (codepoint <= 0x7FF) {
        ss << static_cast<char>(0xC0 | ((codepoint >> 6) & 0x1F))
            << static_cast<char>(0x80 | (codepoint & 0x3F));
    }
    else if (codepoint <= 0xFFFF) {
        ss << static_cast<char>(0xE0 | ((codepoint >> 12) & 0x0F))
            << static_cast<char>(0x80 | ((codepoint >> 6) & 0x3F))
            << static_cast<char>(0x80 | (codepoint & 0x3F));
    }
    else if (codepoint <= 0x10FFFF) {
        ss << static_cast<char>(0xF0 | ((codepoint >> 18) & 0x07))
            << static_cast<char>(0x80 | ((codepoint >> 12) & 0x3F))
            << static_cast<char>(0x80 | ((codepoint >> 6) & 0x3F))
            << static_cast<char>(0x80 | (codepoint & 0x3F));
    }
    else {
        return "";
    }
    return ss.str();
}
