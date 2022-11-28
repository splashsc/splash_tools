int __fastcall user_lock_asp(int a1)
{
  char *v2; // $v0
  char *v3; // $s2
  char *v4; // $s3
  int v5; // $s1
  int v6; // $v0
  const char **v7; // $s2
  int v8; // $s6
  int v9; // $s3
  int v10; // $s5
  const char *v11; // $s4
  size_t v12; // $v0
  size_t v13; // $v0
  const char **v15; // $s2
  int v16; // $s6
  int v17; // $s3
  int v18; // $s5
  const char *v19; // $s4
  size_t v20; // $v0
  size_t v21; // $v0
  char v22[4096]; // [sp+18h] [-1804h] BYREF
  char v23[1024]; // [sp+1018h] [-804h] BYREF
  char v24[1028]; // [sp+1418h] [-404h] BYREF

  memset(v23, 0, sizeof(v23));
  v3 = httpd_get_parm(a1, "mode");
  v2 = httpd_get_parm(a1, "user");
  if ( !v3 )
    return -1;
  v4 = v2;
  v5 = strcmp(v3, "lock_all");
  if ( !v5 )
  {
    user_lock(1, 0, 1);
    return v5;
  }
  if ( !strcmp(v3, "lock_sel") )
  {
    v15 = (const char **)v22;
    v16 = split_string(v4, 44, v22, 1024);
    if ( v16 > 0 )
    {
      v17 = 0;
      v18 = a1 + 196608;
      do
      {
        memset(v24, 0, 0x400u);
        if ( *(_BYTE *)(v18 + 13492) == 2 )
        {
          strlcpy(v24, *v15, 1024);
        }
        else
        {
          memset(v23, 0, sizeof(v23));
          v19 = *v15;
          v20 = strlen(*v15);
          base64_decode(v19, v23, v20);
          v21 = strlen(v23);
          str_to_gb2312(v23, v21, v24, 1024);
        }
        ++v17;
        user_lock(0, v24, 1);
        ++v15;
      }
      while ( v16 != v17 );
    }
    return 0;
  }
  v5 = strcmp(v3, "unlock_all");
  if ( !v5 )
  {
    user_lock(1, 0, 0);
    return v5;
  }
  v6 = strcmp(v3, "unlock_sel");
  v7 = (const char **)v22;
  if ( v6 )
    return -1;
  v8 = split_string(v4, 44, v22, 1024);
  if ( v8 > 0 )
  {
    v9 = 0;
    v10 = a1 + 196608;
    do
    {
      memset(v24, 0, 0x400u);
      if ( *(_BYTE *)(v10 + 13492) == 2 )
      {
        strlcpy(v24, *v7, 1024);
      }
      else
      {
        memset(v23, 0, sizeof(v23));
        v11 = *v7;
        v12 = strlen(*v7);
        base64_decode(v11, v23, v12);
        v13 = strlen(v23);
        str_to_gb2312(v23, v13, v24, 1024);
      }
      ++v9;
      user_lock(0, v24, 0);
      ++v7;
    }
    while ( v8 != v9 );
  }
  return 0;
}
// 6A81CC: using guessed type int __fastcall base64_decode(_DWORD, _DWORD, _DWORD);
// 6A8480: using guessed type int __fastcall strlcpy(_DWORD, _DWORD, _DWORD);
// 6A8604: using guessed type int __fastcall user_lock(_DWORD, _DWORD, _DWORD);
// 6A8778: using guessed type int __fastcall split_string(_DWORD, _DWORD, _DWORD, _DWORD);
// 6A88A4: using guessed type int __fastcall str_to_gb2312(_DWORD, _DWORD, _DWORD, _DWORD);

