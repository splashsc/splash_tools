int __fastcall jhl_web_save_json_parm(int a1, int a2, int a3)
{
  int v3; // $v0
  _DWORD *v5; // $s0
  int v6; // $v0
  int v7; // $a1
  bool v8; // dc
  int result; // $v0
  const char *v10; // $s2
  const char *v11; // $v0

  v3 = httpd_get_json_parm(a1, a2);
  if ( !v3 )
    return 0;
  v5 = (_DWORD *)v3;
  if ( cJSON_IsNumber(v3) )
  {
    v6 = nvram_get_int(v5[8]);
    v7 = v5[5];
    v8 = v6 == v7;
    result = 1;
    if ( !v8 )
    {
      if ( a3 == 1 )
      {
        nvram_set_int(v5[8], v7);
        result = 1;
      }
      return result;
    }
    return 0;
  }
  v8 = cJSON_IsString(v5) == 0;
  result = 0;
  if ( v8 )
    return result;
  v10 = (const char *)v5[4];
  if ( !strcmp(v10, "undefined") )
    return 0;
  v11 = (const char *)nvram_get(v5[8]);
  if ( !v11 || (v8 = strcmp(v11, v10) == 0, result = 0, !v8) )
  {
    result = 1;
    if ( a3 == 1 )
    {
      nvram_set(v5[8], v5[4]);
      result = 1;
    }
  }
  return result;
}
// 6A81B4: using guessed type int __fastcall nvram_get_int(_DWORD);
// 6A81BC: using guessed type int __fastcall nvram_get(_DWORD);
// 6A8248: using guessed type int __fastcall cJSON_IsString(_DWORD);
// 6A878C: using guessed type int __fastcall nvram_set_int(_DWORD, _DWORD);
// 6A88F0: using guessed type int __fastcall cJSON_IsNumber(_DWORD);
// 6A8918: using guessed type int __fastcall nvram_set(_DWORD, _DWORD);

