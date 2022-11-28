int __fastcall exec_service_timeout(int a1)
{
  int v2; // $s0
  char *v3; // $v0
  int v4; // $a0
  const char *v5; // $s2
  const char *v6; // $v0
  int v7; // $a2
  _BYTE *v8; // $v0
  const char *v9; // $a2
  const char *v10; // $v0
  unsigned int v11; // $v0
  const char *v13; // $v0
  const char *v14; // $v0
  char *v15; // $v1
  int v16; // $t0
  int v17; // $a3
  int v18; // $a2
  int v19; // $a1
  int v20; // $v0
  char *v21; // $v0
  char v22[516]; // [sp+20h] [-204h] BYREF

  v2 = a1 + 196608;
  v3 = httpd_get_parm(a1, "exec_service");
  v4 = *(_DWORD *)(v2 + 8968);
  v5 = v3;
  ++*(_DWORD *)(v2 + 8964);
  if ( v4 )
  {
    v13 = (const char *)nvram_get("action_service");
    if ( !v13 || !v5 || strcmp(v13, v5) )
    {
      v14 = "{\"code\":0,\"error\":\"\",\"data\":null}";
      v15 = v22;
      do
      {
        v16 = *(_DWORD *)v14;
        v17 = *((_DWORD *)v14 + 1);
        v18 = *((_DWORD *)v14 + 2);
        v19 = *((_DWORD *)v14 + 3);
        v14 += 16;
        *(_DWORD *)v15 = v16;
        *((_DWORD *)v15 + 1) = v17;
        *((_DWORD *)v15 + 2) = v18;
        *((_DWORD *)v15 + 3) = v19;
        v15 += 16;
      }
      while ( v14 != "}" );
      *(_WORD *)v15 = *(_WORD *)v14;
      return httpd_cgi_ret(a1, v22, 33, 4);
    }
    if ( *(int *)(v2 + 8964) >= 21 )
      goto LABEL_8;
    v20 = jiffies_get() + 1000;
    goto LABEL_27;
  }
  v6 = (const char *)nvram_get("action_service");
  if ( !v6 || !v5 || strcmp(v6, v5) )
  {
    v8 = (_BYTE *)nvram_get("action_service");
    if ( !v8 || *v8 )
    {
      if ( *(int *)(a1 + 205572) < 11 )
      {
        *(_DWORD *)(a1 + 205548) = jiffies_get() + 1000;
        *(_DWORD *)(a1 + 205556) = a1;
        *(_DWORD *)(a1 + 205552) = exec_service_timeout;
        return add_timer(a1 + 205540);
      }
LABEL_8:
      if ( *(_DWORD *)(a1 + 205576) )
        v9 = "after";
      else
        v9 = "before";
      v10 = (const char *)_GET_LANG_TEXT(37, *(unsigned __int8 *)(a1 + 210102), v9);
      goto LABEL_11;
    }
    v21 = httpd_get_parm(a1, "action_iface");
    if ( v21 )
      nvram_set("action_iface", v21);
    nvram_set("action_service", v5);
    kill(1, 16);
    v2 = a1 + 196608;
    *(_DWORD *)(a1 + 205576) = 1;
    *(_DWORD *)(a1 + 205572) = 0;
    v20 = jiffies_get() + 1000;
LABEL_27:
    *(_DWORD *)(v2 + 8940) = v20;
    *(_DWORD *)(v2 + 8948) = a1;
    *(_DWORD *)(v2 + 8944) = exec_service_timeout;
    return add_timer(a1 + 205540);
  }
  v10 = (const char *)_GET_LANG_TEXT(36, *(unsigned __int8 *)(v2 + 13494), v7);
LABEL_11:
  v11 = snprintf(v22, 512, "{\"code\":%d,\"error\":\"%s\",\"data\":null}", 1, v10);
  if ( v11 >= 0x200 )
    v11 = 511;
  return httpd_cgi_ret(a1, v22, v11, 4);
}
// 42A810: variable 'v7' is possibly undefined
// 6A81BC: using guessed type int __fastcall nvram_get(_DWORD);
// 6A8318: using guessed type int __fastcall _GET_LANG_TEXT(_DWORD, _DWORD, _DWORD);
// 6A838C: using guessed type int __fastcall add_timer(_DWORD);
// 6A8824: using guessed type int jiffies_get(void);
// 6A8918: using guessed type int __fastcall nvram_set(_DWORD, _DWORD);

