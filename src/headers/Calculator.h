
typedef char* line_ptr;
typedef double ans_type;

class Calc{

    line_ptr line = nullptr;
    int cur_pos = 0;

    bool error_has_occured = false;

    ans_type prog_expr();
    ans_type plus_minus_expr();
    ans_type mul_div_expr();
    ans_type power_expr();
    ans_type power_args_expr();
    ans_type unary_op_expr();
    ans_type brackets_expr();
    ans_type num_expr();
public:

    Calc(line_ptr new_line);
    Calc(const Calc&) = delete;
    ~Calc();

    ans_type get_ans();

    Calc operator =(const Calc&) = delete;
};