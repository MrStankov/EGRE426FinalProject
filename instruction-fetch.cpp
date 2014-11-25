
#include "instruction-fetch.h"
#include "global.h"

InstructionFetch::InstructionFetch() {
	
}

InstructionFetch::InstructionFetch(struct Instruction &instruction) {
	
	instruction.currentStage = Stage::ID;

}