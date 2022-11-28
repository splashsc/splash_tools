int __fastcall jhl_web_save_parms(int a1, char **a2, int a3)
{
  char *v4; // $a1
  char **v7; // $s0
  int v8; // $s3
  bool v9; // dc

  v4 = *a2;
  if ( !v4 || !*v4 )
    return 0;
  v7 = a2 + 1;
  v8 = 0;
  do
  {
    if ( jhl_web_save_parm(a1, v4, a3) )
      v8 = 1;
    v4 = *v7;
    v9 = *v7++ != 0;
  }
  while ( v9 && *v4 );
  return v8;
}

