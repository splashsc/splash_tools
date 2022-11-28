int __fastcall sub_4C4A00(int a1)
{
  int v2; // $v0
  int v3; // $v0
  bool v4; // dc
  int v5; // $v0
  char v7[4096]; // [sp+18h] [-101Ch] BYREF
  char *v8; // [sp+1018h] [-1Ch] BYREF
  int v9; // [sp+101Ch] [-18h]
  int v10; // [sp+1020h] [-14h]
  int v11; // [sp+1024h] [-10h]
  int v12; // [sp+1028h] [-Ch]

  v8 = v7;
  v9 = 4096;
  strcpy(v7, "{\"code\":0,\"error\":\"\",\"data\":{");
  v10 = 29;
  v11 = 0;
  v12 = 0;
  mcl_bytearray_printf(&v8, "\"lan\":[");
  lan_iface_foreach(&v8, sub_4C4B88);
  v2 = v10;
  if ( v10 > 0 && v8[v10 - 1] == 44 )
    v2 = --v10;
  v8[v2] = 0;
  mcl_bytearray_printf(&v8, &byte_6445A0);
  v3 = snprintf(&v8[v10], v9 - v10, "}}");
  v4 = v3 < v9 - v10;
  v5 = v3 + v10;
  if ( !v4 )
    v5 = v9 - 1;
  v10 = v5;
  return httpd_cgi_ret(a1, v8, v5, 4);
}
// 642164: using guessed type __int16 word_642164;
// 6445A0: using guessed type char byte_6445A0;
// 6A8414: using guessed type int mcl_bytearray_printf(_DWORD, const char *, ...);
// 6A84EC: using guessed type int __fastcall lan_iface_foreach(_DWORD, _DWORD);

