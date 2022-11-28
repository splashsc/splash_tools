int __fastcall sub_4AE5E4(int a1)
{
  char *v1; // $v0
  const char *v3; // $v0
  char *v4; // $v1
  int v5; // $t1
  int v6; // $t0
  int v7; // $a3
  int v8; // $a2
  int v10; // $v0
  int v11; // $v0
  int i; // $s0
  int v13; // $v0
  int v14; // $s6
  char v15[1024]; // [sp+18h] [-490h] BYREF
  char v16[128]; // [sp+418h] [-90h] BYREF
  char v17[5]; // [sp+498h] [-10h] BYREF
  char v18; // [sp+49Dh] [-Bh]

  v1 = httpd_get_parm(a1, "def_mac");
  if ( v1 && !str2mac(v1, v17) )
  {
    v10 = MacToStr(v16, v17);
    nvram_set("mac_deflan", v10);
    ++v18;
    v11 = MacToStr(v16, v17);
    nvram_set("mac_defwl", v11);
    for ( i = 0; i != 9; ++i )
    {
      ++v18;
      v14 = jhl_nvget("mac_defwan", i);
      v13 = MacToStr(v16, v17);
      nvram_set(v14, v13);
    }
  }
  v3 = "{\"code\":0,\"error\":\"\",\"data\":null}";
  v4 = v15;
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
  while ( v3 != "}" );
  *(_WORD *)v4 = *(_WORD *)v3;
  return httpd_cgi_ret(a1, v15, 33, 4);
}
// 6A8220: using guessed type int __fastcall str2mac(_DWORD, _DWORD);
// 6A88C8: using guessed type int __fastcall MacToStr(_DWORD, _DWORD);
// 6A890C: using guessed type int __fastcall jhl_nvget(_DWORD, _DWORD);
// 6A8918: using guessed type int __fastcall nvram_set(_DWORD, _DWORD);

