assets_srcs = [
  'assets.c',
]

inc = get_variable('inc', join_paths(meson.current_source_dir(),'..'))

assets_include_dirs = [
  '.',
  inc,
]

assets_deps = [
  c_vector_dep,incbin_dep,
  c_fsio_dep,
  c_stringfn_dep,
  c_string_buffer_dep,
  timestamp_dep,
  log_dep,
  ms_dep,
  bytes_dep,
]

assets_c_args = [
]

assets_link_args = [
]

assets_lib = library('assets',
  assets_srcs,
  install: false,
  dependencies: assets_deps,
  c_args: assets_c_args,
  include_directories: assets_include_dirs
)

assets_dep = declare_dependency(
  include_directories: assets_include_dirs,
  link_with: assets_lib,
  link_args: assets_link_args,
)
