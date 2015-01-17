#include "utilities.h"

namespace dstl {

template<typename FwdIt>
void rotate(FwdIt first, FwdIt n_first, FwdIt end)
{
    FwdIt middle = n_first;
    while (first != middle)
    {
        dstl::iter_swap(first++, middle++);
        if (middle == end) {
            dstl::rotate(first, n_first, end);
            break;
        } else if (first == n_first) {
            dstl::rotate(first, middle, end);
            break;
        }
    }
}
#if 0
template<typename RandomIterator, typename T>
RandomIterator
binary_search(RandomIterator start, RandomIterator end, const T& value) 
{
   if (start == end) return end;
   auto = std::distance(start, end);

}
#endif
} // namespace dstl
