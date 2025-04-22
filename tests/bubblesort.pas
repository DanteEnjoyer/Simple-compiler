program sort(input,output);
var j,i,o:integer;
var p :array [1..10] of integer;
var b:integer;

procedure czytajtab(a: array[1..10] of integer);
var i: integer;
begin
  i:=1;
  while i<11 do
  begin
    read(a[i]);
    i:=i+1
  end
end;

procedure bubblesort(a:array[1..10] of integer);
var i,j:integer;
var tmp: real;
begin
  i:=1;
  while i<11 do 
  begin
    j:=i+1;
    while j<11 do begin
      if a[i]>a[j] then
       begin
         tmp:=a[i];
 	 a[i]:=a[j];
	 a[j]:=tmp
       end
      else
       begin
       end;
      j:=j+1
     end;
     i:=i+1
  end
end;

procedure wypisztab(a: array[1..10] of integer);
var i: integer;
begin
  i:=1;
  while i<11 do
  begin
    write(a[i]);
    i:=i+1
    
  end
end;

     
begin
  czytajtab(p);
  bubblesort(p);
  wypisztab(p)
end.
