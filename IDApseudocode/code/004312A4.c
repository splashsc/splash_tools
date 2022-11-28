int jhl_user_login_save()
{
  void ***v0; // $s0
  char *v1; // $s2
  int v2; // $s1
  void **v3; // $s7
  uint32_t v4; // $v0
  void **v5; // $s3
  int v6; // $s5
  int v7; // $v0
  _DWORD v9[25600]; // [sp+10h] [-18FE0h] BYREF
  char v10[64]; // [sp+19018h] [+28h] BYREF
  uint32_t v11; // [sp+19058h] [+68h]
  void **v12; // [sp+1905Ch] [+6Ch]
  char *format; // [sp+19060h] [+70h]
  int v14; // [sp+19064h] [+74h]
  void **v15; // [sp+19068h] [+78h]

  v15 = &user_login_list;
  memset(v9, 0, sizeof(v9));
  v0 = (void ***)user_login_list;
  LOWORD(v9[0]) = 32;
  if ( user_login_list != &user_login_list )
  {
    v1 = (char *)v9;
    format = "%x|%x|%x|%s|%u|%s<";
    v2 = 0;
    v14 = 102369;
    do
    {
      v3 = *v0;
      v4 = ntohl((uint32_t)v0[3]);
      v12 = v0[7];
      v11 = v4;
      v5 = v0[8];
      v6 = *((unsigned __int8 *)v0 + 36);
      v7 = IpaddrToStr(v10, v0 + 2);
      v2 += sprintf(v1, format, v11, v12, v5, v0 + 10, v6, v7, v9[0]);
      v0 = (void ***)v3;
      v1 = (char *)v9 + v2;
    }
    while ( v2 < v14 && v3 != v15 );
  }
  nvram_set("jhluser_login", v9);
  nvram_commit();
  return 0;
}
// 66B5E0: using guessed type void *user_login_list;
// 6A843C: using guessed type int __fastcall IpaddrToStr(_DWORD, _DWORD);
// 6A87C4: using guessed type int nvram_commit(void);
// 6A8918: using guessed type int __fastcall nvram_set(_DWORD, _DWORD);

