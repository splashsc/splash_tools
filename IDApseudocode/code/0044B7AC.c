char *__fastcall reltime(char *a1, int a2)
{
  int v3; // $a2
  int v4; // $t0
  int v5; // $v1
  const char *v6; // $a3
  int v7; // $v0
  int v8; // $a1

  if ( a2 < 0 )
  {
    v4 = 0;
    v7 = 0;
    v8 = 0;
    v3 = 0;
    v6 = "s";
  }
  else
  {
    v3 = a2 / 86400;
    v4 = a2 % 60;
    v5 = a2 / 60;
    if ( a2 / 86400 == 1 )
    {
      v8 = a2 / 3600 % 24;
      v7 = v5 % 60;
      v6 = "";
    }
    else
    {
      v6 = "s";
      v7 = v5 % 60;
      v8 = a2 / 3600 % 24;
    }
  }
  sprintf(a1, "%d day%s, %02d:%02d:%02d", v3, v6, v8, v7, v4);
  return a1;
}

