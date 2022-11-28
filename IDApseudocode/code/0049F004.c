int __fastcall pppoe_bridge_user_md5(char *a1, const char *a2, const char *a3)
{
  int v6; // $v0
  int v7; // $v0
  char v9[132]; // [sp+18h] [-84h] BYREF

  memset(v9, 0, 0x80u);
  v6 = strlen(a2);
  pppoe_bridge_md5(v9, (int)a2, v6);
  snprintf(&v9[6], 122, "+%s+wayos", a3);
  v7 = strlen(v9);
  return pppoe_bridge_md5(a1, (int)v9, v7);
}

