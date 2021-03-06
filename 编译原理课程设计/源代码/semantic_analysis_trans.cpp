#include "semantic_analysis_trans.h"

typedef void(*voidptr)();
map<string,voidptr> SA_mp;

void semantic_analysis_init() {
    voidptr p;
    p = [](){SA.program_end();;};
    SA_mp["@0"] = p;
    p = [](){SA.program_merge_function();;};
    SA_mp["@1"] = p;
    p = [](){SA.push_function_block();;};
    SA_mp["@2"] = p;
    p = [](){SA.function_create_synbl_and_vall();;};
    SA_mp["@3"] = p;
    p = [](){SA.function_end();;};
    SA_mp["@4"] = p;
    p = [](){SA.function_get_name();;};
    SA_mp["@5"] = p;
    p = [](){SA.push_type_name();;};
    SA_mp["@6"] = p;
    p = [](){SA.function_re_parameter();SA.pop_type_name();;};
    SA_mp["@7"] = p;
    p = [](){SA.push_type_name();;};
    SA_mp["@8"] = p;
    p = [](){SA.pop_type_name();;};
    SA_mp["@9"] = p;
    p = [](){SA.push_Var_init();;};
    SA_mp["@10"] = p;
    p = [](){SA.Var_init_end();;};
    SA_mp["@11"] = p;
    p = [](){SA.push_variable_name();;};
    SA_mp["@12"] = p;
    p = [](){SA.create_or_find_variable_not_arr();;};
    SA_mp["@13"] = p;
    p = [](){SA.insert_const();;};
    SA_mp["@14"] = p;
    p = [](){SA.push_arr_dimension();;};
    SA_mp["@15"] = p;
    p = [](){SA.create_or_find_variable_arr();SA.pop_arr_dimension();;};
    SA_mp["@16"] = p;
    p = [](){SA.Var_init_variable();;};
    SA_mp["@17"] = p;
    p = [](){SA.Var_init_variable_in_list();;};
    SA_mp["@18"] = p;
    p = [](){SA.push_type_name();;};
    SA_mp["@19"] = p;
    p = [](){SA.define_str();;};
    SA_mp["@20"] = p;
    p = [](){SA.pop_type_name();;};
    SA_mp["@21"] = p;
    p = [](){SA.re_str_variable();;};
    SA_mp["@22"] = p;
    p = [](){SA.create_str();;};
    SA_mp["@23"] = p;
    p = [](){SA.push_code_block();;};
    SA_mp["@24"] = p;
    p = [](){SA.code_block_end();};
    SA_mp["@25"] = p;
    p = [](){SA.code_block_merge_code_block();;};
    SA_mp["@26"] = p;
    p = [](){SA.code_block_merge_if_else_block();;};
    SA_mp["@27"] = p;
    p = [](){SA.code_block_merge_jmp();;};
    SA_mp["@28"] = p;
    p = [](){SA.code_block_merge_assignment();;};
    SA_mp["@29"] = p;
    p = [](){SA.push_if_else_block();;};
    SA_mp["@30"] = p;
    p = [](){SA.if_else_merge_logic();;};
    SA_mp["@31"] = p;
    p = [](){SA.if_else_merge_if_code_block();;};
    SA_mp["@32"] = p;
    p = [](){SA.if_else_end();;};
    SA_mp["@33"] = p;
    p = [](){SA.if_else_merge_else_code_block();;};
    SA_mp["@34"] = p;
    p = [](){SA.push_while_block();;};
    SA_mp["@35"] = p;
    p = [](){SA.while_merge_logic();;};
    SA_mp["@36"] = p;
    p = [](){SA.while_merge_code_block();SA.while_end();SA.code_block_merge_while();;};
    SA_mp["@37"] = p;
    p = [](){SA.push_while_block();;};
    SA_mp["@38"] = p;
    p = [](){SA.while_merge_code_block();;};
    SA_mp["@39"] = p;
    p = [](){SA.while_merge_logic();;};
    SA_mp["@40"] = p;
    p = [](){SA.do_while_end();SA.code_block_merge_while();;};
    SA_mp["@41"] = p;
    p = [](){SA.for_merge_logic();;};
    SA_mp["@42"] = p;
    p = [](){SA.for_merge_code_block();SA.for_end();SA.code_block_merge_for();;};
    SA_mp["@43"] = p;
    p = [](){SA.for_merge_init();;};
    SA_mp["@44"] = p;
    p = [](){SA.push_logic_w();;};
    SA_mp["@45"] = p;
    p = [](){SA.logic_two_operation();;};
    SA_mp["@46"] = p;
    p = [](){SA.push_logic_w();;};
    SA_mp["@47"] = p;
    p = [](){SA.logic_two_operation();;};
    SA_mp["@48"] = p;
    p = [](){SA.push_logic_w();;};
    SA_mp["@49"] = p;
    p = [](){SA.logic_one_operation();;};
    SA_mp["@50"] = p;
    p = [](){SA.arithmetic_to_logic();;};
    SA_mp["@51"] = p;
    p = [](){SA.push_logic_w();;};
    SA_mp["@52"] = p;
    p = [](){SA.arithmetic_to_logic();SA.logic_two_operation();;};
    SA_mp["@53"] = p;
    p = [](){SA.push_logic_w();;};
    SA_mp["@54"] = p;
    p = [](){SA.arithmetic_to_logic();SA.logic_two_operation();;};
    SA_mp["@55"] = p;
    p = [](){SA.push_logic_w();;};
    SA_mp["@56"] = p;
    p = [](){SA.arithmetic_to_logic();SA.logic_two_operation();;};
    SA_mp["@57"] = p;
    p = [](){SA.for_merge_last();;};
    SA_mp["@58"] = p;
    p = [](){SA.push_continues_or_break();;};
    SA_mp["@59"] = p;
    p = [](){SA.push_continues_or_break();;};
    SA_mp["@60"] = p;
    p = [](){SA.push_return();;};
    SA_mp["@61"] = p;
    p = [](){SA.return_re_ans();;};
    SA_mp["@62"] = p;
    p = [](){SA.push_assignment_block();;};
    SA_mp["@63"] = p;
    p = [](){SA.assignment_merge_var();;};
    SA_mp["@64"] = p;
    p = [](){SA.assignment_end_with_arithmetic();;};
    SA_mp["@65"] = p;
    p = [](){SA.arithmetic_add();;};
    SA_mp["@66"] = p;
    p = [](){SA.arithmetic_sub();;};
    SA_mp["@67"] = p;
    p = [](){SA.arithmetic_mul();;};
    SA_mp["@68"] = p;
    p = [](){SA.arithmetic_div();;};
    SA_mp["@69"] = p;
    p = [](){SA.Var_or_item_to_arithmetic();;};
    SA_mp["@70"] = p;
    p = [](){SA.push_Var_or_item_variable();;};
    SA_mp["@71"] = p;
    p = [](){SA.push_Var_or_item_const();;};
    SA_mp["@72"] = p;
    p = [](){SA.push_Var_or_item_fu_const();;};
    SA_mp["@73"] = p;
    p = [](){SA.push_Var_or_item_char();;};
    SA_mp["@74"] = p;
    p = [](){SA.push_Var_or_item_variable();;};
    SA_mp["@75"] = p;
    p = [](){SA.Var_or_item_end_function();;};
    SA_mp["@76"] = p;
    p = [](){SA.insert_const();SA.push_arr_dimension();;};
    SA_mp["@77"] = p;
    p = [](){SA.Var_or_item_str();;};
    SA_mp["@78"] = p;
    p = [](){SA.Var_or_item_get_parameter();;};
    SA_mp["@79"] = p;
    p = [](){SA.insert_const();SA.push_arr_dimension();;};
    SA_mp["@80"] = p;
    p = [](){SA.Var_or_item_arr();;};
    SA_mp["@81"] = p;
    p = [](){SA.Var_or_item_str();;};
    SA_mp["@82"] = p;
    p = [](){SA.Var_or_item_arr();;};
    SA_mp["@83"] = p;
    p=[](){SA.push_for_block();;};
    SA_mp["@84"] = p;
    p=[](){SA.is_define_variable=true;;};
    SA_mp["@85"] = p;
    p=[](){SA.push_variable_name();SA.create_or_find_variable_not_arr();SA.pop_type_name();;};
    SA_mp["@86"] = p;
}

void Action(string s) {
    SA_mp[s]();
}
