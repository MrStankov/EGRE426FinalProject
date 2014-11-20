
using namespace std;

class Parser {
	
	int pc;
	string instruction;
	string registers;
	string rd;
	string rs;
	string rt;
	string imm;

public:
	Parser();
	struct Instruction parseInstruction(string line);

private:
	struct Instruction seperateInstruction(string line);

};