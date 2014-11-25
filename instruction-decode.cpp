
#include "instruction-decode.h"
#include "global.h"

InstructionDecode::InstructionDecode(){
	
}

InstructionDecode::InstructionDecode(struct Instruction &instruction){
	instruction.currentStage = Stage::EX;
}