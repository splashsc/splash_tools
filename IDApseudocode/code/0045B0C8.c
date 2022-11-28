int __fastcall sub_45B0C8(int a1)
{
  char *v2; // $s1
  char *v3; // $s3
  char *v4; // $s4
  char *v5; // $s5
  char *v6; // $s6
  char *v7; // $s2
  char *v8; // $s7
  int v9; // $s3
  char *v10; // $v0
  const char *v11; // $v0
  int v12; // $s2
  char *v13; // $s4
  const char *v14; // $v0
  int v15; // $a0
  int v16; // $a2
  int v18; // $a2
  int v19; // $a1
  const char *v20; // $v0
  const char *v21; // $v1
  unsigned int v22; // $v0
  char *v23; // $v1
  const char *v24; // $v0
  int v25; // $t0
  int v26; // $a3
  int v27; // $a2
  int v28; // $a1
  const char *v29; // $v0
  char v30[1024]; // [sp+20h] [-540h] BYREF
  char v31[256]; // [sp+420h] [-140h] BYREF
  int v32[10]; // [sp+520h] [-40h] BYREF
  char *s; // [sp+548h] [-18h]
  char *v34; // [sp+54Ch] [-14h]
  char *v35; // [sp+550h] [-10h]
  char *v36; // [sp+554h] [-Ch]
  char *v37; // [sp+558h] [-8h]

  v36 = v30;
  memset(v30, 0, sizeof(v30));
  s = v31;
  memset(v31, 0, sizeof(v31));
  v34 = httpd_get_parm(a1, "proxy_http_status");
  v2 = httpd_get_parm(a1, "enable");
  v3 = httpd_get_parm(a1, "name");
  v4 = httpd_get_parm(a1, "email");
  v5 = httpd_get_parm(a1, "time");
  v6 = httpd_get_parm(a1, "mode");
  v7 = httpd_get_parm(a1, "hour");
  v8 = httpd_get_parm(a1, "phone");
  if ( v2 )
  {
    if ( strcmp(v2, "1") )
    {
LABEL_6:
      v35 = "a";
      if ( !nvram_match_def("proxy_email_en", v2) )
      {
        nvram_set(v35 + 24396, v2);
        v35 = (char *)1;
        goto LABEL_8;
      }
LABEL_7:
      v35 = 0;
LABEL_8:
      if ( v3 && (v37 = "a", !nvram_match_def("proxy_email_name", v3)) )
      {
        nvram_set(v37 + 24412, v3);
        v9 = 1;
      }
      else
      {
        v9 = 0;
      }
      if ( v4 )
      {
        v37 = "a";
        if ( !nvram_match_def("proxy_email_url", v4) )
        {
          nvram_set(v37 + 24432, v4);
          ++v9;
        }
      }
      if ( v6 && !nvram_match_def("proxy_email_mode", v6) )
      {
        nvram_set("proxy_email_mode", v6);
        ++v9;
      }
      if ( v5 && !nvram_match_def("proxy_email_time", v5) )
      {
        nvram_set("proxy_email_time", v5);
        ++v9;
      }
      if ( v7 )
      {
        if ( !J_atoi(v7) )
          v7 = "4";
        if ( !nvram_match_def(&unk_645FA8, v7) )
        {
          nvram_set(&unk_645FA8, v7);
          ++v9;
        }
      }
      if ( v8 && !nvram_match_def(&unk_645FBC, v8) )
      {
        nvram_set(&unk_645FBC, v8);
        ++v9;
      }
      if ( v2 )
      {
        if ( nvram_match_def("proxy_email_en", "1") )
        {
          v10 = (char *)nvram_get("proxy_http_port");
          if ( !v10 )
            v10 = "0";
          if ( J_atoi(v10) )
          {
            v29 = (const char *)nvram_get("proxy_http_pid");
            if ( !v29 )
              v29 = "-1";
            if ( J_atoi(v29) )
            {
              stop_proxy_auto_send_email();
              start_proxy_auto_send_email();
              system("proxy_send_email &");
              system("proxy_usb_send_email &");
LABEL_46:
              if ( v9 || v35 )
                jhl_parm_commit(v15);
              v16 = 0;
              if ( !v31[0] )
              {
                v23 = s;
                v24 = "{\"code\":0,\"error\":\"\",\"data\":null}";
                do
                {
                  v25 = *(_DWORD *)v24;
                  v26 = *((_DWORD *)v24 + 1);
                  v27 = *((_DWORD *)v24 + 2);
                  v28 = *((_DWORD *)v24 + 3);
                  v24 += 16;
                  *(_DWORD *)v23 = v25;
                  *((_DWORD *)v23 + 1) = v26;
                  *((_DWORD *)v23 + 2) = v27;
                  *((_DWORD *)v23 + 3) = v28;
                  v23 += 16;
                }
                while ( v24 != "}" );
                v16 = 33;
                *(_WORD *)v23 = *(_WORD *)v24;
              }
              return httpd_cgi_ret(a1, s, v16, 4);
            }
          }
        }
        if ( !nvram_match_def("proxy_email_en", "1") )
        {
          stop_proxy_auto_send_email();
          goto LABEL_46;
        }
      }
      if ( v34 )
        nvram_set("proxy_http_status", v34);
      v11 = (const char *)nvram_get("proxy_http_pid");
      if ( !v11 )
        v11 = "-1";
      v12 = J_atoi(v11);
      if ( v12 > 0 )
      {
        v13 = v36;
        memset(v36, 0, 0x400u);
        snprintf(v13, 1024, "kill -9 %d", v12);
        system(v13);
        if ( !nvram_get("proxy_http_msg") )
          get_web_language_type(a1);
        nvram_set("proxy_http_pid", "-1");
        nvram_set("proxy_http_port", "0");
      }
      exec_service("proxy_client_email-stop");
      v14 = (const char *)nvram_get("proxy_http_status");
      if ( v14 && !strcmp(v14, "1") )
      {
        if ( nvram_match_def("proxy_email_en", "1") )
        {
          exec_service("proxy_client_email-start");
        }
        else
        {
          v32[0] = (int)"proxy_client";
          v32[1] = jhl_nv_get_only_def("proxy_http_srv");
          v32[2] = jhl_nv_get_only_def("proxy_http_srvport");
          v32[3] = jhl_nv_get_def("lan_ipaddr");
          v32[4] = jhl_nv_get_def("http_lanport");
          v32[5] = (int)"proxy_http_port";
          v32[6] = (int)"proxy_http_msg";
          v32[7] = (int)"proxy_http_pid";
          v32[8] = 0;
          eval_nowait(v32, 0, 0, 0);
        }
      }
      else if ( !nvram_get("proxy_http_msg") )
      {
        get_web_language_type(a1);
      }
      goto LABEL_46;
    }
  }
  else
  {
    if ( !v34 )
      goto LABEL_7;
    if ( strcmp(v34, "1") )
    {
      v35 = 0;
      goto LABEL_8;
    }
  }
  if ( gl_httpd_high_admin_en )
  {
    v35 = "http_hadminpwd";
    if ( !jhl_nv_is_def("http_hadmin") )
      goto LABEL_5;
  }
  else
  {
    v35 = "http_passwd";
    if ( !jhl_nv_is_def("http_username") )
      goto LABEL_5;
  }
  if ( !jhl_nv_is_def(v35) )
  {
LABEL_5:
    if ( !v2 )
      goto LABEL_7;
    goto LABEL_6;
  }
  v19 = *(unsigned __int8 *)(a1 + 210102);
  if ( *(_DWORD *)(a1 + 205588) == 5 )
  {
    v20 = (const char *)_GET_LANG_TEXT(144, v19, v18);
    v21 = "huserSet";
  }
  else
  {
    v20 = (const char *)_GET_LANG_TEXT(144, v19, v18);
    v21 = "loginManage";
  }
  v22 = snprintf(s, 256, "{\"code\":%d,\"error\":\"%s\",\"url\":\"%s\",\"data\":null}", 6, v20, v21);
  if ( v22 >= 0x100 )
    v22 = 255;
  return httpd_cgi_ret(a1, s, v22, 4);
}
// 45B624: variable 'v15' is possibly undefined
// 45B6E4: variable 'v18' is possibly undefined
// 67D094: using guessed type int gl_httpd_high_admin_en;
// 6A8180: using guessed type int __fastcall jhl_parm_commit(_DWORD);
// 6A81BC: using guessed type int __fastcall nvram_get(_DWORD);
// 6A8318: using guessed type int __fastcall _GET_LANG_TEXT(_DWORD, _DWORD, _DWORD);
// 6A83E4: using guessed type int __fastcall nvram_match_def(_DWORD, _DWORD);
// 6A84C8: using guessed type int __fastcall jhl_nv_get_def(_DWORD);
// 6A852C: using guessed type int __fastcall eval_nowait(_DWORD, _DWORD, _DWORD, _DWORD);
// 6A85A0: using guessed type int __fastcall jhl_nv_is_def(_DWORD);
// 6A86B4: using guessed type int stop_proxy_auto_send_email(void);
// 6A86F4: using guessed type int __fastcall jhl_nv_get_only_def(_DWORD);
// 6A87EC: using guessed type int start_proxy_auto_send_email(void);
// 6A8918: using guessed type int __fastcall nvram_set(_DWORD, _DWORD);
// 6A89B4: using guessed type int __fastcall J_atoi(_DWORD);

