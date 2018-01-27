#pragma once

class I18n {

public:
    static std::string get(std::string const&);
    static std::string get(std::string const&, std::vector<std::string> const&);

};