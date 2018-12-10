# hello-reason

[![Build status](https://ci.appveyor.com/api/projects/status/clqxyx5ohadbjkcw/branch/master?svg=true)](https://ci.appveyor.com/project/esy/hello-reason/branch/master)
[![Build Status](https://travis-ci.org/esy-ocaml/hello-reason.svg?branch=master)](https://travis-ci.org/esy-ocaml/hello-reason)

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

And test compiled executable (runs `scripts.tests` specified in
`package.json`):

    % esy test

Documentation for the libraries in the project can be generated with:

    % esy doc
    % open _esy/default/build/default/_doc/_html/index.html

Shell into environment:

    % esy shell


## Create Prebuilt Release:

`esy` allows creating prebuilt binary packages for your current platform, with
no dependencies.

    % esy release
    % cd _release
    % npm publish
