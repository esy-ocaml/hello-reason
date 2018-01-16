open Lwt;

let hello = () => Lwt.return(print_string("In EsyReasonProject hello"));
let hello = () => AnotherEsyReasonProject.Helper.hello();

let s = EsyPeasyStarterLib.Util.utilValueString;

print_string(s);

let i = EsyPeasyStarterLib.Util.utilValueString;

print_string(i);

let s = EsyPeasyStarterLib.AnotherUtil.anotherUtilStringValue;

print_string(s);

let i = EsyPeasyStarterLib.AnotherUtil.anotherUtilValue;

print_int(i);
