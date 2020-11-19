#ifndef MJI_MATH_HPP_INCLUDED_
#define MJI_MATH_HPP_INCLUDED_

#include <cstdint>
#include <mji/xplat.hpp>

namespace mji {

// less-confusingly-named network byte order transformation functions,
// including 64-bit variants
// see https://stackoverflow.com/questions/809902/64-bit-ntohl-in-c/4410728#4410728
using xplat::to_network_order_16;
using xplat::to_network_order_32;
using xplat::to_network_order_64;
using xplat::from_network_order_16;
using xplat::from_network_order_32;
using xplat::from_network_order_64;

}  // namespace mji

#endif  // MJI_MATH_HPP_INCLUDED_
