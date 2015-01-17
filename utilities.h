#include <utility>
#include <typeinfo>
#include <cxxabi.h>
#include <string>
#include <cstdlib>

namespace dstl {

template<typename Iterator>
void iter_swap(Iterator it1, Iterator it2) {
    using std::swap;
    swap(*it1, *it2);
}

template<typename T>
std::string demangler(const T& x)
{
    int status;
    char *realname;

    realname = abi::__cxa_demangle(typeid(x).name(),0,0,&status);
    std::string output(realname);
    free(realname);

    return output;
}
} // namespace dstl
