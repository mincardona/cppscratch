/// provides a cross-platform interface for code which differs in implementation
/// per platform
#ifndef MJI_XPLAT_HPP_INCLUDED_
#define MJI_XPLAT_HPP_INCLUDED_

namespace mji::xplat {

std::uint16_t to_network_order_16(std::uint16_t n);
std::uint32_t to_network_order_32(std::uint32_t n);
std::uint64_t to_network_order_64(std::uint64_t n);
std::uint16_t from_network_order_16(std::uint16_t n);
std::uint32_t from_network_order_32(std::uint32_t n);
std::uint64_t from_network_order_64(std::uint64_t n);

}  // namespace mji::xplat

#endif  // MJI_XPLAT_HPP_INCLUDED_
