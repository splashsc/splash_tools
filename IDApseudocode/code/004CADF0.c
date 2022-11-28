int __fastcall sub_4CADF0(int a1)
{
  char *v2; // $s4
  char *v3; // $s5
  char *v4; // $s6
  char *v5; // $s2
  char *v6; // $s3
  int v7; // $v0
  int v8; // $s1
  unsigned int v9; // $s6
  int v10; // $s5
  const char *v11; // $v0
  int v12; // $s7
  const char *v13; // $v0
  int v14; // $v0
  int v15; // $v0
  int result; // $v0
  unsigned int v17; // $v0
  unsigned int v18; // $s7
  char *v19; // $v0
  int v20; // $a2
  char *v21; // $s7
  int v22; // $v0
  int v23; // $s7
  _DWORD *v24; // $s7
  int v25; // $v0
  int v26; // $fp
  int v27; // $v0
  int v28; // $s5
  void *v29; // $s4
  int v30; // $a0
  const char *v31; // $v0
  unsigned int v32; // $a2
  char v33[1024]; // [sp+20h] [-860h] BYREF
  char v34[1024]; // [sp+420h] [-460h] BYREF
  int v35[16]; // [sp+820h] [-60h] BYREF
  char *format; // [sp+860h] [-20h]
  char *name; // [sp+864h] [-1Ch]
  int v38; // [sp+868h] [-18h]
  const char *v39; // [sp+86Ch] [-14h]
  char *v40; // [sp+870h] [-10h]
  const char *v41; // [sp+874h] [-Ch]
  char *v42; // [sp+878h] [-8h]
  int v43; // [sp+87Ch] [-4h]

  v2 = httpd_get_parm(a1, "province");
  v3 = httpd_get_parm(a1, "city");
  v4 = httpd_get_parm(a1, "operator");
  v5 = httpd_get_parm(a1, "en");
  v6 = httpd_get_parm(a1, "host");
  if ( sq_file_get_device_id() )
  {
    _mem_malloc(102400, "iptv_channel_asp", 399);
    v8 = v7;
    if ( v7 )
    {
      if ( !v5 )
      {
        v9 = 0;
        if ( !v6 )
          return httpd_cgi_ret(a1, v33, v9, 4);
        v12 = 0;
        v10 = 0;
        goto LABEL_10;
      }
      if ( *v5 != 49 )
      {
        v9 = 0;
        v10 = 0;
        goto LABEL_6;
      }
      if ( !v2 || !v3 || !v4 )
        goto LABEL_44;
      name = (char *)v35;
      memset(v35, 0, sizeof(v35));
      v18 = snprintf(v34, 1024, "opt=sync&province=%s&city=%s&operator=%s", v2, v3, v4);
      v19 = name;
      v35[0] = *(_DWORD *)"/tmp/iptv_cgiXXXXXX";
      *((_DWORD *)name + 1) = *(_DWORD *)"/iptv_cgiXXXXXX";
      strcpy(v19 + 8, "v_cgiXXXXXX");
      wys_mkstemp(v19);
      v20 = v18;
      if ( v18 >= 0x400 )
        v20 = 1023;
      v21 = name;
      if ( https_post("https://itv.wayos.com/channel/getChannelList.cgi", v34, v20, name, 0, 0) > 0 )
      {
        do_file(v21, v8, 102400);
        v22 = cJSON_Parse(v8);
        v43 = v22;
        if ( v22 )
        {
          v23 = cJSON_GetObjectItem(v22, "data");
          if ( v23 )
          {
            v38 = cJSON_CreateArray();
            memset(v33, 0, sizeof(v33));
            v24 = *(_DWORD **)(v23 + 8);
            if ( v24 )
            {
              v39 = "name";
              format = "%s";
              v40 = "n";
              v41 = "sourceLink";
              v42 = "u";
              do
              {
                v26 = cJSON_CreateObject();
                v25 = GetJSONItemValueAsString(v24, v39);
                snprintf(v33, 1024, format, v25);
                cJSON_AddStringToObject(v26, v40, v33);
                v27 = GetJSONItemValueAsString(v24, v41);
                snprintf(v33, 1024, format, v27);
                cJSON_AddStringToObject(v26, v42, v33);
                cJSON_AddItemToArray(v38, v26);
                v24 = (_DWORD *)*v24;
              }
              while ( v24 );
            }
            nvram_set("iptv_province", v2);
            nvram_set("iptv_city", v3);
            nvram_set("iptv_operator", v4);
            cJSON_Delete(v43);
            unlink(name);
            if ( v38 )
            {
              v9 = snprintf(v33, 1024, "{\"code\":0,\"error\":\"\",\"message\":\"%s\",\"data\":null}", "ok");
              if ( v9 >= 0x400 )
                v9 = 1023;
              v28 = v38;
              v29 = (void *)cJSON_PrintUnformatted(v38);
              nvram_set("iptv_channel_list", v29);
              free(v29);
              v30 = v28;
              v10 = 1;
              cJSON_Delete(v30);
              start_igmp_snooping();
              goto LABEL_6;
            }
            goto LABEL_42;
          }
          cJSON_Delete(v43);
        }
      }
      unlink(name);
LABEL_42:
      v9 = 0;
      if ( *v5 != 49 )
      {
        v10 = 0;
        goto LABEL_6;
      }
LABEL_44:
      v9 = snprintf(v33, 1024, "{\"code\":%d,\"error\":\"%s\",\"data\":null}", 1, "failed");
      v10 = 0;
      if ( v9 >= 0x400 )
        v9 = 1023;
LABEL_6:
      v11 = (const char *)nvram_get("iptv_en");
      if ( v11 && !strcmp(v11, v5) )
      {
        v12 = 0;
        if ( !v6 )
        {
LABEL_15:
          if ( !v10 )
            return httpd_cgi_ret(a1, v33, v9, 4);
LABEL_22:
          nvram_commit();
          return httpd_cgi_ret(a1, v33, v9, 4);
        }
      }
      else
      {
        nvram_set("iptv_en", v5);
        v12 = 1;
        if ( !v6 )
          goto LABEL_13;
        v10 = 1;
      }
LABEL_10:
      v13 = (const char *)nvram_get("iptv_host");
      if ( v13 && !strcmp(v13, v6) )
      {
        if ( !v12 )
        {
          if ( !v10 )
            return httpd_cgi_ret(a1, v33, v9, 4);
          goto LABEL_22;
        }
        goto LABEL_14;
      }
      v14 = nvram_get("iptv_host");
      iptv_channel_wan_set(v14, 0);
      nvram_set("iptv_host", v6);
LABEL_13:
      v10 = 1;
LABEL_14:
      v15 = J_atoi(v5);
      iptv_channel_wan_set(v6, v15);
      goto LABEL_15;
    }
    v31 = (const char *)_GET_LANG_TEXT(4, *(unsigned __int8 *)(a1 + 210102), 102400);
    v32 = snprintf(v33, 1024, "{\"code\":%d,\"error\":\"%s\",\"data\":null}", 1, v31);
    if ( v32 >= 0x400 )
      v32 = 1023;
    result = httpd_cgi_ret(a1, v33, v32, 4);
  }
  else
  {
    v17 = snprintf(v33, 1024, "{\"code\":%d,\"error\":\"%s\",\"data\":null}", 1, "no sq");
    if ( v17 >= 0x400 )
      v17 = 1023;
    result = httpd_cgi_ret(a1, v33, v17, 4);
  }
  return result;
}
// 4CAEF4: variable 'v7' is possibly undefined
// 6A81BC: using guessed type int __fastcall nvram_get(_DWORD);
// 6A8258: using guessed type int cJSON_CreateObject(void);
// 6A8318: using guessed type int __fastcall _GET_LANG_TEXT(_DWORD, _DWORD, _DWORD);
// 6A83A8: using guessed type int __fastcall cJSON_AddStringToObject(_DWORD, _DWORD, _DWORD);
// 6A83B8: using guessed type int sq_file_get_device_id(void);
// 6A8490: using guessed type int cJSON_CreateArray(void);
// 6A84D8: using guessed type int __fastcall iptv_channel_wan_set(_DWORD, _DWORD);
// 6A85D0: using guessed type int __fastcall cJSON_PrintUnformatted(_DWORD);
// 6A863C: using guessed type int __fastcall wys_mkstemp(_DWORD);
// 6A867C: using guessed type int __fastcall https_post(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD);
// 6A8760: using guessed type int start_igmp_snooping(void);
// 6A8780: using guessed type int __fastcall cJSON_Parse(_DWORD);
// 6A87C4: using guessed type int nvram_commit(void);
// 6A8844: using guessed type int __fastcall cJSON_Delete(_DWORD);
// 6A8858: using guessed type int __fastcall cJSON_AddItemToArray(_DWORD, _DWORD);
// 6A887C: using guessed type int __fastcall GetJSONItemValueAsString(_DWORD, _DWORD);
// 6A8910: using guessed type int __fastcall cJSON_GetObjectItem(_DWORD, _DWORD);
// 6A8918: using guessed type int __fastcall nvram_set(_DWORD, _DWORD);
// 6A89B4: using guessed type int __fastcall J_atoi(_DWORD);

