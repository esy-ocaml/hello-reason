/* The Computer Language Benchmarks Game
 * https://salsa.debian.org/benchmarksgame-team/benchmarksgame/
 *
 * Contributed by Troestler Christophe
 * Rough parallelization by Mauricio Fernandez
 * *reset*
 */
type tree('a) =
  | Empty
  | Node(tree('a), tree('a));

let rec make = d =>
  if (d === 0) {
    Node(Empty, Empty);
  } else if (d ===1) {
    Node(Node(Empty, Empty), Node(Empty, Empty));
  } else {
    let d = d - 1;
    Node(make(d), make(d));
  };

let rec check = n => switch(n) {
  | Empty => 0
  | Node(l, r) => 1 + check(l) + check(r)
};

let minDepth = 4;
let determineMaxDepth = () => {
  let n =
    try (int_of_string(Sys.argv[1])) {
    | _ => 10
    };
  max(minDepth + 2, n);
};

let maxDepth = determineMaxDepth();

let stretch_depth = maxDepth + 1;

let c = check(make(stretch_depth));
Printf.printf("stretch tree of depth %i\t check: %i\n", stretch_depth, c);

let longLivedTree = make(maxDepth);

/* function originally due to Jon D. Harrop */
let invoke = (f: 'a => 'b, x) : (unit => 'b) => {
  let (input, output) = Unix.pipe();
  switch (Unix.fork()) {
  | (-1) =>
    Unix.close(input);
    Unix.close(output);
    let v = f(x);
    (() => v);
  | 0 =>
    Unix.close(input);
    let output = Unix.out_channel_of_descr(output);
    Marshal.to_channel(
      output,
      try (`Res(f(x))) {
      | e => `Exn(e)
      },
      [],
    );
    close_out(output);
    exit(0);
  | pid =>
    Unix.close(output);
    let input = Unix.in_channel_of_descr(input);
    (
      () => {
        let v = Marshal.from_channel(input);
        ignore(Unix.waitpid([], pid));
        close_in(input);
        switch (v) {
        | `Res(x) => x
        | `Exn(e) => raise(e)
        };
      }
    );
  };
};

let loopDepths = d => {
  let worker = d => {
    /* Determine the portion of the work to do in this worker. */
    let niter = 1 lsl (maxDepth - d + minDepth);
    let c = {contents: 0};
    for (i in 1 to niter) {
      c.contents = c.contents + check(make(d));
    };
    (niter, c.contents);
  };
  let workers =
    Array.init(
      (maxDepth - d) / 2 + 1,
      i => {
        let d = d + i * 2;
        (d, invoke(worker, d));
      },
    );
  Array.iter(
    (depthWorker) => {
      let (d, w) = depthWorker;
      let (niter, c) = w();
      Printf.printf("%i\t trees of depth %i\t check: %i\n", niter, d, c);
    },
    workers,
  );
};

flush(stdout);
loopDepths(minDepth);
Printf.printf(
  "long lived tree of depth %i\t check: %i\n",
  maxDepth,
  check(longLivedTree),
);

