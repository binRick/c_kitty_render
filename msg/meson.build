msg_srcs = [
  'msg.c',
]

inc = get_variable('inc', join_paths(meson.current_source_dir(),'..'))

msg_include_dirs = [
  '.',
  inc,
]

msg_deps = [
  c_vector_dep,
  c_fsio_dep,
  c_stringfn_dep,
  c_string_buffer_dep,
  timestamp_dep,
  log_dep,
  ms_dep,
  bytes_dep,
]

msg_c_args = [
]

msg_link_args = [
]

msg_lib = library('msg',
  msg_srcs,
  install: false,
  dependencies: msg_deps,
  c_args: msg_c_args,
  include_directories: msg_include_dirs
)

msg_dep = declare_dependency(
  include_directories: msg_include_dirs,
  link_with: msg_lib,
  link_args: msg_link_args,
)
