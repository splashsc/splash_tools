int __fastcall sub_44F9AC(int a1)
{
  char *v1; // $v0
  const char *v3; // $s1
  int v4; // $s0
  int v5; // $v0
  int v6; // $s3
  int v7; // $v0
  int v8; // $a2
  int v9; // $a1
  int v10; // $a0
  const char *v11; // $v0
  unsigned int v12; // $s0
  int v14; // $a1
  int v15; // $a2
  int v16; // $a0
  const char *v17; // $v0
  const char *v18; // $v0
  unsigned int v19; // $v0
  int v20; // $a2
  const char *v21; // $v0
  int v22; // $v0
  int v23; // $s0
  int v24; // $v0
  int v25; // $s4
  int v26; // $v0
  time_t v27; // $v0
  int v28; // $v0
  int v29; // $a0
  int v30; // $a2
  const char *v31; // $s6
  const char *v32; // $v0
  char v33[1024]; // [sp+20h] [-508h] BYREF
  int v34[64]; // [sp+420h] [-108h] BYREF
  int v35; // [sp+520h] [-8h]

  v1 = httpd_get_parm(a1, "opt");
  if ( !v1 )
    goto LABEL_14;
  v3 = v1;
  v4 = strcmp(v1, "check");
  if ( v4 )
  {
    if ( !strcmp(v3, "upgrade") )
    {
      memset(v33, 0, sizeof(v33));
      if ( ai_read_upgrade_state((int)v33, 1024) < 0 )
      {
        v14 = *(unsigned __int8 *)(a1 + 210102);
        v15 = 1;
        v16 = 145;
      }
      else
      {
        v5 = cJSON_Parse(v33);
        v6 = v5;
        if ( v5 )
        {
          v7 = cJSON_GetObjectItem(v5, "state");
          if ( !v7 || !*(_DWORD *)(v7 + 20) )
          {
            v9 = *(unsigned __int8 *)(a1 + 210102);
            v10 = 146;
LABEL_9:
            v11 = (const char *)_GET_LANG_TEXT(v10, v9, v8);
            goto LABEL_10;
          }
          v22 = cJSON_GetObjectItem(v6, "url");
          v23 = v22;
          if ( v22 && *(_DWORD *)(v22 + 16) )
          {
            v24 = cJSON_GetObjectItem(v6, "md5");
            v25 = v24;
            if ( v24 && *(_DWORD *)(v24 + 16) )
            {
              v26 = nvram_get_int("fw_upgrade_state");
              if ( (unsigned int)(v26 - 3) < 2 )
              {
                v9 = *(unsigned __int8 *)(a1 + 210102);
                v10 = 21;
                goto LABEL_9;
              }
              if ( v26 == 2 )
              {
                v31 = *(const char **)(v23 + 16);
                v32 = (const char *)nvram_get("fw_upgrade_last");
                if ( v32 )
                {
                  if ( v31 && !strcmp(v32, v31) )
                  {
                    v9 = *(unsigned __int8 *)(a1 + 210102);
                    v10 = 147;
                    goto LABEL_9;
                  }
                }
              }
              system("killall fw_upgrade");
              nvram_set("fw_upgrade_state", "0");
              nvram_set("fw_upgrade_last", "");
              v34[0] = (int)"fw_upgrade";
              v34[1] = *(_DWORD *)(v23 + 16);
              v34[2] = *(_DWORD *)(v25 + 16);
              v34[3] = 0;
              eval_nowait(v34, 0, 0, 0);
              unregister_signal();
              exec_service("jhttpd_check-stop");
              prepare_upgrade();
              v27 = time(0);
              v28 = ai_wait_upgrade(v27 + 300);
              if ( !v28 )
              {
                jhl_gl_reboot_timer(3000);
                nvram_set("fw_upgrade_last", *(_DWORD *)(v23 + 16));
                v21 = (const char *)_GET_LANG_TEXT(22, *(unsigned __int8 *)(a1 + 210102), v20);
                v12 = snprintf((char *)v34, 256, "{\"code\":0,\"error\":\"\",\"message\":\"%s\",\"data\":null}", v21);
                if ( v12 < 0x100 )
                  goto LABEL_11;
                goto LABEL_23;
              }
              v35 = v28;
              register_signal();
              exec_service("jhttpd_check-start");
              upgrade_after(v29);
              v11 = (const char *)_GET_LANG_TEXT(v35, *(unsigned __int8 *)(a1 + 210102), v30);
            }
            else
            {
              v11 = (const char *)_GET_LANG_TEXT(12, *(unsigned __int8 *)(a1 + 210102), "not md5");
            }
          }
          else
          {
            v11 = (const char *)_GET_LANG_TEXT(12, *(unsigned __int8 *)(a1 + 210102), "not url");
          }
LABEL_10:
          v12 = snprintf((char *)v34, 256, "{\"code\":%d,\"error\":\"%s\",\"data\":null}", 1, v11);
          if ( v12 < 0x100 )
          {
LABEL_11:
            cJSON_Delete(v6);
            return httpd_cgi_ret(a1, (char *)v34, v12, 4);
          }
LABEL_23:
          v12 = 255;
          goto LABEL_11;
        }
        v14 = *(unsigned __int8 *)(a1 + 210102);
        v15 = 2;
        v16 = 145;
      }
LABEL_15:
      v17 = (const char *)_GET_LANG_TEXT(v16, v14, v15);
      v12 = snprintf((char *)v34, 256, "{\"code\":%d,\"error\":\"%s\",\"data\":null}", 1, v17);
      if ( v12 >= 0x100 )
        v12 = 255;
      return httpd_cgi_ret(a1, (char *)v34, v12, 4);
    }
LABEL_14:
    v14 = *(unsigned __int8 *)(a1 + 210102);
    v15 = (int)"not opt";
    v16 = 12;
    goto LABEL_15;
  }
  if ( !ai_is_running(1) )
    return ai_check_upgrade_data(a1);
  v18 = (const char *)custom_device_name();
  v19 = snprintf((char *)v34, 256, "[{\"model\":\"%s\",\"model_x\":\"%s\",\"sversion\":\"%s\"}]", v18, "FBM-1008V", "");
  if ( v19 >= 0x100 )
    v19 = 255;
  ai_unix_cgi_send(0x2727u, *(_DWORD *)(a1 + 205416), v34, v19);
  *(_DWORD *)(a1 + 205572) = 0;
  *(_DWORD *)(a1 + 210096) = 10023;
  ai_cgi_common_timeout((_DWORD *)a1);
  return v4;
}
// 44FAE0: variable 'v8' is possibly undefined
// 44FCFC: variable 'v20' is possibly undefined
// 44FF58: variable 'v29' is possibly undefined
// 44FF7C: variable 'v30' is possibly undefined
// 6A81B4: using guessed type int __fastcall nvram_get_int(_DWORD);
// 6A81BC: using guessed type int __fastcall nvram_get(_DWORD);
// 6A81C0: using guessed type int prepare_upgrade(void);
// 6A8318: using guessed type int __fastcall _GET_LANG_TEXT(_DWORD, _DWORD, _DWORD);
// 6A837C: using guessed type int __fastcall upgrade_after(_DWORD);
// 6A852C: using guessed type int __fastcall eval_nowait(_DWORD, _DWORD, _DWORD, _DWORD);
// 6A86E4: using guessed type int custom_device_name(void);
// 6A8780: using guessed type int __fastcall cJSON_Parse(_DWORD);
// 6A8844: using guessed type int __fastcall cJSON_Delete(_DWORD);
// 6A8910: using guessed type int __fastcall cJSON_GetObjectItem(_DWORD, _DWORD);
// 6A8918: using guessed type int __fastcall nvram_set(_DWORD, _DWORD);

