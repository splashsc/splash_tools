void __fastcall ai_send_router_login(int a1, const char *a2, const char *a3, int a4, const char *a5)
{
  int v9; // $v0
  const char *v10; // $s0
  const char *v11; // $s2
  time_t v12; // $v0
  unsigned int v13; // $v0
  char v14[1024]; // [sp+38h] [-434h] BYREF
  char v15[52]; // [sp+438h] [-34h] BYREF

  memset(v14, 0, sizeof(v14));
  v9 = IpaddrToStr(v15, a1 + 205460);
  v10 = *(const char **)(a1 + 205504);
  v11 = (const char *)v9;
  if ( !v10 )
    v10 = "\"\"";
  v12 = time(0);
  v13 = snprintf(
          v14,
          1024,
          "{\"ip\":\"%s\",\"host\":\"%s\",\"time\":\"%u\",\"ui\":\"%d\",\"type\":\"%s\",\"username\":\"%s\",\"passwd\":\""
          "%s\",\"status\":\"%d\"}",
          v11,
          v10,
          v12,
          3,
          a5,
          a2,
          a3,
          a4);
  if ( v13 >= 0x400 )
    v13 = 1023;
  ai_unix_cgi_send(0x272Bu, 0xFFFFFFFF, v14, v13);
}
// 6A843C: using guessed type int __fastcall IpaddrToStr(_DWORD, _DWORD);

