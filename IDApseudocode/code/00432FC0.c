char *__fastcall httpd_cgi_user_check_admin(int a1, int a2, int a3)
{
  unsigned int v4; // $v0
  unsigned int v5[22]; // [sp+50h] [-6Ch] BYREF
  int v6; // [sp+A8h] [-14h]
  int v7; // [sp+ACh] [-10h]
  int v8; // [sp+B0h] [-Ch]
  int v9; // [sp+B4h] [-8h]

  if ( !jhl_realm_init )
  {
    v4 = get_random_seed(a1, a2, a3);
    srand(v4);
    jhl_realm_init = 1;
    jhl_realm_str = rand();
    *(_DWORD *)&byte_6A38E4 = rand();
    *(_DWORD *)&byte_6A38E8 = rand();
    v5[0] = rand();
    dword_6A38EC = v5[0];
  }
  FBR_MD5Init(v5);
  FBR_MD5Update(v5, (int)&jhl_realm_str, 0x10u);
  FBR_MD5Final(v5);
  jhl_realm_str = v6;
  *(_DWORD *)&byte_6A38E4 = v7;
  *(_DWORD *)&byte_6A38E8 = v8;
  dword_6A38EC = v9;
  sprintf(
    cookie_realm,
    "%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X",
    (unsigned __int8)v6,
    BYTE1(v6),
    BYTE2(v6),
    HIBYTE(v6),
    (unsigned __int8)v7,
    BYTE1(v7),
    BYTE2(v7),
    HIBYTE(v7),
    (unsigned __int8)v8,
    BYTE1(v8),
    BYTE2(v8),
    HIBYTE(v8),
    (unsigned __int8)v9,
    BYTE1(v9),
    BYTE2(v9),
    HIBYTE(v9));
  return cookie_realm;
}
// 67D2E0: using guessed type int jhl_realm_init;
// 6A38E0: using guessed type int jhl_realm_str;
// 6A38E4: using guessed type char byte_6A38E4;
// 6A38E8: using guessed type char byte_6A38E8;
// 6A38EC: using guessed type int dword_6A38EC;
// 6A845C: using guessed type int __fastcall get_random_seed(_DWORD, _DWORD, _DWORD);

