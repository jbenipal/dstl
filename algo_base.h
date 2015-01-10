#include "utilities.h"

namespace dstl {

template<typename FwdIt>
void rotate(FwdIt first, FwdIt n_first, FwdIt last)
{
    FwdIt middle = n_first;
    while (first != middle)
    {
        dstl::iter_swap(first++, middle++);
        if (middle == last) {
            dstl::rotate(first, n_first, last);
            break;
        } else if (first == n_first) {
            dstl::rotate(first, middle, last);
            break;
        }
    }
}
} // namespace dstl
