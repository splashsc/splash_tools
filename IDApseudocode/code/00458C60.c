int __fastcall sub_458C60(int a1)
{
  char **v1; // $v0
  const char **v3; // $v1
  char *v4; // $t0
  const char *v5; // $a3
  const char *v6; // $a2
  const char *v7; // $a1
  char *v8; // $a0
  const char *v9; // $v0
  int v10; // $v0
  int v11; // $s0
  int v12; // $v0
  int v13; // $s1
  int v14; // $s1
  int v15; // $s2
  int v16; // $v0
  int v17; // $a2
  int v18; // $s1
  int v19; // $a2
  const char *v21; // $v0
  unsigned int v22; // $v0
  char v23[256]; // [sp+20h] [-16Ch] BYREF
  const char *v24[27]; // [sp+120h] [-6Ch] BYREF

  v1 = off_66FCA0;
  v3 = v24;
  do
  {
    v4 = *v1;
    v5 = v1[1];
    v6 = v1[2];
    v7 = v1[3];
    v1 += 4;
    *v3 = v4;
    v3[1] = v5;
    v3[2] = v6;
    v3[3] = v7;
    v3 += 4;
  }
  while ( v1 != (char **)&off_66FD00 );
  v8 = *v1;
  v9 = v1[1];
  *v3 = v8;
  v3[1] = v9;
  _mem_malloc(10240, "webgl_data", 65);
  v11 = v10;
  if ( v10 )
  {
    v12 = nvram_match_def("pppoe_br_enable", "1");
    strcpy((char *)v11, "{\"code\":0,\"error\":\"\",\"data\":{");
    qmemcpy((void *)v11, "{\"code\":0,\"error\":\"\"", 20);
    *(_DWORD *)(v11 + 24) = 975331700;
    v13 = sprintf((char *)(v11 + 29), "\"pppoe_br\":\"%d\",", v12 != 0) + 29;
    v14 = v13 + get_nvarms(v24, v11 + v13, 10240 - v13);
    v15 = pidof("dropbear");
    v16 = pidof("telnetd");
    if ( v16 < 0 )
    {
      v16 = 0;
      v17 = v15;
      if ( v15 >= 0 )
        goto LABEL_6;
    }
    else
    {
      v17 = v15;
      if ( v15 >= 0 )
      {
LABEL_6:
        v18 = v14 + sprintf((char *)(v11 + v14), "\"sdup\":\"%d\",\"tdup\":\"%d\"", v17, v16);
        v19 = snprintf((char *)(v11 + v18), 10240 - v18, "}}");
        if ( v19 >= 10240 - v18 )
          v19 = 10239 - v18;
        return httpd_cgi_ret(a1, (char *)v11, v19 + v18, 8);
      }
    }
    v17 = 0;
    goto LABEL_6;
  }
  v21 = (const char *)_GET_LANG_TEXT(4, *(unsigned __int8 *)(a1 + 210102), 10240);
  v22 = snprintf(v23, 256, "{\"code\":%d,\"error\":\"%s\",\"data\":null}", 1, v21);
  if ( v22 >= 0x100 )
    v22 = 255;
  return httpd_cgi_ret(a1, v23, v22, 4);
}
// 458CFC: variable 'v10' is possibly undefined
// 642164: using guessed type __int16 word_642164;
// 66FCA0: using guessed type char *off_66FCA0[24];
// 66FD00: using guessed type void *off_66FD00;
// 6A8318: using guessed type int __fastcall _GET_LANG_TEXT(_DWORD, _DWORD, _DWORD);
// 6A83E4: using guessed type int __fastcall nvram_match_def(_DWORD, _DWORD);
// 6A8614: using guessed type int __fastcall pidof(_DWORD);

