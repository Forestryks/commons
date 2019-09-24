#include <iostream>
#include <cstring>

void assert_errno_internal(bool cond, int line, const char *msg) {
    if (!cond) {
        std::cerr << "Assertation (" << msg << ") [line:" << line << "] failed: " << strerror(errno) << std::endl;
        exit(1);
    }
}

#define assert_errno(cond) assert_errno_internal(cond, __LINE__, #cond)

int main() {
	assert_errno(false);
}
