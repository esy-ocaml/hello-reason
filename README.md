# esy-reason-project

[![Build Status](https://travis-ci.org/esy-ocaml/esy-reason-project.svg?branch=master)](https://travis-ci.org/esy-ocaml/esy-reason-project)

A project which demonstrates a Reason workflow with [Esy][].

[Esy]: https://github.com/esy-ocaml/esy


## Usage

    % npm install -g esy
    % esy install
    % esy build
    % _build/default/HelloWorld.exe


## Coming Soon

Instead of the install process above, the following workflow is coming soon to
`esy`.


    % esx HelloWorld.exe

This will do whatever it takes to run your script, including downloading
dependencies, building them, and compiling your scripts.

## Editing The Scripts:

You can run your editor within the environment (which also includes merlin):

    % esy $EDITOR
    % esy vim

