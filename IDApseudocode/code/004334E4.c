void __fastcall httpd_set_cookie_language(int a1)
{
  const char *v2; // $a0
  char *v3; // $v0
  char *v4; // $v0
  char *v5; // $v0
  char *v6; // $v0
  int v7[9]; // [sp+8h] [-30h] BYREF

  *(_BYTE *)(a1 + 210102) = 0;
  *(_BYTE *)(a1 + 210103) = 1;
  if ( (*(_DWORD *)(a1 + 32) & 0x800) != 0 )
  {
    v2 = *(const char **)(a1 + 205524);
    v7[0] = 0;
    v7[1] = 0;
    v7[2] = 0;
    v7[3] = 0;
    v7[4] = 0;
    v7[5] = 0;
    v7[6] = 0;
    v7[7] = 0;
    v3 = strstr(v2, "language=");
    if ( v3 )
    {
      strlcpy(v7, v3 + 9, 32);
      v4 = strchr((const char *)v7, 44);
      if ( v4 )
        *v4 = 0;
      v5 = strchr((const char *)v7, 59);
      if ( v5 )
        *v5 = 0;
      v6 = strchr((const char *)v7, 32);
      if ( v6 )
        *v6 = 0;
    }
    *(_BYTE *)(a1 + 210102) = get_lang_type(v7);
    *(_BYTE *)(a1 + 210103) = 0;
  }
}
// 6A8480: using guessed type int __fastcall strlcpy(_DWORD, _DWORD, _DWORD);
// 6A8608: using guessed type int __fastcall get_lang_type(_DWORD);

