# esy-reason-project

[![Build Status](https://travis-ci.org/esy-ocaml/esy-reason-project.svg?branch=master)](https://travis-ci.org/esy-ocaml/esy-reason-project)

A project which demonstrates a Reason workflow with [Esy][].

[Esy]: https://github.com/esy-ocaml/esy


## Usage

You need Esy, you can install the beta using [npm][]:

    % npm install -g esy@latest

Then you can install the project dependencies using:

    % esy install

Then build the project dependencies along with the project itself:

    % esy build

Now you can run your editor within the environment (which also includes merlin):

    % esy $EDITOR
    % esy vim

After you make some changes to source code, you can re-run project's build
using:

    % esy build

And test compiled executable:

    % esy ./_build/default/bin/hello.exe

Shell into environment:

    % esy shell
