#include <iostream>
#include <cassert>
#include "headers/Calculator.h"

#define MAXLEN 100

int main(int argc, char** argv){

    if (argc >= 2){

        FILE* file = fopen(argv[1], "r");
        char new_line[MAXLEN];

        assert(file != nullptr);
        assert(fgets(new_line, MAXLEN, file) != nullptr);

        Calc new_calc(new_line);
        printf("ans = %lf\n", new_calc.get_ans());
    } else{

        printf("Not enought args\n");
    }
}
