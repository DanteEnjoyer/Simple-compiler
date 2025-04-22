program example(input, output);
var w,x, y,z: integer;
var g,h:real;

function sub1(a, b: integer):integer;
begin
  sub1 := a - b
end;


function sub2(b, a: integer):integer;
begin
  sub2 := a - b
end;


begin
  write(sub1(3,4), sub2(5,6))
end.
