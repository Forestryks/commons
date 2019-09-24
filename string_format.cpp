#include <string>
#include <vector>
#include <cstdarg>
#include <iostream>

std::string vformat(const char *fmt, va_list args) {
    std::vector<char> v(512);
    while (true) {
        va_list args2;
        va_copy(args2, args);
        int res = vsnprintf(v.data(), v.size(), fmt, args2);

        if ((res >= 0) && (res < static_cast<int>(v.size()))) {
            va_end(args);
            va_end(args2);
            return std::string(v.data());
        }

        size_t size;
        if (res < 0) {
            size = v.size() * 2;
        } else {
            size = static_cast<size_t>(res) + 1;
        }

        v.clear();
        v.resize(size);
        va_end(args2);
    }
}

std::string format(const char *fmt, ...) {
    va_list args;
    va_start(args, fmt);
    return vformat(fmt, args);
}

class StringFormatter {
public:
    StringFormatter(std::string str) : str(std::move(str)) {}
    StringFormatter(const char *ptr) : str(ptr) {}
    template<typename ...T>
    std::string operator()(T... args) {
        return format(str.c_str(), args...);
    }
private:
    std::string str;
};

StringFormatter operator "" _format(const char *s, std::size_t len) {
    return StringFormatter(s);
}

int main() {
    std::cout << format("Hello %s!", "Andrey") << std::endl;
    std::cout << "Hello %s! "_format("Polina") << std::endl;
}
