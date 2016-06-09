//
// Created by joakim on 6/9/16.
//

#include "main.h"


using namespace std;

int main(int argc, char ** argv) {

    ifstream input_file (argv[argc-1]);
    if (input_file.is_open()) {
        run_lexer(input_file);
        input_file.close();
    }

    return 0;
}