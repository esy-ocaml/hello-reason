// In package.json we pass #{self.root} as first argument
if (Array.length(Sys.argv) < 2)
  failwith("pass the project root as first argument");
let projectDir = Sys.argv[1];

include Rely.Make({
  let config =
    Rely.TestFrameworkConfig.initialize({
      snapshotDir:
        Filename.(
          projectDir
          |> (dir => concat(dir, "test"))
          |> (dir => concat(dir, "lib"))
          |> (dir => Filename.concat(dir, "__snapshots__"))
        ),
      projectDir,
    });
});
