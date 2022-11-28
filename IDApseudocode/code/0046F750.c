int __fastcall sub_46F750(int a1)
{
  int v2; // $a2
  int v3; // $v0
  int v5; // $v0
  char v6[1024]; // [sp+18h] [-A00h] BYREF
  char v7[1024]; // [sp+418h] [-600h] BYREF
  __int16 v8[256]; // [sp+818h] [-200h] BYREF

  jhl_parm_get("rzglMsg", v6, 1024);
  jhl_parm_get("rzglLx", v8, 512);
  if ( !v6[0] )
  {
    v5 = _GET_LANG_TEXT(75, *(unsigned __int8 *)(a1 + 210102), v2);
    strlcpy(v6, v5, 1024);
  }
  if ( !LOBYTE(v8[0]) )
    v8[0] = 32;
  v3 = sprintf(v7, "{\"msg\":\"%s\",\"lx\":\"%s\"}", v6, (const char *)v8);
  return httpd_cgi_ret(a1, v7, v3, 4);
}
// 46F838: variable 'v2' is possibly undefined
// 6A8318: using guessed type int __fastcall _GET_LANG_TEXT(_DWORD, _DWORD, _DWORD);
// 6A8480: using guessed type int __fastcall strlcpy(_DWORD, _DWORD, _DWORD);
// 6A8600: using guessed type int __fastcall jhl_parm_get(_DWORD, _DWORD, _DWORD);

