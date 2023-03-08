#include "../lexer.hpp"
#include "../procedure_functions.h"

#include "./utils.hpp"
#define macro TEST_NO_MAIN

#include <map>
#include <sstream>

static void test_parameter_list(void){
    test(procedure_Parameter_List, "a()",           {{"Identifier", "a"}, {"Separator", "("}, {"Separator", ")"}}, CURRENT_LOCATION);
    test(procedure_Parameter_List, "a(1001)",       {{"Identifier", "a"}, {"Separator", "("}, {"Integer", "1001"}, {"Separator", ")"}}, CURRENT_LOCATION);
    test(procedure_Parameter_List, "a(boo)",        {{"Identifier", "a"}, {"Separator", "("}, {"Identifier", "boo"}, {"Separator", ")"}}, CURRENT_LOCATION);
    test(procedure_Parameter_List, "a($)",          {{"Identifier", "a"}, {"Separator", "("}, {"Identifier", "$"}, {"Separator", ")"}}, CURRENT_LOCATION);
    test(procedure_Parameter_List, "a(int,char)",   {{"Identifier", "a"}, {"Separator", "("}, {"Keyword", "int"}, {"Separator", ","}, 
                                                     {"Keyword", "char"}, {"Separator", ")"}}, CURRENT_LOCATION);
    test(procedure_Parameter_List, "a(204,string)", {{"Identifier", "a"}, {"Separator", "("},  {"Integer", "204"}, {"Separator",  ","}, 
                                                     {"Identifier", "string"}, {"Separator", ")"}},  CURRENT_LOCATION);
    
    
}