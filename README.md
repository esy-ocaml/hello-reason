# hello-reason

[![Build Status](https://dev.azure.com/esy-ocaml/esy-ocaml/_apis/build/status/esy-ocaml.hello-reason?branchName=master)](https://dev.azure.com/esy-ocaml/esy-ocaml/_build/latest?definitionId=1?branchName=master)

A project which demonstrates a Reason workflow with [Esy][].

[Esy]: https://github.com/esy-ocaml/esy


## Usage

You need Esy, you can install the beta using [npm](https://npmjs.com):

    % npm install -g esy@latest

> NOTE: Make sure `esy --version` returns at least `0.5.4` for this project to build.

Then run the `esy` command from this project root to install and build dependencies.

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


## Create Prebuilt Release:

`esy` allows creating prebuilt binary packages for your current platform, with
no dependencies.

    % esy npm-release
    % cd _release
    % npm publish

## Continuous Integration:
`hello-reason` includes CI configuration for Azure
[DevOps](https://dev.azure.com) pipelines out of the box.

- Create your Azure DevOps account.
- Add a new project, and point that new Azure DevOps project to your github
  repo that includes the CI (`./azure-pipelines.yml` and the `.ci/` directory)
  from `hello-reason`.
- Create a new Pipeline within that project.
  - When asked how to configure the new pipeline, select the option to use
    existing configuration inside the repo.

The CI is configured to build caches on the `master` branch as well as any pull
request run. Cache keys depend on the platform where builds are run (Linux,
macOS or Windows) as well as the hash of the contents from `esy.lock` file.
In case there is not a match for the current run key, there is a fallback to
get the latest created key for the current run platform.
Cache isolation and security applies thanks to Azure infrastructure. To know
more about this, check the documentation about ["Cache isolation and
security"](https://docs.microsoft.com/en-us/azure/devops/pipelines/caching/?view=azure-devops#cache-isolation-and-security).
