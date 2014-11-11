#include <ros/ros.h>
#include <dynamic_reconfigure/server.h>

#include "dyn_re_test/DynReTestConfig.h"

dynamic_reconfigure::Server<dyn_re_test::DynReTestConfig> *dyn_re = NULL;

void DynReCB( dyn_re_test::DynReTestConfig &cfg, uint32_t lvl)
{
	if( lvl == ~0 )
	{
		std::cout << "---------------------------------" << std::endl
			<< "groups configured" << std::endl;
		//cfg.groups.test_group_1.state = false;
		//dyn_re->updateConfig(cfg);
	}

	std::cout << "---------------------------------" << std::endl
		<< "int_param:\t\t" << cfg.int_param << std::endl
		<< "double_param:\t\t" << cfg.double_param << std::endl
		<< "inf_double_param:\t" << cfg.inf_double_param << std::endl
		<< "str_param:\t\t" << cfg.str_param << std::endl
		<< "bool_param:\t\t" << ( cfg.bool_param ? "True" : "False" ) << std::endl
		<< "enum_param:\t\t" << cfg.enum_param << std::endl
		<< "-test_group_1:\t\t" << cfg.groups.test_group_1.state << std::endl
		<< "--group_1_int_param:\t" << cfg.groups.test_group_1.group_1_int_param << std::endl
		<< "-test_group_2:\t\t" << cfg.groups.test_group_2.state << std::endl
		<< "--group_2_int_param:\t" << cfg.groups.test_group_2.group_2_int_param << std::endl
		<< "-test_group_3:\t\t" << cfg.groups.test_group_3.state << std::endl
		<< "--group_3_int_param:\t" << cfg.groups.test_group_3.group_3_int_param << std::endl
		<< "-test_group_4:\t\t" << cfg.groups.test_group_4.state << std::endl
		<< "--group_4_int_param:\t" << cfg.groups.test_group_4.group_4_int_param << std::endl
		<< "-test_group_5:\t\t" << cfg.groups.test_group_5.state << std::endl
		<< "--test_group_5_1:\t\t" << cfg.groups.test_group_5.test_group_5_1.state << std::endl
		<< "---group_5_1_str_param:\t\t" << cfg.groups.test_group_5.test_group_5_1.group_5_1_str_param << std::endl
		<< "---group_5_1_bool_param:\t" << ( cfg.groups.test_group_5.test_group_5_1.group_5_1_bool_param ? "True" : "False" ) << std::endl
		<< "--test_group_5_2:\t\t" << cfg.groups.test_group_5.test_group_5_2.state << std::endl
		<< "---group_5_2_int_param:\t\t" << cfg.groups.test_group_5.test_group_5_2.group_5_2_int_param << std::endl
		<< "---group_5_2_double_param:\t" << cfg.groups.test_group_5.test_group_5_2.group_5_2_double_param << std::endl;
}

int main( int argc, char *argv[] )
{
	ros::init( argc, argv, "dyn_re_test" );

	dyn_re = new dynamic_reconfigure::Server<dyn_re_test::DynReTestConfig>;
	dynamic_reconfigure::Server<dyn_re_test::DynReTestConfig>::CallbackType dyn_re_cb = boost::bind( &DynReCB, _1, _2 );

	std::cout << "Running..." << std::endl;

	dyn_re->setCallback( dyn_re_cb );

	ros::spin( );

	return 0;
}
