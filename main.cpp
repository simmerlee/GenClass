#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

string helpMessage()
{
	return "Generate .h and .cpp files in current dirctory.\nUsage:\ngenclass <Class Name> [-<STL head file name>]";
}

string upperCase(string& str)
{
	string ret(str);
	for (unsigned int i = 0; i < ret.length(); i++)
		if (ret[i] >= 'a' && ret[i] <= 'z')
			ret[i] -= 32;
	return ret;
}

int main(int argc, char** argv)
{
	if (argc < 2)
	{
		cout << helpMessage() << endl;
		return 1;
	}
	
	string className = argv[1];
	string arg;
	string path;
	vector<string> headers;
	int argIndex;

	for (argIndex = 2; argIndex < argc; argIndex++)
		headers.push_back(argv[argIndex]);

	string classNameMacro = "_" + upperCase(className) + "_H_";
	ofstream ofs;
	ofs.open(className + ".h");
	ofs << "#ifndef " << classNameMacro << endl;
	ofs << "#define " << classNameMacro << endl << endl;
	for (unsigned int i = 0; i < headers.size(); i++)
		ofs << "#include <" << headers[i].substr(1) << '>' << endl;
	ofs << endl << "class " << className << endl << '{' << endl;
	ofs << "public:" << endl;
	ofs << '\t' << className << "();" << endl;
	ofs << "\t~" << className << "();" << endl;
	ofs << "private:" << endl;
	ofs << "};" << endl << endl;
	ofs << "#endif//" << classNameMacro << endl << endl;
	ofs.close();

	ofs.open(className + ".cpp");
	ofs << "#include \"" << className << ".h\"" << endl << endl;
	if (headers.empty() == false)
		ofs << "using namespace std;" << endl<<endl;
	ofs << className << "::" << className << "()" << endl << '{' << endl << endl << '}' << endl << endl;
	ofs << className << "::~" << className << "()" << endl << '{' << endl << endl << '}' << endl << endl;
	ofs.close();

	return 0;
}
