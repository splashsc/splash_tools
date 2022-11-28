int __fastcall sub_4A21C4(int a1)
{
  int v1; // $v0
  int v3; // $s0
  _DWORD *i; // $s0
  char *v5; // $v0
  int *v6; // $v1
  const char *v7; // $v0
  int v8; // $t0
  int v9; // $a3
  int v10; // $a2
  int v11; // $a1
  unsigned int v12; // $a2
  const char *v13; // $v0
  int v15[64]; // [sp+20h] [-100h] BYREF

  v1 = httpd_get_json_parm(a1, (int)&off_646724);
  if ( v1 && (v3 = v1, cJSON_IsArray(v1)) )
  {
    for ( i = *(_DWORD **)(v3 + 8); i; i = (_DWORD *)*i )
    {
      if ( i[4] )
      {
        v15[0] = (int)"ether-wake";
        v15[1] = (int)"-i";
        v5 = (char *)nvram_get("lan_ifname");
        if ( !v5 )
          v5 = "";
        v15[2] = (int)v5;
        v15[3] = i[4];
        v15[4] = 0;
        eval(v15, 0, 0, 0);
      }
    }
    v6 = v15;
    v7 = "{\"code\":0,\"error\":\"\",\"data\":null}";
    do
    {
      v8 = *(_DWORD *)v7;
      v9 = *((_DWORD *)v7 + 1);
      v10 = *((_DWORD *)v7 + 2);
      v11 = *((_DWORD *)v7 + 3);
      v7 += 16;
      *v6 = v8;
      v6[1] = v9;
      v6[2] = v10;
      v6[3] = v11;
      v6 += 4;
    }
    while ( v7 != "}" );
    v12 = 33;
    *(_WORD *)v6 = *(_WORD *)v7;
  }
  else
  {
    v13 = (const char *)_GET_LANG_TEXT(12, *(unsigned __int8 *)(a1 + 210102), "error mac");
    v12 = snprintf((char *)v15, 256, "{\"code\":%d,\"error\":\"%s\",\"data\":null}", 1, v13);
    if ( v12 >= 0x100 )
      v12 = 255;
  }
  httpd_cgi_ret(a1, (char *)v15, v12, 4);
  return 0;
}
// 646724: using guessed type void *off_646724;
// 6A81BC: using guessed type int __fastcall nvram_get(_DWORD);
// 6A82B4: using guessed type int __fastcall cJSON_IsArray(_DWORD);
// 6A8318: using guessed type int __fastcall _GET_LANG_TEXT(_DWORD, _DWORD, _DWORD);
// 6A83DC: using guessed type int __fastcall eval(_DWORD, _DWORD, _DWORD, _DWORD);

