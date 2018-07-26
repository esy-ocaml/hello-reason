# hello-reason

[![Build Status](https://travis-ci.org/esy-ocaml/hello-reason.svg?branch=master)](https://travis-ci.org/esy-ocaml/hello-reason)

A project which demonstrates a Reason workflow with [Esy][].

[Esy]: https://github.com/esy-ocaml/esy


## Shortest path to working

You need Esy, you can install the beta using [npm][https://www.npmjs.com/]:

    % npm install -g esy@latest

Then you can install the project dependencies using:

    % esy install

Then build the project dependencies along with the project itself:

    % esy build

And test compiled executable:

    % ./_build/default/bin/Hello.exe

## Project layout ( What are all these files? )

This project builds an executable (`/bin/Hello.re`) and a library
(`/lib/Util.re`), the executable depends on the library and is statically
linked as a native binary (`./_build/default/bin/Hello.exe`). Despite the
`.exe` extension, This binary is not just for windows, it will build on
whatever platform you are running on.

The esy build uses existing OCaml tooling to build your project so there are
some extra files which are needed in order to make the build happen, but fear
not, it is not as complicated as it might first appear. The main tools which
esy uses are jbuilder (also known as dune), reason, refmterr and (of course)
OCaml itself.

What do the files do:

* `bin`
  * `Hello.re`: This is the entry-point to the executable. Note that this
  file references `Lib.Util.hello()` (defined in `lib`) and also `Lwt_main()`
  (defined in an external library).
  * `jbuild`: This is a configuration for jbuilder/dune which tells it to
  build `Hello.re`, it tells it that `Hello.re` should be compiled into an
  executable file named `Hello` and that it should demand a library called
  `lib` (this library is defined in the `/lib` directory). You can
  [read more about jbuild files](https://jbuilder.readthedocs.io/en/stable/quick-start.html)
  but note that in newer versions of jbuilder/dune, the name of the file has
  been changed to `dune` but esy works with the older jbuild standard.
* `lib`
  * `Util.re`: This is where `Util.hello()` is defined, the function which is
  called by `Hello.re`.
  * `jbuild`: This is configuration for building the `lib` library which
  contains `Util.re`. Note that it specifies
  [compiler flags](https://caml.inria.fr/pub/docs/manual-ocaml/comp.html)
  for ocamlc and that it requires the libraries `lambda-term` and `lwt`.
  `lambda-term` is used only in `Util.re` but `Lwt` is referenced in `Hello.re`
  and included transitively.
* `hello-reason.opam`: This is an empty file which just sits there and
declares to jbuild that there are no opam dependencies, it needs to be there.
* `jbuild-ignore`: This is like a .gitignore file, it helps jbuilder/dune move
more quickly by telling it where it will never find any Reason source code. If
you remove this file, you will see lots and lots of compiler warnings and a very
slow build, as jbuilder tries to build everything in node_modules!

### Files you can delete

* `.travis.yml`: This is a file for the project's
[travis-ci builds](https://travis-ci.org/esy-ocaml/hello-reason).
* `.gitignore`: This is just for preventing git checkins of build artifacts,
but you probably already knew that.
* `/lib`: If you just want to make a simple executable, you can delete this
entire directory, just make sure to update `Hello.re` to stop using it and
update `/bin/jbuild` to stop requiring it.

## package.json ( What are all of these dependencies? )

In order to build your project, esy has 4 dependencies that have to stay:

* `@opam/dune`: This is the jbuilder/dune project which esy uses to perform
the build.
* `@esy-ocaml/reason`: This is the ReasonML Frontend for OCaml, this is the
parser which parses Reason code into the OCaml AST, there is a nice
[diagram of the OCaml toolchain](https://github.com/esy-ocaml/reason/tree/3.0.0/src#repo-walkthrough)
showing where the Reason frontend fits in.
* `refmterr`: This is an error pretty-printer, technically this can be removed
as long as you also remove the call to it from the `esy.build` block in the
`package.json`, but after dealing with a few errors with only the line number
and column shown, you will much rather have it.
* `ocaml`: It seems kind of obvious that an OCaml project needs OCaml, but
because esy is based on npm, the dependency needs to be made clear. By
declaring it both in `devDependencies` and `peerDependencies`, any build which
requires multiple incompatible versions of OCaml will fail, which is good
because there is no way that projects with incompatible versions of OCaml can
ever link with one another.

### Dependencies you can delete

#### Libraries used by the project

There are a few dependencies which are not part of the build itself, these are
part of the example project.

* `@opam/lambda-term`: This provides the
[LTerm library](https://github.com/diml/lambda-term) which allows the
Hello World text to be red and green.
* `@opam/lwt` This provides [Lwt Library](https://github.com/ocsigen/lwt) which
allows for promises and asynchronous IO in OCaml, this is not really used by
the example project except when it calls `Lwt_main()`.

If you remove these dependencies, remember to also remove them from
`/lib/jbuild` which is where they are made available to the project (of course
you also need to change the actual code to stop using them).


#### Additional utilities

* `@esy-ocaml/merlin`: This adds [merlin](https://github.com/ocaml/merlin)
auto-completion for Vim and Emacs, you can access it by invoking vim or emacs
through the esy shell, for example: `esy vim ./bin/Hello.re`. If you use a
different editor and have syntax highlighting and auto-completion taken care
of, you can just remove this.
* `@esy-ocaml/esy-installer`: This is an internal part of esy which is used
for accessing opam, my experience shows that it can be removed along with the
block `"install": [ "esy-installer" ],` and everything works ok.

## Tips and Tricks

You can access a shell in the esy environment (with the correct versions of
ocaml, opam, etc) like this:

    % esy shell

To run your executable in the esy environment, use:

    % esy ./_build/default/bin/Hello.exe

To run your editor in the esy environment (to take advantage of merlin for
example):

    % esy $EDITOR
    % esy vim