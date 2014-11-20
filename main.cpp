#include <iostream>
#include <fstream>
#include <vector>
#include "global.h"
#include "parser.h"
#include "instruction-fetch.h"
#include "instruction-decode.h"
#include "execution.h"
#include "memory-access.h"
#include "write-back.h"

using namespace std;

static void instruction_fetch_stage(void); 
static void instruction_decode_stage(void);
static void execute_stage(void);
static void memory_stage(void);
static void writeback_stage(void);

int main(int argc, char** argv) {

	if ( argc < 4) {

		cout<<"Improper command input. Please follow this format:\n\t pipelining \"instruction_input_file\" \"data_input_file\" \"mode\" "<<endl;
		return 1;

	}

	Parser parser;
	string line;


	deque<Instruction> instructions;

	ifstream instruction_input_file(argv[1]);
	fstream data_input_file(argv[2]);

	if (instruction_input_file.is_open()){
		while (getline(instruction_input_file, line)){

			// InstructionFetch ifetch;
			// InstructionDecode id;
			// Execution ex;
			// MemoryAccess mem;
			// WriteBack wb;
			
			struct Instruction instruction = parser.parseInstruction(line);

			instructions.push_back(instruction);

		}
	}

	cout<<"Deque of instructions"<<endl;
	cout<<instructions<<endl;


	instruction_input_file.close();
	data_input_file.close();


	return 0;

}

static void instruction_fetch_stage(void) { 
}; 
static void instruction_decode_stage(void) { 
};
static void execute_stage(void) { 
}; 
static void memory_stage(void) { 
}; 
static void writeback_stage(void){ 
}; 
