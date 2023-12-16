cpu_family = build_machine.cpu_family()

if ['x86', 'x86_64'].contains(cpu_family)
  subdir('x86')
else
  error('unsupport cpu family: @0@'.format(cpu_family))
endif
