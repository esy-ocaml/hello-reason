# Reason Binary Tree Fork/Join Example.

Small Reason example project that uses Fork/Join to break up a large computation.

Source derived from [this example project](https://benchmarksgame-team.pages.debian.net/benchmarksgame/program/binarytrees-ocaml-2.html)

[Esy]: https://github.com/esy-ocaml/esy


## Usage

You need Esy, you can install the beta using [npm][]:

    % npm install -g esy@preview

Then you can install the project dependencies using:

    % esy install

Then build the project dependencies along with the project itself:

    % esy build

And test compiled executable: `esy x` lets you run built binaries by name.

    % esy x Test.exe

Timing:

You can use `time` from the command line. This also includes the time it takes
to startup the app. Make sure the `time` command is inside the `esy x` command.

    % esy x time Test.exe
