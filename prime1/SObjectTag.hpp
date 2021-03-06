#ifndef PRIME_WATCH_DUMP_SOBJECTTAG_HPP
#define PRIME_WATCH_DUMP_SOBJECTTAG_HPP

#include "game_value.h"

class SObjectTag : public game_value<0x8> {
public:
    SObjectTag(uint32_t base_ptr, uint32_t ptr_offset = 0) : game_value<0x8>(base_ptr, ptr_offset) {}

    game_u32 fourCC = game_u32(ptr(), 0x0);
    game_u32 id = game_u32(ptr(), 0x4);

#ifdef PRIME_DUMP_JSON
    inline nlohmann::json json() {
      nlohmann::json res;
      res["fourCC"] = fourCC.read();
      res["id"] = id.read();
      return res;
    }
#endif
};

#endif //PRIME_WATCH_DUMP_SOBJECTTAG_HPP

