#include "headers/Calculator.h"
#include "headers/DSL.h"

#include <cmath>
#include <cstring>

#define MAX_UNARY_OP_SIZE 3
#define MAX_NUM_SIZE 10

#define IS_DOUBLE ((line[cur_pos + num_size] >= '0') && (line[cur_pos + num_size] <= '9')) || (line[cur_pos + num_size])

Calc::Calc(line_ptr new_line){

    line = new char[strlen(new_line) + 1];
    memcpy(line, new_line, strlen(new_line) + 1);
}

Calc::~Calc(){

    delete[] line;
}

ans_type Calc::get_ans(){

    cur_pos = 0;
    error_has_occured = false;

    printf("expr = |%s|\n", line);
    return prog_expr();
}

ans_type Calc::prog_expr(){

    ans_type val = plus_minus_expr();
    SKIP_SPACES;
    REQUIRE('\0');

    return val;
}

ans_type Calc::plus_minus_expr(){

    ans_type val = mul_div_expr();

    while (REQUIRE('+') || REQUIRE('-')){
        
        char cur_op = line[cur_pos];
        cur_pos++;
        ans_type val2 = mul_div_expr();

        if (cur_op == '+'){

            val += val2;
        } else{

            val -= val2;
        }
    }

    return val;
}

ans_type Calc::mul_div_expr(){

    ans_type val = power_expr();

    while (REQUIRE('*') || REQUIRE('/')){

        char cur_op = line[cur_pos];
        cur_pos++;
        ans_type val2 = power_expr();

        if (cur_op == '*'){

            val *= val2;
        } else{

            val /= val2;
        }
    }
    
    return val;
}

ans_type Calc::power_expr(){

    ans_type val = power_args_expr();

    if (REQUIRE('^')){
        
        cur_pos++;
        ans_type val2 = power_args_expr();

        val = pow(val, val2);
    }

    return val;
}

ans_type Calc::power_args_expr(){

    ans_type val = 0;

    if (REQUIRE('(')){

        cur_pos++;
        val = unary_op_expr();
        SYNTAX_ERROR(REQUIRE(')'), PRINT_ERROR_POS; cur_pos = strlen(line));    
    } else{

        val = brackets_expr();
    }

    return val;
}

ans_type Calc::unary_op_expr(){

    ans_type val = 0;

    char unary_op[MAX_UNARY_OP_SIZE + 1];
    unary_op[MAX_UNARY_OP_SIZE] = '\0';

    for (int i = 0; i < MAX_UNARY_OP_SIZE; i++){

        unary_op[i] = line[cur_pos + i];
    }

    if (strcmp(unary_op, "sin") == 0){

        cur_pos += 3;
        return sin(brackets_expr());
    } else{

        if (strcmp(unary_op, "cos") == 0){

            cur_pos += 3;
            return cos(brackets_expr());
        } else{

            unary_op[MAX_UNARY_OP_SIZE - 1] = '\0';

            if (strcmp(unary_op, "tg") == 0){

                cur_pos += 2;
                return tan(brackets_expr());
            }
        }
    }

    return brackets_expr();
}

ans_type Calc::brackets_expr(){

    ans_type val = 0;

    if (REQUIRE('(')){

        cur_pos++;
        val = plus_minus_expr();
        SYNTAX_ERROR(REQUIRE(')'), PRINT_ERROR_POS; cur_pos = strlen(line));
    } else{

        val = num_expr();
    }

    return val;
}

ans_type Calc::num_expr(){
    
   /* int num_size = 0;
    char cur_num[MAX_NUM_SIZE];
    for (num_size = 0; (num_size < MAX_NUM_SIZE) && (IS_DOUBLE); num_size++){

        cur_num[num_size] = line[cur_pos + num_size];
    }

    SYNTAX_ERROR(num_size < MAX_NUM_SIZE, PRINT_ERROR_POS; cur_pos = strlen(line));

    if *///???????? ??????

    ans_type val = 0;
    int num_size = 0;

    for (; (line[cur_pos + num_size] >= '0') && (line[cur_pos + num_size] <= '9'); num_size++){

        val = val * 10 + (line[cur_pos + num_size] - '0'); 
    }

    cur_pos += num_size;
    SYNTAX_ERROR(num_size != 0, PRINT_ERROR_POS; cur_pos = strlen(line));
    
    return val;
}
