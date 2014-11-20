#include "global.h"
#include <map>


namespace Operation {
	const std::string ADD = "ADD";
	const std::string ADDI = "ADDI";

	const std::string MV = "MV";
	const std::string LW = "LW";
	const std::string SW = "SW";

	const std::string SLT = "SLT";
	const std::string BEQZ = "BEQZ";
	const std::string BNEZ = "BNEZ";
	const std::string J = "J";

}

namespace Register {

	const std::string ZERO = "$ZERO";

	const std::string TO = "$T0";
	const std::string T1 = "$T1";
	const std::string T2 = "$T2";
	const std::string T3 = "$T3";
	const std::string T4 = "$T4";

	const std::string S0 = "$S0";
	const std::string S1 = "$S1";
	const std::string S2 = "$S2";
	const std::string S3 = "$S3";

	std::map<std::string, int> RegisterValues = std::map<std::string, int>{{ZERO, 0}, 
																			{TO, 0}, {T1, 0}, {T2, 0}, {T3, 0}, {T4, 0},
																			{S0, 0}, {S1, 0}, {S2, 0}, {S3, 0}};

}

std::ostream& operator<<(std::ostream &stream, const Instruction &instruction) {

	stream<<std::endl;
	stream<<"Line: "<<instruction.fullLine <<std::endl;
	stream<<"Instruction: "<<instruction.operation <<std::endl;
	stream<<"Instruction Address: "<<instruction.pc <<std::endl;
	stream<<"RD: "<<instruction.rd <<std::endl;
	stream<<"RS: "<<instruction.rs <<std::endl;
	stream<<"RT: "<<instruction.rt <<std::endl;
	stream<<"Offset: "<<instruction.offset <<std::endl;
	stream<<"Immediate Value: "<<instruction.immValue <<std::endl;

	switch(instruction.currentStage) {
		case IF: stream<<"Current Stage: Instruction Fetch"<<std::endl; break;
		case ID: stream<<"Current Stage: Instruction Decode"<<std::endl; break;
		case EX: stream<<"Current Stage: Execution"<<std::endl; break;
		case MEM: stream<<"Current Stage: Memory Access"<<std::endl; break;
		case WB: stream<<"Current Stage: Write-back"<<std::endl; break;
	}

	return stream;
}

std::ostream &operator<<(std::ostream &stream, const std::map<std::string, int>& map) {
  for (typename std::map<std::string, int>::const_iterator it = map.begin(); it != map.end(); ++it) {
      stream << (*it).first << " --> " << (*it).second << std::endl;
   }
  return stream;
}

std::ostream& operator<<(std::ostream &stream, const std::vector<Instruction> &vector){
	for (Instruction i : vector) {
		stream<<i<<std::endl;
	}
	return stream;
}

std::ostream& operator<<(std::ostream &stream, const std::deque<Instruction> &deque) {
	for (Instruction i : deque) {
		stream<<i<<std::endl;
	}
	return stream;
}





