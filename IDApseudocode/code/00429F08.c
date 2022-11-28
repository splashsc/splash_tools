int __fastcall httpd_send_sj_file(_DWORD *a1)
{
  char *v2; // $s0
  char *v3; // $v0
  size_t v4; // $v0
  int v5; // $v0
  const char *v6; // $a0
  int v7; // $s3
  char *v8; // $v0
  char *v9; // $s1
  int v10; // $s7
  const char *v11; // $a3
  int v12; // $v0
  const char *v13; // $a3
  _DWORD *v14; // $fp
  int v15; // $v0
  int v16; // $s0
  signed int v17; // $s3
  int v19; // $s2
  char v20[256]; // [sp+20h] [-1A0h] BYREF
  struct stat v21; // [sp+120h] [-A0h] BYREF

  strcpy(v20, "/tmp/sj/");
  memset(&v20[9], 0, 0xF7u);
  v2 = (char *)a1[11];
  v3 = strstr(v2, "/sj/");
  if ( v3 )
    v2 = v3 + 4;
  if ( *v2 == 47 )
    ++v2;
  v4 = strlen(v2);
  if ( v4 < 0xC9 )
  {
    memcpy(&v20[8], v2, v4 + 1);
    if ( !stat(v20, &v21) || (unescape(v20), !stat(v20, &v21)) )
    {
      if ( (v21.st_uid & 0xF000) != 0x4000 )
      {
        httpd_send_big_file((int)a1, (int)v20, v21.st_atim.tv_sec);
        return 0;
      }
    }
  }
  v5 = nvram_get("sj_http_port");
  if ( v5 )
    v6 = (const char *)v5;
  else
    v6 = "";
  v7 = atoi(v6);
  if ( v7 < 80 )
    return -1;
  _mem_malloc(419430, "httpd_send_sj_file", 3214);
  v9 = v8;
  if ( !v8 )
    return -1;
  v10 = snprintf(v8, 419430, "http://127.0.0.1:%d/sj/%s", v7, v2);
  if ( v10 >= 419430 )
  {
    v11 = (const char *)a1[13];
    v10 = 419429;
    if ( v11 )
      goto LABEL_12;
  }
  else
  {
    v11 = (const char *)a1[13];
    if ( v11 )
    {
LABEL_12:
      v12 = snprintf(&v9[v10], 419430 - v10, "?%s", v11);
      if ( v12 >= 419430 - v10 )
        v12 = 419429 - v10;
      v13 = (const char *)a1[14];
      v10 += v12;
      if ( v13 )
      {
        v14 = a1 + 15;
        do
        {
          v15 = snprintf(&v9[v10], 419430 - v10, "&%s", v13);
          if ( v15 >= 419430 - v10 )
            v15 = 419429 - v10;
          v13 = (const char *)*v14++;
          v10 += v15;
        }
        while ( v13 );
      }
      goto LABEL_19;
    }
  }
LABEL_19:
  v16 = -1;
  if ( v10 < 419429 )
  {
    v17 = httpd_wget(v9, "/tmp/sj_ack");
    if ( v17 && f_exists("/tmp/sj_ack") )
    {
      if ( v17 < 10240 )
      {
        v19 = f_read("/tmp/sj_ack", v9, 419429);
        unlink("/tmp/sj_ack");
        if ( v19 >= 0 )
        {
          v9[v19] = 0;
          return httpd_cgi_ret((int)a1, v9, v19, 8);
        }
        v16 = -1;
      }
      else
      {
        httpd_send_big_file((int)a1, (int)"/tmp/sj_ack", v17);
        v16 = 0;
        unlink("/tmp/sj_ack");
      }
    }
    else
    {
      unlink("/tmp/sj_ack");
      v16 = -1;
    }
  }
  _mem_free(v9);
  return v16;
}
// 42A040: variable 'v8' is possibly undefined
// 6A81BC: using guessed type int __fastcall nvram_get(_DWORD);
// 6A846C: using guessed type int __fastcall f_exists(_DWORD);
// 6A869C: using guessed type int __fastcall f_read(_DWORD, _DWORD, _DWORD);
// 6A8718: using guessed type int __fastcall httpd_wget(_DWORD, _DWORD);

