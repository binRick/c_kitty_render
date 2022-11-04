msg_test_srcs = [
  'msg-test.c',
]
inc = get_variable('inc', join_paths(meson.current_source_dir(),'..'))
msg_test_include_dirs = [
  '.',
  inc,
]
msg_test_deps = [
  c_greatest_dep,
  c_vector_dep,
  c_fsio_dep,
  c_stringfn_dep,
  c_string_buffer_dep,
  timestamp_dep,
  log_dep,
  ms_dep,
  bytes_dep,
  msg_dep,kitty_dep,
]
msg_test_c_args = [
]
msg_test_link_args = [
]

msg_test_test_dir = join_paths(meson.current_source_dir(), '..')

if get_option('enable-binaries')
  msg_test_exec = executable('msg-test',
     msg_test_srcs,
     dependencies: msg_test_deps,
     include_directories: msg_test_include_dirs,
     link_args: msg_test_link_args,
     c_args: msg_test_c_args,
     install: false,
  )
  test('msg-test', 
    msg_test_exec, args: ['-v','-a'],
    workdir: msg_test_test_dir,
  )
endif
