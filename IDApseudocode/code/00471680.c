int __fastcall sub_471680(int a1)
{
  char *v2; // $s2
  size_t v3; // $v0
  int v4; // $v0
  int v5; // $v0
  char *v6; // $v1
  const char *v7; // $v0
  int v8; // $t0
  int v9; // $a3
  int v10; // $a2
  int v11; // $a1
  unsigned int v12; // $a2
  const char *v14; // $v0
  char v15[512]; // [sp+20h] [-240h] BYREF
  char v16[64]; // [sp+220h] [-40h] BYREF

  memset(v16, 0, sizeof(v16));
  v2 = httpd_get_parm(a1, "name");
  if ( v2 )
  {
    if ( *(_BYTE *)(a1 + 210100) == 2 )
    {
      strlcpy(v16, v2, 64);
    }
    else
    {
      v3 = strlen(v2);
      base64_decode(v2, v16, v3);
    }
    v4 = jhl_nv_get_def("macuser_down_del");
    v5 = J_atoi(v4);
    user_namedown_set(v16, v5);
    v6 = v15;
    v7 = "{\"code\":0,\"error\":\"\",\"data\":null}";
    do
    {
      v8 = *(_DWORD *)v7;
      v9 = *((_DWORD *)v7 + 1);
      v10 = *((_DWORD *)v7 + 2);
      v11 = *((_DWORD *)v7 + 3);
      v7 += 16;
      *(_DWORD *)v6 = v8;
      *((_DWORD *)v6 + 1) = v9;
      *((_DWORD *)v6 + 2) = v10;
      *((_DWORD *)v6 + 3) = v11;
      v6 += 16;
    }
    while ( v7 != "}" );
    v12 = 33;
    *(_WORD *)v6 = *(_WORD *)v7;
  }
  else
  {
    v14 = (const char *)_GET_LANG_TEXT(12, *(unsigned __int8 *)(a1 + 210102), &unk_6442E4);
    v12 = snprintf(v15, 512, "{\"code\":%d,\"error\":\"%s\",\"data\":null}", 1, v14);
    if ( v12 >= 0x200 )
      v12 = 511;
  }
  return httpd_cgi_ret(a1, v15, v12, 4);
}
// 6A81CC: using guessed type int __fastcall base64_decode(_DWORD, _DWORD, _DWORD);
// 6A8318: using guessed type int __fastcall _GET_LANG_TEXT(_DWORD, _DWORD, _DWORD);
// 6A8480: using guessed type int __fastcall strlcpy(_DWORD, _DWORD, _DWORD);
// 6A84C8: using guessed type int __fastcall jhl_nv_get_def(_DWORD);
// 6A8528: using guessed type int __fastcall user_namedown_set(_DWORD, _DWORD);
// 6A89B4: using guessed type int __fastcall J_atoi(_DWORD);

