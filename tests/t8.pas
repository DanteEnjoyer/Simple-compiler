program example(input, output);
var x, y: integer;
var g,h:real;

function f(a, b: real):real;
var q:integer;
begin
   q:=4;
   f:=a+b+q
end;


begin
  g:=3.25;
  write(f(g,10.28))
end.
