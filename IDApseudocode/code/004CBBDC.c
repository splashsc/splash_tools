int __fastcall iptv_get_channel_list(int a1, int a2)
{
  int v4; // $s1
  int v5; // $s0
  int v6; // $v0
  _DWORD *v7; // $s0
  int v8; // $s6
  int v9; // $s3
  int v10; // $v0
  int v11; // $v1
  const char *v12; // $v0
  int v13; // $s1
  int v14; // $v0
  char *v15; // $a2
  int v16; // $a2
  int v17; // $a3
  int v18; // $v0
  char *v19; // $a2
  int v20; // $v0
  char *v21; // $a2
  int v22; // $v0
  char *v23; // $a2
  int v24; // $v0
  char *v25; // $a2
  int v26; // $v0
  char *v27; // $a2
  char v29[1024]; // [sp+18h] [-420h] BYREF
  int v30; // [sp+418h] [-20h]
  char *format; // [sp+41Ch] [-1Ch]
  char *v32; // [sp+420h] [-18h]
  char *v33; // [sp+424h] [-14h]
  char *v34; // [sp+428h] [-10h]
  char *v35; // [sp+42Ch] [-Ch]
  int v36; // [sp+430h] [-8h]

  v4 = cJSON_CreateObject();
  v30 = v4;
  if ( v4 )
  {
    v5 = cJSON_Parse(a1);
    v36 = v5;
    if ( v5 )
    {
      memset(v29, 0, sizeof(v29));
      v6 = cJSON_AddArrayToObject(v4, "list");
      v7 = *(_DWORD **)(v5 + 8);
      v8 = v6;
      if ( v7 )
      {
        v34 = "1\"";
        format = "%d";
        v32 = "number";
        v9 = 1;
        v33 = "0";
        v35 = "%s";
        do
        {
          v13 = cJSON_CreateObject();
          v12 = (const char *)GetJSONItemValueAsString(v7, "n");
          snprintf(v29, 1024, "%s", v12);
          cJSON_AddStringToObject(v13, "name", v29);
          if ( a2 )
          {
            snprintf(v29, 1024, format, v9);
            cJSON_AddStringToObject(v13, v32, v29);
            cJSON_AddStringToObject(v13, v34 + 5772, v33);
            snprintf(v29, 1024, "%08X", v9);
            cJSON_AddStringToObject(v13, "id", v29);
            v14 = GetJSONItemValueAsString(v7, "u");
            snprintf(v29, 1024, v35, v14);
            ++v9;
            if ( !memcmp(v29, "rtp", 3u) || !memcmp(v29, "udp", 3u) )
            {
              cJSON_AddStringToObject(v13, "multicast", v29);
              v15 = "";
            }
            else
            {
              cJSON_AddStringToObject(v13, "multicast", "");
              v15 = v29;
            }
            cJSON_AddStringToObject(v13, "unicast", v15);
          }
          v10 = cJSON_AddItemToArray(v8, v13);
          v7 = (_DWORD *)*v7;
        }
        while ( v7 );
        v16 = v10;
        v17 = v11;
      }
      else
      {
        v16 = 0;
        v17 = 0;
      }
      cJSON_AddNumberToObject(v30, "count", v16, v17);
      if ( !a2 )
      {
        v18 = nvram_get("iptv_province");
        if ( v18 )
          v19 = (char *)v18;
        else
          v19 = "";
        cJSON_AddStringToObject(v30, "province", v19);
        v20 = nvram_get("iptv_city");
        if ( v20 )
          v21 = (char *)v20;
        else
          v21 = "";
        cJSON_AddStringToObject(v30, "city", v21);
        v22 = nvram_get("iptv_operator");
        if ( v22 )
          v23 = (char *)v22;
        else
          v23 = "";
        cJSON_AddStringToObject(v30, "operator", v23);
        v24 = nvram_get("iptv_en");
        if ( v24 )
          v25 = (char *)v24;
        else
          v25 = "";
        cJSON_AddStringToObject(v30, "en", v25);
        v26 = nvram_get("iptv_host");
        if ( v26 )
          v27 = (char *)v26;
        else
          v27 = "";
        cJSON_AddStringToObject(v30, "host", v27);
      }
      cJSON_Delete(v36);
    }
  }
  return v30;
}
// 4CBED4: variable 'v11' is possibly undefined
// 6A81BC: using guessed type int __fastcall nvram_get(_DWORD);
// 6A8258: using guessed type int cJSON_CreateObject(void);
// 6A83A8: using guessed type int __fastcall cJSON_AddStringToObject(_DWORD, _DWORD, _DWORD);
// 6A86D4: using guessed type int __fastcall cJSON_AddArrayToObject(_DWORD, _DWORD);
// 6A8780: using guessed type int __fastcall cJSON_Parse(_DWORD);
// 6A87C8: using guessed type int __fastcall cJSON_AddNumberToObject(_DWORD, _DWORD, _DWORD, _DWORD);
// 6A8844: using guessed type int __fastcall cJSON_Delete(_DWORD);
// 6A8858: using guessed type int __fastcall cJSON_AddItemToArray(_DWORD, _DWORD);
// 6A887C: using guessed type int __fastcall GetJSONItemValueAsString(_DWORD, _DWORD);

