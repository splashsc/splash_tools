int __fastcall jhl_web_save_parm(int a1, char *a2, int a3)
{
  char *v5; // $v0
  const char *v7; // $s0
  bool v8; // dc
  int result; // $v0
  const char *v10; // $v0

  v5 = httpd_get_parm(a1, a2);
  if ( !v5 )
    return jhl_web_save_json_parm(a1, (int)a2, a3);
  v7 = v5;
  v8 = strcmp(v5, "undefined") != 0;
  result = 0;
  if ( v8 )
  {
    v10 = (const char *)nvram_get(a2);
    if ( !v10 || (v8 = strcmp(v10, v7) == 0, result = 0, !v8) )
    {
      result = 1;
      if ( a3 == 1 )
      {
        nvram_set(a2, v7);
        result = 1;
      }
    }
  }
  return result;
}
// 6A81BC: using guessed type int __fastcall nvram_get(_DWORD);
// 6A8918: using guessed type int __fastcall nvram_set(_DWORD, _DWORD);

