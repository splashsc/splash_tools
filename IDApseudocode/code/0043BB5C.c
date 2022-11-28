int __fastcall sub_43BB5C(int a1)
{
  void **v1; // $v0
  void **v3; // $s0
  void ***v4; // $v1
  char *v5; // $v1
  const char *v6; // $v0
  int v7; // $t1
  int v8; // $t0
  int v9; // $a3
  int v10; // $a2
  char v12[516]; // [sp+18h] [-204h] BYREF

  v1 = (void **)user_login_list;
  if ( user_login_list != &user_login_list )
  {
    do
    {
      v3 = (void **)*v1;
      v4 = (void ***)v1[1];
      v3[1] = v4;
      *v4 = v3;
      *v1 = (void *)1048832;
      v1[1] = (void *)2097664;
      _mem_free(v1);
      v1 = v3;
    }
    while ( v3 != &user_login_list );
  }
  user_login_num = 0;
  nvram_set("jhluser_login", " ");
  nvram_commit();
  v5 = v12;
  v6 = "{\"code\":0,\"error\":\"\",\"data\":null}";
  do
  {
    v7 = *(_DWORD *)v6;
    v8 = *((_DWORD *)v6 + 1);
    v9 = *((_DWORD *)v6 + 2);
    v10 = *((_DWORD *)v6 + 3);
    v6 += 16;
    *(_DWORD *)v5 = v7;
    *((_DWORD *)v5 + 1) = v8;
    *((_DWORD *)v5 + 2) = v9;
    *((_DWORD *)v5 + 3) = v10;
    v5 += 16;
  }
  while ( v6 != "}" );
  *(_WORD *)v5 = *(_WORD *)v6;
  return httpd_cgi_ret(a1, v12, 33, 4);
}
// 66B5E0: using guessed type void *user_login_list;
// 67D2E8: using guessed type int user_login_num;
// 6A87C4: using guessed type int nvram_commit(void);
// 6A8918: using guessed type int __fastcall nvram_set(_DWORD, _DWORD);

