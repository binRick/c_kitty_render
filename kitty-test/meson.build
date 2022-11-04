kitty_test_srcs = [
  'kitty-test.c',
]
inc = get_variable('inc', join_paths(meson.current_source_dir(),'..'))
kitty_test_include_dirs = [
  '.',
  inc,
]
kitty_test_deps = [
  c_greatest_dep,
  c_stringfn_dep,
  kitty_dep,
]
kitty_test_c_args = [
]
kitty_test_link_args = [
]

kitty_test_test_dir = join_paths(meson.current_source_dir(), '..')

if get_option('enable-binaries')
  kitty_test_exec = executable('kitty-test',
     kitty_test_srcs,
     dependencies: kitty_test_deps,
     include_directories: kitty_test_include_dirs,
     link_args: kitty_test_link_args,
     c_args: kitty_test_c_args,
     install: false,
  )
  test('kitty-test', 
    kitty_test_exec, args: ['-v','-a'],
    workdir: kitty_test_test_dir,
  )
endif
