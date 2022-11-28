int __fastcall sub_460DC4(int a1)
{
  void *v2; // $v0
  int v3; // $v0
  void *v4; // $s1
  int *v5; // $s0
  int v6; // $s3
  int v7; // $s2
  int v8; // $s1
  int v9; // $v0
  char *v10; // $s1
  int v12[4096]; // [sp+28h] [-4158h] BYREF
  char v13[256]; // [sp+4028h] [-158h] BYREF
  int v14[7]; // [sp+4128h] [-58h] BYREF
  int v15; // [sp+4144h] [-3Ch] BYREF
  int v16; // [sp+4148h] [-38h]
  int v17; // [sp+414Ch] [-34h]
  int v18; // [sp+4150h] [-30h]
  int v19; // [sp+4154h] [-2Ch]
  int v20; // [sp+4160h] [-20h]
  char *v21; // [sp+4164h] [-1Ch]
  char *format; // [sp+4168h] [-18h]
  const char *v23; // [sp+416Ch] [-14h]
  void *v24; // [sp+4170h] [-10h]
  char *v25; // [sp+4174h] [-Ch]
  char *v26; // [sp+4178h] [-8h]

  v26 = "a";
  memset(v13, 0, sizeof(v13));
  _mem_malloc(0x200000, "mac_filter_change_def", 786);
  v24 = v2;
  v4 = v2;
  _mem_malloc(0x200000, "mac_filter_change_def", 787);
  v21 = (char *)v3;
  if ( !v4 )
    return -1;
  v5 = v12;
  if ( !v3 )
    return -1;
  v25 = "a";
  v12[0] = (int)"macfilter_delall.sh";
  v12[1] = 0;
  eval(v12, 0, 0, 0);
  jhl_parm_get("macfilterAll", v4, 0x200000);
  v6 = split_string(v4, 60, v12, 4096);
  if ( v6 > 0 )
  {
    format = "%s|%s|%s|%s|%s<";
    v7 = 0;
    v8 = 0;
    v23 = "macfilter_add.sh";
    do
    {
      while ( split_string(*v5, 124, &v15, 5) < 5 )
      {
        ++v8;
        ++v5;
        if ( v6 == v8 )
          goto LABEL_12;
      }
      v20 = 0x200000 - v7;
      v19 = a1;
      v9 = snprintf(&v21[v7], 0x200000 - v7, format, v15, v16, v17, v18, a1);
      if ( v9 >= v20 )
        v9 = 0x1FFFFF - v7;
      v7 += v9;
      if ( get_time_group(v18, v13, 256) )
        strlcpy(v13, v18, 256);
      v14[0] = (int)v23;
      v14[1] = v16;
      v14[2] = v15;
      v14[3] = v17;
      v14[4] = v19;
      v14[5] = (int)v13;
      v14[6] = 0;
      ++v8;
      eval(v14, 0, 0, 0);
      ++v5;
    }
    while ( v6 != v8 );
  }
LABEL_12:
  v10 = v21;
  jhl_parm_set(v25 + 25912, v21);
  _mem_free(v24);
  _mem_free(v10);
  return 0;
}
// 460E54: variable 'v2' is possibly undefined
// 460E60: variable 'v3' is possibly undefined
// 6A8298: using guessed type int __fastcall get_time_group(_DWORD, _DWORD, _DWORD);
// 6A8308: using guessed type int __fastcall jhl_parm_set(_DWORD, _DWORD);
// 6A83DC: using guessed type int __fastcall eval(_DWORD, _DWORD, _DWORD, _DWORD);
// 6A8480: using guessed type int __fastcall strlcpy(_DWORD, _DWORD, _DWORD);
// 6A8600: using guessed type int __fastcall jhl_parm_get(_DWORD, _DWORD, _DWORD);
// 6A8778: using guessed type int __fastcall split_string(_DWORD, _DWORD, _DWORD, _DWORD);

