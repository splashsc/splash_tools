int __fastcall sub_44B100(int a1, char *a2, int a3, int a4)
{
  char *v7; // $v0
  const char *v9; // $s0
  bool v10; // dc
  int result; // $v0
  const char *v12; // $v0

  v7 = httpd_get_parm(a1, a2);
  if ( !v7 )
    return jhl_web_save_json_parm2(a1, (int)a2, a3, a4);
  v9 = v7;
  v10 = strcmp(v7, "undefined") != 0;
  result = 0;
  if ( v10 )
  {
    v12 = (const char *)nvram_get(a3);
    if ( !v12 || (v10 = strcmp(v12, v9) == 0, result = 0, !v10) )
    {
      result = 1;
      if ( a4 == 1 )
      {
        nvram_set(a3, v9);
        result = 1;
      }
    }
  }
  return result;
}
// 6A81BC: using guessed type int __fastcall nvram_get(_DWORD);
// 6A8918: using guessed type int __fastcall nvram_set(_DWORD, _DWORD);

