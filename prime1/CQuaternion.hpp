#ifndef PRIME_WATCH_DUMP_CQUATERNION_HPP
#define PRIME_WATCH_DUMP_CQUATERNION_HPP

#include "game_value.h"

class CQuaternion : public game_value<0x4 * 4> {
public:
    CQuaternion(uint32_t base_ptr, uint32_t ptr_offset = 0) : game_value(base_ptr, ptr_offset) {}

    game_array<game_float, 0x4> values = game_array<game_float, 0x4>(ptr(), 0x0);
    game_array<game_float, 0x4> rawValues = game_array<game_float, 0x4>(ptr(), 0x0);
    game_float x = game_float(ptr(), 0x0);
    game_float y = game_float(ptr(), 0x4);
    game_float z = game_float(ptr(), 0x8);
    game_float w = game_float(ptr(), 0xC);

#ifdef PRIME_DUMP_JSON
    inline nlohmann::json json() {
      return {x.read(), y.read(), z.read(), w.read()};
    }

    inline nlohmann::json rawJson() {
      return rawValues.json();
    }
#endif
};

#endif //PRIME_WATCH_DUMP_CQUATERNION_HPP
