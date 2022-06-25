#include "cheats.hpp"

namespace CTRPluginFramework
{
u32 offset=0;

void Number1(MenuEntry *entry)
{
Process::Write32(offset + 0x005989FC,0xEA000030);
}
//終わりの括弧↓
}
