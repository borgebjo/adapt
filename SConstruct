import os

env = Environment()
env.Append(CCFLAGS = '-std=c++11')
env['LIBPATH'] = ['/usr/share/lintian/overrides']
env['LIBS'] = ['boost_program_options']
env['CPPPATH'] = ['#/src']
Export('env')

objs = SConscript('src/SConscript')

env.Program('adapt', objs)


