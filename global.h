#include <map>
#include <string>
#include <iostream>
#include <vector>
#include <deque>


namespace Register {
	extern const std::string TO;
	extern const std::string T1;
	extern const std::string T2;
	extern const std::string T3;
	extern const std::string T4;

	extern const std::string S0;
	extern const std::string S1;
	extern const std::string S2;
	extern const std::string S3;

	extern std::map<std::string, int> RegisterValues;
}

namespace Operation {
	extern const std::string ADD;
	extern const std::string ADDI;

	extern const std::string MV;
	extern const std::string LW;
	extern const std::string SW;

	extern const std::string SLT;
	extern const std::string BEQZ;
	extern const std::string BNEZ;
	extern const std::string J;

}

enum Stage { IF, ID, EX, MEM, WB };

struct Instruction {

	std::string fullLine;
	std::string operation;
	int pc;
	std::string rd;
	std::string rs;
	std::string rt;
	int offset;
	int immValue;
	Stage currentStage;

};

std::ostream& operator<<(std::ostream &stream, const std::map<std::string, int>& map);

std::ostream& operator<<(std::ostream &stream, const Instruction &instruction);

std::ostream& operator<<(std::ostream &stream, const std::vector<Instruction> &vector);

std::ostream& operator<<(std::ostream &stream, const std::deque<Instruction> &deque);

