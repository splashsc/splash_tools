int __fastcall sub_4B9F7C(int a1)
{
  char *v2; // $v0
  size_t v3; // $v0
  char *v4; // $s2
  int v5; // $v0
  int v6; // $s1
  int v7; // $v0
  char *v8; // $s4
  const char *v9; // $v0
  unsigned int v10; // $s1
  const char *v11; // $v0
  char *v13; // $v0
  char *v14; // $s2
  char *v15; // $s1
  const char *v16; // $s2
  char *v17; // $v0
  const char *v18; // $s1
  char *v19; // $v0
  int v20; // $s1
  unsigned int v21; // $v0
  int v22; // $a1
  const char *v23; // $a2
  int v24; // $a0
  char v25[1024]; // [sp+20h] [-804h] BYREF
  char v26[1028]; // [sp+420h] [-404h] BYREF

  memset(v26, 0, 0x400u);
  memset(v25, 0, sizeof(v25));
  v2 = httpd_get_parm(a1, "url");
  if ( !v2 )
  {
    v22 = *(unsigned __int8 *)(a1 + 210102);
    v23 = "not url";
    v24 = 12;
LABEL_24:
    v11 = (const char *)_GET_LANG_TEXT(v24, v22, v23);
    goto LABEL_12;
  }
  v4 = v2;
  v3 = strlen(v2);
  base64_decode(v4, v25, v3);
  if ( httpd_wget(v25, "/tmp/LatitudeL") <= 0 )
  {
    v11 = "wget error";
    goto LABEL_12;
  }
  if ( access("/tmp/LatitudeL", 0) == -1 )
  {
    v11 = "F_OK error";
    goto LABEL_12;
  }
  v5 = f_size("/tmp/LatitudeL");
  v6 = v5;
  if ( v5 > 0 )
  {
    _mem_malloc(v5, "jsonp_ajax_data", 775);
    v8 = (char *)v7;
    if ( v7 )
    {
      if ( v6 == do_file("/tmp/LatitudeL", v7, v6) )
      {
        v14 = strstr(v8, "<lat>");
        v13 = strstr(v8, "<lng>");
        v15 = v13;
        if ( v14 && (v16 = v14 + 5, v13) )
        {
          v17 = strchr(v16, 60);
          v18 = v15 + 5;
          if ( v17 )
          {
            *v17 = 0;
            v19 = strchr(v18, 60);
            if ( v19 )
            {
              *v19 = 0;
              strcpy(v26, "{\"code\":0,\"error\":\"\",\"data\":{");
              v20 = sprintf(&v26[29], "\"ret\":0,\"lat\":\"%s\",\"lng\":\"%s\"", v16, v18) + 29;
              v21 = snprintf(&v26[v20], 1024 - v20, "}}");
              if ( v21 >= 1024 - v20 )
                v21 = 1023 - v20;
              v10 = v21 + v20;
              goto LABEL_10;
            }
            v9 = "file_info 3 error";
          }
          else
          {
            v9 = "file_info 2 error";
          }
        }
        else
        {
          v9 = "file_info error";
        }
      }
      else
      {
        v9 = "do_file error";
      }
      v10 = snprintf(v26, 1024, "{\"code\":%d,\"error\":\"%s\",\"data\":null}", 1, v9);
      if ( v10 >= 0x400 )
        v10 = 1023;
LABEL_10:
      _mem_free(v8);
      return httpd_cgi_ret(a1, v26, v10, 4);
    }
    v22 = *(unsigned __int8 *)(a1 + 210102);
    v23 = (const char *)v6;
    v24 = 4;
    goto LABEL_24;
  }
  v11 = "f_size error";
LABEL_12:
  v10 = snprintf(v26, 1024, "{\"code\":%d,\"error\":\"%s\",\"data\":null}", 1, v11);
  if ( v10 >= 0x400 )
    v10 = 1023;
  return httpd_cgi_ret(a1, v26, v10, 4);
}
// 4BA0B8: variable 'v7' is possibly undefined
// 642164: using guessed type __int16 word_642164;
// 6A81CC: using guessed type int __fastcall base64_decode(_DWORD, _DWORD, _DWORD);
// 6A8318: using guessed type int __fastcall _GET_LANG_TEXT(_DWORD, _DWORD, _DWORD);
// 6A8718: using guessed type int __fastcall httpd_wget(_DWORD, _DWORD);
// 6A8950: using guessed type int __fastcall f_size(_DWORD);

