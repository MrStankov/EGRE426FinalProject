#include <string>
#include <iostream>
#import "data-transfer.h"
#import "global.h"

using namespace std;

DataTransfer::DataTransfer() {

}

DataTransfer::DataTransfer(string instruction, string destination, int value) {
	
	if (!instruction.compare(Operation::MV)) {

		moveValueToRegister(destination, value);

	}

}

void DataTransfer::moveValueToRegister(string destination, int value) {

	Register::RegisterValues[destination] = value;

}

void DataTransfer::loadWord(string destinationRegister, string sourceRegister, int offset) {



}