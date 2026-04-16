#ifndef BLOCK_SERIALIZER_H
#define BLOCK_SERIALIZER_H

#include "BlockCore.h"
#include <string>

class BlockSerializer {
public:
    static std::string serialize_block(const Block& block);
    static Block deserialize_block(const std::string& data);
    static std::string serialize_tx(const Transaction& tx);
    static Transaction deserialize_tx(const std::string& data);
};

#endif
