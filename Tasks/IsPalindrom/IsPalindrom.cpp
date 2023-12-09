#include <string>

bool IsPalindrom(std::string _palindrom)
{
    for(int i = 0; i < _palindrom.length()/2; ++i)
    {
        if (_palindrom[i] != _palindrom[_palindrom.length() - 1 - i]) return false;
    }
    return true;
}