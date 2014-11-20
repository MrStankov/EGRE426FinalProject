#include <iostream>
#include <string>
#include <sstream>
#include "parser.h"
#include "global.h"
#include "arithmatic.h"
#include "data-transfer.h"


using namespace std;


Parser::Parser() {
	


}

struct Instruction Parser::parseInstruction(string line) {

	struct Instruction instruction = seperateInstruction(line);

	return instruction;

	// if (!instruction.compare(Operation::ADD)) {

	// 	cout<<"ADD instruction"<<endl;
	// 	cout<<"Instruction: "<<instruction<<" Rd: "<<rd<<" Rt: "<<rt<<endl;

	// 	Arithmatic arithmatic(instruction);

	// } else if (!instruction.compare(Operation::MV)) {

	// 	cout<<"MV instruction"<<endl;
	// 	cout<<"Instruction: "<<instruction<<" Rd: "<<rd<<" Rt: "<<rt<<endl;

	// 	DataTransfer dataTransfer(instruction, rd, 1000);
	// }

	// cout<<"Register Values: "<<endl<<Register::RegisterValues<<endl;

}

struct Instruction Parser::seperateInstruction(string line) {

	string delimiter = "\t";
	int pos = 0;
	string token;

	string originalLine = line;

	int offset = 0;
	int immValue = 0;
	int pc;

	/**
	 * Gets the instruction line number for the input.txt line
	 */
	if ((pos = line.find(delimiter)) != string::npos) {

		stringstream ss(line.substr(0, pos));
		pc = ss >> pc ? pc : 0;

	    line.erase(0, pos + delimiter.length());
	}

	/**
	 * Gets the actual instruction from the line
	 */
	if ((pos = line.find(delimiter)) != string::npos) {

		instruction = line.substr(0, pos);
	    line.erase(0, pos + delimiter.length());

	}

	/**
	 * Parsing the Registers
	 */
	registers = line;
	delimiter = ", ";

	/**
	 * Gets the rd register
	 */
	if ((pos = line.find(delimiter)) != string::npos) {

		rd = line.substr(0, pos);
		line.erase(0, pos + delimiter.length());

	}

	/**
	 * Gets the rs register, if ", " doesn't exist just set it to the value of line
	 * Most likely this should never find a ", ", but keep this here just to be sure
	 */
	if ((pos = line.find(delimiter)) != string::npos) {

		stringstream ss(line.substr(0, pos));

		rs = line.substr(0, pos);
		line.erase(0, pos + delimiter.length());

	} else if ((pos = line.find("(")) != string::npos) {

		stringstream ss(line.substr(0, pos));

		offset = ss >> offset ? offset : 0;
		line.erase(0, pos + string("(").length());

		rs = line;

		if ((pos = line.find(")")) != string::npos) {
			line.erase(pos, pos + string(")").length());
			rs = line.substr(0, pos);
			line.erase(0, pos);
		}


	}else {
		stringstream ss(line);

		if (ss >> immValue) {
			rs = "";
		} else {
			rs = line;
		}

		line = "";
	}


	/**
	 * Gets the rt register, if ", " doesn't exist just set it to the value of line
	 */
	if ((pos = line.find(delimiter)) != string::npos) {

		rt = line.substr(0, pos);
		line.erase(0, pos + delimiter.length());
		
	} else if ((pos = line.find("(")) != string::npos) {

		stringstream ss(line.substr(0, pos));

		offset = ss >> offset ? offset : 0;
		line.erase(0, pos + string("(").length());

		if ((pos = line.find(")")) != string::npos) {
			line.erase(pos, pos + string(")").length());
		}

		rt = line;
 
	} else {
		stringstream ss(line);

		if (ss >> immValue) {
			rt = "";
		} else {
			rt = line;
		}

		line = "";
	}



	// cout<< "Instruction Address: "<<pc<<endl;
	// cout<< "Instruction: "<<instruction<<endl;
	// cout<< "Registers: "<<registers<<endl;
	// cout<< "Rd: "<<rd<<endl;
	// cout<< "Rt: "<<rt<<endl;
	// cout<< "Rs: "<<rs<<endl;

	Instruction instruct = { originalLine, instruction, pc, rd, rs, rt, offset, immValue, Stage::IF};

	return instruct;
}