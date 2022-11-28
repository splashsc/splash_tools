int __fastcall mrclfile_cgi(int a1, int a2, const char *a3)
{
  int v3; // $s3
  int v4; // $s6
  char *v7; // $v0
  char *v9; // $v0
  const char *v10; // $s0
  int v11; // $s6
  signed int v12; // $v0
  int v13; // $s1
  const char *v14; // $a2
  const char *v15; // $v0
  unsigned int v16; // $a2
  int v18; // $a0
  const char *v19; // $v0
  int v20[256]; // [sp+20h] [-60Ch] BYREF
  char v21[256]; // [sp+420h] [-20Ch] BYREF
  char v22[256]; // [sp+520h] [-10Ch] BYREF
  const char *v23; // [sp+620h] [-Ch]

  v3 = a1 + 196608;
  v4 = *(_DWORD *)(a1 + 205364);
  find_file_head(a1, *(const char **)(a1 + 205564));
  if ( v7 )
  {
    v10 = v7;
    v9 = find_file_end(a1, v7, *(_DWORD *)(v3 + 8956) + v4 - (_DWORD)v7);
    v11 = v9 - v10;
    if ( v9 )
    {
      if ( v11 >= 204801 )
      {
        v14 = (const char *)_GET_LANG_TEXT(40, *(unsigned __int8 *)(v3 + 13494), "200K");
      }
      else
      {
        *v9 = 0;
        v12 = strlen(v10);
        v13 = v11;
        if ( v12 < v11 )
          v13 = v12;
        sprintf(v22, "/etc/mrcl/%s_tmp.txt", a3);
        f_write(v22, v10, v13, 0, 448);
        if ( judge_ipaddr_file_valid(v22) )
        {
          unlink(v22);
          sprintf(v22, "/etc/mrcl/%s.txt", a3);
          sprintf(v21, "mrcl_%s", a3);
          f_write(v22, v10, v13, 0, 448);
          v20[0] = (int)"wys";
          v20[1] = (int)"mrcl_ips";
          v20[2] = a2;
          v20[3] = (int)a3;
          v20[4] = (int)v22;
          v20[5] = 0;
          eval(v20, 0, 0, 0);
          nvram_set_zipfile(v21, v22, 204800);
          jhl_parm_commit(v18);
          goto LABEL_12;
        }
        v23 = (const char *)_GET_LANG_TEXT(42, *(unsigned __int8 *)(a1 + 210102), "");
        unlink(v22);
        v14 = v23;
      }
      if ( v14 )
        goto LABEL_9;
LABEL_12:
      v19 = (const char *)_GET_LANG_TEXT(34, *(unsigned __int8 *)(a1 + 210102), v14);
      v16 = snprintf((char *)v20, 1024, "{\"code\":0,\"error\":\"\",\"message\":\"%s\",\"data\":null}", v19);
      if ( v16 < 0x400 )
        return httpd_cgi_ret(a1, (char *)v20, v16, 4);
LABEL_13:
      v16 = 1023;
      return httpd_cgi_ret(a1, (char *)v20, v16, 4);
    }
  }
  v14 = "Error reading file";
LABEL_9:
  v15 = (const char *)_GET_LANG_TEXT(33, *(unsigned __int8 *)(a1 + 210102), v14);
  v16 = snprintf((char *)v20, 1024, "{\"code\":%d,\"error\":\"%s\",\"data\":null}", 1, v15);
  if ( v16 >= 0x400 )
    goto LABEL_13;
  return httpd_cgi_ret(a1, (char *)v20, v16, 4);
}
// 4C4578: variable 'v7' is possibly undefined
// 4C47FC: variable 'v18' is possibly undefined
// 4C4818: variable 'v14' is possibly undefined
// 6A8180: using guessed type int __fastcall jhl_parm_commit(_DWORD);
// 6A8204: using guessed type int __fastcall f_write(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD);
// 6A8318: using guessed type int __fastcall _GET_LANG_TEXT(_DWORD, _DWORD, _DWORD);
// 6A83DC: using guessed type int __fastcall eval(_DWORD, _DWORD, _DWORD, _DWORD);
// 6A84F8: using guessed type int __fastcall judge_ipaddr_file_valid(_DWORD);
// 6A861C: using guessed type int __fastcall nvram_set_zipfile(_DWORD, _DWORD, _DWORD);

