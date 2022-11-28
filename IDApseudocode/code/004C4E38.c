int __fastcall sub_4C4E38(int a1)
{
  const char *v2; // $v0
  int v3; // $v0
  bool v4; // dc
  int v5; // $v0
  char v7[8192]; // [sp+18h] [-2018h] BYREF
  char *v8; // [sp+2018h] [-18h] BYREF
  int v9; // [sp+201Ch] [-14h]
  int v10; // [sp+2020h] [-10h]
  int v11; // [sp+2024h] [-Ch]
  int v12; // [sp+2028h] [-8h]

  v8 = v7;
  v9 = 0x2000;
  strcpy(v7, "{\"code\":0,\"error\":\"\",\"data\":{");
  v10 = 29;
  v11 = 0;
  v12 = 0;
  v2 = (const char *)nvram_get("ipv6in4_all");
  if ( !v2 )
    v2 = "";
  mcl_bytearray_printf(&v8, "\"list\":\"%s\"", v2);
  v3 = snprintf(&v8[v10], v9 - v10, "}}");
  v4 = v3 < v9 - v10;
  v5 = v3 + v10;
  if ( !v4 )
    v5 = v9 - 1;
  v10 = v5;
  return httpd_cgi_ret(a1, v8, v5, 4);
}
// 642164: using guessed type __int16 word_642164;
// 6A81BC: using guessed type int __fastcall nvram_get(_DWORD);
// 6A8414: using guessed type int mcl_bytearray_printf(_DWORD, const char *, ...);

