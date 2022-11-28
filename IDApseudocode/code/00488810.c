int __fastcall sub_488810(int a1)
{
  void *v2; // $v0
  int v3; // $v0
  void *v4; // $s1
  const char **v5; // $s0
  int v6; // $s3
  int v7; // $s2
  int v8; // $s1
  int v9; // $v0
  char *v10; // $s1
  const char *v12; // [sp+38h] [-4178h] BYREF
  int v13; // [sp+3Ch] [-4174h]
  char v14[256]; // [sp+4038h] [-178h] BYREF
  int v15[11]; // [sp+4138h] [-78h] BYREF
  int v16; // [sp+4164h] [-4Ch] BYREF
  int v17; // [sp+4168h] [-48h]
  int v18; // [sp+416Ch] [-44h]
  int v19; // [sp+4170h] [-40h]
  int v20; // [sp+4174h] [-3Ch]
  int v21; // [sp+4178h] [-38h]
  int v22; // [sp+417Ch] [-34h]
  int v23; // [sp+4180h] [-30h]
  int v24; // [sp+4184h] [-2Ch]
  int v25; // [sp+4190h] [-20h]
  char *v26; // [sp+4194h] [-1Ch]
  char *format; // [sp+4198h] [-18h]
  const char *v28; // [sp+419Ch] [-14h]
  void *v29; // [sp+41A0h] [-10h]
  char *v30; // [sp+41A4h] [-Ch]
  char *v31; // [sp+41A8h] [-8h]

  v31 = "1\"";
  memset(v14, 0, sizeof(v14));
  _mem_malloc(0x200000, "url_rule_change_def", 654);
  v29 = v2;
  v4 = v2;
  _mem_malloc(0x200000, "url_rule_change_def", 655);
  v26 = (char *)v3;
  if ( !v4 )
    return -1;
  v5 = &v12;
  if ( !v3 )
    return -1;
  v12 = "url_clean.sh";
  v13 = 0;
  eval(&v12, 0, 0, 0);
  v30 = "a";
  v12 = "urlfilter_clean.sh";
  v13 = 0;
  eval(&v12, 0, 0, 0);
  jhl_parm_get("url_rules", v4, 0x200000);
  v6 = split_string(v4, 60, &v12, 4096);
  if ( v6 > 0 )
  {
    format = "%s|%s|%s|%s|%s|%s|%s|%s|%s<";
    v7 = 0;
    v8 = 0;
    v28 = "url_add.sh";
    do
    {
      while ( split_string(*v5, 124, &v16, 9) < 9 )
      {
        ++v8;
        ++v5;
        if ( v6 == v8 )
          goto LABEL_12;
      }
      v25 = 0x200000 - v7;
      v23 = a1;
      v9 = snprintf(&v26[v7], 0x200000 - v7, format, v16, v17, v18, v19, v20, v21, v22, a1, v24);
      if ( v9 >= v25 )
        v9 = 0x1FFFFF - v7;
      v7 += v9;
      if ( get_time_group(v20, v14, 256) )
        strlcpy(v14, v20, 256);
      v15[0] = (int)v28;
      v15[1] = v16;
      v15[2] = v17;
      v15[3] = v18;
      v15[4] = v19;
      v15[5] = (int)v14;
      v15[7] = v21;
      v15[6] = (int)v14;
      v15[8] = v22;
      v15[10] = 0;
      v15[9] = v23;
      ++v8;
      eval(v15, 0, 0, 0);
      ++v5;
    }
    while ( v6 != v8 );
  }
LABEL_12:
  v10 = v26;
  jhl_parm_set(v30 + 27940, v26);
  _mem_free(v29);
  _mem_free(v10);
  return 0;
}
// 4888A0: variable 'v2' is possibly undefined
// 4888AC: variable 'v3' is possibly undefined
// 6A8298: using guessed type int __fastcall get_time_group(_DWORD, _DWORD, _DWORD);
// 6A8308: using guessed type int __fastcall jhl_parm_set(_DWORD, _DWORD);
// 6A83DC: using guessed type int __fastcall eval(_DWORD, _DWORD, _DWORD, _DWORD);
// 6A8480: using guessed type int __fastcall strlcpy(_DWORD, _DWORD, _DWORD);
// 6A8600: using guessed type int __fastcall jhl_parm_get(_DWORD, _DWORD, _DWORD);
// 6A8778: using guessed type int __fastcall split_string(_DWORD, _DWORD, _DWORD, _DWORD);

