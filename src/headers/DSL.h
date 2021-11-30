#include <stdio.h>

#define SYNTAX_ERROR(expr, action)  if (!(expr) && !error_has_occured){ \
                                        action;                         \
                                        error_has_occured = true;       \
                                    }                                                

#define REQUIRE(symbol) line[cur_pos] == symbol

#define PRINT_ERROR_POS printf("Syntax error: ");                              \
                        fwrite(line, sizeof(char), cur_pos + 1, stdout);       \
                        for(int i = 0; i < cur_pos; i++){ putc('~', stdout); } \
                        putc('^', stdout);

#define SKIP_SPACES while((line[cur_pos] == ' ') && (line[cur_pos] != '\0')){ cur_pos++;}