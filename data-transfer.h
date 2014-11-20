
#include <string>

using namespace std;

class DataTransfer {

	string reg;
	string instruction;
	int value;

	public:
		DataTransfer();
		DataTransfer(string instruction, string reg, int value);
	private:
		void moveValueToRegister(string reg, int value);
		void loadWord(string destinationRegister, string sourceRegister, int offset);
};