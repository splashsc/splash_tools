int __fastcall set_nvrams(int a1, _BYTE **a2, int a3)
{
  _DWORD *v3; // $s0
  _BYTE *v4; // $a1
  int v7; // $s3
  int v8; // $v0
  int v9; // $s1
  int v10; // $v0
  int v11; // $a1
  const char *v13; // $s7
  const char *v14; // $v0

  v3 = a2;
  v4 = *a2;
  v7 = 0;
  if ( v4 )
  {
    while ( 1 )
    {
      if ( !*v4 )
        return v7;
      v8 = httpd_get_json_parm(a1, (int)v4);
      v9 = v8;
      if ( !v8 )
        goto LABEL_8;
      if ( !cJSON_IsNumber(v8) )
        break;
      v10 = nvram_get_int(*v3);
      v11 = *(_DWORD *)(v9 + 20);
      if ( v10 != v11 )
      {
        if ( a3 == 1 )
        {
          v7 = 1;
          nvram_set_int(*v3++, v11);
          goto LABEL_9;
        }
LABEL_7:
        v7 = 1;
      }
LABEL_8:
      ++v3;
LABEL_9:
      v4 = (_BYTE *)*v3;
      if ( !*v3 )
        return v7;
    }
    if ( !cJSON_IsString(v9) )
      goto LABEL_8;
    v13 = *(const char **)(v9 + 16);
    if ( !strcmp(v13, "undefined") )
      goto LABEL_8;
    v14 = (const char *)nvram_get(*v3);
    if ( v14 )
    {
      if ( !strcmp(v14, v13) )
        goto LABEL_8;
    }
    if ( a3 == 1 )
    {
      v7 = 1;
      nvram_set(*v3++, *(_DWORD *)(v9 + 16));
      goto LABEL_9;
    }
    goto LABEL_7;
  }
  return v7;
}
// 6A81B4: using guessed type int __fastcall nvram_get_int(_DWORD);
// 6A81BC: using guessed type int __fastcall nvram_get(_DWORD);
// 6A8248: using guessed type int __fastcall cJSON_IsString(_DWORD);
// 6A878C: using guessed type int __fastcall nvram_set_int(_DWORD, _DWORD);
// 6A88F0: using guessed type int __fastcall cJSON_IsNumber(_DWORD);
// 6A8918: using guessed type int __fastcall nvram_set(_DWORD, _DWORD);

