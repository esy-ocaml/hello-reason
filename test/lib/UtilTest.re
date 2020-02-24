open TestFramework;

open Lib;

describe("Util", ({test, _}) => {
  test("add", ({expect, _}) => {
    expect.int(Util.add(3, 3)).toBe(6)
  })
});
