#include "huffman.h"
#include "exceptions.h"
#include <iostream>
#include <map>

void huffman(std::map<std::string, std::string> params) {
    if (params["mode"] == "c") {
	HuffmanArchiver ha = HuffmanArchiver(params["file"], params["output"]);
	ha.archivate();
    }
    if (params["mode"] == "u") {
	HuffmanArchiver ha = HuffmanArchiver(params["file"], params["output"]);
	ha.unarchivate();
    }
}

void interface(int argc, std::vector<std::string> argv) {
    std::map<std::string, std::string> cmds = {{"-c", ""}, {"-u", ""}, {"-f", ""}, {"--file", ""}, {"-o", ""}, {"--output", ""}};
    std::map<std::string, std::string> params = {{"mode", ""}, {"file", ""}, {"output", ""}};
    if (argc != 5) {
	throw MyExceptions("Error!\nUsage: ./hw_3 [-c / -u] [-f / --file <file_name>] [-o / --output <file_name>]");
    }
    for (int i=0; i<argc; i++) {
	std::cout << argv[i] << std::endl;
	if (cmds.find(argv[i]) == cmds.end())
	    throw MyExceptions("Error! Invalid key");
	if (argv[i] == "-c")
	    params["mode"] = "c";
	if (argv[i] == "-u")
	    params["mode"] = "u";
	if (argv[i] == "-f" || argv[i] == "--file") {
	    if (i < 5) {
		params["file"] = argv[i+1];
		i++;
	    }
	    else
		throw MyExceptions("Error! Incorrect order of args.");
	}
	if (argv[i] == "-o" || argv[i] == "--output") {
	    params["output"] = argv[i+1];
	    i++;
	}
    }

    huffman(params);
}
int main(int argc, char* argv[])
{
    std::vector<std::string> argv_v;
    for (int i=1; i<argc; ++i) {
	std::string str(argv[i]);
	argv_v.push_back(str);
    }
    try {
	interface(argc-1, argv_v);
    }
    catch (MyExceptions e) {
	std::cout << e.what() << std::endl;
    }

    return 0;
}
