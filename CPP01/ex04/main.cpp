#include "Sed.hpp"

int     main(int argc, char **argv) {
    if (argc != 4) {
        std::cout << "program accepts only 3 arguments\n";
        return (1);
    }
    std::string filename = argv[1];
    std::string s1 = argv[2];
    std::string s2 = argv[3];
    if ((filename.find(".txt", filename.length() - 4) == std::string::npos))  {
        std::cout << "first argument should be a .txt" << std::endl;
        return (1);
    }

    std::string filenameR = filename;
    filenameR.insert(filename.length() - 4, ".replace");

    std::ofstream OutFile(filenameR.c_str(), std::ios::out);// write mode for files
    if (OutFile.is_open()) {
        std::ifstream InFile(filename.c_str(), std::ios::in);
        if (InFile.is_open()) {
            std::string line;
            while (std::getline(InFile, line)) {
                Sed strings (line, s1, s2);
                line = strings.replaceStr(line, s1, s2);
                OutFile << line << std::endl;
            }
        }
        else {
            std::cout << "cannot open infile" << std::endl;
            OutFile.close();
            return (1);
        }
        InFile.close();
        OutFile.close();
    }
    else {
        std::cout << "cannot open outfile" << std::endl;
        return (1);
    }
    return (0);
}