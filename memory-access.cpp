
#include "memory-access.h"
#include "global.h"

MemoryAccess::MemoryAccess() {

}

MemoryAccess::MemoryAccess(struct Instruction &instruction) {
	instruction.currentStage = Stage::WB;
}