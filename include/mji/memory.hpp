#ifndef MJI_MEMORY_HPP_INCLUDED_
#define MJI_MEMORY_HPP_INCLUDED_

namespace mji {

struct c_free_deleter {
    void operator()(void* p) const {
        std::free(p);
    }
};

/// A unique_ptr which is freed using std::free. Useful for iteroperation with
/// some C libraries that return dynamically allocated buffers.
template<typename T>
using unique_ptr_malloced = std::unique_ptr<T, c_free_deleter>;

// uses memcpy to type pun
template<typename To, typename From>
constexpr To* memcpy_pun(To* pt, From* pf) {
    memcpy(pt, pf, sizeof(*pt));
    return pt;
}

// overload which default constructs the To object and returns it after calling
// memcpy
template<typename To, typename From>
constexpr To memcpy_pun(From* pf) {
    To t;
    memcpy_pun(&t, pf);
    return t;
}

}  // namespace mji

#endif  // MJI_MEMORY_HPP_INCLUDED_
