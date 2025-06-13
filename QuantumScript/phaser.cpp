#include "phaser2.h"
#include "lexer.h"
#include <vector>
#include <string>
#include <stdexcept>
#include <iostream>
#include <algorithm>    
#include <fstream>
#include <direct.h> // For _mkdir on Windows

using std::vector;
using std::string;
using std::cout;
using std::endl;

// Helper function to create directory if it doesn't exist
void createDirectoryIfNotExists(const std::string& dir) {
#ifdef _WIN32
    _mkdir(dir.c_str());
#else
    mkdir(dir.c_str(), 0777);
#endif
}

// Loads a module from QS_Modules directory and returns its content as a string
string importModule(const string& moduleName) {
    string modulePath = "QS_Modules/" + moduleName + ".qs";
    std::ifstream file(modulePath);
    if (!file) {
        // Module not found: return empty string and print message
        cout << "Module not found: " << modulePath << endl;
        return "";
    }
    return string((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
}

// Exports a module to QS_Modules directory
void exportModule(const string& moduleName, const string& code) {
    createDirectoryIfNotExists("QS_Modules");
    string modulePath = "QS_Modules/" + moduleName + ".qs";
    std::ofstream file(modulePath);
    if (!file) {
        throw std::runtime_error("Could not export module: " + modulePath);
    }
    file << code;
    cout << "Module exported: " << modulePath << endl;
}

int phaser() {
    Lexer lexer;
    // List of JavaScript-like keywords
    vector<string> keywords = {
        "if", "else", "while", "for", "return", "function", "var", "let", "const", "import", "export"
    };

    // Example: Import a module
    string moduleCode = importModule("exampleModule");
    if (!moduleCode.empty()) {
        cout << "Imported module code:\n" << moduleCode << endl;
    }

    // Example: Export a module
    string codeToExport = "// QuantumScript module code";
    try {
        exportModule("myExportedModule", codeToExport);
    } catch (const std::exception& ex) {
        cout << ex.what() << endl;
    }

    return 0;
}


