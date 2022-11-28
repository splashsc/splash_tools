int __fastcall sub_4CC344(int a1)
{
  int v2; // $v0
  int v3; // $s0
  char *v4; // $v0
  int v5; // $v0
  int v6; // $s3
  size_t v7; // $s3
  int v8; // $s1
  int v9; // $a0
  int v10; // $a1
  int v11; // $a2
  int result; // $v0
  unsigned int v13; // $v0
  const char *v14; // $v0
  unsigned int v15; // $v0
  char v16[132]; // [sp+20h] [-84h] BYREF

  _mem_malloc(0x200000, "iptv_channel_data", 494);
  v3 = v2;
  if ( sq_file_get_device_id() )
  {
    if ( v3 )
    {
      strcpy((char *)v3, "{\"code\":0,\"error\":\"\",\"data\":");
      qmemcpy((void *)v3, "{\"code\":0,\"error", 16);
      v4 = (char *)nvram_get("iptv_channel_list");
      if ( !v4 )
        v4 = "";
      v5 = iptv_get_channel_list((int)v4, 0);
      v6 = v5;
      if ( v5 )
      {
        cJSON_PrintPreallocated(v5, v3 + 28, 2097118, 0);
        cJSON_Delete(v6);
        v7 = strlen((const char *)(v3 + 28)) + 28;
        v8 = 0x200000 - v7;
        v9 = v7;
        v10 = 0x200000 - v7;
      }
      else
      {
        v10 = 2097124;
        v8 = 2097124;
        v9 = 28;
        v7 = 28;
      }
      v11 = snprintf((char *)(v3 + v9), v10, "}");
      if ( v11 >= v8 )
        v11 = 0x1FFFFF - v7;
      *(_DWORD *)(a1 + 36) |= 0x8000u;
      result = httpd_cgi_ret(a1, (char *)v3, v7 + v11, 8);
    }
    else
    {
      v14 = (const char *)_GET_LANG_TEXT(4, *(unsigned __int8 *)(a1 + 210102), 0x200000);
      v15 = snprintf(v16, 128, "{\"code\":%d,\"error\":\"%s\",\"data\":null}", 1, v14);
      if ( v15 >= 0x80 )
        v15 = 127;
      result = httpd_cgi_ret(a1, 0, v15, 4);
    }
  }
  else
  {
    v13 = snprintf(v16, 128, "{\"code\":%d,\"error\":\"%s\",\"data\":null}", 1, "no sq");
    if ( v13 >= 0x80 )
      result = httpd_cgi_ret(a1, (char *)v3, 127, 4);
    else
      result = httpd_cgi_ret(a1, (char *)v3, v13, 4);
  }
  return result;
}
// 4CC39C: variable 'v2' is possibly undefined
// 6A81BC: using guessed type int __fastcall nvram_get(_DWORD);
// 6A8318: using guessed type int __fastcall _GET_LANG_TEXT(_DWORD, _DWORD, _DWORD);
// 6A83B8: using guessed type int sq_file_get_device_id(void);
// 6A8740: using guessed type int __fastcall cJSON_PrintPreallocated(_DWORD, _DWORD, _DWORD, _DWORD);
// 6A8844: using guessed type int __fastcall cJSON_Delete(_DWORD);

