int __fastcall sub_4CC0F4(int a1)
{
  int v2; // $v0
  int v3; // $s0
  char *v4; // $v0
  int v5; // $s5
  size_t v6; // $s2
  int v7; // $v0
  int v8; // $s2
  int v9; // $a3
  int v10; // $a2
  char *v11; // $a1

  _mem_malloc(0x200000, "channel_list_cgi", 234);
  v3 = v2;
  if ( sq_file_get_device_id() && nvram_get_int("iptv_en") )
  {
    if ( !v3 )
    {
      v9 = 4;
      v10 = 42;
      v11 = 0;
      return httpd_cgi_ret(a1, v11, v10, v9);
    }
    httpd_get_parm(a1, "token");
    strcpy((char *)v3, "{\"ret\":\"1\",\"msg\":\"ok\",\"data\":");
    qmemcpy((void *)v3, "{\"ret\":\"1\",\"msg\":\"ok", 20);
    v4 = (char *)nvram_get("iptv_channel_list");
    if ( !v4 )
      v4 = "";
    v5 = iptv_get_channel_list((int)v4, 1);
    cJSON_PrintPreallocated(v5, v3 + 29, 2097117, 0);
    v6 = strlen((const char *)(v3 + 29)) + 29;
    v7 = snprintf((char *)(v3 + v6), 0x200000 - v6, "}");
    if ( v7 >= (int)(0x200000 - v6) )
      v7 = 0x1FFFFF - v6;
    v8 = v7 + v6;
    cJSON_Delete(v5);
    *(_DWORD *)(a1 + 36) |= 0x8000u;
    v9 = 8;
    v10 = v8;
  }
  else
  {
    v9 = 4;
    v10 = 42;
  }
  v11 = (char *)v3;
  return httpd_cgi_ret(a1, v11, v10, v9);
}
// 4CC154: variable 'v2' is possibly undefined
// 6A81B4: using guessed type int __fastcall nvram_get_int(_DWORD);
// 6A81BC: using guessed type int __fastcall nvram_get(_DWORD);
// 6A83B8: using guessed type int sq_file_get_device_id(void);
// 6A8740: using guessed type int __fastcall cJSON_PrintPreallocated(_DWORD, _DWORD, _DWORD, _DWORD);
// 6A8844: using guessed type int __fastcall cJSON_Delete(_DWORD);

