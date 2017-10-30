all: build

build: build-lib build-bin

build-lib:
	@esy jbuilder build lib

build-bin:
	@esy jbuilder build bin/hello.exe

clean:
	@esy jbuilder clean
	@rm -rf _esybuild _esyinstall _release node_modules

esy-install:
ifndef cur__install
	@echo "error: this command requires esy environment" && exit 1
endif
	@jbuilder build lib
	@jbuilder build bin/hello.exe
	@jbuilder build @install
	@esy-installer

.DEFAULT: all
