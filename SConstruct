import os

env = Environment()
env.Append(CCFLAGS = '-std=c++11')
env['LIBS'] = ['boost_unit_test_framework', 'boost_program_options']
env['CPPPATH'] = ['#/src']
Export('env')

[adapt, testapp] = SConscript('src/SConscript')

test_alias = Alias('test', [testapp], testapp[0].abspath)
AlwaysBuild(test_alias)

Depends(adapt, test_alias)

env.Install("#/bin", adapt)


