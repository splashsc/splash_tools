int __fastcall sub_44D870(int a1)
{
  char *v2; // $v0
  int v3; // $s1
  char *v4; // $s4
  int v5; // $fp
  int v6; // $s3
  int v7; // $v0
  char *v8; // $s6
  unsigned int v9; // $v0
  int v10; // $s0
  int v11; // $a0
  int v12; // $a1
  int v13; // $v0
  int v14; // $a2
  int v16; // $v0
  const char *v17; // $v0
  int v18; // $a2
  int v19; // $v0
  int v20; // $s3
  int v21; // $v0
  int v22; // $a2
  int v23; // $v0
  int v24; // $s0
  int v25[256]; // [sp+58h] [-410h] BYREF
  char *format; // [sp+458h] [-10h]
  char *v27; // [sp+45Ch] [-Ch]
  char *v28; // [sp+460h] [-8h]
  int v29; // [sp+464h] [-4h]

  v3 = sq_file_get_max_wan();
  _mem_malloc(102400, "ai_rate_flow", 1328);
  v4 = v2;
  if ( !v2 )
    return httpd_cgi_ret(a1, (char *)v25, 24, 4);
  *v2 = 91;
  v2[1] = 0;
  if ( v3 > 0 )
  {
    v27 = "a";
    v28 = "{\"wan_num\":\"all\",";
    v5 = 0;
    v6 = 1;
    format = "\"totup\":%llu,\"totqup\":%llu,\"totupk\":%lu,\"totqupk\":%lu,\"totdw\":%llu,\"totqdw\":%llu,\"totdwk\":%lu"
             ",\"totqdwk\":%lu,\"zup\":%lu,\"zdw\":%lu,\"qzup\":%lu,\"qzdw\":%lu},";
    while ( 1 )
    {
      if ( v5 <= 0 )
      {
        memset(v25, 0, sizeof(v25));
        v25[0] = 14;
        v25[3] = 4;
        LOWORD(v25[8]) = v5;
        v25[1] = 1024;
        if ( jianhl_order_opt_fun(v25, 1024, v22) )
        {
LABEL_30:
          v14 = 23;
          strcpy(v4, "{\"err\":\"get_opt false\"}");
          qmemcpy(v4, "{\"err\":\"get_opt ", 16);
          *((_DWORD *)v4 + 5) = 8200805;
          return httpd_cgi_ret(a1, v4, v14, 8);
        }
        v23 = snprintf(&v4[v6], 102400 - v6, v28);
        if ( v23 < 102400 - v6 )
          v24 = v23;
        else
          v24 = 102399 - v6;
        v20 = v24 + v6;
      }
      else
      {
        v7 = jhl_nvget("wan_ifname", v5 - 1);
        v8 = (char *)nvram_get(v7);
        if ( !v8 )
          v8 = "";
        v9 = jhl_get_wan_proto(v5 - 1) - 10;
        if ( !*v8 )
          goto LABEL_9;
        if ( v9 < 3 )
          goto LABEL_9;
        v16 = jhl_nvget("wan_down", v5 - 1);
        v17 = (const char *)nvram_get(v16);
        if ( v17 )
        {
          if ( !strcmp(v17, "1") )
            goto LABEL_9;
        }
        if ( jhl_iface_link_up_check(v8, v5 - 1) )
          goto LABEL_9;
        memset(v25, 0, sizeof(v25));
        v25[0] = 14;
        v25[3] = 4;
        LOWORD(v25[8]) = v5;
        v25[1] = 1024;
        if ( jianhl_order_opt_fun(v25, 1024, v18) )
          goto LABEL_30;
        v29 = 102400 - v6;
        v19 = snprintf(&v4[v6], 102400 - v6, v27 + 19392, v5 - 1);
        if ( v19 >= v29 )
          v19 = 102399 - v6;
        v20 = v19 + v6;
      }
      v21 = snprintf(&v4[v20], 102400 - v20, format);
      if ( v21 >= 102400 - v20 )
        v21 = 102399 - v20;
      v6 = v20 + v21;
LABEL_9:
      if ( v3 == ++v5 )
      {
        if ( v6 >= 4 )
          --v6;
        v10 = 102400 - v6;
        v11 = v6;
        v12 = 102400 - v6;
        goto LABEL_13;
      }
    }
  }
  v12 = 102399;
  v10 = 102399;
  v11 = 1;
  v6 = 1;
LABEL_13:
  v13 = snprintf(&v4[v11], v12, &byte_6445A0);
  if ( v13 >= v10 )
    v13 = 102399 - v6;
  v14 = v6 + v13;
  return httpd_cgi_ret(a1, v4, v14, 8);
}
// 44D8E4: variable 'v2' is possibly undefined
// 44DAE0: variable 'v18' is possibly undefined
// 44DCD8: variable 'v22' is possibly undefined
// 6445A0: using guessed type char byte_6445A0;
// 6A81BC: using guessed type int __fastcall nvram_get(_DWORD);
// 6A82F4: using guessed type int __fastcall jhl_iface_link_up_check(_DWORD, _DWORD);
// 6A8460: using guessed type int __fastcall jhl_get_wan_proto(_DWORD);
// 6A85E0: using guessed type int sq_file_get_max_wan(void);
// 6A8900: using guessed type int __fastcall jianhl_order_opt_fun(_DWORD, _DWORD, _DWORD);
// 6A890C: using guessed type int __fastcall jhl_nvget(_DWORD, _DWORD);

