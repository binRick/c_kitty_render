assets_test_srcs = [
  'assets-test.c',
]
inc = get_variable('inc', join_paths(meson.current_source_dir(),'..'))
assets_test_include_dirs = [
  '.',
  inc,
]
assets_test_deps = [
  c_greatest_dep,
  c_vector_dep,
  c_fsio_dep,
  c_stringfn_dep,
  c_string_buffer_dep,
  timestamp_dep,
  log_dep,
  ms_dep,
  bytes_dep,
  assets_dep,
]
assets_test_c_args = [
]
assets_test_link_args = [
]

assets_test_test_dir = join_paths(meson.current_source_dir(), '..')

if get_option('enable-binaries')
  assets_test_exec = executable('assets-test',
     assets_test_srcs,
     dependencies: assets_test_deps,
     include_directories: assets_test_include_dirs,
     link_args: assets_test_link_args,
     c_args: assets_test_c_args,
     install: false,
  )
  test('assets-test', 
    assets_test_exec, args: ['-v','-a'],
    workdir: assets_test_test_dir,
  )
endif
