int __fastcall webauth_data_send(int a1, int a2)
{
  int v4; // $a2
  char *v5; // $s3
  const char *v6; // $v0
  int v7; // $v0
  int v8; // $v0
  int v10; // $s4
  const char *v11; // $s0
  const char *v12; // $v0
  char v13[2048]; // [sp+20h] [-C00h] BYREF
  char v14[1024]; // [sp+820h] [-400h] BYREF

  v5 = httpd_get_parm(a1, "callback");
  if ( a2 != 1 )
  {
    if ( a2 < 2 )
    {
      if ( !a2 )
      {
        v6 = (const char *)_GET_LANG_TEXT(1778, *(unsigned __int8 *)(a1 + 210102), v4);
        goto LABEL_6;
      }
    }
    else
    {
      if ( a2 == 2 )
      {
        v6 = (const char *)_GET_LANG_TEXT(179, *(unsigned __int8 *)(a1 + 210102), v4);
        goto LABEL_6;
      }
      if ( a2 == 4 )
      {
        v6 = (const char *)_GET_LANG_TEXT(175, *(unsigned __int8 *)(a1 + 210102), v4);
LABEL_6:
        v7 = sprintf(v14, "{\"ret\":1,\"msg\":\"%s\"}", v6);
        goto LABEL_7;
      }
    }
    v6 = (const char *)_GET_LANG_TEXT(171, *(unsigned __int8 *)(a1 + 210102), a2);
    goto LABEL_6;
  }
  v10 = *(_DWORD *)(a1 + 205464);
  v11 = (const char *)nvram_get("rzgl_redirct_en");
  if ( !v11 )
    v11 = "0";
  v12 = (const char *)nvram_get("rzgl_redirct_url");
  if ( !v12 )
    v12 = "";
  v7 = sprintf(v14, "{\"ret\":0,\"i\":%u,\"e\":\"%s\",\"l\":\"%s\",\"isto_en\":\"%d\"}", v10, v11, v12, 0);
LABEL_7:
  if ( !v5 )
    return httpd_cgi_ret(a1, v14, v7, 4);
  memset(v13, 0, sizeof(v13));
  v8 = sprintf(v13, "try{%s(%s);}catch(e){}", v5, v14);
  return httpd_cgi_ret(a1, v13, v8, 4);
}
// 4809D4: variable 'v4' is possibly undefined
// 6A81BC: using guessed type int __fastcall nvram_get(_DWORD);
// 6A8318: using guessed type int __fastcall _GET_LANG_TEXT(_DWORD, _DWORD, _DWORD);

