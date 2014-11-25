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
			
			struct Instruction instruction = parser.parseInstruction(line);

			instructions.push_back(instruction);

		}
	}

	int numOfInstructions = 0;
	int cycles;
	bool popFront = false;

	for( cycles=0; instructions.empty() == false; ++cycles)	{


		if(instructions.size()-1 < numOfInstructions) {
			numOfInstructions = instructions.size() - 1;
		}

		cout<<"Number of Instructions: "<<numOfInstructions<<endl;
		cout<<"Instruction Size: "<<instructions.size()-1<<endl;

		for( int i=0; i<=numOfInstructions; ++i) {

			try{
				instructions.at(i);
			} catch(exception& e) {
				cout<<"Exception i: "<<i<<endl;
				cout<<"Exception numOfInstructions: "<<numOfInstructions<<endl;
				cout<<"Exception size of instructions: "<<instructions.size()<<endl;
				cout<<"Exception: "<<e.what()<<endl;
			}

			switch(instructions.at(i).currentStage){
				case IF:
					cout<<"IF ";
					InstructionFetch(instructions.at(i));
					break;
				case ID:
					cout<<"ID ";
					InstructionDecode(instructions.at(i));
					break;
				case EX:
					cout<<"EX ";
					Execution(instructions.at(i));
					break;
				case MEM:
					cout<<"MEM ";
					MemoryAccess(instructions.at(i));
					break;
				case WB:
					cout<<"WB ";
					WriteBack(instructions.at(i));
					popFront = true;
					break;
			}

			cout<<"PC: "<<instructions.at(i).pc<<endl;

		}

		if (popFront){
			instructions.pop_front();
			popFront = false;
		}

		if(numOfInstructions <= 4 && instructions.size()-1 >= numOfInstructions){
			cout<<"(numOfInstructions < 4 && instructions.size()-1 > numOfInstructions) instruction.size()-1: "<<instructions.size()-1<<" numOfInstructions: "<<numOfInstructions<<endl;
			numOfInstructions++;
		}


	}

	cout<<"Cycles: "<<cycles<<endl;

	instruction_input_file.close();
	data_input_file.close();


	return 0;

}