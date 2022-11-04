default: all
##############################################################
MESON_DEFAULT_LIBRARY=shared
REPO_DIR=$(shell pwd)
WARN_LEVEL=0
##############################################################
build:
	if [[ -d build ]]; then meson setup --fatal-meson-warnings --buildtype debug --default-library shared --warnlevel 0 --backend ninja --errorlogs --reconfigure build; else meson setup --fatal-meson-warnings --buildtype debug --default-library shared --warnlevel 0 --backend ninja --errorlogs build; fi
	meson compile -C build -j 15
	env MESON_TESTTHREADS=3 meson test -C build --print-errorlogs

clean:
	rm -rf build .cache

all: clean build

_entr-files:
	find . \
	-maxdepth 3 \
	-type f \
	-not -path \*.attic\* \
	-and -not -path \*/subprojects/\* \
	-and -not -path \*/\.\* \
	-and -not -path \*/submodules/\* \
	-and -not -path \*/wrapdb/\* \
	-and -not -path \*/build/\* \
	-and -not -path \*/build-muon/\* \
	-and -not -path \*/gpp-\* \
	-name "*.c" -or -name "*.h" -or -name "*.j2" -or -name "*.gpp" 2>/dev/null


entr-files: _entr-files


entr:
	env bash +e -xc "while :; do env SHELL=/usr/local/bin/bash entr -r -c -s 'make -B build && sleep 0' < <(make entr-files); sleep 1; done"


