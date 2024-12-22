//
// Created by pmrj on 21-12-2024.
//

#ifndef QUEUEFAMILYINDICES_H
#define QUEUEFAMILYINDICES_H
#include <cstdint>
#include <optional>

struct QueueFamilyIndices {
    std::optional<uint32_t> graphicsFamily;

    bool isComplete() {
        return graphicsFamily.has_value();
    }
};

#endif //QUEUEFAMILYINDICES_H
