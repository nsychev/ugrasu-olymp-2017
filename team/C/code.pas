// Copyright (c) Yulia Gainichina, 28.04.2017
// Licensed by MIT

var n,k,i,s,d:int64;
begin
  read(n,k);
  d:=1;
  s:=1;
  for i:=1 to k do
  begin
    s:=s*(n-i+1)*(n-i+1);
    d:=d*i;
  end;
  s:=s div d;
  write(s);
end.
