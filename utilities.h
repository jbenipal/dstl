#include <utility>

namespace dstl {

template<typename Iterator>
void iter_swap(Iterator it1, Iterator it2) {
    using std::swap;
    swap(*it1, *it2);
}
} // namespace dstl
