int __fastcall sub_44F178(int a1)
{
  char *v2; // $fp
  char *v3; // $s2
  char *v4; // $s4
  char *v5; // $s3
  char *v6; // $s5
  char *v7; // $v0
  char *v8; // $s7
  const char *v9; // $a3
  unsigned int v10; // $v0
  char *v11; // $v1
  const char *v12; // $v0
  int v13; // $t0
  int v14; // $a3
  int v15; // $a2
  int v16; // $a1
  unsigned int v17; // $a2
  const char *v19; // $s6
  const char *v20; // $v0
  const char *v21; // $v0
  int v22; // $fp
  const char *v23; // $v0
  int v24; // $a0
  int v25; // $s2
  const char *v26; // $v0
  const char *v27; // $v0
  const char *v28; // $v0
  const char *v29; // $v0
  int v30; // $t0
  int v31; // $a3
  int v32; // $a2
  int v33; // $a1
  const char *v34; // $v0
  char v35[1024]; // [sp+20h] [-408h] BYREF
  char *v36; // [sp+420h] [-8h]

  memset(v35, 0, sizeof(v35));
  v2 = httpd_get_parm(a1, "en");
  v3 = httpd_get_parm(a1, "srv_addr");
  v4 = httpd_get_parm(a1, "srv_port");
  v5 = httpd_get_parm(a1, "iface");
  v6 = httpd_get_parm(a1, "alone");
  v36 = httpd_get_parm(a1, "mode");
  v8 = httpd_get_parm(a1, "ping_addr1");
  v7 = httpd_get_parm(a1, "ping_addr2");
  if ( v6 )
  {
    if ( J_atoi(v6) )
      v9 = "true";
    else
      v9 = "false";
    v10 = snprintf(v35, 1024, "{\"alone\":%s}", v9);
    if ( v10 >= 0x400 )
      v10 = 1023;
    ai_unix_cgi_send(0x272Au, 0xFFFFFFFF, v35, v10);
    v11 = v35;
    v12 = "{\"code\":0,\"error\":\"\",\"data\":null}";
    do
    {
      v13 = *(_DWORD *)v12;
      v14 = *((_DWORD *)v12 + 1);
      v15 = *((_DWORD *)v12 + 2);
      v16 = *((_DWORD *)v12 + 3);
      v12 += 16;
      *(_DWORD *)v11 = v13;
      *((_DWORD *)v11 + 1) = v14;
      *((_DWORD *)v11 + 2) = v15;
      *((_DWORD *)v11 + 3) = v16;
      v11 += 16;
    }
    while ( v12 != "}" );
    goto LABEL_8;
  }
  if ( v2 )
  {
    v19 = v7;
    if ( v3 )
    {
      v20 = (const char *)nvram_get("mqtt_ai_enable");
      if ( v20 && !strcmp(v20, v2) )
      {
        v21 = (const char *)nvram_get("wys_mqtt_ai_v3_addr");
        v22 = 0;
        if ( !v21 )
          goto LABEL_17;
      }
      else
      {
        nvram_set("mqtt_ai_enable", v2);
        v21 = (const char *)nvram_get("wys_mqtt_ai_v3_addr");
        v22 = 1;
        if ( !v21 )
          goto LABEL_17;
      }
      if ( !strcmp(v21, v3) )
      {
LABEL_18:
        v23 = (const char *)nvram_get("wys_mqtt_ai_v3_port");
        if ( !v23 || !v4 || strcmp(v23, v4) )
        {
          nvram_set("wys_mqtt_ai_v3_port", v4);
          v22 = 1;
        }
        v25 = v22;
        if ( v8 )
        {
          v26 = (const char *)nvram_get("mqtt_ai_ping_addr1");
          if ( v26 && !strcmp(v26, v8) )
          {
            v25 = v22;
          }
          else
          {
            nvram_set("mqtt_ai_ping_addr1", v8);
            v25 = 1;
          }
        }
        if ( v19 )
        {
          v27 = (const char *)nvram_get("mqtt_ai_ping_addr2");
          if ( !v27 || strcmp(v27, v19) )
          {
            nvram_set("mqtt_ai_ping_addr2", v19);
            v25 = 1;
          }
        }
        if ( !v36 || (v28 = (const char *)nvram_get("mqtt_sdwan_mode")) != 0 && !strcmp(v28, v36) )
        {
          if ( !v5 )
            goto LABEL_41;
        }
        else
        {
          nvram_set("mqtt_sdwan_mode", v36);
          v22 = 1;
          if ( !v5 )
          {
LABEL_46:
            v25 = 1;
LABEL_47:
            stop_mqtt_ai();
            start_mqtt_ai();
LABEL_42:
            if ( !v25 )
            {
LABEL_43:
              v11 = v35;
              v12 = "{\"code\":0,\"error\":\"\",\"data\":null}";
              do
              {
                v30 = *(_DWORD *)v12;
                v31 = *((_DWORD *)v12 + 1);
                v32 = *((_DWORD *)v12 + 2);
                v33 = *((_DWORD *)v12 + 3);
                v12 += 16;
                *(_DWORD *)v11 = v30;
                *((_DWORD *)v11 + 1) = v31;
                *((_DWORD *)v11 + 2) = v32;
                *((_DWORD *)v11 + 3) = v33;
                v11 += 16;
              }
              while ( v12 != "}" );
LABEL_8:
              v17 = 33;
              *(_WORD *)v11 = *(_WORD *)v12;
              return httpd_cgi_ret(a1, v35, v17, 4);
            }
LABEL_39:
            jhl_parm_commit(v24);
            goto LABEL_43;
          }
          v25 = 1;
        }
        v29 = (const char *)nvram_get("mqtt_ai_sdwan_iface");
        if ( !v29 || strcmp(v29, v5) )
        {
          if ( J_atoi(v5) != 0xFFFF )
          {
            nvram_set("mqtt_ai_sdwan_iface", v5);
            if ( !v22 )
              goto LABEL_39;
            goto LABEL_46;
          }
          if ( nvram_get("mqtt_ai_sdwan_iface") )
          {
            nvram_unset("mqtt_ai_sdwan_iface");
            if ( !v22 )
              goto LABEL_39;
            v25 = 1;
            goto LABEL_47;
          }
        }
LABEL_41:
        if ( !v22 )
          goto LABEL_42;
        goto LABEL_47;
      }
LABEL_17:
      nvram_set("wys_mqtt_ai_v3_addr", v3);
      v22 = 1;
      goto LABEL_18;
    }
  }
  v34 = (const char *)_GET_LANG_TEXT(12, *(unsigned __int8 *)(a1 + 210102), "not en or addr");
  v17 = snprintf(v35, 1024, "{\"code\":%d,\"error\":\"%s\",\"data\":null}", 1, v34);
  if ( v17 >= 0x400 )
    v17 = 1023;
  return httpd_cgi_ret(a1, v35, v17, 4);
}
// 44F684: variable 'v24' is possibly undefined
// 6A8180: using guessed type int __fastcall jhl_parm_commit(_DWORD);
// 6A81BC: using guessed type int __fastcall nvram_get(_DWORD);
// 6A8318: using guessed type int __fastcall _GET_LANG_TEXT(_DWORD, _DWORD, _DWORD);
// 6A8540: using guessed type int __fastcall nvram_unset(_DWORD);
// 6A8868: using guessed type int start_mqtt_ai(void);
// 6A8918: using guessed type int __fastcall nvram_set(_DWORD, _DWORD);
// 6A8964: using guessed type int stop_mqtt_ai(void);
// 6A89B4: using guessed type int __fastcall J_atoi(_DWORD);

