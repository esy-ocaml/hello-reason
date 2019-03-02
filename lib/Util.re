let capitalize = (name) => String.capitalize_ascii(name)
let%test "capitalize" = capitalize("test") == "Test"

let hello = (name) =>
  Pastel.(
    <Pastel>
      <Pastel color=Red> "Hello" </Pastel>
      ", "
      <Pastel color=Green> (capitalize(name)) </Pastel>
      "!"
    </Pastel>
  );

let%expect_test "hello" = {
  print_endline(hello("tester"));
  %expect {| [31mHello[39m, [32mTester[39m! |}
}