#!/usr/bin/env python

PACKAGE = "dyn_re_test"

from dynamic_reconfigure.parameter_generator_catkin import *

gen = ParameterGenerator()

gen.add("int_param",        int_t,    0, "An Integer parameter", 50,  0, 100)
gen.add("double_param",     double_t, 0, "A double parameter (bounded)",    .5, 0,   1)
gen.add("inf_double_param", double_t, 0, "A double parameter (bounded)",    0.0)
gen.add("str_param",        str_t,    0, "A string parameter",  "Hello World")
gen.add("bool_param",       bool_t,   0, "A Boolean parameter",  True)

size_enum = gen.enum([ gen.const("Small",      int_t, 0, "A small constant"),
                       gen.const("Medium",     int_t, 1, "A medium constant"),
                       gen.const("Large",      int_t, 2, "A large constant"),
                       gen.const("ExtraLarge", int_t, 3, "An extra large constant")],
                     "An enum to set size")

gen.add("enum_param", int_t, 0, "A size parameter which is edited via an enum", 1, 0, 3, edit_method=size_enum)

group1 = gen.add_group("test_group_1", "tab")
group1.add("group_1_int_param", int_t, 0, "An Integer parameter in a group", 0, -1000, 1000)

group2 = gen.add_group("test_group_2", "hide")
group2.add("group_2_int_param", int_t, 0, "An Integer parameter in a group", 0, -1000, 1000)

group3 = gen.add_group("test_group_3", "collapse")
group3.add("group_3_int_param", int_t, 0, "An Integer parameter in a group", 0, -1000, 1000)

group4 = gen.add_group("test_group_4", "apply")
group4.add("group_4_int_param", int_t, 0, "An Integer parameter in a group", 0, -1000, 1000)

group5 = gen.add_group("test_group_5", "tab")
group5_1 = group5.add_group("test_group_5_1", "collapse", False)
group5_1.add("group_5_1_str_param",        str_t,    0, "A string parameter",  "Hello World2")
group5_1.add("group_5_1_bool_param",       bool_t,   0, "A Boolean parameter",  True)
group5_2 = group5.add_group("test_group_5_2", "collapse")
group5_2.add("group_5_2_int_param",        int_t,    0, "An Integer parameter", 50,  0, 100)
group5_2.add("group_5_2_double_param",     double_t, 0, "A double parameter (bounded)",    .5, 0,   1)

exit(gen.generate(PACKAGE, "dyn_re_test", "DynReTest"))
