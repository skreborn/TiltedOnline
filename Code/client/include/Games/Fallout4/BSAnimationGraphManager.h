#pragma once

#if TP_FALLOUT4

#include <Games/Primitives.h>

struct BSFixedString;
struct BShkbAnimationGraph;

struct BSAnimationGraphManager
{
    virtual ~BSAnimationGraphManager();
    virtual void sub_1(void* apUnk1);

    void Release()
    {
        if (InterlockedDecrement(&refCount) == 0)
            this->~BSAnimationGraphManager();
    }

    volatile LONG refCount;

    void* pad_ptrs[6];
    BSTSmallArray<BShkbAnimationGraph> animationGraphs;
    uint8_t pad54[0xC8 - 0x58];
    BSRecursiveLock lock; // C8
    void* unkD0; // D0
    uint32_t animationGraphIndex; // D8

    void DumpAnimationVariables();
};


static_assert(offsetof(BSAnimationGraphManager, animationGraphs) == 0x40);
static_assert(offsetof(BSAnimationGraphManager, lock) == 0xC8);
static_assert(offsetof(BSAnimationGraphManager, animationGraphIndex) == 0xD8);

#endif

