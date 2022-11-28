int __fastcall sub_4C975C(int a1)
{
  int v2; // $v0
  char *v3; // $s2
  int v4; // $s1
  size_t v5; // $v0
  unsigned int v6; // $s2
  unsigned int v7; // $v0
  size_t v8; // $s3
  const char *v10; // $v0
  unsigned int v11; // $a2
  const char *v12; // $v0
  char *v13; // $v1
  int v14; // $t0
  int v15; // $a3
  int v16; // $a2
  int v17; // $a1
  char v18[4100]; // [sp+20h] [-1004h] BYREF

  v3 = httpd_get_parm(a1, "opt");
  v2 = httpd_get_json_parm(a1, (int)"list");
  if ( !v2 || (v4 = v2, !cJSON_IsArray(v2)) )
  {
    v10 = (const char *)_GET_LANG_TEXT(12, *(unsigned __int8 *)(a1 + 210102), "error list");
    v11 = snprintf(v18, 4096, "{\"code\":%d,\"error\":\"%s\",\"data\":null}", 1, v10);
    if ( v11 >= 0x1000 )
      v11 = 4095;
    return httpd_cgi_ret(a1, v18, v11, 4);
  }
  if ( v3 && !strcmp(v3, "auto") )
    return switch_reboot_auto_asp(a1);
  if ( !ai_is_running(0) )
  {
    v12 = "{\"code\":0,\"error\":\"\",\"data\":null}";
    v13 = v18;
    do
    {
      v14 = *(_DWORD *)v12;
      v15 = *((_DWORD *)v12 + 1);
      v16 = *((_DWORD *)v12 + 2);
      v17 = *((_DWORD *)v12 + 3);
      v12 += 16;
      *(_DWORD *)v13 = v14;
      *((_DWORD *)v13 + 1) = v15;
      *((_DWORD *)v13 + 2) = v16;
      *((_DWORD *)v13 + 3) = v17;
      v13 += 16;
    }
    while ( v12 != "}" );
    v11 = 33;
    *(_WORD *)v13 = *(_WORD *)v12;
    return httpd_cgi_ret(a1, v18, v11, 4);
  }
  strcpy(v18, "{\"sn\":");
  cJSON_PrintPreallocated(v4, &v18[6], 4090, 0);
  v5 = strlen(v18);
  v6 = 4096 - v5;
  v8 = v5;
  v7 = snprintf(&v18[v5], 4096 - v5, "}");
  if ( v7 >= v6 )
    v7 = 4095 - v8;
  ai_unix_cgi_send(0x272Cu, *(_DWORD *)(a1 + 205416), v18, v7 + v8);
  *(_DWORD *)(a1 + 210096) = 10028;
  *(_DWORD *)(a1 + 205572) = 0;
  ai_cgi_common_timeout((_DWORD *)a1);
  return 0;
}
// 6A82B4: using guessed type int __fastcall cJSON_IsArray(_DWORD);
// 6A8318: using guessed type int __fastcall _GET_LANG_TEXT(_DWORD, _DWORD, _DWORD);
// 6A8740: using guessed type int __fastcall cJSON_PrintPreallocated(_DWORD, _DWORD, _DWORD, _DWORD);

