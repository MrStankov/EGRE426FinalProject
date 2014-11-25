
#include "execution.h"
#include "global.h"

Execution::Execution(){

}

Execution::Execution(struct Instruction &instruction){
	instruction.currentStage = Stage::MEM;

}