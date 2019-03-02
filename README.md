# hello-reason

[![Build Status](https://dev.azure.com/esy-ocaml/esy-ocaml/_apis/build/status/esy-ocaml.hello-reason?branchName=master)](https://dev.azure.com/esy-ocaml/esy-ocaml/_build/latest?definitionId=1?branchName=master)

A project which demonstrates a Reason workflow with [Esy][].

[Esy]: https://github.com/esy-ocaml/esy


## Usage

You need Esy, you can install the beta using [npm](https://npmjs.com):

    % npm install -g esy@latest

> NOTE: Make sure `esy --version` returns at least `0.5.4` for this project to build.

Then run the `esy` command from this project root to install and build depenencies.

    % esy

Now you can run your editor within the environment (which also includes merlin):

    % esy $EDITOR
    % esy vim

Alternatively you can try [vim-reasonml](https://github.com/jordwalke/vim-reasonml)
which loads esy project environments automatically.

After you make some changes to source code, you can re-run project's build
again with the same simple `esy` command.

    % esy

And test compiled executable (runs `scripts.tests` specified in
`package.json`):

    % esy test

Documentation for the libraries in the project can be generated with:

    % esy doc
    % esy open '#{self.target_dir}/default/_doc/_html/index.html'

Shell into environment:

    % esy shell

## Unit testing

There are two test-cases in `lib/Util.re`. There is a command to execute them:

    % esy test:unit

First test-case uses [inline_test](https://github.com/janestreet/ppx_inline_test),
using the `let%test` that checks an expression is true.

Same library provides `let%test_unit` that checks there is no exception and `let%test_module` for grouping tests.

Second test-case uses [expect-test](https://github.com/janestreet/ppx_expect),
using `let%expect_test` with code that prints to stdout and `%expect` at the the end with the expected output.
If the output differs, there is a command to automatically update the `%expect` assertion to match the actual output:

    % esy test:promote

This functionality is provided by [dune build system when running tests](https://dune.readthedocs.io/en/latest/tests.html)
Additional configuration as well as enabling the extension-points that the test-frameworks rely on is done in `lib/dune`

## Create Prebuilt Release:

`esy` allows creating prebuilt binary packages for your current platform, with
no dependencies.

    % esy npm-release
    % cd _release
    % npm publish
