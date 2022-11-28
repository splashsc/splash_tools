int __fastcall sub_4744F0(int a1)
{
  char *v2; // $s0
  const char *v3; // $v0
  char *v4; // $v1
  const char *v5; // $v0
  int v6; // $t0
  int v7; // $a3
  int v8; // $a2
  int v9; // $a1
  const char *v11; // $v0
  char v12[260]; // [sp+18h] [-104h] BYREF

  memset(v12, 0, 0x100u);
  v2 = httpd_get_parm(a1, "timeout");
  if ( v2 && ((v3 = (const char *)nvram_get("rzgl_mac_timeout")) == 0 || strcmp(v3, v2))
    || (v11 = (const char *)nvram_get("rzgl_mac_en")) == 0
    || strcmp(v11, "2") )
  {
    nvram_set("rzgl_mac_timeout", v2);
    nvram_set("rzgl_mac_en", "2");
    macuser_conf_set();
  }
  v4 = v12;
  v5 = "{\"code\":0,\"error\":\"\",\"data\":null}";
  do
  {
    v6 = *(_DWORD *)v5;
    v7 = *((_DWORD *)v5 + 1);
    v8 = *((_DWORD *)v5 + 2);
    v9 = *((_DWORD *)v5 + 3);
    v5 += 16;
    *(_DWORD *)v4 = v6;
    *((_DWORD *)v4 + 1) = v7;
    *((_DWORD *)v4 + 2) = v8;
    *((_DWORD *)v4 + 3) = v9;
    v4 += 16;
  }
  while ( v5 != "}" );
  *(_WORD *)v4 = *(_WORD *)v5;
  return httpd_cgi_ret(a1, v12, 33, 4);
}
// 6A81BC: using guessed type int __fastcall nvram_get(_DWORD);
// 6A86DC: using guessed type int macuser_conf_set(void);
// 6A8918: using guessed type int __fastcall nvram_set(_DWORD, _DWORD);

