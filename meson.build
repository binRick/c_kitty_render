project('c_kitty_render', ['c'],default_options: [
  'warning_level=1',
  'c_std=gnu99',
],
  subproject_dir: 'subprojects',
  version:'0.0.1')
fs = import('fs')
pwd = meson.current_source_dir()
c_deps_dir = join_paths(meson.current_source_dir(),pwd)

inc = [include_directories(
  '.',
  'submodules',
  'submodules/c_ansi',
  'submodules/c_ansi/ansi-codes',
)]
#############################################################################
subdir('submodules/c_deps/meson/osx')
subdir('meson')
subdir('submodules')
#############################################################################
subdir('msg')
subdir('kitty')
#############################################################################
subdir('kitty-test')
#############################################################################
subdir('msg-test')
