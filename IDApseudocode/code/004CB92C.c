int __fastcall sub_4CB92C(int a1)
{
  char *v2; // $s1
  const char *v3; // $v0
  char *v4; // $v1
  int v5; // $t0
  int v6; // $a3
  int v7; // $a2
  int v8; // $a1
  int v9; // $a0
  char v10; // $v0
  unsigned int v11; // $a2
  char *v13; // $v0
  char v14[1028]; // [sp+18h] [-404h] BYREF

  v2 = httpd_get_parm(a1, "key");
  if ( !sq_file_get_device_id() || !nvram_get_int("iptv_en") )
    return httpd_cgi_ret(a1, v14, 43, 4);
  if ( v2 && !strcmp(v2, "11778438-7062-4520-b24f-14ed345421b7") )
  {
    v13 = iptv_get_new_token();
    v11 = snprintf(v14, 1024, "{\"ret\":\"1\",\"msg\":\"ok\",\"data\":{\"token\":\"%s\"}}", v13);
    if ( v11 >= 0x400 )
      v11 = 1023;
  }
  else
  {
    v3 = "{\"ret\":\"-1\",\"msg\":\"error\",\"data\":{}}";
    v4 = v14;
    do
    {
      v5 = *(_DWORD *)v3;
      v6 = *((_DWORD *)v3 + 1);
      v7 = *((_DWORD *)v3 + 2);
      v8 = *((_DWORD *)v3 + 3);
      v3 += 16;
      *(_DWORD *)v4 = v5;
      *((_DWORD *)v4 + 1) = v6;
      *((_DWORD *)v4 + 2) = v7;
      *((_DWORD *)v4 + 3) = v8;
      v4 += 16;
    }
    while ( v3 != ":{}}" );
    v9 = *(_DWORD *)v3;
    v10 = v3[4];
    *(_DWORD *)v4 = v9;
    v4[4] = v10;
    v11 = 36;
  }
  *(_DWORD *)(a1 + 36) |= 0x8000u;
  return httpd_cgi_ret(a1, v14, v11, 4);
}
// 6A81B4: using guessed type int __fastcall nvram_get_int(_DWORD);
// 6A83B8: using guessed type int sq_file_get_device_id(void);

