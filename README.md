# esy-reason-project (aspirational)

Demonstrates ideal scripts use case for Reason.

[Esy]: https://github.com/esy-ocaml/esy

Clone and run the following:

    % esx HelloWorld.exe

This will do whatever it takes to run your script, including downloading
dependencies, building them, and compiling your scripts.

Since the `package.json` [sets the `esy.main` field](https://github.com/esy-ocaml/esy-reason-project/blob/scripts/package.json#L7) to be `HelloWorld.exe`, you can also just run:

    % esx

`esx` will automatically run the main program.

## Editing The Scripts:

You can run your editor within the environment (which also includes merlin):

    % esy $EDITOR
    % esy vim

