#pragma once

#include "common/buffer/buffer_impl.h"
#include "common/common/logger.h"

namespace Envoy {
namespace Extensions {
namespace NetworkFilters {
namespace MetaProtocolProxy {
namespace Brpc {

enum class BrpcCode {
  NoRoute = 1,
  Error = 1,
};

struct BrpcHeader : public Logger::Loggable<Logger::Id::filter> {
  static const uint32_t HEADER_SIZE;
  static const uint32_t MAGIC;
  uint32_t _body_len;
  uint32_t _meta_len;

  bool decode(Buffer::Instance& buffer);
  bool encode(Buffer::Instance& buffer);

  uint32_t get_body_len() const {return _body_len;};
  uint32_t get_meta_len() const {return _meta_len;};
  void set_body_len(uint32_t body_len) {_body_len = body_len;};
  void set_meta_len(uint32_t meta_len) {_meta_len = meta_len;};   
};

} // namespace Brpc
} // namespace MetaProtocolProxy
} // namespace NetworkFilters
} // namespace Extensions
} // namespace Envoy
