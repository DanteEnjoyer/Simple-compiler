program example(input, output);
var w,x, y,z: integer;
var g,h:real;

function gcd(a, b: integer):integer;
begin
  if b=0 then 
    gcd:=a
  else 
    gcd:=gcd(b, a mod b)
end;


begin
  read(w, x, y, z);
  g := 4.5;
  write(gcd(gcd(g, -6.7),gcd(y,z)))
end.
