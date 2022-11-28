int __fastcall sub_43937C(int a1)
{
  int v1; // $v0
  int v2; // $s0
  char *v3; // $s1
  char *v4; // $v0
  char *v5; // $s6
  char *v6; // $v0
  char *v7; // $s5
  void *v8; // $v0
  void *v9; // $v0
  int v10; // $a0
  _BYTE *v11; // $v0
  _BYTE *v12; // $s7
  int **v13; // $fp
  int i; // $s0
  int v15; // $v0
  char *v16; // $v1
  const char *v17; // $v0
  int v18; // $t0
  int v19; // $a3
  int v20; // $a2
  int v21; // $a1
  unsigned int v22; // $s0
  const char *v24; // $v0
  int v25; // $a1
  const char *v26; // $a2
  int v27; // $a0
  const char *v28; // $v0
  void *v29; // $s2
  char *v30; // $s1
  int v31; // $s4
  int v32; // $s2
  int v33; // $v0
  void *v34; // $s0
  const char *v35; // $v0
  const char *v36; // $v0
  int v37; // $s2
  void *v38; // $s3
  int v39; // $v0
  char v40[8000]; // [sp+28h] [-1FE8h] BYREF
  char v41[128]; // [sp+1F68h] [-A8h] BYREF
  int v42; // [sp+1FE8h] [-28h] BYREF
  int v43; // [sp+1FECh] [-24h]
  void *v44; // [sp+1FF0h] [-20h]
  char *v45; // [sp+1FF4h] [-1Ch]
  char *format; // [sp+1FF8h] [-18h]
  char *s; // [sp+1FFCh] [-14h]
  void *v48; // [sp+2000h] [-10h]
  char *v49; // [sp+2004h] [-Ch]
  char *v50; // [sp+2008h] [-8h]

  s = v41;
  memset(v41, 0, sizeof(v41));
  v1 = httpd_get_json_parm(a1, (int)"mac_arr");
  v49 = "a";
  v2 = v1;
  v3 = httpd_get_parm(a1, "wan_id");
  format = (char *)nvram_get("wysz_wan_out_rule");
  if ( v2 )
  {
    if ( v3 )
    {
      v45 = "a";
      _mem_malloc(0x80000, "sdwan_hi_asp", 1325);
      v5 = v4;
      if ( v4 )
      {
        _mem_malloc(0x80000, v45 + 11232, 1332);
        v7 = v6;
        if ( !v6 )
        {
          v35 = (const char *)_GET_LANG_TEXT(4, *(unsigned __int8 *)(a1 + 210102), 0x80000);
          v22 = snprintf(s, 128, "{\"code\":%d,\"error\":\"%s\",\"data\":null}", 1, v35);
          if ( v22 >= 0x80 )
            v22 = 127;
          v48 = 0;
          v44 = 0;
          v12 = 0;
          goto LABEL_16;
        }
        _mem_malloc(0x80000, v45 + 11232, 1339);
        v44 = v8;
        if ( v8 )
        {
          _mem_malloc(0x80000, v45 + 11232, 1346);
          v48 = v9;
          if ( v9 )
          {
            _mem_malloc(0x80000, v45 + 11232, 1353);
            v12 = v11;
            if ( v11 )
            {
              v13 = *(int ***)(v2 + 8);
              for ( i = 0; v13; i += v15 )
              {
                v15 = snprintf(&v12[i], 0x80000 - i, "%s|%s;", (const char *)v13[4], v3);
                if ( v15 >= 0x80000 - i )
                  v15 = 0x7FFFF - i;
                v13 = (int **)*v13;
              }
              if ( *v12 )
              {
                v29 = v48;
                strlcpy(v48, v12, 0x80000);
                v30 = v40;
                v31 = split_string(v29, 59, v40, 2000);
                if ( format && *format )
                {
                  v50 = "1\"";
                  snprintf(v7, 0x80000, "%s", format);
                  if ( v31 > 0 )
                  {
                    v37 = 0;
                    format = "%s|%s;";
                    do
                    {
                      if ( split_string(*(_DWORD *)v30, 124, &v42, 2) > 0 )
                      {
                        v38 = v44;
                        nvparm_del_str_too_too_long(v7, 59, 0, v42, 124, 0, v44);
                        memset(v7, 0, 0x80000u);
                        v44 = v38;
                        strlcpy(v7, v38, 0x80000);
                        memset(v44, 0, 0x80000u);
                        if ( J_atoi(v43) != 0xFFFF )
                        {
                          v39 = snprintf(&v5[i], 0x80000 - i, format, v42, v43);
                          if ( v39 >= 0x80000 - i )
                            v39 = 0x7FFFF - i;
                          i += v39;
                        }
                      }
                      ++v37;
                      v30 += 4;
                    }
                    while ( v31 != v37 );
                  }
                  snprintf(&v5[i], 0x80000 - i, v50 - 26268, v7);
                }
                else if ( v31 > 0 )
                {
                  v32 = 0;
                  format = "%s|%s;";
                  do
                  {
                    if ( split_string(*(_DWORD *)v30, 124, &v42, 2) > 0 && J_atoi(v43) != 0xFFFF )
                    {
                      v33 = snprintf(&v5[i], 0x80000 - i, format, v42, v43);
                      if ( v33 >= 0x80000 - i )
                        v33 = 0x7FFFF - i;
                      i += v33;
                    }
                    ++v32;
                    v30 += 4;
                  }
                  while ( v31 != v32 );
                }
                v34 = v48;
                memset(v48, 0, 0x80000u);
                strlcpy(v34, v12, 0x80000);
                wyaos_z_wan_out_set_macs(v34);
                nvram_set(v49 + 10056, v5);
              }
              jhl_parm_commit(v10);
              v16 = s;
              v17 = "{\"code\":0,\"error\":\"\",\"data\":null}";
              do
              {
                v18 = *(_DWORD *)v17;
                v19 = *((_DWORD *)v17 + 1);
                v20 = *((_DWORD *)v17 + 2);
                v21 = *((_DWORD *)v17 + 3);
                v17 += 16;
                *(_DWORD *)v16 = v18;
                *((_DWORD *)v16 + 1) = v19;
                *((_DWORD *)v16 + 2) = v20;
                *((_DWORD *)v16 + 3) = v21;
                v16 += 16;
              }
              while ( v17 != "}" );
              v22 = 33;
              *(_WORD *)v16 = *(_WORD *)v17;
              goto LABEL_16;
            }
          }
          v36 = (const char *)_GET_LANG_TEXT(4, *(unsigned __int8 *)(a1 + 210102), 0x80000);
          v22 = snprintf(s, 128, "{\"code\":%d,\"error\":\"%s\",\"data\":null}", 1, v36);
          if ( v22 >= 0x80 )
          {
            v22 = 127;
            v12 = 0;
            goto LABEL_16;
          }
        }
        else
        {
          v24 = (const char *)_GET_LANG_TEXT(4, *(unsigned __int8 *)(a1 + 210102), 0x80000);
          v22 = snprintf(s, 128, "{\"code\":%d,\"error\":\"%s\",\"data\":null}", 1, v24);
          if ( v22 >= 0x80 )
            v22 = 127;
          v48 = 0;
        }
        v12 = 0;
LABEL_16:
        _mem_free(v5);
        if ( v7 )
          _mem_free(v7);
        if ( v44 )
          _mem_free(v44);
        if ( v48 )
          _mem_free(v48);
        if ( v12 )
          _mem_free(v12);
        return httpd_cgi_ret(a1, s, v22, 4);
      }
      v25 = *(unsigned __int8 *)(a1 + 210102);
      v26 = (const char *)0x80000;
      v27 = 4;
    }
    else
    {
      v25 = *(unsigned __int8 *)(a1 + 210102);
      v26 = "wan_id";
      v27 = 12;
    }
  }
  else
  {
    v25 = *(unsigned __int8 *)(a1 + 210102);
    v26 = "mac_arr";
    v27 = 12;
  }
  v28 = (const char *)_GET_LANG_TEXT(v27, v25, v26);
  v22 = snprintf(s, 128, "{\"code\":%d,\"error\":\"%s\",\"data\":null}", 1, v28);
  if ( v22 >= 0x80 )
    v22 = 127;
  return httpd_cgi_ret(a1, s, v22, 4);
}
// 439468: variable 'v4' is possibly undefined
// 43948C: variable 'v6' is possibly undefined
// 4394A8: variable 'v8' is possibly undefined
// 4394CC: variable 'v9' is possibly undefined
// 4394F8: variable 'v11' is possibly undefined
// 439580: variable 'v10' is possibly undefined
// 6A8180: using guessed type int __fastcall jhl_parm_commit(_DWORD);
// 6A81BC: using guessed type int __fastcall nvram_get(_DWORD);
// 6A8318: using guessed type int __fastcall _GET_LANG_TEXT(_DWORD, _DWORD, _DWORD);
// 6A8480: using guessed type int __fastcall strlcpy(_DWORD, _DWORD, _DWORD);
// 6A8500: using guessed type int __fastcall wyaos_z_wan_out_set_macs(_DWORD);
// 6A8560: using guessed type int __fastcall nvparm_del_str_too_too_long(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD);
// 6A8778: using guessed type int __fastcall split_string(_DWORD, _DWORD, _DWORD, _DWORD);
// 6A8918: using guessed type int __fastcall nvram_set(_DWORD, _DWORD);
// 6A89B4: using guessed type int __fastcall J_atoi(_DWORD);

