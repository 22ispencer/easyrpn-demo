project('rpn', 'c')

libeasyrpn_proj = subproject('libeasyrpn')
libeasyrpn_dep = libeasyrpn_proj.get_variable('libeasyrpn_dep')

executable('rpn', 
  'src/main.c',
  dependencies: libeasyrpn_dep)
