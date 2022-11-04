kitty_srcs = [
  'kitty.c',
]

inc = get_variable('inc', join_paths(meson.current_source_dir(),'..'))

kitty_include_dirs = [
  '.',
  inc,
]

kitty_deps = [
  b64_dep,
  c_vector_dep,
  hash_dep,
  bytes_dep,
  timestamp_dep,
  c_stringfn_dep,
  c_string_buffer_dep,
  c_fsio_dep,
  c_workqueue_dep,
  chan_dep,
]

kitty_c_args = [
]

kitty_link_args = [
]

kitty_lib = library('kitty',
  kitty_srcs,
  install: false,
  dependencies: kitty_deps,
  c_args: kitty_c_args,
  include_directories: kitty_include_dirs
)

kitty_dep = declare_dependency(
  include_directories: kitty_include_dirs,
  link_with: kitty_lib,
  link_args: kitty_link_args,
)
