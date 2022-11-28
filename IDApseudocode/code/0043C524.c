int __fastcall sub_43C524(int a1)
{
  char *v1; // $s2
  int v2; // $s3
  int v3; // $s0
  int v4; // $s7
  const char **v5; // $s6
  int v6; // $fp
  const char *v7; // $a3
  char *v8; // $a0
  unsigned int v9; // $v0
  char *v10; // $a0
  int v11; // $a0
  char *v12; // $v1
  const char *v13; // $v0
  int v14; // $t0
  int v15; // $a3
  int v16; // $a2
  int v17; // $a1
  unsigned int v18; // $a2
  int v20; // $a1
  void *v21; // $a2
  const char *v22; // $v0
  char *v23; // $v0
  char v24[1024]; // [sp+20h] [-1018h] BYREF
  char v25[1024]; // [sp+420h] [-C18h] BYREF
  char v26[1024]; // [sp+820h] [-818h] BYREF
  char v27[1024]; // [sp+C20h] [-418h] BYREF
  const char *v28; // [sp+1020h] [-18h]
  char *v29; // [sp+1024h] [-14h]
  char *s; // [sp+1028h] [-10h]
  char *v31; // [sp+102Ch] [-Ch]
  char *v32; // [sp+1030h] [-8h]

  s = v27;
  memset(v27, 0, sizeof(v27));
  memset(v26, 0, sizeof(v26));
  memset(v25, 0, sizeof(v25));
  v1 = httpd_get_parm(a1, "mod_vid");
  v31 = httpd_get_parm(a1, "desc");
  if ( v1 )
  {
    if ( v31 )
    {
      v32 = "a";
      v2 = atoi(v1);
      v29 = v24;
      jhl_parm_get_def("port_desc", v26, 1024);
      v3 = split_string(v26, 124, v24, 256);
      if ( v2 >= v3 )
        v3 = v2 + 1;
      v4 = 0;
      if ( v3 > 0 )
      {
        v5 = (const char **)v29;
        v28 = "a: no-cache\r\nCache-Control: no-cache\r\nSec-WebSocket-Accept: %s\r\n\r\n";
        v6 = 0;
        do
        {
          if ( v2 == v6 )
          {
            v23 = v31;
            *v5 = v31;
            v8 = &v25[v4];
            v7 = v23;
          }
          else
          {
            v7 = *v5;
            v8 = &v25[v4];
            if ( !*v5 )
              v7 = v28 - 1556;
          }
          v9 = snprintf(v8, 1024 - v4, "%s|", v7);
          ++v6;
          if ( v9 >= 1024 - v4 )
            v9 = 1023 - v4;
          v4 += v9;
          ++v5;
        }
        while ( v3 != v6 );
        if ( v4 > 0 && v29[v4 + 1023] == 124 )
          --v4;
      }
      v10 = v32 + 11480;
      v29[v4 + 1024] = 0;
      nvram_set(v10, v25);
      jhl_parm_commit(v11);
      v12 = s;
      v13 = "{\"code\":0,\"error\":\"\",\"data\":null}";
      do
      {
        v14 = *(_DWORD *)v13;
        v15 = *((_DWORD *)v13 + 1);
        v16 = *((_DWORD *)v13 + 2);
        v17 = *((_DWORD *)v13 + 3);
        v13 += 16;
        *(_DWORD *)v12 = v14;
        *((_DWORD *)v12 + 1) = v15;
        *((_DWORD *)v12 + 2) = v16;
        *((_DWORD *)v12 + 3) = v17;
        v12 += 16;
      }
      while ( v13 != "}" );
      v18 = 33;
      *(_WORD *)v12 = *(_WORD *)v13;
      return httpd_cgi_ret(a1, s, v18, 4);
    }
    v20 = *(unsigned __int8 *)(a1 + 210102);
    v21 = &unk_642CF0;
  }
  else
  {
    v20 = *(unsigned __int8 *)(a1 + 210102);
    v21 = &unk_642CE4;
  }
  v22 = (const char *)_GET_LANG_TEXT(12, v20, v21);
  v18 = snprintf(s, 1024, "{\"code\":%d,\"error\":\"%s\",\"data\":null}", 1, v22);
  if ( v18 >= 0x400 )
    v18 = 1023;
  return httpd_cgi_ret(a1, s, v18, 4);
}
// 43C740: variable 'v11' is possibly undefined
// 6A8180: using guessed type int __fastcall jhl_parm_commit(_DWORD);
// 6A8318: using guessed type int __fastcall _GET_LANG_TEXT(_DWORD, _DWORD, _DWORD);
// 6A8778: using guessed type int __fastcall split_string(_DWORD, _DWORD, _DWORD, _DWORD);
// 6A8918: using guessed type int __fastcall nvram_set(_DWORD, _DWORD);
// 6A8988: using guessed type int __fastcall jhl_parm_get_def(_DWORD, _DWORD, _DWORD);

