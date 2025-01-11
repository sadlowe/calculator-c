#ifndef EVALUATOR_H
#define EVALUATOR_H

#include "parser.h"  

double evaluate(Expr *expr);
void free_expr(Expr *expr);

#endif 
