int __fastcall sub_4B0B54(int a1)
{
  int v2; // $s5
  int v3; // $v0
  int v4; // $s1
  ssize_t v5; // $s4
  int v6; // $s0
  const char *v7; // $a2
  int v8; // $s0
  unsigned int v9; // $v0
  int v11; // $v0
  char v12[1024]; // [sp+18h] [-444h] BYREF
  char v13[68]; // [sp+418h] [-44h] BYREF

  v2 = jhl_get_3g_iface();
  memset(v13, 0, 0x40u);
  v3 = open("/var/3gstatus", 0);
  if ( v3 < 0 || (v4 = v3, v5 = read(v3, v13, 0x40u), close(v4), v5 < 8) )
    strcpy(v13, "Disconnect");
  else
    v12[v5 + 1024] = 0;
  strcpy(v12, "{\"code\":0,\"error\":\"\",\"data\":{");
  v6 = sprintf(&v12[29], "\"usb_3g_status\":\"%s\"", v13) + 29;
  if ( jhl_check_wanup(v2) )
  {
    v11 = jhl_nvget("ppp_get_ip", v2);
    v7 = (const char *)nvram_get(v11);
  }
  else
  {
    v7 = "0.0.0.0";
  }
  v8 = v6 + sprintf(&v12[v6], ",\"ip\":\"%s\"", v7);
  v9 = snprintf(&v12[v8], 1024 - v8, "}}");
  if ( v9 >= 1024 - v8 )
    v9 = 1023 - v8;
  return httpd_cgi_ret(a1, v12, v9 + v8, 4);
}
// 642164: using guessed type __int16 word_642164;
// 6A81BC: using guessed type int __fastcall nvram_get(_DWORD);
// 6A8538: using guessed type int __fastcall jhl_check_wanup(_DWORD);
// 6A880C: using guessed type int jhl_get_3g_iface(void);
// 6A890C: using guessed type int __fastcall jhl_nvget(_DWORD, _DWORD);

