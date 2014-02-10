import os

env = Environment()
env.Append(CCFLAGS = '-std=c++11')

Export('env')

objs = SConscript('src/SConscript')

env.Program('adapt', objs)


