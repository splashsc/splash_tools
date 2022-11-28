int __fastcall get_nvarms(const char **a1, int a2, int a3)
{
  const char **v3; // $s0
  const char *v4; // $a0
  int v7; // $s1
  const char *v8; // $s7
  const char *v9; // $v0
  int v10; // $a0

  v3 = a1;
  v4 = *a1;
  if ( !v4 || !*v4 )
    return 0;
  v7 = 0;
  do
  {
    v10 = jhl_nv_get_def(v4);
    if ( v10 )
    {
      v8 = *v3++;
      v9 = (const char *)get_json_data(v10);
      v7 += sprintf((char *)(a2 + v7), " \"%s\":\"%s\",", v8, v9);
      if ( v7 + 199 >= a3 )
        return v7;
    }
    else
    {
      v7 += sprintf((char *)(a2 + v7), " \"%s\":\"\",", *v3++);
      if ( v7 + 199 >= a3 )
        return v7;
    }
    v4 = *v3;
  }
  while ( *v3 && *v4 );
  return v7;
}
// 6A84C8: using guessed type int __fastcall jhl_nv_get_def(_DWORD);
// 6A871C: using guessed type int __fastcall get_json_data(_DWORD);

